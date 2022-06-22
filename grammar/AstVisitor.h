
// Generated from ObjectPascalParser.g4 by ANTLR 4.10.1

#pragma once

#include "antlr4-runtime.h"
#include "libs/ObjectPascalParserBaseVisitor.h"

/**
 * This class provides an empty implementation of ObjectPascalParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class AstVisitor : public ObjectPascalParserBaseVisitor
{
public:
    std::any visitGoal(ObjectPascalParser::GoalContext *ctx) override
    {
        std::cout << "goal" << std::endl;
        return visitChildren(ctx);
    }

    std::any visitProgram(ObjectPascalParser::ProgramContext *ctx) override;

    std::any visitConstantDecl(ObjectPascalParser::ConstantDeclContext *ctx) override
    {
        if (ctx->constExpr()->number().size())
        {
            const double d = std::stod(ctx->constExpr()->number()[0]->getText());
            // return std::make_unique<ConstExprAST>(ctx->Ident->getSymbol()->getText(), d, Double);
        }
        return visitChildren(ctx);
    }

    std::any visitString(ObjectPascalParser::StringContext *ctx) override;

    std::any visitNumber(ObjectPascalParser::NumberContext *ctx) override;
};
