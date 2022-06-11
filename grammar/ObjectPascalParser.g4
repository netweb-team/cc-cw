parser grammar ObjectPascalParser;
options {
	tokenVocab = ObjectPascalLexer;
}


Goal: Program | Package | Library | Unit;
Program: PROGRAM Ident (LEFT_PAREN IdentList RIGHT_PAREN)? SEMI 
        ProgramBlock DOT;

Unit: UNIT QualIdent (PortabilityDirective)? SEMI
        InterfaceSection
        ImplementationSection
        InitSection DOT;

Package: PACKAGE Ident SEMI
           RequiresClause?
           ContainsClause?
           END DOT;

Library: LIBRARY Ident SEMI
           ProgramBlock DOT;

ProgramBlock: UsesClause?
                DeclSection*        
                 CompoundStmt;

UsesClause: USES QualIdentList SEMI;

PortabilityDirective: PLATFORM | DEPRECATED | LIBRARY; //хз

InterfaceSection: INTERFACE
                    UsesClause?
                    InterfaceDecl*;

InterfaceDecl:  ConstSection | TypeSection | VarSection | ExportedHeading; //хз

ExportedHeading: (ProcedureHeading SEMI [Directive]) | (FunctionHeading ';' [Directive]);

ImplementationSection: IMPLEMENTATION
                         UsesClause?
                        DeclSection*
                         ExportsStmt*;

Block: DeclSection?
         ExportsStmt+
         CompoundStmt
         ExportsStmt*;


ExportsStmt: EXPORT ExportsItem (, ExportsItem)*;

ExportsItem: Ident (NAME|INDEX "'" ConstExpr "'")?
                     (INDEX|NAME "'" ConstExpr "'")?;

DeclSection: LabelDeclSection | ConstSection | TypeSection | VarSection |  ProcedureDeclSection;

LabelDeclSection: LABEL LabelId;

ConstSection: CONST (ConstantDecl SEMI)*;

ConstantDecl: (Ident ASSIGN ConstExpr [PortabilityDirective] ) | ( Ident COLON TypeId ASSIGN TypedConstant [PortabilityDirective]);

TypeSection: TYPE (TypeDecl SEMI)+;  

TypeDecl: ( Ident ASSIGN TYPE? Type PortabilityDirective?) | ( Ident ASSIGN TYPE? RestrictedType PortabilityDirective?);

TypedConstant: (ConstExpr | ArrayConstant | RecordConstant);

ArrayConstant: LEFT_PAREN TypedConstant ( COMMA TypedConstant )* RIGHT_PAREN;

RecordConstant:  LEFT_PAREN (RecordFieldConstant SEMI)* RIGHT_PAREN; 

RecordFieldConstant: Ident COLON TypedConstant;
Type:  TypeId |  SimpleType |  StrucType | PointerType | StringType | ProcedureType | VariantType | ClassRefType;

RestrictedType:  ObjectType | ClassType | InterfaceType;

ClassRefType: CLASS OF TypeId; 

SimpleType: (OrdinalType | RealType)
RealType: REAL48 | REAL | SINGLE | DOUBLE | EXTENDED | CURRENCY | COMP;

OrdinalType: (SubrangeType | EnumeratedType | OrdIdent);
OrdIdent: SHORTINT | SMALLINT | INTEGER | BYTE| CARDINAL | LONGINT | INT64 | WORD | BOOLEAN | CHAR | WIDECHAR | LONGWORD | PCHAR;

VariantType: VARIANT | OLEVARIANT;

SubrangeType: ConstExpr DOT_DOT ConstExpr;

EnumeratedType: LEFT_PAREN EnumeratedTypeElement (',' EnumeratedTypeElement)* RIGHT_PAREN;
EnumeratedTypeElement: Ident ( '=' ConstExpr )?;
StringType: STRING | ANSISTRING | WIDESTRING | UNICODESTRING | (STRING LEFT_BRACKET  ConstExpr RIGHT_BRACKET );

StrucType:  PACKED? (ArrayType | SetType | FileType | RecType PACKED?);

ArrayType: ARRAY (LEFT_BRACKET OrdinalType ( ',' OrdinalType)* RIGHT_BRACKET)? OF Type PortabilityDirective?;

RecType: RECORD FieldList? END PortabilityDirective?;

FieldList: (FieldDecl SEMI)+ VariantSection? SEMI?;

FieldDecl: IdentList COLON Type PortabilityDirective?;

VariantSection: CASE (Ident COLON)? TypeId OF RecVariant (SEMI RecVariant )*;

RecVariant: ConstExpr (COMMA ConstExpr)* COLON LEFT_PAREN FieldList? RIGHT_PAREN;

SetType: SET OF OrdinalType PortabilityDirective?;

FileType: FILE OF TypeId PortabilityDirective?;

PointerType: CARET TypeId PortabilityDirective?;

ProcedureType: (ProcedureHeading | FunctionHeading) (OF OBJECT)?;
VarSection: VAR VarDecl (SEMI VarDecl)*;

VarDecl: IdentList COLON Type [(ABSOLUTE (Ident | ConstExpr)) | '=' ConstExpr] [PortabilityDirective];
      
Expression: SimpleGrouped (RelOp SimpleGrouped ...)*;
SimpleGrouped: SimpleExpression | LEFT_PAREN SimpleExpression RIGHT_PAREN; 
SimpleExpression: ('+' | '-')? Term (AddOp Term)*;

Term: Factor (MulOp Factor)*;

Factor: Designator (LEFT_PAREN ExprList RIGHT_PAREN)?;
Factor: DOG Designator;
Factor: Number;
Factor: String;
Factor: OneChar;
Factor: NIL;
Factor: LEFT_PAREN Expression RIGHT_PAREN;
Factor: NOT Factor;
Factor: SetConstructor;
Factor: TypeId LEFT_PAREN Expression RIGHT_PAREN;
RelOp: GRATER | LESS | LESS_EQUAL | GRATER_EQUAL | NOT_EQUAL | IN | IS | AS;
AddOp: PLUS | MINUS | OR | XOR;
MulOp: STAR | DIV_ | DIV | MOD | AND | SHL | SHR;
AdditiveOp: PLUS | MINUS | STAR;
Designator: QualId (DOT Ident | LEFT_BRACKET ExprList RIGHT_BRACKET | CARET)*;
SetConstructor: LEFT_BRACKET SetElement (',' SetElement  )* RIGHT_BRACKET;
SetElement: Expressio (DOT_DOT Expression)?;
ExprList: Expression (COMMA Expression)*; 
Statement: (LabelId COLON)? (SimpleStatement | StructStmt)?; 
StmtList: Statement (SEMI Statement )*;
SimpleStatement: ProcedureCall           | AssignmentStmt  |INHERITED | ( GOTO LabelId);
StructStmt: CompoundStmt | ConditionalStmt | LoopStmt | WithStmt | TryExceptStmt | TryFinallyStmt | RaiseStmt | AssemblerStmt;
CompoundStmt: BEGIN StmtList SEMI? END
ConditionalStmt: IfStmt | CaseStmt;
ProcedureCall: QualId (LEFT_PAREN (ExprList)? RIGHT_PAREN)?;
AssignmentStmt: Designator COLON_ASSIGN Expression;
IfStmt: IF Expression THEN Statement (ELSE Statement)?;
CaseStmt: CASE Expression OF (CaseSelector (SEMI CaseSelector)*) (ELSE StmtList)? SEMI? END;

CaseSelector: CaseLabel (COMMA CaseLabel)* COLON Statement;
CaseLabel: ConstExpr (DOT_DOT ConstExpr)?;
LoopStmt: RepeatStmt | WhileStmt | ForStmt;

RepeatStmt: REPEAT StmtList SEMI? UNTIL Expression;

WhileStmt: WHILE Expression DO Statement;
ForStmt: FOR QualId COLON_ASSIGN Expression (TO | DOWNTO) Expression DO Statement;

WithStmt: WITH QualIdentList DO Statement;
TryExceptStmt: TRY
                   Statement (SEMI Statement )*
                 EXCEPT
                   ExceptionBlock
                 END;

ExceptionBlock: (ON (Ident COLON)? TypeID DO Statement)? (SEMI ON (Ident COLON)? TypeID DO Statement)*
                  (ELSE Statement* ) SEMI?;

TryFinallyStmt: TRY
                   Statement
                  FINALLY
                   Statement SEMI?
                  END
RaiseStmt: RAISE object? (AT address)?;

AssemblerStatement: ASM | <assemblylanguage> | END;
ProcedureDeclSection: ProcedureDecl | FunctionDecl; 
ProcedureDecl: ProcedureHeading SEMI Directive?  PortabilityDirective? Block SEMI;
FunctionDecl: FunctionHeading SEMI Directive? PortabilityDirective? Block SEMI; 
FunctionHeading: FUNCTION Ident FormalParameters? COLON (SimpleType | STRING);

ProcedureHeading: PROCEDURE Ident FormalParameters?;
FormalParameters: LEFT_PAREN (FormalParm SEMI)* RIGHT_PAREN; 

FormalParm: (VAR | CONST | OUT)? Parameter;

Parameter: IdentList (COLON ((ARRAY OF)? SimpleType | STRING | FILE))?;
Parameter: Ident COLON SimpleType ASSIGN ConstExpr;
Directive: CDECL | REGISTER | DYNAMIC | VIRTUAL | EXPORT | ExternalDirective | NEAR | FAR | FORWARD | INLINE | ASSEMBLER | ( MESSAGE ConstExpr) | OVERRIDE | OVERLOAD | PASCAL | REINTRODUCE | SAFECALL |STDCALL | VARARGS | LOCAL | ABSTRACT;

ExternalDirective: EXTERNAL (String (NAME Ident*)?)?;
ObjectType: OBJECT ObjHeritage? ObjFieldList? MethodList? END;

ObjHeritage: LEFT_PAREN QualId RIGHT_PAREN;
MethodList: ((MethodHeading (SEMI VIRTUAL (SEMI ABSTRACT)?)?) SEMI)*;
MethodHeading: (CLASS? (ProcedureHeading |FunctionHeading)) |  ConstructorHeading | DestructorHeading;

ConstructorHeading: CONSTRUCTOR Ident FormalParameters?;
DestructorHeading: DESTRUCTOR Ident FormalParameters?;
ObjFieldList:  (IdentList COLON Type) SEMI; 
InitSection: INITIALIZATION StmtList (FINALIZATION StmtList)? END;
InitSection: BEGIN StmtList END;
InitSection: END;

//REGION CLASS

PROTECTED:  PROTECTED_1 | PROTECTED_2;

ClassType: CLASS ClassHeritage?
             ClassVisibility?
             ClassFieldList? 

             ClassMethodList?
             ClassPropertyList?
             END;
ClassHeritage: LEFT_PAREN IdentList RIGHT_PAREN;

ClassVisibility: (PUBLIC | PROTECTED | PRIVATE | PUBLISHED)?;

ClassFieldList: (ClassVisibility ObjFieldList SEMI)*;

ClassMethodList: (ClassVisibility MethodList SEMI)*;
ClassPropertyList: (ClassVisibility PropertyList SEMI)*;

PropertyList: PROPERTY_1 Ident PropertyInterface? PropertySpecifiers? PortabilityDirective?;

PropertyInterface: PropertyParameterList? COLON Ident;
PropertyParameterList: LEFT_BRACKET (IdentList COLON TypeId) SEMI* RIGHT_BRACKET;
PropertySpecifiers: (INDEX ConstExpr)?
                      (READ Ident)?
                      (WRITE Ident)?
                      (STORED (Ident | Constant))?
                      ((DEFAULT ConstExpr) | NODEFAULT)?
                      (IMPLEMENTS TypeId)?;
InterfaceType: INTERFACE 
				(InterfaceHeritage)?
                 (ClassMethodList)?
                 (ClassPropertyList)?        
                 END;

InterfaceHeritage: LEFT_PAREN Ident RIGHT_PAREN;


RequiresClause: REQUIRES IdentList+ SEMI;
ContainsClause: CONTAINS IdentList+ SEMI;
IdentList: Ident (COMMA ident)+;
QualId: (UnitId DOT)? (DOT Ident CARET+)?; 
TypeId: (UnitId DOT)? <type-identifier>
// Ident* -> <Case-Sensitive> Ident;
Ident: IdentStart (AlphaNum*)?;
//ENDREGION CLASS