
// Generated from ObjectPascalParser.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ObjectPascalParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ObjectPascalParser.
 */
class  ObjectPascalParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ObjectPascalParser.
   */
    virtual std::any visitGoal(ObjectPascalParser::GoalContext *context) = 0;

    virtual std::any visitProgram(ObjectPascalParser::ProgramContext *context) = 0;

    virtual std::any visitUnit(ObjectPascalParser::UnitContext *context) = 0;

    virtual std::any visitPackage(ObjectPascalParser::PackageContext *context) = 0;

    virtual std::any visitLibrary(ObjectPascalParser::LibraryContext *context) = 0;

    virtual std::any visitUsesClause(ObjectPascalParser::UsesClauseContext *context) = 0;

    virtual std::any visitPortabilityDirective(ObjectPascalParser::PortabilityDirectiveContext *context) = 0;

    virtual std::any visitInterfaceSection(ObjectPascalParser::InterfaceSectionContext *context) = 0;

    virtual std::any visitInterfaceDecl(ObjectPascalParser::InterfaceDeclContext *context) = 0;

    virtual std::any visitExportedHeading(ObjectPascalParser::ExportedHeadingContext *context) = 0;

    virtual std::any visitImplementationSection(ObjectPascalParser::ImplementationSectionContext *context) = 0;

    virtual std::any visitBlock(ObjectPascalParser::BlockContext *context) = 0;

    virtual std::any visitExportsStmt(ObjectPascalParser::ExportsStmtContext *context) = 0;

    virtual std::any visitExportsItem(ObjectPascalParser::ExportsItemContext *context) = 0;

    virtual std::any visitDeclSection(ObjectPascalParser::DeclSectionContext *context) = 0;

    virtual std::any visitLabelDeclSection(ObjectPascalParser::LabelDeclSectionContext *context) = 0;

    virtual std::any visitConstSection(ObjectPascalParser::ConstSectionContext *context) = 0;

    virtual std::any visitConstantDecl(ObjectPascalParser::ConstantDeclContext *context) = 0;

    virtual std::any visitTypeSection(ObjectPascalParser::TypeSectionContext *context) = 0;

    virtual std::any visitTypeDecl(ObjectPascalParser::TypeDeclContext *context) = 0;

    virtual std::any visitTypedConstant(ObjectPascalParser::TypedConstantContext *context) = 0;

    virtual std::any visitArrayConstant(ObjectPascalParser::ArrayConstantContext *context) = 0;

    virtual std::any visitRecordConstant(ObjectPascalParser::RecordConstantContext *context) = 0;

    virtual std::any visitRecordFieldConstant(ObjectPascalParser::RecordFieldConstantContext *context) = 0;

    virtual std::any visitType(ObjectPascalParser::TypeContext *context) = 0;

    virtual std::any visitRestrictedType(ObjectPascalParser::RestrictedTypeContext *context) = 0;

    virtual std::any visitClassRefType(ObjectPascalParser::ClassRefTypeContext *context) = 0;

    virtual std::any visitSimpleType(ObjectPascalParser::SimpleTypeContext *context) = 0;

    virtual std::any visitOrdinalType(ObjectPascalParser::OrdinalTypeContext *context) = 0;

    virtual std::any visitSubrangeType(ObjectPascalParser::SubrangeTypeContext *context) = 0;

    virtual std::any visitEnumeratedType(ObjectPascalParser::EnumeratedTypeContext *context) = 0;

    virtual std::any visitEnumeratedTypeElement(ObjectPascalParser::EnumeratedTypeElementContext *context) = 0;

    virtual std::any visitStringType(ObjectPascalParser::StringTypeContext *context) = 0;

    virtual std::any visitStrucType(ObjectPascalParser::StrucTypeContext *context) = 0;

    virtual std::any visitArrayType(ObjectPascalParser::ArrayTypeContext *context) = 0;

    virtual std::any visitRecType(ObjectPascalParser::RecTypeContext *context) = 0;

    virtual std::any visitFieldList(ObjectPascalParser::FieldListContext *context) = 0;

    virtual std::any visitFieldDecl(ObjectPascalParser::FieldDeclContext *context) = 0;

    virtual std::any visitVariantSection(ObjectPascalParser::VariantSectionContext *context) = 0;

    virtual std::any visitRecVariant(ObjectPascalParser::RecVariantContext *context) = 0;

    virtual std::any visitSetType(ObjectPascalParser::SetTypeContext *context) = 0;

    virtual std::any visitFileType(ObjectPascalParser::FileTypeContext *context) = 0;

    virtual std::any visitPointerType(ObjectPascalParser::PointerTypeContext *context) = 0;

    virtual std::any visitProcedureType(ObjectPascalParser::ProcedureTypeContext *context) = 0;

    virtual std::any visitVarSection(ObjectPascalParser::VarSectionContext *context) = 0;

    virtual std::any visitVarDecl(ObjectPascalParser::VarDeclContext *context) = 0;

    virtual std::any visitExpression(ObjectPascalParser::ExpressionContext *context) = 0;

    virtual std::any visitSimpleGrouped(ObjectPascalParser::SimpleGroupedContext *context) = 0;

    virtual std::any visitSimpleExpression(ObjectPascalParser::SimpleExpressionContext *context) = 0;

    virtual std::any visitTerm(ObjectPascalParser::TermContext *context) = 0;

    virtual std::any visitFactor(ObjectPascalParser::FactorContext *context) = 0;

    virtual std::any visitDesignator(ObjectPascalParser::DesignatorContext *context) = 0;

    virtual std::any visitSetConstructor(ObjectPascalParser::SetConstructorContext *context) = 0;

    virtual std::any visitSetElement(ObjectPascalParser::SetElementContext *context) = 0;

    virtual std::any visitExprList(ObjectPascalParser::ExprListContext *context) = 0;

    virtual std::any visitStatement(ObjectPascalParser::StatementContext *context) = 0;

    virtual std::any visitStmtList(ObjectPascalParser::StmtListContext *context) = 0;

    virtual std::any visitSimpleStatement(ObjectPascalParser::SimpleStatementContext *context) = 0;

    virtual std::any visitStructStmt(ObjectPascalParser::StructStmtContext *context) = 0;

    virtual std::any visitCompoundStmt(ObjectPascalParser::CompoundStmtContext *context) = 0;

    virtual std::any visitConditionalStmt(ObjectPascalParser::ConditionalStmtContext *context) = 0;

    virtual std::any visitProcedureCall(ObjectPascalParser::ProcedureCallContext *context) = 0;

    virtual std::any visitAssignmentStmt(ObjectPascalParser::AssignmentStmtContext *context) = 0;

    virtual std::any visitIfStmt(ObjectPascalParser::IfStmtContext *context) = 0;

    virtual std::any visitCaseStmt(ObjectPascalParser::CaseStmtContext *context) = 0;

    virtual std::any visitCaseSelector(ObjectPascalParser::CaseSelectorContext *context) = 0;

    virtual std::any visitCaseLabel(ObjectPascalParser::CaseLabelContext *context) = 0;

    virtual std::any visitLoopStmt(ObjectPascalParser::LoopStmtContext *context) = 0;

    virtual std::any visitRepeatStmt(ObjectPascalParser::RepeatStmtContext *context) = 0;

    virtual std::any visitWhileStmt(ObjectPascalParser::WhileStmtContext *context) = 0;

    virtual std::any visitForStmt(ObjectPascalParser::ForStmtContext *context) = 0;

    virtual std::any visitWithStmt(ObjectPascalParser::WithStmtContext *context) = 0;

    virtual std::any visitTryExceptStmt(ObjectPascalParser::TryExceptStmtContext *context) = 0;

    virtual std::any visitExceptionBlock(ObjectPascalParser::ExceptionBlockContext *context) = 0;

    virtual std::any visitTryFinallyStmt(ObjectPascalParser::TryFinallyStmtContext *context) = 0;

    virtual std::any visitRaiseStmt(ObjectPascalParser::RaiseStmtContext *context) = 0;

    virtual std::any visitProcedureDeclSection(ObjectPascalParser::ProcedureDeclSectionContext *context) = 0;

    virtual std::any visitProcedureDecl(ObjectPascalParser::ProcedureDeclContext *context) = 0;

    virtual std::any visitFunctionDecl(ObjectPascalParser::FunctionDeclContext *context) = 0;

    virtual std::any visitConstructorDecl(ObjectPascalParser::ConstructorDeclContext *context) = 0;

    virtual std::any visitDestructorDecl(ObjectPascalParser::DestructorDeclContext *context) = 0;

    virtual std::any visitFunctionHeading(ObjectPascalParser::FunctionHeadingContext *context) = 0;

    virtual std::any visitProcedureHeading(ObjectPascalParser::ProcedureHeadingContext *context) = 0;

    virtual std::any visitFormalParameters(ObjectPascalParser::FormalParametersContext *context) = 0;

    virtual std::any visitFormalParm(ObjectPascalParser::FormalParmContext *context) = 0;

    virtual std::any visitParameter(ObjectPascalParser::ParameterContext *context) = 0;

    virtual std::any visitDirective(ObjectPascalParser::DirectiveContext *context) = 0;

    virtual std::any visitExternalDirective(ObjectPascalParser::ExternalDirectiveContext *context) = 0;

    virtual std::any visitObjectType(ObjectPascalParser::ObjectTypeContext *context) = 0;

    virtual std::any visitObjHeritage(ObjectPascalParser::ObjHeritageContext *context) = 0;

    virtual std::any visitMethodList(ObjectPascalParser::MethodListContext *context) = 0;

    virtual std::any visitMethodHeading(ObjectPascalParser::MethodHeadingContext *context) = 0;

    virtual std::any visitConstructorHeading(ObjectPascalParser::ConstructorHeadingContext *context) = 0;

    virtual std::any visitDestructorHeading(ObjectPascalParser::DestructorHeadingContext *context) = 0;

    virtual std::any visitObjFieldList(ObjectPascalParser::ObjFieldListContext *context) = 0;

    virtual std::any visitInitSection(ObjectPascalParser::InitSectionContext *context) = 0;

    virtual std::any visitClassType(ObjectPascalParser::ClassTypeContext *context) = 0;

    virtual std::any visitClassHeritage(ObjectPascalParser::ClassHeritageContext *context) = 0;

    virtual std::any visitClassFieldList(ObjectPascalParser::ClassFieldListContext *context) = 0;

    virtual std::any visitClassMethodList(ObjectPascalParser::ClassMethodListContext *context) = 0;

    virtual std::any visitClassPropertyList(ObjectPascalParser::ClassPropertyListContext *context) = 0;

    virtual std::any visitPropertyList(ObjectPascalParser::PropertyListContext *context) = 0;

    virtual std::any visitPropertyInterface(ObjectPascalParser::PropertyInterfaceContext *context) = 0;

    virtual std::any visitPropertyParameterList(ObjectPascalParser::PropertyParameterListContext *context) = 0;

    virtual std::any visitPropertySpecifiers(ObjectPascalParser::PropertySpecifiersContext *context) = 0;

    virtual std::any visitInterfaceType(ObjectPascalParser::InterfaceTypeContext *context) = 0;

    virtual std::any visitInterfaceHeritage(ObjectPascalParser::InterfaceHeritageContext *context) = 0;

    virtual std::any visitRequiresClause(ObjectPascalParser::RequiresClauseContext *context) = 0;

    virtual std::any visitContainsClause(ObjectPascalParser::ContainsClauseContext *context) = 0;

    virtual std::any visitIdentList(ObjectPascalParser::IdentListContext *context) = 0;

    virtual std::any visitQualIdList(ObjectPascalParser::QualIdListContext *context) = 0;

    virtual std::any visitQualId(ObjectPascalParser::QualIdContext *context) = 0;

    virtual std::any visitTypeId(ObjectPascalParser::TypeIdContext *context) = 0;

    virtual std::any visitCharExpr(ObjectPascalParser::CharExprContext *context) = 0;

    virtual std::any visitUnitId(ObjectPascalParser::UnitIdContext *context) = 0;

    virtual std::any visitLabelId(ObjectPascalParser::LabelIdContext *context) = 0;

    virtual std::any visitString(ObjectPascalParser::StringContext *context) = 0;

    virtual std::any visitNumber(ObjectPascalParser::NumberContext *context) = 0;

    virtual std::any visitConstExpr(ObjectPascalParser::ConstExprContext *context) = 0;

    virtual std::any visitRealType(ObjectPascalParser::RealTypeContext *context) = 0;

    virtual std::any visitOrdIdent(ObjectPascalParser::OrdIdentContext *context) = 0;

    virtual std::any visitVariantType(ObjectPascalParser::VariantTypeContext *context) = 0;

    virtual std::any visitRelOp(ObjectPascalParser::RelOpContext *context) = 0;

    virtual std::any visitAddOp(ObjectPascalParser::AddOpContext *context) = 0;

    virtual std::any visitMulOp(ObjectPascalParser::MulOpContext *context) = 0;

    virtual std::any visitAdditiveOp(ObjectPascalParser::AdditiveOpContext *context) = 0;

    virtual std::any visitClassVisibility(ObjectPascalParser::ClassVisibilityContext *context) = 0;


};

