
// Generated from ObjectPascalParser.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  ObjectPascalParser : public antlr4::Parser {
public:
  enum {
    PROGRAM = 1, PACKAGE = 2, END = 3, REQUIRES = 4, CONTAINS = 5, LIBRARY = 6, 
    UNIT = 7, INTERFACE = 8, IMPLEMENTATION = 9, INITIALIZATION = 10, USES = 11, 
    IN = 12, LABEL = 13, CONST = 14, TYPE_ = 15, CLASS = 16, OF = 17, REAL = 18, 
    SINGLE = 19, DOUBLE = 20, EXTENDED = 21, CURRENCY = 22, COMP = 23, SHORTINT = 24, 
    SMALLINT = 25, INTEGER = 26, BYTE = 27, LONGINT = 28, WORD = 29, BOOLEAN = 30, 
    CHAR = 31, WIDECHAR = 32, LONGCHAR = 33, PCHAR = 34, VARIANT = 35, OLEVARIANT = 36, 
    STRING = 37, ANSISTRING = 38, WIDESTRING = 39, PACKED = 40, ARRAY = 41, 
    RECORD = 42, CASE = 43, SET = 44, FILE = 45, OBJECT = 46, VIRTUAL = 47, 
    CONSTRUCTOR = 48, DESTRUCTOR = 49, FINALIZATION = 50, PUBLIC = 51, PROTECTED = 52, 
    PRIVATE = 53, PUBLISHED = 54, PROPERTY = 55, INDEX = 56, READ = 57, 
    WRITE = 58, STORED = 59, DEFAULT = 60, NODEFAULT = 61, IMPLEMENTS = 62, 
    VAR = 63, ABSOLUTE = 64, ABSTRACT = 65, FUNCTION = 66, PROCEDURE = 67, 
    OUT = 68, INHERITED = 69, GOTO = 70, BEGIN = 71, THEN = 72, ELSE = 73, 
    IF = 74, REPEAT = 75, UNTIL = 76, WHILE = 77, TO = 78, DOWNTO = 79, 
    FOR = 80, DO = 81, WITH = 82, TRY = 83, FINALLY = 84, EXCEPT = 85, ON = 86, 
    RAISE = 87, AT = 88, IS = 89, OR = 90, XOR = 91, DIV = 92, MOD = 93, 
    AND = 94, SHL = 95, SHR = 96, NIL = 97, NOT = 98, TRUE = 99, FALSE = 100, 
    UID = 101, NAME = 102, AS = 103, CDECL = 104, REGISTER = 105, DYNAMIC = 106, 
    EXPORT = 107, EXTERNAL = 108, FAR = 109, FORWARD = 110, MESSAGE = 111, 
    OVERRIDE = 112, OVERLOAD = 113, PASCAL = 114, REINTRODUCE = 115, SAFECALL = 116, 
    STDCALL = 117, VARARGS = 118, LOCAL = 119, REAL48 = 120, SEMI = 121, 
    DOT = 122, DOT_DOT = 123, LEFT_PAREN = 124, RIGHT_PAREN = 125, LEFT_BRACKET = 126, 
    RIGHT_BRACKET = 127, COMMA = 128, ASSIGN = 129, COLON = 130, CARET = 131, 
    COLON_ASSIGN = 132, GRATER = 133, LESS = 134, GRATER_EQUAL = 135, LESS_EQUAL = 136, 
    NOT_EQUAL = 137, PLUS = 138, MINUS = 139, STAR = 140, DIV_ = 141, DOG = 142, 
    SHARP = 143, LESS_DIV = 144, NEAR = 145, INLINE = 146, ASSEMBLER = 147, 
    PLATFORM = 148, DEPRECATED = 149, CARDINAL = 150, INT64 = 151, LONGWORD = 152, 
    UNICODESTRING = 153, QUOTE = 154, E = 155, SINGLE_QUOTE = 156, Identifier = 157, 
    Integer = 158, IntegerLiteral = 159, OctLiteral = 160, HexLiteral = 161, 
    Float = 162, Whitespace = 163, Newline = 164, BlockComment = 165, LineComment = 166, 
    CharacterLiteral = 167, StringLiteral = 168, BooleanLiteral = 169, MultiLineMacro = 170
  };

  enum {
    RuleGoal = 0, RuleProgram = 1, RuleUnit = 2, RulePackage = 3, RuleLibrary = 4, 
    RuleUsesClause = 5, RulePortabilityDirective = 6, RuleInterfaceSection = 7, 
    RuleInterfaceDecl = 8, RuleExportedHeading = 9, RuleImplementationSection = 10, 
    RuleBlock = 11, RuleExportsStmt = 12, RuleExportsItem = 13, RuleDeclSection = 14, 
    RuleLabelDeclSection = 15, RuleConstSection = 16, RuleConstantDecl = 17, 
    RuleTypeSection = 18, RuleTypeDecl = 19, RuleTypedConstant = 20, RuleArrayConstant = 21, 
    RuleRecordConstant = 22, RuleRecordFieldConstant = 23, RuleType = 24, 
    RuleRestrictedType = 25, RuleClassRefType = 26, RuleSimpleType = 27, 
    RuleRealType = 28, RuleOrdinalType = 29, RuleOrdIdent = 30, RuleVariantType = 31, 
    RuleSubrangeType = 32, RuleEnumeratedType = 33, RuleEnumeratedTypeElement = 34, 
    RuleStringType = 35, RuleStrucType = 36, RuleArrayType = 37, RuleRecType = 38, 
    RuleFieldList = 39, RuleFieldDecl = 40, RuleVariantSection = 41, RuleRecVariant = 42, 
    RuleSetType = 43, RuleFileType = 44, RulePointerType = 45, RuleProcedureType = 46, 
    RuleVarSection = 47, RuleVarDecl = 48, RuleExpression = 49, RuleSimpleGrouped = 50, 
    RuleSimpleExpression = 51, RuleTerm = 52, RuleFactor = 53, RuleRelOp = 54, 
    RuleAddOp = 55, RuleMulOp = 56, RuleAdditiveOp = 57, RuleDesignator = 58, 
    RuleSetConstructor = 59, RuleSetElement = 60, RuleExprList = 61, RuleStatement = 62, 
    RuleStmtList = 63, RuleSimpleStatement = 64, RuleStructStmt = 65, RuleCompoundStmt = 66, 
    RuleConditionalStmt = 67, RuleProcedureCall = 68, RuleAssignmentStmt = 69, 
    RuleIfStmt = 70, RuleCaseStmt = 71, RuleCaseSelector = 72, RuleCaseLabel = 73, 
    RuleLoopStmt = 74, RuleRepeatStmt = 75, RuleWhileStmt = 76, RuleForStmt = 77, 
    RuleWithStmt = 78, RuleTryExceptStmt = 79, RuleExceptionBlock = 80, 
    RuleTryFinallyStmt = 81, RuleRaiseStmt = 82, RuleProcedureDeclSection = 83, 
    RuleProcedureDecl = 84, RuleFunctionDecl = 85, RuleConstructorDecl = 86, 
    RuleDestructorDecl = 87, RuleFunctionHeading = 88, RuleProcedureHeading = 89, 
    RuleFormalParameters = 90, RuleFormalParm = 91, RuleParameter = 92, 
    RuleDirective = 93, RuleExternalDirective = 94, RuleObjectType = 95, 
    RuleObjHeritage = 96, RuleMethodList = 97, RuleMethodHeading = 98, RuleConstructorHeading = 99, 
    RuleDestructorHeading = 100, RuleObjFieldList = 101, RuleInitSection = 102, 
    RuleClassType = 103, RuleClassHeritage = 104, RuleClassVisibility = 105, 
    RuleClassFieldList = 106, RuleClassMethodList = 107, RuleClassPropertyList = 108, 
    RulePropertyList = 109, RulePropertyInterface = 110, RulePropertyParameterList = 111, 
    RulePropertySpecifiers = 112, RuleInterfaceType = 113, RuleInterfaceHeritage = 114, 
    RuleRequiresClause = 115, RuleContainsClause = 116, RuleIdentList = 117, 
    RuleQualIdList = 118, RuleQualId = 119, RuleTypeId = 120, RulePredefinedType = 121, 
    RuleCharExpr = 122, RuleUnitId = 123, RuleLabelId = 124, RuleString = 125, 
    RuleNumber = 126, RuleConstExpr = 127
  };

  explicit ObjectPascalParser(antlr4::TokenStream *input);

  ObjectPascalParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ObjectPascalParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class GoalContext;
  class ProgramContext;
  class UnitContext;
  class PackageContext;
  class LibraryContext;
  class UsesClauseContext;
  class PortabilityDirectiveContext;
  class InterfaceSectionContext;
  class InterfaceDeclContext;
  class ExportedHeadingContext;
  class ImplementationSectionContext;
  class BlockContext;
  class ExportsStmtContext;
  class ExportsItemContext;
  class DeclSectionContext;
  class LabelDeclSectionContext;
  class ConstSectionContext;
  class ConstantDeclContext;
  class TypeSectionContext;
  class TypeDeclContext;
  class TypedConstantContext;
  class ArrayConstantContext;
  class RecordConstantContext;
  class RecordFieldConstantContext;
  class TypeContext;
  class RestrictedTypeContext;
  class ClassRefTypeContext;
  class SimpleTypeContext;
  class RealTypeContext;
  class OrdinalTypeContext;
  class OrdIdentContext;
  class VariantTypeContext;
  class SubrangeTypeContext;
  class EnumeratedTypeContext;
  class EnumeratedTypeElementContext;
  class StringTypeContext;
  class StrucTypeContext;
  class ArrayTypeContext;
  class RecTypeContext;
  class FieldListContext;
  class FieldDeclContext;
  class VariantSectionContext;
  class RecVariantContext;
  class SetTypeContext;
  class FileTypeContext;
  class PointerTypeContext;
  class ProcedureTypeContext;
  class VarSectionContext;
  class VarDeclContext;
  class ExpressionContext;
  class SimpleGroupedContext;
  class SimpleExpressionContext;
  class TermContext;
  class FactorContext;
  class RelOpContext;
  class AddOpContext;
  class MulOpContext;
  class AdditiveOpContext;
  class DesignatorContext;
  class SetConstructorContext;
  class SetElementContext;
  class ExprListContext;
  class StatementContext;
  class StmtListContext;
  class SimpleStatementContext;
  class StructStmtContext;
  class CompoundStmtContext;
  class ConditionalStmtContext;
  class ProcedureCallContext;
  class AssignmentStmtContext;
  class IfStmtContext;
  class CaseStmtContext;
  class CaseSelectorContext;
  class CaseLabelContext;
  class LoopStmtContext;
  class RepeatStmtContext;
  class WhileStmtContext;
  class ForStmtContext;
  class WithStmtContext;
  class TryExceptStmtContext;
  class ExceptionBlockContext;
  class TryFinallyStmtContext;
  class RaiseStmtContext;
  class ProcedureDeclSectionContext;
  class ProcedureDeclContext;
  class FunctionDeclContext;
  class ConstructorDeclContext;
  class DestructorDeclContext;
  class FunctionHeadingContext;
  class ProcedureHeadingContext;
  class FormalParametersContext;
  class FormalParmContext;
  class ParameterContext;
  class DirectiveContext;
  class ExternalDirectiveContext;
  class ObjectTypeContext;
  class ObjHeritageContext;
  class MethodListContext;
  class MethodHeadingContext;
  class ConstructorHeadingContext;
  class DestructorHeadingContext;
  class ObjFieldListContext;
  class InitSectionContext;
  class ClassTypeContext;
  class ClassHeritageContext;
  class ClassVisibilityContext;
  class ClassFieldListContext;
  class ClassMethodListContext;
  class ClassPropertyListContext;
  class PropertyListContext;
  class PropertyInterfaceContext;
  class PropertyParameterListContext;
  class PropertySpecifiersContext;
  class InterfaceTypeContext;
  class InterfaceHeritageContext;
  class RequiresClauseContext;
  class ContainsClauseContext;
  class IdentListContext;
  class QualIdListContext;
  class QualIdContext;
  class TypeIdContext;
  class PredefinedTypeContext;
  class CharExprContext;
  class UnitIdContext;
  class LabelIdContext;
  class StringContext;
  class NumberContext;
  class ConstExprContext; 

  class  GoalContext : public antlr4::ParserRuleContext {
  public:
    GoalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();
    PackageContext *package();
    LibraryContext *library();
    UnitContext *unit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GoalContext* goal();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGRAM();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMI();
    CompoundStmtContext *compoundStmt();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    IdentListContext *identList();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    UsesClauseContext *usesClause();
    std::vector<DeclSectionContext *> declSection();
    DeclSectionContext* declSection(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNIT();
    QualIdContext *qualId();
    antlr4::tree::TerminalNode *SEMI();
    InterfaceSectionContext *interfaceSection();
    ImplementationSectionContext *implementationSection();
    InitSectionContext *initSection();
    antlr4::tree::TerminalNode *DOT();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnitContext* unit();

  class  PackageContext : public antlr4::ParserRuleContext {
  public:
    PackageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *DOT();
    RequiresClauseContext *requiresClause();
    ContainsClauseContext *containsClause();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackageContext* package();

  class  LibraryContext : public antlr4::ParserRuleContext {
  public:
    LibraryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIBRARY();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMI();
    CompoundStmtContext *compoundStmt();
    antlr4::tree::TerminalNode *DOT();
    UsesClauseContext *usesClause();
    std::vector<DeclSectionContext *> declSection();
    DeclSectionContext* declSection(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LibraryContext* library();

  class  UsesClauseContext : public antlr4::ParserRuleContext {
  public:
    UsesClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USES();
    QualIdListContext *qualIdList();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UsesClauseContext* usesClause();

  class  PortabilityDirectiveContext : public antlr4::ParserRuleContext {
  public:
    PortabilityDirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLATFORM();
    antlr4::tree::TerminalNode *DEPRECATED();
    antlr4::tree::TerminalNode *LIBRARY();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PortabilityDirectiveContext* portabilityDirective();

  class  InterfaceSectionContext : public antlr4::ParserRuleContext {
  public:
    InterfaceSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERFACE();
    UsesClauseContext *usesClause();
    std::vector<InterfaceDeclContext *> interfaceDecl();
    InterfaceDeclContext* interfaceDecl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceSectionContext* interfaceSection();

  class  InterfaceDeclContext : public antlr4::ParserRuleContext {
  public:
    InterfaceDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstSectionContext *constSection();
    TypeSectionContext *typeSection();
    VarSectionContext *varSection();
    ExportedHeadingContext *exportedHeading();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceDeclContext* interfaceDecl();

  class  ExportedHeadingContext : public antlr4::ParserRuleContext {
  public:
    ExportedHeadingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureHeadingContext *procedureHeading();
    antlr4::tree::TerminalNode *SEMI();
    DirectiveContext *directive();
    FunctionHeadingContext *functionHeading();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExportedHeadingContext* exportedHeading();

  class  ImplementationSectionContext : public antlr4::ParserRuleContext {
  public:
    ImplementationSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPLEMENTATION();
    UsesClauseContext *usesClause();
    std::vector<DeclSectionContext *> declSection();
    DeclSectionContext* declSection(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImplementationSectionContext* implementationSection();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompoundStmtContext *compoundStmt();
    DeclSectionContext *declSection();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  ExportsStmtContext : public antlr4::ParserRuleContext {
  public:
    ExportsStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXPORT();
    std::vector<ExportsItemContext *> exportsItem();
    ExportsItemContext* exportsItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExportsStmtContext* exportsStmt();

  class  ExportsItemContext : public antlr4::ParserRuleContext {
  public:
    ExportsItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *INDEX();
    std::vector<antlr4::tree::TerminalNode *> SINGLE_QUOTE();
    antlr4::tree::TerminalNode* SINGLE_QUOTE(size_t i);
    ConstExprContext *constExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExportsItemContext* exportsItem();

  class  DeclSectionContext : public antlr4::ParserRuleContext {
  public:
    DeclSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelDeclSectionContext *labelDeclSection();
    ConstSectionContext *constSection();
    TypeSectionContext *typeSection();
    VarSectionContext *varSection();
    ProcedureDeclSectionContext *procedureDeclSection();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclSectionContext* declSection();

  class  LabelDeclSectionContext : public antlr4::ParserRuleContext {
  public:
    LabelDeclSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LABEL();
    LabelIdContext *labelId();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelDeclSectionContext* labelDeclSection();

  class  ConstSectionContext : public antlr4::ParserRuleContext {
  public:
    ConstSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    std::vector<ConstantDeclContext *> constantDecl();
    ConstantDeclContext* constantDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstSectionContext* constSection();

  class  ConstantDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstantDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    ConstExprContext *constExpr();
    PortabilityDirectiveContext *portabilityDirective();
    antlr4::tree::TerminalNode *COLON();
    TypeIdContext *typeId();
    TypedConstantContext *typedConstant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantDeclContext* constantDecl();

  class  TypeSectionContext : public antlr4::ParserRuleContext {
  public:
    TypeSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_();
    std::vector<TypeDeclContext *> typeDecl();
    TypeDeclContext* typeDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeSectionContext* typeSection();

  class  TypeDeclContext : public antlr4::ParserRuleContext {
  public:
    TypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    TypeContext *type();
    antlr4::tree::TerminalNode *TYPE_();
    PortabilityDirectiveContext *portabilityDirective();
    RestrictedTypeContext *restrictedType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDeclContext* typeDecl();

  class  TypedConstantContext : public antlr4::ParserRuleContext {
  public:
    TypedConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstExprContext *constExpr();
    ArrayConstantContext *arrayConstant();
    RecordConstantContext *recordConstant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedConstantContext* typedConstant();

  class  ArrayConstantContext : public antlr4::ParserRuleContext {
  public:
    ArrayConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<TypedConstantContext *> typedConstant();
    TypedConstantContext* typedConstant(size_t i);
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayConstantContext* arrayConstant();

  class  RecordConstantContext : public antlr4::ParserRuleContext {
  public:
    RecordConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<RecordFieldConstantContext *> recordFieldConstant();
    RecordFieldConstantContext* recordFieldConstant(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordConstantContext* recordConstant();

  class  RecordFieldConstantContext : public antlr4::ParserRuleContext {
  public:
    RecordFieldConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *COLON();
    TypedConstantContext *typedConstant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordFieldConstantContext* recordFieldConstant();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeIdContext *typeId();
    SimpleTypeContext *simpleType();
    StrucTypeContext *strucType();
    PointerTypeContext *pointerType();
    StringTypeContext *stringType();
    ProcedureTypeContext *procedureType();
    VariantTypeContext *variantType();
    ClassRefTypeContext *classRefType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  RestrictedTypeContext : public antlr4::ParserRuleContext {
  public:
    RestrictedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ObjectTypeContext *objectType();
    ClassTypeContext *classType();
    InterfaceTypeContext *interfaceType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RestrictedTypeContext* restrictedType();

  class  ClassRefTypeContext : public antlr4::ParserRuleContext {
  public:
    ClassRefTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *OF();
    TypeIdContext *typeId();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassRefTypeContext* classRefType();

  class  SimpleTypeContext : public antlr4::ParserRuleContext {
  public:
    SimpleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OrdinalTypeContext *ordinalType();
    RealTypeContext *realType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleTypeContext* simpleType();

  class  RealTypeContext : public antlr4::ParserRuleContext {
  public:
    RealTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REAL48();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *SINGLE();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *EXTENDED();
    antlr4::tree::TerminalNode *CURRENCY();
    antlr4::tree::TerminalNode *COMP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RealTypeContext* realType();

  class  OrdinalTypeContext : public antlr4::ParserRuleContext {
  public:
    OrdinalTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SubrangeTypeContext *subrangeType();
    EnumeratedTypeContext *enumeratedType();
    OrdIdentContext *ordIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrdinalTypeContext* ordinalType();

  class  OrdIdentContext : public antlr4::ParserRuleContext {
  public:
    OrdIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHORTINT();
    antlr4::tree::TerminalNode *SMALLINT();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *BYTE();
    antlr4::tree::TerminalNode *CARDINAL();
    antlr4::tree::TerminalNode *LONGINT();
    antlr4::tree::TerminalNode *INT64();
    antlr4::tree::TerminalNode *WORD();
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *WIDECHAR();
    antlr4::tree::TerminalNode *LONGWORD();
    antlr4::tree::TerminalNode *PCHAR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrdIdentContext* ordIdent();

  class  VariantTypeContext : public antlr4::ParserRuleContext {
  public:
    VariantTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIANT();
    antlr4::tree::TerminalNode *OLEVARIANT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariantTypeContext* variantType();

  class  SubrangeTypeContext : public antlr4::ParserRuleContext {
  public:
    SubrangeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT_DOT();
    std::vector<ConstExprContext *> constExpr();
    ConstExprContext* constExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubrangeTypeContext* subrangeType();

  class  EnumeratedTypeContext : public antlr4::ParserRuleContext {
  public:
    EnumeratedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<EnumeratedTypeElementContext *> enumeratedTypeElement();
    EnumeratedTypeElementContext* enumeratedTypeElement(size_t i);
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumeratedTypeContext* enumeratedType();

  class  EnumeratedTypeElementContext : public antlr4::ParserRuleContext {
  public:
    EnumeratedTypeElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    ConstExprContext *constExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumeratedTypeElementContext* enumeratedTypeElement();

  class  StringTypeContext : public antlr4::ParserRuleContext {
  public:
    StringTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *ANSISTRING();
    antlr4::tree::TerminalNode *WIDESTRING();
    antlr4::tree::TerminalNode *UNICODESTRING();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    ConstExprContext *constExpr();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringTypeContext* stringType();

  class  StrucTypeContext : public antlr4::ParserRuleContext {
  public:
    StrucTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayTypeContext *arrayType();
    SetTypeContext *setType();
    FileTypeContext *fileType();
    RecTypeContext *recType();
    std::vector<antlr4::tree::TerminalNode *> PACKED();
    antlr4::tree::TerminalNode* PACKED(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrucTypeContext* strucType();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *OF();
    TypeContext *type();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    std::vector<OrdinalTypeContext *> ordinalType();
    OrdinalTypeContext* ordinalType(size_t i);
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    PortabilityDirectiveContext *portabilityDirective();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();

  class  RecTypeContext : public antlr4::ParserRuleContext {
  public:
    RecTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RECORD();
    antlr4::tree::TerminalNode *END();
    FieldListContext *fieldList();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecTypeContext* recType();

  class  FieldListContext : public antlr4::ParserRuleContext {
  public:
    FieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FieldDeclContext *> fieldDecl();
    FieldDeclContext* fieldDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    VariantSectionContext *variantSection();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldListContext* fieldList();

  class  FieldDeclContext : public antlr4::ParserRuleContext {
  public:
    FieldDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentListContext *identList();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldDeclContext* fieldDecl();

  class  VariantSectionContext : public antlr4::ParserRuleContext {
  public:
    VariantSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    TypeIdContext *typeId();
    antlr4::tree::TerminalNode *OF();
    std::vector<RecVariantContext *> recVariant();
    RecVariantContext* recVariant(size_t i);
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariantSectionContext* variantSection();

  class  RecVariantContext : public antlr4::ParserRuleContext {
  public:
    RecVariantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstExprContext *> constExpr();
    ConstExprContext* constExpr(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    FieldListContext *fieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecVariantContext* recVariant();

  class  SetTypeContext : public antlr4::ParserRuleContext {
  public:
    SetTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *OF();
    OrdinalTypeContext *ordinalType();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetTypeContext* setType();

  class  FileTypeContext : public antlr4::ParserRuleContext {
  public:
    FileTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILE();
    antlr4::tree::TerminalNode *OF();
    TypeIdContext *typeId();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileTypeContext* fileType();

  class  PointerTypeContext : public antlr4::ParserRuleContext {
  public:
    PointerTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CARET();
    TypeIdContext *typeId();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PointerTypeContext* pointerType();

  class  ProcedureTypeContext : public antlr4::ParserRuleContext {
  public:
    ProcedureTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureHeadingContext *procedureHeading();
    FunctionHeadingContext *functionHeading();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *OBJECT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureTypeContext* procedureType();

  class  VarSectionContext : public antlr4::ParserRuleContext {
  public:
    VarSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    std::vector<VarDeclContext *> varDecl();
    VarDeclContext* varDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarSectionContext* varSection();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentListContext *identList();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    antlr4::tree::TerminalNode *ASSIGN();
    ConstExprContext *constExpr();
    PortabilityDirectiveContext *portabilityDirective();
    antlr4::tree::TerminalNode *ABSOLUTE();
    antlr4::tree::TerminalNode *Identifier();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimpleGroupedContext *> simpleGrouped();
    SimpleGroupedContext* simpleGrouped(size_t i);
    std::vector<RelOpContext *> relOp();
    RelOpContext* relOp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  SimpleGroupedContext : public antlr4::ParserRuleContext {
  public:
    SimpleGroupedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleExpressionContext *simpleExpression();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleGroupedContext* simpleGrouped();

  class  SimpleExpressionContext : public antlr4::ParserRuleContext {
  public:
    SimpleExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<AddOpContext *> addOp();
    AddOpContext* addOp(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleExpressionContext* simpleExpression();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<MulOpContext *> mulOp();
    MulOpContext* mulOp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DesignatorContext *designator();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExprListContext *exprList();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *DOG();
    NumberContext *number();
    StringContext *string();
    antlr4::tree::TerminalNode *NIL();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();
    SetConstructorContext *setConstructor();
    TypeIdContext *typeId();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  RelOpContext : public antlr4::ParserRuleContext {
  public:
    RelOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GRATER();
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *LESS_EQUAL();
    antlr4::tree::TerminalNode *GRATER_EQUAL();
    antlr4::tree::TerminalNode *NOT_EQUAL();
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *AS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelOpContext* relOp();

  class  AddOpContext : public antlr4::ParserRuleContext {
  public:
    AddOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *XOR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddOpContext* addOp();

  class  MulOpContext : public antlr4::ParserRuleContext {
  public:
    MulOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *SHL();
    antlr4::tree::TerminalNode *SHR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulOpContext* mulOp();

  class  AdditiveOpContext : public antlr4::ParserRuleContext {
  public:
    AdditiveOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *STAR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveOpContext* additiveOp();

  class  DesignatorContext : public antlr4::ParserRuleContext {
  public:
    DesignatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualIdContext *qualId();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LEFT_BRACKET();
    antlr4::tree::TerminalNode* LEFT_BRACKET(size_t i);
    std::vector<ExprListContext *> exprList();
    ExprListContext* exprList(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RIGHT_BRACKET();
    antlr4::tree::TerminalNode* RIGHT_BRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CARET();
    antlr4::tree::TerminalNode* CARET(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DesignatorContext* designator();

  class  SetConstructorContext : public antlr4::ParserRuleContext {
  public:
    SetConstructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    std::vector<SetElementContext *> setElement();
    SetElementContext* setElement(size_t i);
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetConstructorContext* setConstructor();

  class  SetElementContext : public antlr4::ParserRuleContext {
  public:
    SetElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DOT_DOT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetElementContext* setElement();

  class  ExprListContext : public antlr4::ParserRuleContext {
  public:
    ExprListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprListContext* exprList();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleStatementContext *simpleStatement();
    StructStmtContext *structStmt();
    LabelIdContext *labelId();
    antlr4::tree::TerminalNode *COLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  StmtListContext : public antlr4::ParserRuleContext {
  public:
    StmtListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtListContext* stmtList();

  class  SimpleStatementContext : public antlr4::ParserRuleContext {
  public:
    SimpleStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentStmtContext *assignmentStmt();
    antlr4::tree::TerminalNode *INHERITED();
    antlr4::tree::TerminalNode *GOTO();
    LabelIdContext *labelId();
    ProcedureCallContext *procedureCall();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleStatementContext* simpleStatement();

  class  StructStmtContext : public antlr4::ParserRuleContext {
  public:
    StructStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompoundStmtContext *compoundStmt();
    ConditionalStmtContext *conditionalStmt();
    LoopStmtContext *loopStmt();
    WithStmtContext *withStmt();
    TryExceptStmtContext *tryExceptStmt();
    TryFinallyStmtContext *tryFinallyStmt();
    RaiseStmtContext *raiseStmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructStmtContext* structStmt();

  class  CompoundStmtContext : public antlr4::ParserRuleContext {
  public:
    CompoundStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    StmtListContext *stmtList();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundStmtContext* compoundStmt();

  class  ConditionalStmtContext : public antlr4::ParserRuleContext {
  public:
    ConditionalStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStmtContext *ifStmt();
    CaseStmtContext *caseStmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionalStmtContext* conditionalStmt();

  class  ProcedureCallContext : public antlr4::ParserRuleContext {
  public:
    ProcedureCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualIdContext *qualId();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExprListContext *exprList();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureCallContext* procedureCall();

  class  AssignmentStmtContext : public antlr4::ParserRuleContext {
  public:
    AssignmentStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DesignatorContext *designator();
    antlr4::tree::TerminalNode *COLON_ASSIGN();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentStmtContext* assignmentStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *THEN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  CaseStmtContext : public antlr4::ParserRuleContext {
  public:
    CaseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *END();
    std::vector<CaseSelectorContext *> caseSelector();
    CaseSelectorContext* caseSelector(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    StmtListContext *stmtList();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseStmtContext* caseStmt();

  class  CaseSelectorContext : public antlr4::ParserRuleContext {
  public:
    CaseSelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CaseLabelContext *> caseLabel();
    CaseLabelContext* caseLabel(size_t i);
    antlr4::tree::TerminalNode *COLON();
    StatementContext *statement();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseSelectorContext* caseSelector();

  class  CaseLabelContext : public antlr4::ParserRuleContext {
  public:
    CaseLabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstExprContext *> constExpr();
    ConstExprContext* constExpr(size_t i);
    antlr4::tree::TerminalNode *DOT_DOT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseLabelContext* caseLabel();

  class  LoopStmtContext : public antlr4::ParserRuleContext {
  public:
    LoopStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RepeatStmtContext *repeatStmt();
    WhileStmtContext *whileStmt();
    ForStmtContext *forStmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopStmtContext* loopStmt();

  class  RepeatStmtContext : public antlr4::ParserRuleContext {
  public:
    RepeatStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REPEAT();
    StmtListContext *stmtList();
    antlr4::tree::TerminalNode *UNTIL();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RepeatStmtContext* repeatStmt();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtContext* whileStmt();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    QualIdContext *qualId();
    antlr4::tree::TerminalNode *COLON_ASSIGN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *DOWNTO();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStmtContext* forStmt();

  class  WithStmtContext : public antlr4::ParserRuleContext {
  public:
    WithStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    QualIdListContext *qualIdList();
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WithStmtContext* withStmt();

  class  TryExceptStmtContext : public antlr4::ParserRuleContext {
  public:
    TryExceptStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRY();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *EXCEPT();
    ExceptionBlockContext *exceptionBlock();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TryExceptStmtContext* tryExceptStmt();

  class  ExceptionBlockContext : public antlr4::ParserRuleContext {
  public:
    ExceptionBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ON();
    antlr4::tree::TerminalNode* ON(size_t i);
    std::vector<TypeIdContext *> typeId();
    TypeIdContext* typeId(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DO();
    antlr4::tree::TerminalNode* DO(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExceptionBlockContext* exceptionBlock();

  class  TryFinallyStmtContext : public antlr4::ParserRuleContext {
  public:
    TryFinallyStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRY();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *FINALLY();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TryFinallyStmtContext* tryFinallyStmt();

  class  RaiseStmtContext : public antlr4::ParserRuleContext {
  public:
    RaiseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAISE();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *AT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RaiseStmtContext* raiseStmt();

  class  ProcedureDeclSectionContext : public antlr4::ParserRuleContext {
  public:
    ProcedureDeclSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureDeclContext *procedureDecl();
    FunctionDeclContext *functionDecl();
    ConstructorDeclContext *constructorDecl();
    DestructorDeclContext *destructorDecl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureDeclSectionContext* procedureDeclSection();

  class  ProcedureDeclContext : public antlr4::ParserRuleContext {
  public:
    ProcedureDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureHeadingContext *procedureHeading();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    BlockContext *block();
    DirectiveContext *directive();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureDeclContext* procedureDecl();

  class  FunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionHeadingContext *functionHeading();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    BlockContext *block();
    DirectiveContext *directive();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclContext* functionDecl();

  class  ConstructorDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstructorDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstructorHeadingContext *constructorHeading();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    BlockContext *block();
    DirectiveContext *directive();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructorDeclContext* constructorDecl();

  class  DestructorDeclContext : public antlr4::ParserRuleContext {
  public:
    DestructorDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DestructorHeadingContext *destructorHeading();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    BlockContext *block();
    DirectiveContext *directive();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DestructorDeclContext* destructorDecl();

  class  FunctionHeadingContext : public antlr4::ParserRuleContext {
  public:
    FunctionHeadingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTION();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *COLON();
    SimpleTypeContext *simpleType();
    antlr4::tree::TerminalNode *STRING();
    FormalParametersContext *formalParameters();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionHeadingContext* functionHeading();

  class  ProcedureHeadingContext : public antlr4::ParserRuleContext {
  public:
    ProcedureHeadingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROCEDURE();
    antlr4::tree::TerminalNode *Identifier();
    FormalParametersContext *formalParameters();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureHeadingContext* procedureHeading();

  class  FormalParametersContext : public antlr4::ParserRuleContext {
  public:
    FormalParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<FormalParmContext *> formalParm();
    FormalParmContext* formalParm(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParametersContext* formalParameters();

  class  FormalParmContext : public antlr4::ParserRuleContext {
  public:
    FormalParmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterContext *parameter();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *OUT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParmContext* formalParm();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentListContext *identList();
    antlr4::tree::TerminalNode *COLON();
    SimpleTypeContext *simpleType();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *FILE();
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    ConstExprContext *constExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  DirectiveContext : public antlr4::ParserRuleContext {
  public:
    DirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CDECL();
    antlr4::tree::TerminalNode *REGISTER();
    antlr4::tree::TerminalNode *DYNAMIC();
    antlr4::tree::TerminalNode *VIRTUAL();
    antlr4::tree::TerminalNode *EXPORT();
    ExternalDirectiveContext *externalDirective();
    antlr4::tree::TerminalNode *NEAR();
    antlr4::tree::TerminalNode *FAR();
    antlr4::tree::TerminalNode *FORWARD();
    antlr4::tree::TerminalNode *INLINE();
    antlr4::tree::TerminalNode *ASSEMBLER();
    antlr4::tree::TerminalNode *MESSAGE();
    ConstExprContext *constExpr();
    antlr4::tree::TerminalNode *OVERRIDE();
    antlr4::tree::TerminalNode *OVERLOAD();
    antlr4::tree::TerminalNode *PASCAL();
    antlr4::tree::TerminalNode *REINTRODUCE();
    antlr4::tree::TerminalNode *SAFECALL();
    antlr4::tree::TerminalNode *STDCALL();
    antlr4::tree::TerminalNode *VARARGS();
    antlr4::tree::TerminalNode *LOCAL();
    antlr4::tree::TerminalNode *ABSTRACT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectiveContext* directive();

  class  ExternalDirectiveContext : public antlr4::ParserRuleContext {
  public:
    ExternalDirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTERNAL();
    StringContext *string();
    antlr4::tree::TerminalNode *NAME();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternalDirectiveContext* externalDirective();

  class  ObjectTypeContext : public antlr4::ParserRuleContext {
  public:
    ObjectTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECT();
    antlr4::tree::TerminalNode *END();
    ObjHeritageContext *objHeritage();
    ObjFieldListContext *objFieldList();
    MethodListContext *methodList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectTypeContext* objectType();

  class  ObjHeritageContext : public antlr4::ParserRuleContext {
  public:
    ObjHeritageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    QualIdContext *qualId();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjHeritageContext* objHeritage();

  class  MethodListContext : public antlr4::ParserRuleContext {
  public:
    MethodListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    std::vector<MethodHeadingContext *> methodHeading();
    MethodHeadingContext* methodHeading(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VIRTUAL();
    antlr4::tree::TerminalNode* VIRTUAL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ABSTRACT();
    antlr4::tree::TerminalNode* ABSTRACT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodListContext* methodList();

  class  MethodHeadingContext : public antlr4::ParserRuleContext {
  public:
    MethodHeadingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureHeadingContext *procedureHeading();
    FunctionHeadingContext *functionHeading();
    antlr4::tree::TerminalNode *CLASS();
    ConstructorHeadingContext *constructorHeading();
    DestructorHeadingContext *destructorHeading();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodHeadingContext* methodHeading();

  class  ConstructorHeadingContext : public antlr4::ParserRuleContext {
  public:
    ConstructorHeadingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSTRUCTOR();
    antlr4::tree::TerminalNode *Identifier();
    FormalParametersContext *formalParameters();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructorHeadingContext* constructorHeading();

  class  DestructorHeadingContext : public antlr4::ParserRuleContext {
  public:
    DestructorHeadingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DESTRUCTOR();
    antlr4::tree::TerminalNode *Identifier();
    FormalParametersContext *formalParameters();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DestructorHeadingContext* destructorHeading();

  class  ObjFieldListContext : public antlr4::ParserRuleContext {
  public:
    ObjFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    IdentListContext *identList();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjFieldListContext* objFieldList();

  class  InitSectionContext : public antlr4::ParserRuleContext {
  public:
    InitSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INITIALIZATION();
    std::vector<StmtListContext *> stmtList();
    StmtListContext* stmtList(size_t i);
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *FINALIZATION();
    antlr4::tree::TerminalNode *BEGIN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitSectionContext* initSection();

  class  ClassTypeContext : public antlr4::ParserRuleContext {
  public:
    ClassTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *END();
    ClassHeritageContext *classHeritage();
    std::vector<ClassFieldListContext *> classFieldList();
    ClassFieldListContext* classFieldList(size_t i);
    std::vector<ClassMethodListContext *> classMethodList();
    ClassMethodListContext* classMethodList(size_t i);
    std::vector<ClassPropertyListContext *> classPropertyList();
    ClassPropertyListContext* classPropertyList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassTypeContext* classType();

  class  ClassHeritageContext : public antlr4::ParserRuleContext {
  public:
    ClassHeritageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    IdentListContext *identList();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassHeritageContext* classHeritage();

  class  ClassVisibilityContext : public antlr4::ParserRuleContext {
  public:
    ClassVisibilityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *PUBLISHED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassVisibilityContext* classVisibility();

  class  ClassFieldListContext : public antlr4::ParserRuleContext {
  public:
    ClassFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassVisibilityContext *classVisibility();
    std::vector<ObjFieldListContext *> objFieldList();
    ObjFieldListContext* objFieldList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassFieldListContext* classFieldList();

  class  ClassMethodListContext : public antlr4::ParserRuleContext {
  public:
    ClassMethodListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassVisibilityContext *classVisibility();
    std::vector<MethodListContext *> methodList();
    MethodListContext* methodList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassMethodListContext* classMethodList();

  class  ClassPropertyListContext : public antlr4::ParserRuleContext {
  public:
    ClassPropertyListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassVisibilityContext *classVisibility();
    std::vector<PropertyListContext *> propertyList();
    PropertyListContext* propertyList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassPropertyListContext* classPropertyList();

  class  PropertyListContext : public antlr4::ParserRuleContext {
  public:
    PropertyListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROPERTY();
    antlr4::tree::TerminalNode *Identifier();
    PropertyInterfaceContext *propertyInterface();
    PropertySpecifiersContext *propertySpecifiers();
    PortabilityDirectiveContext *portabilityDirective();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyListContext* propertyList();

  class  PropertyInterfaceContext : public antlr4::ParserRuleContext {
  public:
    PropertyInterfaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *Identifier();
    PropertyParameterListContext *propertyParameterList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyInterfaceContext* propertyInterface();

  class  PropertyParameterListContext : public antlr4::ParserRuleContext {
  public:
    PropertyParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    IdentListContext *identList();
    antlr4::tree::TerminalNode *COLON();
    TypeIdContext *typeId();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyParameterListContext* propertyParameterList();

  class  PropertySpecifiersContext : public antlr4::ParserRuleContext {
  public:
    PropertySpecifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDEX();
    ConstExprContext *constExpr();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *STORED();
    antlr4::tree::TerminalNode *NODEFAULT();
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *IMPLEMENTS();
    TypeIdContext *typeId();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertySpecifiersContext* propertySpecifiers();

  class  InterfaceTypeContext : public antlr4::ParserRuleContext {
  public:
    InterfaceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERFACE();
    antlr4::tree::TerminalNode *END();
    InterfaceHeritageContext *interfaceHeritage();
    ClassMethodListContext *classMethodList();
    ClassPropertyListContext *classPropertyList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceTypeContext* interfaceType();

  class  InterfaceHeritageContext : public antlr4::ParserRuleContext {
  public:
    InterfaceHeritageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceHeritageContext* interfaceHeritage();

  class  RequiresClauseContext : public antlr4::ParserRuleContext {
  public:
    RequiresClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REQUIRES();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<IdentListContext *> identList();
    IdentListContext* identList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RequiresClauseContext* requiresClause();

  class  ContainsClauseContext : public antlr4::ParserRuleContext {
  public:
    ContainsClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTAINS();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<IdentListContext *> identList();
    IdentListContext* identList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContainsClauseContext* containsClause();

  class  IdentListContext : public antlr4::ParserRuleContext {
  public:
    IdentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentListContext* identList();

  class  QualIdListContext : public antlr4::ParserRuleContext {
  public:
    QualIdListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QualIdContext *> qualId();
    QualIdContext* qualId(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualIdListContext* qualIdList();

  class  QualIdContext : public antlr4::ParserRuleContext {
  public:
    QualIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitIdContext *unitId();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> CARET();
    antlr4::tree::TerminalNode* CARET(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualIdContext* qualId();

  class  TypeIdContext : public antlr4::ParserRuleContext {
  public:
    TypeIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    UnitIdContext *unitId();
    antlr4::tree::TerminalNode *DOT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeIdContext* typeId();

  class  PredefinedTypeContext : public antlr4::ParserRuleContext {
  public:
    PredefinedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *BYTE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PredefinedTypeContext* predefinedType();

  class  CharExprContext : public antlr4::ParserRuleContext {
  public:
    CharExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StringLiteral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharExprContext* charExpr();

  class  UnitIdContext : public antlr4::ParserRuleContext {
  public:
    UnitIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *DOT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnitIdContext* unitId();

  class  LabelIdContext : public antlr4::ParserRuleContext {
  public:
    LabelIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *IntegerLiteral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelIdContext* labelId();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StringLiteral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integer();
    antlr4::tree::TerminalNode *Float();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  ConstExprContext : public antlr4::ParserRuleContext {
  public:
    ConstExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NumberContext *> number();
    NumberContext* number(size_t i);
    StringContext *string();
    CharExprContext *charExpr();
    AdditiveOpContext *additiveOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstExprContext* constExpr();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

