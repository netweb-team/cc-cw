parser grammar ObjectPascalParser;
options {
	tokenVocab = ObjectPascalLexer;
}

goal: program | package | library | unit;
program: PROGRAM identDifficlt (LEFT_PAREN identList RIGHT_PAREN)? SEMI 
        programBlock DOT;

unit: UNIT qualId (portabilityDirective)? SEMI interfaceSection implementationSection initSection DOT;

package: PACKAGE identDifficlt SEMI requiresClause? containsClause? END DOT;

library: LIBRARY identDifficlt SEMI  programBlock DOT;

programBlock: usesClause? declSection*  compoundStmt;

usesClause: USES qualIdList SEMI;

portabilityDirective: PLATFORM | DEPRECATED | LIBRARY; //хз

interfaceSection: INTERFACE
                    usesClause?
                    interfaceDecl*;

interfaceDecl:  constSection | typeSection | varSection | exportedHeading; //хз

exportedHeading: (procedureHeading SEMI directive?) | (functionHeading SEMI directive?);

implementationSection: IMPLEMENTATION
                        usesClause?
                        declSection*;

block: declSection?  compoundStmt;


exportsStmt: EXPORT exportsItem (COMMA exportsItem)*;

exportsItem: (Ident (NAME|INDEX SINGLE_QUOTE constExpr SINGLE_QUOTE)?) | (INDEX|NAME SINGLE_QUOTE constExpr SINGLE_QUOTE)?;

declSection: labelDeclSection | constSection | typeSection | varSection |  procedureDeclSection;

labelDeclSection: LABEL labelId;

constSection: CONST (constantDecl SEMI)*;

constantDecl: (Ident ASSIGN constExpr portabilityDirective? ) | ( identDifficlt COLON typeId ASSIGN typedConstant portabilityDirective?);

typeSection: TYPE_ (typeDecl SEMI)+;  

typeDecl: ( identDifficlt ASSIGN TYPE_? type portabilityDirective?) | ( identDifficlt ASSIGN TYPE_? restrictedType portabilityDirective?);

typedConstant: (constExpr | arrayConstant | recordConstant);

arrayConstant: LEFT_PAREN typedConstant ( COMMA typedConstant )* RIGHT_PAREN;

recordConstant:  LEFT_PAREN (recordFieldConstant SEMI)* RIGHT_PAREN; 

recordFieldConstant: identDifficlt COLON typedConstant;
type:  typeId |  simpleType |  strucType | pointerType | stringType | procedureType | variantType | classRefType;

restrictedType:  objectType | classType | interfaceType;

classRefType: CLASS OF typeId; 

simpleType: (ordinalType | realType);
realType: REAL48 | REAL | SINGLE | DOUBLE | EXTENDED | CURRENCY | COMP;

ordinalType: (subrangeType | enumeratedType | ordIdent);
ordIdent: SHORTINT | SMALLINT | INTEGER | BYTE| CARDINAL | LONGINT | INT64 | WORD | BOOLEAN | CHAR | WIDECHAR | LONGWORD | PCHAR;

variantType: VARIANT | OLEVARIANT;

subrangeType: (constExpr | Ident) DOT_DOT (constExpr | Ident);

enumeratedType: LEFT_PAREN enumeratedTypeElement (COMMA enumeratedTypeElement)* RIGHT_PAREN;
enumeratedTypeElement: identDifficlt ( '=' constExpr )?;
stringType: STRING | ANSISTRING | WIDESTRING | UNICODESTRING | (STRING LEFT_BRACKET  constExpr RIGHT_BRACKET );

strucType:  PACKED? (arrayType | setType | fileType | recType PACKED?);

arrayType: array (LEFT_BRACKET ordinalType (COMMA ordinalType)* RIGHT_BRACKET)? OF type portabilityDirective?;

recType: RECORD fieldList? END portabilityDirective?;

fieldList: (fieldDecl SEMI)+ variantSection? SEMI?;

fieldDecl: identList COLON type portabilityDirective?;

variantSection: CASE (Ident COLON)? typeId OF recVariant (SEMI recVariant )*;

recVariant: constExpr (COMMA constExpr)* COLON LEFT_PAREN fieldList? RIGHT_PAREN;

setType: SET OF ordinalType portabilityDirective?;

fileType: FILE OF typeId portabilityDirective?;

pointerType: CARET typeId portabilityDirective?;

procedureType: (procedureHeading | functionHeading) (OF OBJECT)?;

varSection: var (varDecl SEMI)+;

varDecl: identList COLON type ((ABSOLUTE (Ident | constExpr)) | ASSIGN constExpr)? portabilityDirective?;
      
expression: simpleGrouped (relOp simpleGrouped)*;
simpleGrouped: simpleExpression | LEFT_PAREN simpleExpression RIGHT_PAREN; 
simpleExpression: (PLUS | MINUS)? term (addOp term)*;

term: factor (mulOp factor)*;


factor: designator (LEFT_PAREN exprList RIGHT_PAREN)? 
|  (DOG designator) 
| number 
| string 
//| OneChar 
| NIL 
| (LEFT_PAREN expression RIGHT_PAREN) 
| (not factor) 
| setConstructor 
| (typeId LEFT_PAREN expression RIGHT_PAREN);
relOp: GRATER | LESS | LESS_EQUAL | GRATER_EQUAL | NOT_EQUAL | IN | IS | as;
addOp: PLUS | MINUS | OR | XOR;
mulOp: STAR | DIV_ | div | MOD | and | SHL | SHR;
additiveOp: PLUS | MINUS | STAR;
designator: qualId (DOT identDifficlt | LEFT_BRACKET exprList RIGHT_BRACKET | CARET)*;
setConstructor: LEFT_BRACKET setElement (COMMA setElement)* RIGHT_BRACKET;
setElement: expression (DOT_DOT expression)?;
exprList: expression (COMMA expression)*; 
statement: (labelId COLON)? (simpleStatement | structStmt); 
stmtList: (statement SEMI)+;
simpleStatement:      assignmentStmt  |INHERITED | ( GOTO labelId) | procedureCall ;
structStmt: compoundStmt | conditionalStmt | loopStmt | withStmt | tryExceptStmt | tryFinallyStmt | raiseStmt; // | AssemblerStmt;
begin: BEGIN_1 | BEGIN_2;
compoundStmt: begin stmtList SEMI? END;
conditionalStmt: ifStmt | caseStmt;
procedureCall: qualId (LEFT_PAREN exprList RIGHT_PAREN)?;
assignmentStmt: designator COLON_ASSIGN expression;

ifStmt: if expression THEN statement (ELSE statement)?;
caseStmt: CASE expression OF (caseSelector (SEMI caseSelector)*) (ELSE stmtList)? SEMI? END;

caseSelector: caseLabel (COMMA caseLabel)* COLON statement;
caseLabel: constExpr (DOT_DOT constExpr)?;
loopStmt: repeatStmt | whileStmt | forStmt;

repeatStmt: REPEAT stmtList SEMI? UNTIL expression;

whileStmt: WHILE expression do statement;

forStmt: for qualId COLON_ASSIGN expression (TO | DOWNTO) expression do statement;

withStmt: WITH qualIdList do statement;
tryExceptStmt: TRY
                   statement (SEMI statement )*
                 except
                   exceptionBlock
                 END;

exceptionBlock: ON (Ident COLON)? typeId do statement (SEMI ON (Ident COLON)? typeId do statement)*
                  (ELSE statement*) SEMI?;

tryFinallyStmt: TRY statement FINALLY  statement SEMI? END; 

raiseStmt: RAISE Ident? (AT Ident)?;
//AssemblerStmt: ASM | <assemblylanguage> | END;
procedureDeclSection: procedureDecl | functionDecl | constructorDecl | destructorDecl; 
procedureDecl: procedureHeading SEMI directive?  portabilityDirective? block SEMI;
functionDecl: functionHeading SEMI directive? portabilityDirective? block SEMI; 

constructorDecl: constructorHeading SEMI directive? portabilityDirective? block SEMI; 
destructorDecl: destructorHeading SEMI directive? portabilityDirective? block SEMI; 
functionHeading: function identDifficlt formalParameters? COLON (simpleType | STRING);
procedureHeading: procedure identDifficlt formalParameters?;
formalParameters: LEFT_PAREN formalParm? (COMMA formalParm)* RIGHT_PAREN; 

formalParm: (var | CONST | OUT)? parameter;

parameter: (identList (COLON ((array OF)? simpleType | STRING | FILE))?) 
| (Ident COLON simpleType (ASSIGN constExpr)?);

directive: CDECL | REGISTER | DYNAMIC | VIRTUAL | EXPORT | externalDirective | NEAR | FAR | FORWARD | INLINE | ASSEMBLER | ( MESSAGE constExpr) | override | OVERLOAD | PASCAL | REINTRODUCE | SAFECALL |STDCALL | VARARGS | LOCAL | ABSTRACT;

externalDirective: EXTERNAL (string (NAME Ident*)?)?;
objectType: OBJECT objHeritage? objFieldList? methodList? END;

objHeritage: LEFT_PAREN qualId RIGHT_PAREN;
methodList: ((methodHeading (SEMI VIRTUAL (SEMI ABSTRACT)?)?) SEMI)+;
methodHeading: (CLASS? (procedureHeading |functionHeading)) |  constructorHeading | destructorHeading;

constructorHeading: CONSTRUCTOR identDifficlt formalParameters?;
destructorHeading: DESTRUCTOR identDifficlt formalParameters?;
objFieldList:  (identList COLON type) SEMI; 

initSection: (INITIALIZATION stmtList (FINALIZATION stmtList)? END) | (begin stmtList END) | END;

//REGION CLASS


classType: CLASS classHeritage? (classFieldList | classMethodList | classPropertyList)* END;

classHeritage: LEFT_PAREN identList RIGHT_PAREN;

classVisibility: PUBLIC | protected | PRIVATE | PUBLISHED;

classFieldList: classVisibility? objFieldList+;

classMethodList: classVisibility? methodList+;
classPropertyList: classVisibility? propertyList+;

propertyList: PROPERTY_1 identDifficlt propertyInterface? propertySpecifiers? portabilityDirective?;

propertyInterface: propertyParameterList? COLON Ident;
propertyParameterList: LEFT_BRACKET (identList COLON typeId) SEMI* RIGHT_BRACKET;
propertySpecifiers: (INDEX constExpr) 
                     | (READ Ident)
                     |  (WRITE Ident)
                     | (STORED (Ident | constExpr))
                     | ((DEFAULT constExpr) | NODEFAULT)
                     | (IMPLEMENTS typeId);
interfaceType: INTERFACE 
				(interfaceHeritage)?
                 (classMethodList)?
                 (classPropertyList)?        
                 END;

interfaceHeritage: LEFT_PAREN identDifficlt RIGHT_PAREN;


requiresClause: REQUIRES identList+ SEMI;
containsClause: CONTAINS identList+ SEMI;
identList: identDifficlt (COMMA identDifficlt)*;
qualIdList: qualId (COMMA qualId)+;
qualId: unitId (DOT identDifficlt CARET+)?; 
typeId: (unitId DOT)? Ident;

predefinedType: INTEGER | REAL | BOOLEAN | CHAR | BYTE;

// Ident* -> <Case-Sensitive> Ident;
//ENDREGION CLASS
//OneChar: (Char |'''' (<character (except quote)> | Quote) '''';
charExpr: StringLiteral;           
subrangeExp: identDifficlt | integer;
constExpr: number | string | charExpr | (integer additiveOp integer);
unitId: identDifficlt | identDifficlt DOT identDifficlt;  
labelId: identDifficlt | integer;
string: StringLiteral;
number:  IntegerLiteral | FloatingLiteral | DecimalLiteral; 
radixNumber: hexNumber | octalNumber;
hexNumber: HexadecimalLiteral;
octalNumber: OctalLiteral;
integer: UserDefinedIntegerLiteral; 
signedInteger: (PLUS | MINUS) integer; 


array: ARRAY_1 | ARRAY_2;
var: VAR_1 | VAR_2;
not: NOT_1 | NOT_2 | NOT_3;
div: DIV_BIG | DIV_LITTLE;
and: AND_BIG | AND_LITTLE;
as: AS_1 | AS_2;
if: IF_1 | IF_2;
do: DO_1 | DO_2 | DO_3;
for: FOR_1 | FOR_2;
except: EXCEPT_1 | EXCEPT_2;
function: FUNCTION_1 | FUNCTION_2;
procedure: PROCEDURE_1 | PROCEDURE_2;
override: OVERRIDE_1 | OVERRIDE_2;

protected:  PROTECTED_1 | PROTECTED_2;

identDifficlt: Ident (DOT Ident)*;