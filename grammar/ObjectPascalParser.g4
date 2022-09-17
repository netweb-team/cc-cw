parser grammar ObjectPascalParser;

options {
  tokenVocab = ObjectPascalLexer;
}

goal: program | package | library | unit;
program: PROGRAM Identifier (LEFT_PAREN identList RIGHT_PAREN)? SEMI 
        usesClause? declSection* compoundStmt DOT;

unit: UNIT qualId (portabilityDirective)? SEMI interfaceSection implementationSection initSection DOT;

package: PACKAGE Identifier SEMI requiresClause? containsClause? END DOT;

library: LIBRARY Identifier SEMI  usesClause? declSection* compoundStmt DOT;

usesClause: USES qualIdList SEMI;

portabilityDirective: PLATFORM | DEPRECATED | LIBRARY;

interfaceSection: INTERFACE
                    usesClause?
                    interfaceDecl*;

interfaceDecl:  constSection | typeSection | varSection | exportedHeading;

exportedHeading: (procedureHeading SEMI directive?) | (functionHeading SEMI directive?);

implementationSection: IMPLEMENTATION
                        usesClause?
                        declSection*;

block: declSection?  compoundStmt;


exportsStmt: EXPORT exportsItem (COMMA exportsItem)*;

exportsItem: (Identifier (NAME|INDEX SINGLE_QUOTE constExpr SINGLE_QUOTE)?) | (INDEX|NAME SINGLE_QUOTE constExpr SINGLE_QUOTE)?;

declSection: labelDeclSection | constSection | typeSection | varSection |  procedureDeclSection;

labelDeclSection: LABEL labelId;

constSection: CONST (constantDecl SEMI)*;

constantDecl: (Identifier ASSIGN constExpr portabilityDirective? ) | ( Identifier COLON typeId ASSIGN typedConstant portabilityDirective?);

typeSection: TYPE_ (typeDecl SEMI)+;  

typeDecl: Identifier ASSIGN TYPE_? (type | restrictedType) portabilityDirective?;

typedConstant: (constExpr | arrayConstant | recordConstant);

arrayConstant: LEFT_PAREN typedConstant ( COMMA typedConstant )* RIGHT_PAREN;

recordConstant:  LEFT_PAREN (recordFieldConstant SEMI)* RIGHT_PAREN; 

recordFieldConstant: Identifier COLON typedConstant;

type:  typeId |  simpleType |  strucType | pointerType | stringType | procedureType | variantType | classRefType;
restrictedType:  objectType | classType | interfaceType;

classRefType: CLASS OF typeId; 

simpleType: (ordinalType | realType);

ordinalType: (subrangeType | enumeratedType | ordIdent);

subrangeType: (constExpr DOT_DOT constExpr) | subrangeType2;
subrangeType2: (Identifier DOT_DOT Identifier) | subrangeType3;
subrangeType3: (Identifier DOT_DOT constExpr) | subrangeType4;
subrangeType4: (constExpr DOT_DOT Identifier);

enumeratedType: LEFT_PAREN enumeratedTypeElement (COMMA enumeratedTypeElement)* RIGHT_PAREN;
enumeratedTypeElement: Identifier ( ASSIGN constExpr )?;
stringType: STRING | ANSISTRING | WIDESTRING | UNICODESTRING | (STRING LEFT_BRACKET  constExpr RIGHT_BRACKET );

strucType:  PACKED? (arrayType | setType | fileType | recType PACKED?);

arrayType: ARRAY (LEFT_BRACKET ordinalType (COMMA ordinalType)* RIGHT_BRACKET)? OF type portabilityDirective?;

recType: RECORD fieldList? END portabilityDirective?;

fieldList: (fieldDecl SEMI)+ variantSection? SEMI?;

fieldDecl: identList COLON type portabilityDirective?;

variantSection: CASE (Identifier COLON)? typeId OF recVariant (SEMI recVariant )*;

recVariant: constExpr (COMMA constExpr)* COLON LEFT_PAREN fieldList? RIGHT_PAREN;

setType: SET OF ordinalType portabilityDirective?;

fileType: FILE OF typeId portabilityDirective?;

pointerType: CARET typeId portabilityDirective?;

procedureType: (procedureHeading | functionHeading) (OF OBJECT)?;

varSection: VAR (varDecl SEMI)+;

varDecl: identList COLON type ((ABSOLUTE (Identifier | constExpr)) | ASSIGN constExpr)? portabilityDirective?;
      
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
| (NOT factor) 
| setConstructor 
| (typeId LEFT_PAREN expression RIGHT_PAREN);

designator: qualId (DOT Identifier | LEFT_BRACKET exprList RIGHT_BRACKET | CARET)*;
setConstructor: LEFT_BRACKET setElement (COMMA setElement)* RIGHT_BRACKET;
setElement: expression (DOT_DOT expression)?;
exprList: expression (COMMA expression)*; 
statement: (labelId COLON)? (simpleStatement | structStmt); 
stmtList: (statement SEMI)+;
simpleStatement: assignmentStmt | INHERITED | ( GOTO labelId) | procedureCall ;
structStmt: compoundStmt | conditionalStmt | loopStmt | withStmt | tryExceptStmt | tryFinallyStmt | raiseStmt; // | AssemblerStmt;
compoundStmt: BEGIN stmtList SEMI? END;
conditionalStmt: ifStmt | caseStmt;
procedureCall: qualId (LEFT_PAREN exprList RIGHT_PAREN)?;
assignmentStmt: designator COLON_ASSIGN expression;

ifStmt: IF expression THEN statement (ELSE statement)?;
caseStmt: CASE expression OF (caseSelector (SEMI caseSelector)*) (ELSE stmtList)? SEMI? END;

caseSelector: caseLabel (COMMA caseLabel)* COLON statement;
caseLabel: constExpr (DOT_DOT constExpr)?;
loopStmt: repeatStmt | whileStmt | forStmt;

repeatStmt: REPEAT stmtList SEMI? UNTIL expression;

whileStmt: WHILE expression DO statement;

forStmt: FOR qualId COLON_ASSIGN expression (TO | DOWNTO) expression DO statement;

withStmt: WITH qualIdList DO statement;
tryExceptStmt: TRY statement (SEMI statement)* EXCEPT exceptionBlock END;
exceptionBlock: ON (Identifier COLON)? typeId DO statement (SEMI ON (Identifier COLON)? typeId DO statement)*
                  (ELSE statement*) SEMI?;

tryFinallyStmt: TRY statement FINALLY  statement SEMI? END; 

raiseStmt: RAISE Identifier? (AT Identifier)?;
//AssemblerStmt: ASM | <assemblylanguage> | END;
procedureDeclSection: procedureDecl | functionDecl | constructorDecl | destructorDecl; 
procedureDecl: procedureHeading SEMI directive?  portabilityDirective? block SEMI;
functionDecl: functionHeading SEMI directive? portabilityDirective? block SEMI; 

constructorDecl: constructorHeading SEMI directive? portabilityDirective? block SEMI; 
destructorDecl: destructorHeading SEMI directive? portabilityDirective? block SEMI; 
functionHeading: FUNCTION Identifier formalParameters? COLON (simpleType | STRING);
procedureHeading: PROCEDURE Identifier formalParameters?;
formalParameters: LEFT_PAREN formalParm? (COMMA formalParm)* RIGHT_PAREN; 

formalParm: (VAR | CONST | OUT)? parameter;

parameter: (identList (COLON ((ARRAY OF)? simpleType | STRING | FILE))?) 
| (Identifier COLON simpleType (ASSIGN constExpr)?);

directive: CDECL | REGISTER | DYNAMIC | VIRTUAL | EXPORT | externalDirective | NEAR | FAR | FORWARD | INLINE | ASSEMBLER | ( MESSAGE constExpr) | OVERRIDE | OVERLOAD | PASCAL | REINTRODUCE | SAFECALL |STDCALL | VARARGS | LOCAL | ABSTRACT;

externalDirective: EXTERNAL (string (NAME Identifier*)?)?;
objectType: OBJECT objHeritage? objFieldList? methodList? END;

objHeritage: LEFT_PAREN qualId RIGHT_PAREN;
methodList: ((methodHeading (SEMI VIRTUAL (SEMI ABSTRACT)?)?) SEMI)+;
methodHeading: (CLASS? (procedureHeading |functionHeading)) |  constructorHeading | destructorHeading;

constructorHeading: CONSTRUCTOR Identifier formalParameters?;
destructorHeading: DESTRUCTOR Identifier formalParameters?;
objFieldList:  (identList COLON type) SEMI; 

initSection: (INITIALIZATION stmtList (FINALIZATION stmtList)? END) | (BEGIN stmtList END) | END;

//REGION CLASS

classType: CLASS classHeritage? (classFieldList | classMethodList | classPropertyList)* END;
classHeritage: LEFT_PAREN identList RIGHT_PAREN;

classFieldList: classVisibility? objFieldList+;
classMethodList: classVisibility? methodList+;
classPropertyList: classVisibility? propertyList+;

propertyList: PROPERTY Identifier propertyInterface? propertySpecifiers? portabilityDirective?;
propertyInterface: propertyParameterList? COLON Identifier;
propertyParameterList: LEFT_BRACKET (identList COLON typeId) SEMI* RIGHT_BRACKET;
propertySpecifiers: (INDEX constExpr) 
                     | (READ Identifier)
                     | (WRITE Identifier)
                     | (STORED (Identifier | constExpr))
                     | ((DEFAULT constExpr) | NODEFAULT)
                     | (IMPLEMENTS typeId);

interfaceType: INTERFACE 
				(interfaceHeritage)?
                 (classMethodList)?
                 (classPropertyList)?        
                 END;
interfaceHeritage: LEFT_PAREN Identifier RIGHT_PAREN;


requiresClause: REQUIRES identList+ SEMI;
containsClause: CONTAINS identList+ SEMI;
identList: Identifier (COMMA Identifier)*;
qualIdList: qualId (COMMA qualId)+;
qualId: (unitId DOT)? ((DOT)? Identifier (CARET)?)+;
typeId: (unitId DOT)? Identifier;

// Ident* -> <Case-Sensitive> Ident;
//ENDREGION CLASS
//OneChar: (Char |'''' (<character (except quote)> | Quote) '''';
charExpr: StringLiteral;           
unitId: Identifier | Identifier DOT Identifier;  
labelId: Identifier | IntegerLiteral;
string: StringLiteral;
number: Integer | Float;
constExpr: number | string | charExpr | (number additiveOp number);

realType: REAL48 | REAL | SINGLE | DOUBLE | EXTENDED | CURRENCY | COMP;
ordIdent: SHORTINT | SMALLINT | INTEGER | BYTE| CARDINAL | LONGINT | INT64 | WORD | BOOLEAN | CHAR | WIDECHAR | LONGWORD | PCHAR;
variantType: VARIANT | OLEVARIANT;

relOp: GRATER | LESS | LESS_EQUAL | GRATER_EQUAL | NOT_EQUAL | ASSIGN | IN | IS | AS;
addOp: PLUS | MINUS | OR | XOR;
mulOp: STAR | DIV | MOD | AND | SHL | SHR;
additiveOp: PLUS | MINUS | STAR;

classVisibility: PUBLIC | PROTECTED | PRIVATE | PUBLISHED;
