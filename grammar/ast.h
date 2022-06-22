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
#include "llvm/Bitcode/BitcodeReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"

#include <cctype>
#include <cstdlib>
#include <unistd.h>

#include <map>
#include <string>
#include <vector>

#define LLC "/lib/llvm-10/bin/llc"
#define GPP "/bin/g++"

using namespace llvm;

enum TypeName
{
    Void,
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
    Custom,
};

void WriteFile(const std::string &name);

Type *getType(TypeName t, const std::string &custom = "");
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
    std::vector<ExprAST *> Nodes;

public:
    ExprListAST(std::vector<ExprAST *> Nodes) : Nodes(std::move(Nodes)) {}
    ~ExprListAST() { for (int i = 0; i < Nodes.size(); i++) delete Nodes[i]; Nodes.clear(); }
    Value *codegen() override;
};

// ProgramExprAST - class for program overall
class ProgramExprAST : public ExprAST
{
    std::string Name;
    ExprListAST *Declarations;
    ExprListAST *MainBlock;

public:
    ProgramExprAST(const std::string &Name, ExprListAST *Decls, ExprListAST *Block) : Name(Name), Declarations(Decls), MainBlock(Block) {}
    ~ProgramExprAST() { delete Declarations; delete MainBlock; }
    Value *codegen() override;
};

// NumberExprAST - class for numeric literals like "1".
class NumberExprAST : public ExprAST
{
    double Val;

public:
    NumberExprAST(double Val, TypeName Type = Integer) : Val(Val) { type = Type; }
    ~NumberExprAST() {}
    Value *codegen() override;
};

// StringExprAST - class for string literals.
class StringExprAST : public ExprAST
{
    std::string Val;

public:
    StringExprAST(const std::string &Val, TypeName Type = Char) : Val(Val) { type = Type; }
    ~StringExprAST() {}
    Value *codegen() override;
};

// ConstExprAST - class for const declaration
class ConstExprAST : public ExprAST
{
    std::string Name;
    double Val;

public:
    ConstExprAST(const std::string &Name, double Val, TypeName Type = Integer) : Name(Name), Val(Val) { type = Type; }
    ~ConstExprAST() {}
    Value *codegen() override;
};

// DeclareExprAST - class for variable/array declaration
class DeclareExprAST : public ExprAST
{
    std::string Name;
    int Offset;
    int Length;

public:
    DeclareExprAST(const std::string &Name, TypeName Type = Integer, int Offset = 0, int Length = 0) : 
        Name(Name), Offset(Offset), Length(Length) { type = Type; }
    ~DeclareExprAST() {}
    Value *codegen() override;
};

/// VariableExprAST - class for referencing a variable, like "a".
class VariableExprAST : public ExprAST
{
protected:
    std::string Name;

public:
    VariableExprAST(const std::string &Name) : Name(Name) {}
    ~VariableExprAST() {}
    Value *codegen() override;
    const std::string &getName() const { return Name; }
    virtual Value *alloca() const;
};

// ArrayExprAST - class for referencing array element
class ArrayExprAST : public VariableExprAST
{
    ExprAST *Index;

public:
    ArrayExprAST(const std::string &Name, ExprAST *Index, TypeName Type = Integer) : 
        VariableExprAST(Name), Index(Index) { type = Type; }
    ~ArrayExprAST() { delete Index; }
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
    ExprAST *LHS, *RHS;

public:
    BinaryExprAST(OperEnum Op, ExprAST *LHS, ExprAST *RHS) : Op(Op), LHS(LHS), RHS(RHS) {}
    ~BinaryExprAST() { delete LHS; delete RHS; }
    Value *codegen() override;
};

// IfExprAST - class for if/then/else.
class IfExprAST : public ExprAST
{
    ExprAST *Cond, *Then, *Else;

public:
    IfExprAST(ExprAST *Cond, ExprAST *Then, ExprAST *Else) : Cond(Cond), Then(Then), Else(Else) {}
    ~IfExprAST() { delete Cond; delete Then; delete Else; }
    Value *codegen() override;
};

// ForExprAST -  class for for/to(downto).
class ForExprAST : public ExprAST
{
    std::string VarName;
    ExprAST *Start, *End, *Step, *Body;

public:
    ForExprAST(const std::string &VarName, ExprAST *Start,
               ExprAST *End, ExprAST *Step, ExprAST *Body)
        : VarName(VarName), Start(Start), End(End), Step(Step), Body(Body) {}
    ~ForExprAST() { delete Start; delete Step; delete End; delete Body; }
    Value *codegen() override;
};

// WhileExprAST -  class for while/do.
class WhileExprAST : public ExprAST
{
    ExprAST *Cond, *Body;

public:
    WhileExprAST(ExprAST *Cond, ExprAST *Body) : Cond(Cond), Body(Body) {}
    ~WhileExprAST() { delete Body; delete Cond; }
    Value *codegen() override;
};

// RepeatExprAST -  class for repeat/until.
class RepeatExprAST : public ExprAST
{
    ExprAST *Cond, *Body;

public:
    RepeatExprAST(ExprAST *Cond, ExprAST *Body) : Cond(Cond), Body(Body) {}
    ~RepeatExprAST() { delete Body; delete Cond; }
    Value *codegen() override;
};

// CallExprAST - class for function calls.
class CallExprAST : public ExprAST
{
    std::string Callee;
    std::vector<ExprAST *> Args;

public:
    CallExprAST(const std::string &Callee, std::vector<ExprAST *> Args) : Callee(Callee), Args(std::move(Args)) {}
    ~CallExprAST() { for (int i = 0; i < Args.size(); i++) delete Args[i]; Args.clear(); }
    Value *codegen() override;
};

// LibraryExprAST - class for function (from standard library) calls
class LibraryExprAST : public ExprAST
{
    std::string Name;
    std::string Arg;

public:
    LibraryExprAST(const std::string &Name, const std::string &Arg) : Name(Name), Arg(Arg) {}
    ~LibraryExprAST() {}
    Value *codegen() override;
};

// ReturnExprAST - class for return statement
class ReturnExprAST : public ExprAST
{
public:
    ReturnExprAST() {}
    ~ReturnExprAST() {}
    Value *codegen() override;
};

// PrototypeAST - class represents prototype for a function
class PrototypeAST : public ExprAST
{
public:
    std::string Name;
    std::vector<std::string> Args;
    std::vector<TypeName> Types;
    TypeName ReturnType;

    PrototypeAST(const std::string &Name, std::vector<std::string> Args, std::vector<TypeName> ArgTypes, TypeName Ret)
        : Name(Name), Args(std::move(Args)), Types(std::move(ArgTypes)), ReturnType(Ret) {}
    ~PrototypeAST() { Args.clear(); Types.clear(); }
    Function *codegen() override;
};

// FunctionAST - class represents a function definition itself.
class FunctionAST : public ExprAST
{
    PrototypeAST *Proto;
    std::vector<ExprAST *> Body;

public:
    FunctionAST(PrototypeAST *Proto, std::vector<ExprAST *> Body) : Proto(Proto), Body(std::move(Body)) {}
    ~FunctionAST() { for (int i = 0; i < Body.size(); i++) delete Body[i]; Body.clear(); delete Proto; }
    Function *codegen() override;
};

// RecordAST - class for record (struct) definition
class RecordAST : public ExprAST
{
protected:
    std::vector<ExprAST *> DataMembers;

public:
    std::string Name;

    RecordAST(const std::string &Name, std::vector<ExprAST *> Body, TypeName Type = Custom) : 
        Name(Name), DataMembers(std::move(Body)) { type = Type; }
    ~RecordAST() { for (int i = 0; i < DataMembers.size(); i++) delete DataMembers[i]; DataMembers.clear(); }
    Value *codegen() override;
};

// ClassAST - class for class definition
class ClassAST : public RecordAST
{
    std::vector<PrototypeAST *> ProtoMembers;

public:
    ClassAST(const std::string &Name, std::vector<ExprAST *> Data, std::vector<PrototypeAST *> Proto) : 
             RecordAST(Name, std::move(Data)), ProtoMembers(std::move(Proto)) {}
    ~ClassAST() { for (int i = 0; i < ProtoMembers.size(); i++) delete ProtoMembers[i]; ProtoMembers.clear(); }
    Value *codegen() override;
};

// TypeExprAST - class for type directive
class TypeExprAST : public ExprAST
{
    std::vector<RecordAST *> Declarations;

public:
    TypeExprAST(std::vector<RecordAST *> Decls) : Declarations(std::move(Decls)) {}
    ~TypeExprAST() { for (int i = 0; i < Declarations.size(); i++) delete Declarations[i]; Declarations.clear(); }
    Value *codegen() override;
};

//################################################################################
AllocaInst *CreateEntryBlockAlloca(Function *TheFunction,
                                   const std::string &VarName);

#endif
