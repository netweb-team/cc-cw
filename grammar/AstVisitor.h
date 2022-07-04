
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
    std::any visitGoal(ObjectPascalParser::GoalContext *ctx) override;

    std::any visitProgram(ObjectPascalParser::ProgramContext *ctx) override;

    std::any visitDeclSection(ObjectPascalParser::DeclSectionContext *ctx) override;

    std::any visitCompoundStmt(ObjectPascalParser::CompoundStmtContext *ctx) override;

    std::any visitStmtList(ObjectPascalParser::StmtListContext *ctx) override;

    std::any visitStatement(ObjectPascalParser::StatementContext *ctx) override;

    std::any visitSimpleStatement(ObjectPascalParser::SimpleStatementContext *ctx) override;

    std::any visitAssignmentStmt(ObjectPascalParser::AssignmentStmtContext *ctx) override;

    std::any visitProcedureCall(ObjectPascalParser::ProcedureCallContext *ctx) override;

    std::any visitStructStmt(ObjectPascalParser::StructStmtContext *ctx) override;

    std::any visitConditionalStmt(ObjectPascalParser::ConditionalStmtContext *ctx) override;

    std::any visitIfStmt(ObjectPascalParser::IfStmtContext *ctx) override;

    std::any visitWhileStmt(ObjectPascalParser::WhileStmtContext *ctx) override;

    std::any visitForStmt(ObjectPascalParser::ForStmtContext *ctx) override;

    std::any visitRepeatStmt(ObjectPascalParser::RepeatStmtContext *ctx) override;

    std::any visitConstSection(ObjectPascalParser::ConstSectionContext *ctx) override;

    std::any visitConstantDecl(ObjectPascalParser::ConstantDeclContext *ctx) override;

    std::any visitConstExpr(ObjectPascalParser::ConstExprContext *ctx) override;

    std::any visitVarSection(ObjectPascalParser::VarSectionContext *ctx) override;

    std::any visitVarDecl(ObjectPascalParser::VarDeclContext *ctx) override;

    std::any visitProcedureDecl(ObjectPascalParser::ProcedureDeclContext *ctx) override;

    std::any visitFunctionDecl(ObjectPascalParser::FunctionDeclContext *ctx) override;

    std::any visitProcedureHeading(ObjectPascalParser::ProcedureHeadingContext *ctx) override;

    std::any visitFunctionHeading(ObjectPascalParser::FunctionHeadingContext *ctx) override;

    //std::any visitTypeSection(ObjectPascalParser::TypeSectionContext *ctx) override;

    std::any visitBlock(ObjectPascalParser::BlockContext *ctx) override;

    std::any visitIdentList(ObjectPascalParser::IdentListContext *ctx) override;

    std::any visitExprList(ObjectPascalParser::ExprListContext *ctx) override;

    std::any visitExpression(ObjectPascalParser::ExpressionContext *ctx) override;

    std::any visitTerm(ObjectPascalParser::TermContext *ctx) override;

    std::any visitFactor(ObjectPascalParser::FactorContext *ctx) override;

    std::any visitSimpleGrouped(ObjectPascalParser::SimpleGroupedContext *ctx) override;

    std::any visitSimpleExpression(ObjectPascalParser::SimpleExpressionContext *ctx) override;

    std::any visitDesignator(ObjectPascalParser::DesignatorContext *ctx) override;

    std::any visitFormalParameters(ObjectPascalParser::FormalParametersContext *ctx) override;

    std::any visitParameter(ObjectPascalParser::ParameterContext *ctx) override;

    std::any visitString(ObjectPascalParser::StringContext *ctx) override;

    std::any visitNumber(ObjectPascalParser::NumberContext *ctx) override;
};
