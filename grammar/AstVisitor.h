
// Generated from ObjectPascalParser.g4 by ANTLR 4.10.1

#pragma once

#include "antlr4-runtime.h"
#include "libs/ObjectPascalParserBaseVisitor.h"
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>

class AstVisitor : public ObjectPascalParserBaseVisitor
{
private:
    std::unordered_set<std::string> typenames;
    std::unordered_map<std::string, std::string> vartypes;

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

    std::any visitTypeSection(ObjectPascalParser::TypeSectionContext *ctx) override;

    std::any visitTypeDecl(ObjectPascalParser::TypeDeclContext *ctx) override;

    std::any visitType(ObjectPascalParser::TypeContext *ctx) override;

    std::any visitSimpleType(ObjectPascalParser::SimpleTypeContext *ctx) override;

    std::any visitOrdinalType(ObjectPascalParser::OrdinalTypeContext *ctx) override;

    std::any visitSubrangeType(ObjectPascalParser::SubrangeTypeContext *ctx) override;

    std::any visitSubrangeType2(ObjectPascalParser::SubrangeType2Context *ctx) override;

    std::any visitSubrangeType3(ObjectPascalParser::SubrangeType3Context *ctx) override;

    std::any visitSubrangeType4(ObjectPascalParser::SubrangeType4Context *ctx) override;

    std::any visitOrdIdent(ObjectPascalParser::OrdIdentContext *ctx) override;

    std::any visitRealType(ObjectPascalParser::RealTypeContext *ctx) override;

    std::any visitStrucType(ObjectPascalParser::StrucTypeContext *ctx) override;

    std::any visitArrayType(ObjectPascalParser::ArrayTypeContext *ctx) override;

    std::any visitRecType(ObjectPascalParser::RecTypeContext *ctx) override;

    std::any visitFieldList(ObjectPascalParser::FieldListContext *ctx) override;

    std::any visitFieldDecl(ObjectPascalParser::FieldDeclContext *ctx) override;

    std::any visitStringType(ObjectPascalParser::StringTypeContext *ctx) override;

    std::any visitProcedureType(ObjectPascalParser::ProcedureTypeContext *ctx) override;

    std::any visitRestrictedType(ObjectPascalParser::RestrictedTypeContext *ctx) override;

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

    std::any visitQualId(ObjectPascalParser::QualIdContext *ctx) override;

    std::any visitQualIdList(ObjectPascalParser::QualIdListContext *ctx) override;

    std::any visitTypeId(ObjectPascalParser::TypeIdContext *ctx) override;

    std::any visitUnitId(ObjectPascalParser::UnitIdContext *ctx) override;
};
