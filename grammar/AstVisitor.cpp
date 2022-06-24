#include "AstVisitor.h"
#include "ast.h"

std::any AstVisitor::visitGoal(ObjectPascalParser::GoalContext *ctx)
{
    if (ctx->program())
        return visitProgram(ctx->program());
    return visitChildren(ctx);
}

std::any AstVisitor::visitProgram(ObjectPascalParser::ProgramContext *ctx)
{
    std::vector<ExprAST *> decls;
    for (auto decl : ctx->declSection())
    {
        auto d = std::any_cast<ExprAST *>(visitDeclSection(decl));
        decls.push_back(d);
    }
    ExprListAST *section = new ExprListAST(decls);
    ExprListAST *stmts = std::any_cast<ExprListAST *>(visitCompoundStmt(ctx->compoundStmt()));
    return new ProgramExprAST(ctx->Identifier()->getText(), section, stmts);
}

std::any AstVisitor::visitStmtList(ObjectPascalParser::StmtListContext *ctx)
{
    std::vector<ExprAST *> stmts;
    for (auto s : ctx->statement())
        stmts.push_back(std::any_cast<ExprAST *>(visitStatement(s)));
    return new ExprListAST(stmts);
}

std::any AstVisitor::visitStatement(ObjectPascalParser::StatementContext *ctx)
{
    if (ctx->simpleStatement())
        return visitSimpleStatement(ctx->simpleStatement());
    else if (ctx->structStmt())
        return visitStructStmt(ctx->structStmt());
    return visitChildren(ctx);
}

std::any AstVisitor::visitSimpleStatement(ObjectPascalParser::SimpleStatementContext *ctx)
{
    if (ctx->assignmentStmt())
        return visitAssignmentStmt(ctx->assignmentStmt());
    else if (ctx->procedureCall())
        return visitProcedureCall(ctx->procedureCall());
    return visitChildren(ctx);
}

std::any AstVisitor::visitAssignmentStmt(ObjectPascalParser::AssignmentStmtContext *ctx)
{

}

std::any AstVisitor::visitProcedureCall(ObjectPascalParser::ProcedureCallContext *ctx)
{
    
}

std::any AstVisitor::visitStructStmt(ObjectPascalParser::StructStmtContext *ctx)
{
    if (ctx->compoundStmt())
        return visitCompoundStmt(ctx->compoundStmt());
    else if (ctx->conditionalStmt())
        return visitConditionalStmt(ctx->conditionalStmt());
    else if (ctx->loopStmt())
        return visitLoopStmt(ctx->loopStmt());
    return visitChildren(ctx);
}

std::any AstVisitor::visitConditionalStmt(ObjectPascalParser::ConditionalStmtContext *ctx)
{

}

std::any AstVisitor::visitLoopStmt(ObjectPascalParser::LoopStmtContext *ctx)
{

}

std::any AstVisitor::visitConstSection(ObjectPascalParser::ConstSectionContext *ctx)
{
    std::vector<ExprAST *> consts;
    for (auto s : ctx->constantDecl())
        consts.push_back(std::any_cast<ExprAST *>(visitConstantDecl(s)));
    return new ExprListAST(consts);
}

std::any AstVisitor::visitConstantDecl(ObjectPascalParser::ConstantDeclContext *ctx)
{
    if (ctx->constExpr())
    {
        // TODO: add string values
        TypeName t = Integer;
        const double d = std::any_cast<double>(visitConstExpr(ctx->constExpr()));
        if (d != (long int) d)
            t = Double;
        return new ConstExprAST(ctx->Identifier()->getText(), d, t);
    }
    return visitChildren(ctx);
}

std::any AstVisitor::visitConstExpr(ObjectPascalParser::ConstExprContext *ctx)
{
    if (ctx->number().size())
    {
        std::vector<double> nums;
        for (auto n : ctx->number())
            nums.push_back(std::stod(n->getText()));
        char op;
        if (ctx->additiveOp())
            op = ctx->additiveOp()->getText()[0];
        double val;
        switch (op)
        {   
            case '+':
                val = nums[0] + nums[1]; break;
            case '-':
                val = nums[0] - nums[1]; break;
            case '*':
                val = nums[0] * nums[1]; break;
            default:
                val = nums[0]; break;
        }
        return val;
    }
    // TODO: visit string values
    return visitChildren(ctx);
}

std::any AstVisitor::visitVarSection(ObjectPascalParser::VarSectionContext *ctx)
{
    std::vector<ExprAST *> vars;
    for (auto v : ctx->varDecl())
        vars.push_back(std::any_cast<ExprAST *>(visitVarDecl(v)));
    return new ExprListAST(vars);
}

std::any AstVisitor::visitVarDecl(ObjectPascalParser::VarDeclContext *ctx)
{
    std::vector<ExprAST *> vars;
    std::vector<std::string> ids = std::any_cast<std::vector<std::string>>(visitIdentList(ctx->identList()));
    std::string type = ctx->type()->getText();
    // TODO: get typename
    TypeName t = Integer;
    for (auto id : ids)
        vars.push_back(new DeclareExprAST(id));
    return new ExprListAST(vars);
}

std::any AstVisitor::visitProcedureDecl(ObjectPascalParser::ProcedureDeclContext *ctx)
{
    PrototypeAST *proto = std::any_cast<PrototypeAST *>(visitProcedureHeading(ctx->procedureHeading()));
    std::vector<ExprAST *> body;
    body.push_back(std::any_cast<ExprListAST *>(visitBlock(ctx->block())));
    body.push_back(new NumberExprAST(0));
    return new FunctionAST(proto, body);
}

std::any AstVisitor::visitFunctionDecl(ObjectPascalParser::FunctionDeclContext *ctx)
{
    PrototypeAST *proto = std::any_cast<PrototypeAST *>(visitFunctionHeading(ctx->functionHeading()));
    std::vector<ExprAST *> body;
    body.push_back(new DeclareExprAST(proto->Name, proto->ReturnType));
    body.push_back(std::any_cast<ExprListAST *>(visitBlock(ctx->block())));
    body.push_back(new VariableExprAST(proto->Name));
    return new FunctionAST(proto, body);
}

std::any AstVisitor::visitProcedureHeading(ObjectPascalParser::ProcedureHeadingContext *ctx)
{
    std::string name = ctx->Identifier()->getText();
    auto args = std::any_cast<std::vector<std::pair<std::string, TypeName>>>(visitFormalParameters(ctx->formalParameters()));
    std::vector<std::string> argnames;
    std::vector<TypeName> argtypes;
    for (auto arg : args)
    {
        argnames.push_back(arg.first);
        argtypes.push_back(arg.second);
    }
    return new PrototypeAST(name, argnames, argtypes);
}

std::any AstVisitor::visitFunctionHeading(ObjectPascalParser::FunctionHeadingContext *ctx)
{
    std::string name = ctx->Identifier()->getText();
    auto args = std::any_cast<std::vector<std::pair<std::string, TypeName>>>(visitFormalParameters(ctx->formalParameters()));
    std::vector<std::string> argnames;
    std::vector<TypeName> argtypes;
    for (auto arg : args)
    {
        argnames.push_back(arg.first);
        argtypes.push_back(arg.second);
    }
    // TODO: get return type instead of integer
    return new PrototypeAST(name, argnames, argtypes, Integer);
}

std::any AstVisitor::visitBlock(ObjectPascalParser::BlockContext *ctx)
{
    std::vector<ExprAST *> result;
    if (ctx->declSection())
        result.push_back(std::any_cast<ExprAST *>(visitDeclSection(ctx->declSection())));
    result.push_back(std::any_cast<ExprAST *>(visitCompoundStmt(ctx->compoundStmt())));
    return new ExprListAST(result);
}

std::any AstVisitor::visitIdentList(ObjectPascalParser::IdentListContext *ctx)
{
    std::vector<std::string> result;
    for (auto id : ctx->Identifier())
        result.push_back(id->getText());
    return result;
}

std::any AstVisitor::visitFormalParameters(ObjectPascalParser::FormalParametersContext *ctx)
{
    std::vector<std::pair<std::string, TypeName>> params;
    for (auto fp : ctx->formalParm())
        params.push_back(std::any_cast<std::pair<std::string, TypeName>>(visitFormalParm(fp)));
    return params;
}

std::any AstVisitor::visitParameter(ObjectPascalParser::ParameterContext *ctx)
{
    // TODO: get param type instead of integer
    return std::pair<std::string, TypeName>(ctx->Identifier()->getText(), Integer);
}

std::any AstVisitor::visitString(ObjectPascalParser::StringContext *ctx)
{
    // TODO::проверить на ковычки и другие лишние вещи
    return StringExprAST(ctx->StringLiteral()->getText(), String);
}

std::any AstVisitor::visitNumber(ObjectPascalParser::NumberContext *ctx)
{
    const double d = std::stod(ctx->getText());
    TypeName type = Double;
    if (int(d) == d)
    {
        type = Integer;
    }
    else if (short(d) == d)
    {
        type = SmallInt;
    }
    return new NumberExprAST(d, type);
}
