#include "ast.h"
#include <iostream>

LLVMContext TheContext;
std::unique_ptr<Module> TheModule(std::make_unique<Module>("my module", TheContext));
IRBuilder<> Builder = IRBuilder<>(TheContext);
std::map<std::string, Value *> NamedValues;
std::map<std::string, Value *> ConstValues;
std::map<std::string, std::unique_ptr<PrototypeAST>> FunctionProtos;
std::map<std::string, Function *> Library
{
    std::make_pair("readln",
                   dyn_cast<Function>(dyn_cast<Constant>(TheModule->getOrInsertFunction("readln", getType(Integer), PointerType::getUnqual(getType(Integer)))
                                                             .getCallee()))),
    std::make_pair("inc",
                   dyn_cast<Function>(dyn_cast<Constant>(TheModule->getOrInsertFunction("inc", getType(Integer), PointerType::getUnqual(getType(Integer)))
                                                             .getCallee()))),
    std::make_pair("dec",
                   dyn_cast<Function>(dyn_cast<Constant>(TheModule->getOrInsertFunction("dec", getType(Integer), PointerType::getUnqual(getType(Integer)))
                                                             .getCallee())))
};

// Create main function
Function *main_func = dyn_cast<Function>(dyn_cast<Constant>(TheModule->getOrInsertFunction("main", getType(Integer), NULL).getCallee()));

// Create basic block and start inserting into it
BasicBlock *mainBlock = BasicBlock::Create(TheModule->getContext(), "main.0", main_func);

void WriteFile(const std::string& name)
{
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    TheModule->setTargetTriple(TargetTriple);

    std::string error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, error);
    if (!Target)
    {
        errs() << error;
        return;
    }
    
    auto TheTargetMachine = Target->createTargetMachine(TargetTriple, "generic", "", TargetOptions(), Optional<Reloc::Model>());
    TheModule->setDataLayout(TheTargetMachine->createDataLayout());

    std::string filename = name + ".o";
    std::error_code ec;
    raw_fd_ostream dest(filename, ec, sys::fs::OF_None);
    if (ec)
    {
        errs() << "Can't open a file:" << ec.message();
        return;
    }

    legacy::PassManager Pass;
    auto filetype = CGFT_ObjectFile;
    TheTargetMachine->addPassesToEmitFile(Pass, dest, nullptr, filetype);
    Pass.run(*TheModule);
    dest.flush();

    execl(GPP, GPP, "inc.o", filename, "-o", name, NULL);
}

Type *getType(TypeName t)
{
    switch (t)
    {
    case Real:
    case Single:
    case Double:
        return Type::getDoubleTy(TheContext);
    case Boolean:
        return Type::getInt1Ty(TheContext);
    case Byte:
    case ShortInt:
        return Type::getInt8Ty(TheContext);
    case SmallInt:
    case Word:
        return Type::getInt16Ty(TheContext);
    case Integer:
    case LongInt:
        return Type::getInt32Ty(TheContext);
    case Char:
        return Type::getInt8Ty(TheContext);
    default:
        throw("Unknown typename");
    }
    return Type::getVoidTy(TheContext);
}

Value *ProgramExprAST::codegen()
{
    PrototypeAST("writeln", {"x"}, {Integer}, Integer).codegen();

    Builder.SetInsertPoint(mainBlock);
    Declarations->codegen();
    MainBlock->codegen();

    Builder.CreateRet(NumberExprAST(0).codegen());

    WriteFile(Name);
}

Value *getNumberValue(double Val, TypeName t)
{
    switch (t)
    {
    case Real:
    case Single:
    case Double:
        return ConstantFP::get(TheContext, APFloat(Val));
    case Boolean:
        return ConstantInt::get(TheContext, APInt(1, Val));
    case Byte:
        return ConstantInt::get(TheContext, APInt(8, Val, false));
    case ShortInt:
        return ConstantInt::get(TheContext, APInt(8, Val, true));
    case SmallInt:
        return ConstantInt::get(TheContext, APInt(16, Val, true));
    case Word:
        return ConstantInt::get(TheContext, APInt(16, Val, false));
    case Integer:
    case LongInt:
        return ConstantInt::get(TheContext, APInt(32, Val, true));
    default:
        throw("Unknown type");
    }
}

int getPrecedence(OperEnum &op)
{
    switch (op)
    {
    case ASSIGN:
        throw("Assign should not have any precedence");
    case ADD:
    case SUB:
        return 1;
    case MULT:
    case DIV:
    case MOD:
        return 2;
    case LT:
    case LE:
    case GT:
    case GE:
    case EQ:
    case NE:
        return 3;
    case OR:
    case AND:
        return 4;
    default:
        throw("Unknown operator precedence");
    }
    return 0;
}

//===----------------------------------------------------------------------===//
// Code Generation
//===----------------------------------------------------------------------===//

Value *NumberExprAST::codegen()
{
    return getNumberValue(Val, type);
}

Value *StringExprAST::codegen()
{
    return Builder.CreateGlobalStringPtr(StringRef(Val));
}

Value *ExprListAST::codegen()
{
    for (auto &expr : Nodes)
        if (expr)
            if (!expr->codegen())
                return nullptr;
    return Constant::getNullValue(Type::getInt32Ty(TheContext));
}

Value *ConstExprAST::codegen()
{
    Value *alloca = ConstValues[Name];
    if (alloca)
        throw("Constant redeclaration");
    alloca = Builder.CreateAlloca(getType(type));
    Builder.CreateStore(getNumberValue(Val, type), alloca);
    ConstValues[Name] = alloca;
    return alloca;
}

Value *DeclareExprAST::codegen()
{
    std::string sugar = Name + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    std::cerr << "Declare sugar:" << sugar << std::endl;
    Value *alloca = NamedValues[sugar];
    if (alloca)
        throw("Variable redeclaration.");

    if (Length)
    {
        alloca = Builder.CreateAlloca(getType(type), ConstantInt::get(TheContext, APInt(32, Length, true)));
        alloca = Builder.CreateGEP(getType(type), alloca, ConstantInt::get(TheContext, APInt(32, Offset, true)));
    }
    else
        alloca = Builder.CreateAlloca(getType(type));
    NamedValues[sugar] = alloca;
    return alloca;
}

Value *VariableExprAST::codegen()
{
    std::string sugar = Name + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    std::cerr << "Variable sugar:" << sugar << std::endl;

    Value *V = NamedValues[sugar];
    if (!V)
        V = ConstValues[Name];
    if (!V)
        throw("Unknown constant/variable name");
    return Builder.CreateLoad(V, Name.c_str());
}

Value *ArrayExprAST::codegen()
{
    std::string sugar = Name + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    std::cerr << "Array sugar:" << sugar << std::endl;
    Value *V = NamedValues[sugar];
    if (!V)
        throw("Unknown array name");
    auto ptr = Builder.CreateGEP(getType(type), V, Index->codegen());
    return Builder.CreateLoad(ptr);
}

Value *BinaryExprAST::codegen()
{
    // Special case '=' because we don't want to emit the LHS as an expression.
    if (Op == ASSIGN)
    {
        VariableExprAST *LHSE = static_cast<VariableExprAST *>(LHS.get());
        if (!LHSE)
            throw("destination of '=' must be a variable");
        // Codegen the RHS.
        Value *Val = RHS->codegen();
        if (!Val)
            return nullptr;

        // Look up the name.
        // Value *Variable = NamedValues[LHSE->getName()];
        Value *Variable = LHSE->alloca();
        if (!Variable)
            throw("Unknown variable name");

        Builder.CreateStore(Val, Variable);
        return Val;
    }

    Value *L = LHS->codegen();
    Value *R = RHS->codegen();
    if (!L || !R)
        return nullptr;

    switch (Op)
    {
    case ADD:
        return Builder.CreateAdd(L, R, "addtmp");
    case SUB:
        return Builder.CreateSub(L, R, "subtmp");
    case MULT:
        return Builder.CreateMul(L, R, "multmp");
    case DIV:
        return Builder.CreateSDiv(L, R, "divtmp");
    case MOD:
        return Builder.CreateSRem(L, R, "modtmp");
    case LT:
        L = Builder.CreateICmpSLT(L, R, "lttmp");
        return Builder.CreateIntCast(L, Type::getInt32Ty(TheContext), true, "booltmp");
    case LE:
        L = Builder.CreateICmpSLE(L, R, "letmp");
        return Builder.CreateIntCast(L, Type::getInt32Ty(TheContext), true, "booltmp");
    case GT:
        L = Builder.CreateICmpSGT(L, R, "gttmp");
        return Builder.CreateIntCast(L, Type::getInt32Ty(TheContext), true, "booltmp");
    case GE:
        L = Builder.CreateICmpSGE(L, R, "getmp");
        return Builder.CreateIntCast(L, Type::getInt32Ty(TheContext), true, "booltmp");
    case EQ:
        L = Builder.CreateICmpEQ(L, R, "eqtmp");
        return Builder.CreateIntCast(L, Type::getInt32Ty(TheContext), true, "booltmp");
    case NE:
        L = Builder.CreateICmpNE(L, R, "netmp");
        return Builder.CreateIntCast(L, Type::getInt32Ty(TheContext), true, "booltmp");
    case AND:
        L = Builder.CreateICmpNE(
            L, ConstantInt::get(TheContext, APInt(32, 0, true)), "booltmp");
        R = Builder.CreateICmpNE(
            R, ConstantInt::get(TheContext, APInt(32, 0, true)), "booltmp");
        L = Builder.CreateAnd(L, R, "andtmp");
        return Builder.CreateIntCast(L, Type::getInt32Ty(TheContext), true, "booltmp");
    case OR:
        return Builder.CreateOr(L, R, "ortmp");
    default:
        throw("Unknown operator");
    }
    return nullptr;
}

Value *CallExprAST::codegen()
{
    // Look up the name in the global module table.
    Function *CalleeF = TheModule->getFunction(Callee);
    if (!CalleeF)
        throw("Unknown function referenced");

    // If argument mismatch error.
    if (CalleeF->arg_size() != Args.size())
        throw("Incorrect # arguments passed");

    std::vector<Value *> ArgsV;
    for (unsigned i = 0, e = Args.size(); i != e; ++i)
    {
        ArgsV.push_back(Args[i]->codegen());
        if (!ArgsV.back())
            return nullptr;
    }

    return Builder.CreateCall(CalleeF, ArgsV, "calltmp");
}

Value *LibraryExprAST::codegen()
{
    std::string sugar = Arg + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    std::cerr << "Library sugar:" << sugar << std::endl;
    auto ptr = NamedValues[sugar];
    if (!ptr)
        return nullptr;
    auto func = Library[Name];
    return Builder.CreateCall(func, ptr);
}

Function *PrototypeAST::codegen()
{
    std::vector<Type *> ParamTypes;
    for (int i = 0; i < Types.size(); i++)
        ParamTypes.push_back(getType(Types[i]));

    FunctionType *FT = FunctionType::get(getType(ReturnType), ParamTypes, false);
    Function *F = Function::Create(FT, Function::ExternalLinkage, Name, TheModule.get());

    // Set names for all arguments.
    unsigned Idx = 0;
    for (auto &Arg : F->args())
        Arg.setName(Args[Idx++]);

    return F;
}

Function *FunctionAST::codegen()
{
    // First, check for an existing function from a previous 'extern' declaration.
    Function *TheFunction = TheModule->getFunction(Proto->getName());

    if (!TheFunction)
        TheFunction = Proto->codegen();

    if (!TheFunction)
        return nullptr;

    // Create a new basic block to start insertion into.
    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", TheFunction);
    Builder.SetInsertPoint(BB);

    for (auto &Arg : TheFunction->args())
    {
        // Create an alloca for this variable.
        Value *Alloca = CreateEntryBlockAlloca(TheFunction, Arg.getName());

        // Store the initial value int o the alloca.
        Builder.CreateStore(&Arg, Alloca);

        // Add arguments to variable symbol table.
        std::string sugar = Arg.getName().str() + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
        NamedValues[sugar] = Alloca;
    }

    BasicBlock *Ret = BasicBlock::Create(TheContext, "return", TheFunction);

    for (unsigned i = 0; i < Body.size(); i++)
    {
        if (i != Body.size() - 1)
            Body[i]->codegen();
        else if (Value *RetVal = Body[i]->codegen())
        {
            Builder.CreateBr(Ret);
            // Finish off the function.
            Builder.SetInsertPoint(Ret);
            Builder.CreateRet(RetVal);

            // Validate the generated code, checking for consistency.
            verifyFunction(*TheFunction);

            Builder.SetInsertPoint(mainBlock);
            return TheFunction;
        }
        else
            break;
    }

    // Error reading body, remove function.
    TheFunction->eraseFromParent();
    return nullptr;
}

Value *ReturnExprAST::codegen()
{
    Function *TheFunction = TheModule->getFunction(Builder.GetInsertPoint()->getParent()->getName());
    std::string sugar = TheFunction->getName().str() + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    Value *Alloca = NamedValues[sugar];
    Value *Ret;
    if (Alloca)
        Ret = Builder.CreateLoad(Alloca);
    else
        Ret = ConstantInt::get(TheContext, APInt(32, 0, true));
    Builder.CreateRet(Ret);
    BasicBlock *Cont = BasicBlock::Create(TheContext, "dunno", TheFunction);
    Builder.SetInsertPoint(Cont);
    return ConstantInt::get(TheContext, APInt(32, 0, true));
}

Value *ForExprAST::codegen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    // Create an alloca for the variable in the entry block.
    // Value *Alloca = CreateEntryBlockAlloca(TheFunction, VarName);
    std::string sugar = VarName + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    Value *Alloca = NamedValues[sugar];
    if (!Alloca)
        throw("Unknown variable name in for cycle");

    // Emit the start code first, without 'variable' in scope.
    Value *StartVal = Start->codegen();
    if (!StartVal)
        return nullptr;

    // Store the value into the alloca.
    Builder.CreateStore(StartVal, Alloca);

    // Make the new basic block for the loop header, inserting after current
    // block.
    BasicBlock *LoopBB = BasicBlock::Create(TheContext, "loop", TheFunction);

    // Insert an explicit fall through from the current block to the LoopBB.
    Builder.CreateBr(LoopBB);

    // Start insertion in LoopBB.
    Builder.SetInsertPoint(LoopBB);

    // Within the loop, the variable is defined equal to the PHI node.  If it
    // shadows an existing variable, we have to restore it, so save it now.
    Value *OldVal = NamedValues[sugar];
    NamedValues[sugar] = Alloca;

    // Emit the body of the loop.  This, like any other expr, can change the
    // current BB.  Note that we ignore the value computed by the body, but don't
    // allow an error.
    if (!Body->codegen())
        return nullptr;

    // Emit the step value.
    Value *StepVal = nullptr;
    if (Step)
    {
        StepVal = Step->codegen();
        if (!StepVal)
            return nullptr;
    }
    else
    {
        // If not specified, use 1.0.
        StepVal = ConstantInt::get(TheContext, APInt(32, 1, true));
    }

    // Compute the end condition.
    Value *EndCond = Builder.CreateIntCast(
        Builder.CreateICmpEQ(End->codegen(),
                             Builder.CreateLoad(Alloca, "endforload"),
                             "endfor"),
        Type::getInt32Ty(TheContext),
        false,
        "endforcast");
    if (!EndCond)
        return nullptr;

    // Reload, increment, and restore the alloca.  This handles the case where
    // the body of the loop mutates the variable.
    Value *CurVar = Builder.CreateLoad(Alloca, VarName.c_str());
    Value *NextVar = Builder.CreateFAdd(CurVar, StepVal, "nextvar");
    Builder.CreateStore(NextVar, Alloca);

    // Convert condition to a bool by comparing non-equal to 0.0.
    EndCond = Builder.CreateICmpNE(EndCond, ConstantInt::get(TheContext, APInt(32, 1, true)), "loopcond");

    // Create the "after loop" block and insert it.
    BasicBlock *AfterBB = BasicBlock::Create(TheContext, "afterloop", TheFunction);

    // Insert the conditional branch into the end of LoopEndBB.
    Builder.CreateCondBr(EndCond, LoopBB, AfterBB);

    // Any new code will be inserted in AfterBB.
    Builder.SetInsertPoint(AfterBB);

    // Restore the unshadowed variable.
    if (OldVal)
        NamedValues[sugar] = OldVal;
    else
        NamedValues.erase(sugar);

    // for expr always returns 0.0.
    return Constant::getNullValue(Type::getInt32Ty(TheContext));
}

Value *IfExprAST::codegen()
{
    Value *CondV = Cond->codegen();
    if (!CondV)
        return nullptr;

    // Convert condition to a bool by comparing non-equal to 0.0.
    CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(TheContext, APInt(32, 0, true)), "ifcond");

    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    // Create blocks for the then and else cases.  Insert the 'then' block at the
    // end of the function.
    BasicBlock *ThenBB = BasicBlock::Create(TheContext, "then", TheFunction);
    BasicBlock *ElseBB = BasicBlock::Create(TheContext, "else");
    BasicBlock *MergeBB = BasicBlock::Create(TheContext, "ifcont");

    Builder.CreateCondBr(CondV, ThenBB, ElseBB);
    Builder.SetInsertPoint(ThenBB);

    Value *ThenV = Then->codegen();
    if (!ThenV)
        return nullptr;

    Builder.CreateBr(MergeBB);
    // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
    ThenBB = Builder.GetInsertBlock();

    // Emit else block.
    TheFunction->getBasicBlockList().push_back(ElseBB);
    Builder.SetInsertPoint(ElseBB);

    Value *ElseV = Else->codegen();
    if (!ElseV)
        return nullptr;

    Builder.CreateBr(MergeBB);
    // Codegen of 'Else' can change the current block, update ElseBB for the PHI.
    ElseBB = Builder.GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(MergeBB);
    Builder.SetInsertPoint(MergeBB);
    PHINode *PN = Builder.CreatePHI(Type::getInt32Ty(TheContext), 2, "iftmp");

    PN->addIncoming(ThenV, ThenBB);
    PN->addIncoming(ElseV, ElseBB);
    return PN;
}

Value *RepeatExprAST::codegen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    // Make the new basic block for the loop header, inserting after current
    // block.
    BasicBlock *CondBB = BasicBlock::Create(TheContext, "cond", TheFunction);
    // Create blocks for the body and exit.  Insert the 'cond' block at the
    // end of the function.
    BasicBlock *LoopBB = BasicBlock::Create(TheContext, "loop");
    BasicBlock *ExitBB = BasicBlock::Create(TheContext, "exit");

    Builder.CreateBr(LoopBB);

    TheFunction->getBasicBlockList().push_back(LoopBB);
    Builder.SetInsertPoint(LoopBB);
    Value *LoopV = Body->codegen();
    if (!LoopV)
        return nullptr;

    Builder.CreateBr(CondBB);
    Builder.SetInsertPoint(CondBB);
    Value *CondV = Cond->codegen();
    if (!CondV)
        return nullptr;

    // Convert condition to a bool by comparing equal to 0.0.
    CondV = Builder.CreateICmpEQ(CondV, ConstantInt::get(TheContext, APInt(32, 0, true)), "ifcond");
    Builder.CreateCondBr(CondV, LoopBB, ExitBB);

    TheFunction->getBasicBlockList().push_back(ExitBB);
    Builder.SetInsertPoint(ExitBB);

    return Constant::getNullValue(Type::getInt32Ty(TheContext));
}

Value *WhileExprAST::codegen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    // Make the new basic block for the loop header, inserting after current
    // block.
    BasicBlock *CondBB = BasicBlock::Create(TheContext, "cond", TheFunction);
    // Create blocks for the body and exit.  Insert the 'cond' block at the
    // end of the function.
    BasicBlock *LoopBB = BasicBlock::Create(TheContext, "loop");
    BasicBlock *ExitBB = BasicBlock::Create(TheContext, "exit");

    Builder.CreateBr(CondBB);

    // Start insertion in LoopBB.
    Builder.SetInsertPoint(CondBB);
    Value *CondV = Cond->codegen();
    if (!CondV)
        return nullptr;

    // Convert condition to a bool by comparing non-equal to 0.0.
    CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(TheContext, APInt(32, 0, true)), "ifcond");
    Builder.CreateCondBr(CondV, LoopBB, ExitBB);

    TheFunction->getBasicBlockList().push_back(LoopBB);
    Builder.SetInsertPoint(LoopBB);

    Value *LoopV = Body->codegen();
    if (!LoopV)
        return nullptr;
    Builder.CreateBr(CondBB);

    TheFunction->getBasicBlockList().push_back(ExitBB);
    Builder.SetInsertPoint(ExitBB);

    return Constant::getNullValue(Type::getInt32Ty(TheContext));
}

//#######################################################################################

Value *VariableExprAST::alloca(void) const
{
    std::string sugar = Name + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    std::cout << "sugar: " << sugar << std::endl;
    Value *ret = NamedValues[sugar];
    if (!ret)
        throw("Unknown variable alloca name");
    return ret;
}

Value *ArrayExprAST::alloca(void) const
{
    std::string sugar = Name + '/' + Builder.GetInsertBlock()->getParent()->getName().str();
    Value *V = NamedValues[sugar];
    if (!V)
        throw("Unknown array name");
    auto ptr = Builder.CreateGEP(Type::getInt32Ty(TheContext), V, Index->codegen());
    return ptr;
}

//#######################################################################################

/// CreateEntryBlockAlloca - Create an alloca instruction in the entry block of
/// the function.  This is used for mutable variables etc.
AllocaInst *CreateEntryBlockAlloca(Function *TheFunction,
                                   const std::string &VarName)
{
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
                     TheFunction->getEntryBlock().begin());
    return TmpB.CreateAlloca(Type::getInt32Ty(TheContext), 0,
                             VarName.c_str());
}
