#include "AstVisitor.h"
#include "ast.h"

std::any AstVisitor::visitProgram(ObjectPascalParser::ProgramContext *ctx)
{
    std::vector<ExprAST *> decls;
    for (auto decl : ctx->declSection())
    {
        auto d = std::any_cast<ExprListAST *>(visitDeclSection(decl));
        decls.push_back(d);
    }
    ExprListAST *section = new ExprListAST(decls);
    ExprListAST *stmts = new ExprListAST(std::any_cast<ExprListAST>(visitCompoundStmt(ctx->compoundStmt())));
    auto result = new ProgramExprAST(ctx->Identifier()->getText(), section, stmts);
    return result;
}

std::any AstVisitor::visitString(ObjectPascalParser::StringContext *ctx)
{
    // TODO::проверить на ковычки и другие лишние вещи
    return StringExprAST(
        ctx->StringLiteral()->getText(),
        AnsiString);
}

std::any AstVisitor::visitNumber(ObjectPascalParser::NumberContext *ctx)
{
    const double d = std::stod(ctx->getText());

    // TODO: проверить определение типов
    TypeName type = Double;
    if (int(d) == d)
    {
        type = Integer;
    }
    if (d == (short)d)
    {
        type = SmallInt;
    }
    return NumberExprAST(
        d,
        type);
}
