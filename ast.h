#ifndef AST_H
#define AST_H

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#include <cctype>
#include <cstdlib>
#include <unistd.h>

#include <map>
#include <string>
#include <vector>

#define GPP "/bin/g++"

using namespace llvm;

enum TypeName
{
    Boolean,
    Real,
    Single,
    Double,
    Byte,
    ShortInt,
    SmallInt,
    Integer,
    LongInt,
    Word,
    Char,
    WideChar,
    LongChar,
    PChar,
    String,
    AnsiString,
    WideString,
};

void WriteFile(const std::string& name);

Type *getType(TypeName t);
Value *getNumberValue(double Val, TypeName t);

// Base class
class ExprAST
{
public:
    TypeName type;
    virtual ~ExprAST() {}
    virtual Value *codegen() = 0;
};

// ExprListAST - class for program block - list of expression
class ExprListAST : public ExprAST
{
    std::vector<std::unique_ptr<ExprAST>> Nodes;

public:
    ExprListAST(std::vector<std::unique_ptr<ExprAST>> Nodes) : Nodes(std::move(Nodes)) {}
    Value *codegen() override;
};

// ProgramExprAST - class for program overall
class ProgramExprAST : public ExprAST
{
    std::string Name;
    std::unique_ptr<ExprListAST> Declarations;
    std::unique_ptr<ExprListAST> MainBlock;

public:
    ProgramExprAST(const std::string& Name, std::unique_ptr<ExprListAST> Decls, std::unique_ptr<ExprListAST> Block) : 
        Name(Name), Declarations(std::move(Decls)), MainBlock(std::move(Block)) {}
    Value *codegen() override;
};

// NumberExprAST - class for numeric literals like "1".
class NumberExprAST : public ExprAST
{
    double Val;

public:
    NumberExprAST(double Val, const TypeName &Type = Integer) : Val(Val) { type = Type; }
    Value *codegen() override;
};

// StringExprAST - class for string literals.
class StringExprAST : public ExprAST
{
    std::string Val;

public:
    StringExprAST(const std::string &Val, const TypeName &Type = Char) : Val(Val) { type = Type; }
    Value *codegen() override;
};

// ConstExprAST - class for const declaration
class ConstExprAST : public ExprAST
{
    std::string Name;
    double Val;

public:
    ConstExprAST(const std::string &Name, double Val, const TypeName &Type = Integer) : Name(Name), Val(Val) { type = Type; }
    Value *codegen() override;
};

// DeclareExprAST - class for variable/array declaration
class DeclareExprAST : public ExprAST
{
    std::string Name;
    int Offset;
    int Length;

public:
    DeclareExprAST(const std::string &Name, const TypeName &Type = Integer, int Offset = 0, int Length = 0) : Name(Name), Offset(Offset), Length(Length) { type = Type; }
    Value *codegen() override;
};

/// VariableExprAST - class for referencing a variable, like "a".
class VariableExprAST : public ExprAST
{
protected:
    std::string Name;

public:
    VariableExprAST(const std::string &Name) : Name(Name) {}
    Value *codegen() override;
    const std::string &getName() const { return Name; }
    virtual Value *alloca() const;
};

// ArrayExprAST - class for referencing array element
class ArrayExprAST : public VariableExprAST
{
    std::unique_ptr<ExprAST> Index;

public:
    ArrayExprAST(const std::string &Name, std::unique_ptr<ExprAST> Index, const TypeName &Type = Integer) : VariableExprAST(Name), Index(std::move(Index)) { type = Type; }
    Value *codegen() override;
    virtual Value *alloca() const;
};

enum OperEnum
{
    ASSIGN, // 0
    ADD,    // 1
    SUB,    // 2
    MULT,   // 3
    DIV,    // 4
    MOD,    // 5
    LT,     // 6
    LE,     // 7
    GT,     // 8
    GE,     // 9
    EQ,     // 10
    NE,     // 11
    AND,    // 12
    OR,     // 13
};

int getPrecedence(OperEnum &op);

// BinaryExprAST - class for a binary operator.
class BinaryExprAST : public ExprAST
{
    OperEnum Op;
    std::unique_ptr<ExprAST> LHS, RHS;

public:
    BinaryExprAST(OperEnum Op, std::unique_ptr<ExprAST> LHS,
                  std::unique_ptr<ExprAST> RHS)
        : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
    Value *codegen() override;
};

// IfExprAST - class for if/then/else.
class IfExprAST : public ExprAST
{
    std::unique_ptr<ExprAST> Cond, Then, Else;

public:
    IfExprAST(std::unique_ptr<ExprAST> Cond, std::unique_ptr<ExprAST> Then,
              std::unique_ptr<ExprAST> Else)
        : Cond(std::move(Cond)), Then(std::move(Then)), Else(std::move(Else)) {}

    Value *codegen() override;
};

// ForExprAST -  class for for/to(downto).
class ForExprAST : public ExprAST
{
    std::string VarName;
    std::unique_ptr<ExprAST> Start, End, Step, Body;

public:
    ForExprAST(const std::string &VarName, std::unique_ptr<ExprAST> Start,
               std::unique_ptr<ExprAST> End, std::unique_ptr<ExprAST> Step,
               std::unique_ptr<ExprAST> Body)
        : VarName(VarName), Start(std::move(Start)), End(std::move(End)),
          Step(std::move(Step)), Body(std::move(Body)) {}

    Value *codegen() override;
};

// WhileExprAST -  class for while/do.
class WhileExprAST : public ExprAST
{
    std::unique_ptr<ExprAST> Cond, Body;

public:
    WhileExprAST(std::unique_ptr<ExprAST> Cond, std::unique_ptr<ExprAST> Body)
        : Cond(std::move(Cond)), Body(std::move(Body)) {}
    Value *codegen() override;
};

// RepeatExprAST -  class for repeat/until.
class RepeatExprAST : public ExprAST
{
    std::unique_ptr<ExprAST> Cond, Body;

public:
    RepeatExprAST(std::unique_ptr<ExprAST> Cond, std::unique_ptr<ExprAST> Body)
        : Cond(std::move(Cond)), Body(std::move(Body)) {}
    Value *codegen() override;
};

// CallExprAST - class for function calls.
class CallExprAST : public ExprAST
{
    std::string Callee;
    std::vector<std::unique_ptr<ExprAST>> Args;

public:
    CallExprAST(const std::string &Callee,
                std::vector<std::unique_ptr<ExprAST>> Args)
        : Callee(Callee), Args(std::move(Args)) {}
    Value *codegen() override;
};

// LibraryExprAST - class for function (from standard library) calls
class LibraryExprAST : public ExprAST
{
    std::string Name;
    std::string Arg;

public:
    LibraryExprAST(const std::string &Name, const std::string &Arg) : Name(Name), Arg(Arg) {}
    Value *codegen() override;
};

// ReturnExprAST - class for return statement
class ReturnExprAST : public ExprAST
{
public:
    ReturnExprAST() {}
    Value *codegen() override;
};

// PrototypeAST - class represents prototype for a function
class PrototypeAST : public ExprAST
{
    std::string Name;
    std::vector<std::string> Args;
    std::vector<TypeName> Types;
    TypeName ReturnType;

public:
    PrototypeAST(const std::string &Name, std::vector<std::string> Args, std::vector<TypeName> ArgTypes, TypeName Ret)
        : Name(Name), Args(std::move(Args)), Types(std::move(ArgTypes)), ReturnType(Ret) {}
    Function *codegen() override;
    const std::string &getName() const { return Name; }
};

// FunctionAST - class represents a function definition itself.
class FunctionAST : public ExprAST
{
    std::unique_ptr<PrototypeAST> Proto;
    std::vector<std::unique_ptr<ExprAST>> Body;

public:
    FunctionAST(std::unique_ptr<PrototypeAST> Proto,
                std::vector<std::unique_ptr<ExprAST>> Body)
        : Proto(std::move(Proto)), Body(std::move(Body)) {}
    Function *codegen() override;
};

//################################################################################
AllocaInst *CreateEntryBlockAlloca(Function *TheFunction,
                                   const std::string &VarName);

#endif
