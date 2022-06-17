
// Generated from ObjectPascalParser.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ObjectPascalParserVisitor.h"
#include "../../ast.h"


/**
 * This class provides an empty implementation of ObjectPascalParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class AstVisitor : public ObjectPascalParserVisitor {
public:

  virtual std::any visitGoal(ObjectPascalParser::GoalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::unique_ptr<ProgramExprAST> visitProgram(ObjectPascalParser::ProgramContext *ctx) override {
    return std::make_unique<ProgramExprAST>(
        ctx->Ident()->getSymbol()->getText(),
        this->visitDeclSection(ctx->programBlock()->declSection()),
        this->visitProgramBlock(ctx->programBlock()->compoundStmt()),
        )
  }

  virtual std::any visitUnit(ObjectPascalParser::UnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPackage(ObjectPascalParser::PackageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary(ObjectPascalParser::LibraryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramBlock(ObjectPascalParser::ProgramBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUsesClause(ObjectPascalParser::UsesClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPortabilityDirective(ObjectPascalParser::PortabilityDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceSection(ObjectPascalParser::InterfaceSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceDecl(ObjectPascalParser::InterfaceDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExportedHeading(ObjectPascalParser::ExportedHeadingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImplementationSection(ObjectPascalParser::ImplementationSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(ObjectPascalParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExportsStmt(ObjectPascalParser::ExportsStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExportsItem(ObjectPascalParser::ExportsItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclSection(ObjectPascalParser::DeclSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelDeclSection(ObjectPascalParser::LabelDeclSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstSection(ObjectPascalParser::ConstSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantDecl(ObjectPascalParser::ConstantDeclContext *ctx) override {
    if (ctx->constExpr()->number()) {
        const d = std::atod(ctx->constExpr()->number()->getText());
        return std::make_unique<ConstExprAST>(ctx->Ident->getSymbol()->getText(), d, TypeName.Double);
    }
    return visitChildren(ctx);
  }

  virtual std::any visitTypeSection(ObjectPascalParser::TypeSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeDecl(ObjectPascalParser::TypeDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypedConstant(ObjectPascalParser::TypedConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayConstant(ObjectPascalParser::ArrayConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordConstant(ObjectPascalParser::RecordConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordFieldConstant(ObjectPascalParser::RecordFieldConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(ObjectPascalParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRestrictedType(ObjectPascalParser::RestrictedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassRefType(ObjectPascalParser::ClassRefTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleType(ObjectPascalParser::SimpleTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRealType(ObjectPascalParser::RealTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrdinalType(ObjectPascalParser::OrdinalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrdIdent(ObjectPascalParser::OrdIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariantType(ObjectPascalParser::VariantTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubrangeType(ObjectPascalParser::SubrangeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumeratedType(ObjectPascalParser::EnumeratedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumeratedTypeElement(ObjectPascalParser::EnumeratedTypeElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringType(ObjectPascalParser::StringTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrucType(ObjectPascalParser::StrucTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(ObjectPascalParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecType(ObjectPascalParser::RecTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldList(ObjectPascalParser::FieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldDecl(ObjectPascalParser::FieldDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariantSection(ObjectPascalParser::VariantSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecVariant(ObjectPascalParser::RecVariantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetType(ObjectPascalParser::SetTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFileType(ObjectPascalParser::FileTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPointerType(ObjectPascalParser::PointerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureType(ObjectPascalParser::ProcedureTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarSection(ObjectPascalParser::VarSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(ObjectPascalParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(ObjectPascalParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleGrouped(ObjectPascalParser::SimpleGroupedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleExpression(ObjectPascalParser::SimpleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(ObjectPascalParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(ObjectPascalParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelOp(ObjectPascalParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddOp(ObjectPascalParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulOp(ObjectPascalParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveOp(ObjectPascalParser::AdditiveOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDesignator(ObjectPascalParser::DesignatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetConstructor(ObjectPascalParser::SetConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetElement(ObjectPascalParser::SetElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprList(ObjectPascalParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(ObjectPascalParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtList(ObjectPascalParser::StmtListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleStatement(ObjectPascalParser::SimpleStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructStmt(ObjectPascalParser::StructStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBegin(ObjectPascalParser::BeginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundStmt(ObjectPascalParser::CompoundStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditionalStmt(ObjectPascalParser::ConditionalStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureCall(ObjectPascalParser::ProcedureCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentStmt(ObjectPascalParser::AssignmentStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(ObjectPascalParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseStmt(ObjectPascalParser::CaseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseSelector(ObjectPascalParser::CaseSelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseLabel(ObjectPascalParser::CaseLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopStmt(ObjectPascalParser::LoopStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRepeatStmt(ObjectPascalParser::RepeatStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(ObjectPascalParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(ObjectPascalParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithStmt(ObjectPascalParser::WithStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryExceptStmt(ObjectPascalParser::TryExceptStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExceptionBlock(ObjectPascalParser::ExceptionBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryFinallyStmt(ObjectPascalParser::TryFinallyStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRaiseStmt(ObjectPascalParser::RaiseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureDeclSection(ObjectPascalParser::ProcedureDeclSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureDecl(ObjectPascalParser::ProcedureDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(ObjectPascalParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionHeading(ObjectPascalParser::FunctionHeadingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureHeading(ObjectPascalParser::ProcedureHeadingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormalParameters(ObjectPascalParser::FormalParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormalParm(ObjectPascalParser::FormalParmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(ObjectPascalParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDirective(ObjectPascalParser::DirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternalDirective(ObjectPascalParser::ExternalDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjectType(ObjectPascalParser::ObjectTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjHeritage(ObjectPascalParser::ObjHeritageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodList(ObjectPascalParser::MethodListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodHeading(ObjectPascalParser::MethodHeadingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstructorHeading(ObjectPascalParser::ConstructorHeadingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDestructorHeading(ObjectPascalParser::DestructorHeadingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjFieldList(ObjectPascalParser::ObjFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitSection(ObjectPascalParser::InitSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassType(ObjectPascalParser::ClassTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassHeritage(ObjectPascalParser::ClassHeritageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassVisibility(ObjectPascalParser::ClassVisibilityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassFieldList(ObjectPascalParser::ClassFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassMethodList(ObjectPascalParser::ClassMethodListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassPropertyList(ObjectPascalParser::ClassPropertyListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyList(ObjectPascalParser::PropertyListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyInterface(ObjectPascalParser::PropertyInterfaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyParameterList(ObjectPascalParser::PropertyParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertySpecifiers(ObjectPascalParser::PropertySpecifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceType(ObjectPascalParser::InterfaceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceHeritage(ObjectPascalParser::InterfaceHeritageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRequiresClause(ObjectPascalParser::RequiresClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContainsClause(ObjectPascalParser::ContainsClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentList(ObjectPascalParser::IdentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQualIdList(ObjectPascalParser::QualIdListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQualId(ObjectPascalParser::QualIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeId(ObjectPascalParser::TypeIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPredefinedType(ObjectPascalParser::PredefinedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharExpr(ObjectPascalParser::CharExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExpr(ObjectPascalParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitId(ObjectPascalParser::UnitIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelId(ObjectPascalParser::LabelIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(ObjectPascalParser::StringContext *ctx) override {
    // TODO::проверить на ковычки и другие лишние вещи
    return std::make_unique<StringExprAST>(
        ctx->StringLiteral->getText(),
        TypeName.AnsiString,
    );
  }

  virtual std::any visitNumber(ObjectPascalParser::NumberContext *ctx) override {
    const double  d = std::stod(ctx->getText());

    // TODO: проверить определение типов
    int type = TypeName.Double;
    if ((d % 1) == 0) {
        type = TypeName.Integer;
    }
    if (d == (short) d) {
        type = TypeName.SmallInt;
    }
    return std::make_unique<NumberExprAST>(
        d,
        type,
    );
  }

  virtual std::any visitRadixNumber(ObjectPascalParser::RadixNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHexNumber(ObjectPascalParser::HexNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOctalNumber(ObjectPascalParser::OctalNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInteger(ObjectPascalParser::IntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignedInteger(ObjectPascalParser::SignedIntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray(ObjectPascalParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(ObjectPascalParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNot(ObjectPascalParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiv(ObjectPascalParser::DivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnd(ObjectPascalParser::AndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs(ObjectPascalParser::AsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(ObjectPascalParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo(ObjectPascalParser::DoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor(ObjectPascalParser::ForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExcept(ObjectPascalParser::ExceptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(ObjectPascalParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedure(ObjectPascalParser::ProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOverride(ObjectPascalParser::OverrideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProtected(ObjectPascalParser::ProtectedContext *ctx) override {
    return visitChildren(ctx);
  }


};

