parser grammar ObjectPascalParser;
options {
	tokenVocab = ObjectPascalLexer;
}

goal: program | package | library | unit;
program: PROGRAM Ident (LEFT_PAREN identList RIGHT_PAREN)? SEMI 
        programBlock DOT;

unit: UNIT qualId (portabilityDirective)? SEMI interfaceSection implementationSection initSection DOT;

package: PACKAGE Ident SEMI requiresClause? containsClause? END DOT;

library: LIBRARY Ident SEMI  programBlock DOT;

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


// ExportsStmt: EXPORT ExportsItem (COMMA ExportsItem)*;

// ExportsItem: Ident (NAME|INDEX "'" ConstExpr "'")?
                //      (INDEX|NAME "'" ConstExpr "'")?;

declSection: labelDeclSection | constSection | typeSection | varSection |  procedureDeclSection;

labelDeclSection: LABEL labelId;

constSection: CONST (constantDecl SEMI)*;

constantDecl: (Ident ASSIGN constExpr portabilityDirective? ) | ( Ident COLON typeId ASSIGN typedConstant portabilityDirective?);

typeSection: TYPE_ (typeDecl SEMI)+;  

typeDecl: ( Ident ASSIGN TYPE_? type portabilityDirective?) | ( Ident ASSIGN TYPE_? restrictedType portabilityDirective?);

typedConstant: (constExpr | arrayConstant | recordConstant);

arrayConstant: LEFT_PAREN typedConstant ( COMMA typedConstant )* RIGHT_PAREN;

recordConstant:  LEFT_PAREN (recordFieldConstant SEMI)* RIGHT_PAREN; 

recordFieldConstant: Ident COLON typedConstant;
type:  typeId |  simpleType |  strucType | pointerType | stringType | procedureType | variantType | classRefType;

restrictedType:  objectType | classType | interfaceType;

classRefType: CLASS OF typeId; 

simpleType: (ordinalType | realType);
realType: REAL48 | REAL | SINGLE | DOUBLE | EXTENDED | CURRENCY | COMP;

ordinalType: (subrangeType | enumeratedType | ordIdent);
ordIdent: SHORTINT | SMALLINT | INTEGER | BYTE| CARDINAL | LONGINT | INT64 | WORD | BOOLEAN | CHAR | WIDECHAR | LONGWORD | PCHAR;

variantType: VARIANT | OLEVARIANT;

subrangeType: constExpr DOT_DOT constExpr;

enumeratedType: LEFT_PAREN enumeratedTypeElement (COMMA enumeratedTypeElement)* RIGHT_PAREN;
enumeratedTypeElement: Ident ( '=' constExpr )?;
stringType: STRING | ANSISTRING | WIDESTRING | UNICODESTRING | (STRING LEFT_BRACKET  constExpr RIGHT_BRACKET );

strucType:  PACKED? (arrayType | setType | fileType | recType PACKED?);

arrayType: ARRAY (LEFT_BRACKET ordinalType (COMMA ordinalType)* RIGHT_BRACKET)? OF type portabilityDirective?;

recType: RECORD fieldList? END portabilityDirective?;

fieldList: (fieldDecl SEMI)+ variantSection? SEMI?;

fieldDecl: identList COLON type portabilityDirective?;

variantSection: CASE (Ident COLON)? typeId OF recVariant (SEMI recVariant )*;

recVariant: constExpr (COMMA constExpr)* COLON LEFT_PAREN fieldList? RIGHT_PAREN;

setType: SET OF ordinalType portabilityDirective?;

fileType: FILE OF typeId portabilityDirective?;

pointerType: CARET typeId portabilityDirective?;

procedureType: (procedureHeading | functionHeading) (OF OBJECT)?;

varSection: VAR varDecl (SEMI varDecl)*;

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
| (NOT factor) 
| setConstructor 
| (typeId LEFT_PAREN expression RIGHT_PAREN);
relOp: GRATER | LESS | LESS_EQUAL | GRATER_EQUAL | NOT_EQUAL | IN | IS | AS;
addOp: PLUS | MINUS | OR | XOR;
mulOp: STAR | DIV_ | DIV | MOD | AND | SHL | SHR;
additiveOp: PLUS | MINUS | STAR;
designator: qualId (DOT Ident | LEFT_BRACKET exprList RIGHT_BRACKET | CARET)*;
setConstructor: LEFT_BRACKET setElement (COMMA setElement)* RIGHT_BRACKET;
setElement: expression (DOT_DOT expression)?;
exprList: expression (COMMA expression)*; 
statement: (labelId COLON)? (simpleStatement | structStmt)?; 
stmtList: statement (SEMI statement )*;
simpleStatement:      assignmentStmt  |INHERITED | ( GOTO labelId); //| ProcedureCall ;
structStmt: compoundStmt | conditionalStmt | loopStmt | withStmt | tryExceptStmt | tryFinallyStmt | raiseStmt; // | AssemblerStmt;
compoundStmt: BEGIN stmtList SEMI? END;
conditionalStmt: ifStmt | caseStmt;
//ProcedureCall: QualId (LEFT_PAREN (ExprList)? RIGHT_PAREN)?;
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
tryExceptStmt: TRY
                   statement (SEMI statement )*
                 EXCEPT
                   exceptionBlock
                 END;

exceptionBlock: ON (Ident COLON)? typeId DO statement (SEMI ON (Ident COLON)? typeId DO statement)*
                  (ELSE statement*) SEMI?;

tryFinallyStmt: TRY statement FINALLY  statement SEMI? END; 

raiseStmt: RAISE Ident? (AT Ident)?;

//AssemblerStmt: ASM | <assemblylanguage> | END;
procedureDeclSection: procedureDecl | functionDecl; 
procedureDecl: procedureHeading SEMI directive?  portabilityDirective? block SEMI;
functionDecl: functionHeading SEMI directive? portabilityDirective? block SEMI; 
functionHeading: FUNCTION Ident formalParameters? COLON (simpleType | STRING);
procedureHeading: PROCEDURE Ident formalParameters?;
formalParameters: LEFT_PAREN (formalParm SEMI)* RIGHT_PAREN; 

formalParm: (VAR | CONST | OUT)? parameter;

parameter: (identList (COLON ((ARRAY OF)? simpleType | STRING | FILE))?) 
| (Ident COLON simpleType ASSIGN constExpr);

directive: CDECL | REGISTER | DYNAMIC | VIRTUAL | EXPORT | externalDirective | NEAR | FAR | FORWARD | INLINE | ASSEMBLER | ( MESSAGE constExpr) | OVERRIDE | OVERLOAD | PASCAL | REINTRODUCE | SAFECALL |STDCALL | VARARGS | LOCAL | ABSTRACT;

externalDirective: EXTERNAL (string (NAME Ident*)?)?;
objectType: OBJECT objHeritage? objFieldList? methodList? END;

objHeritage: LEFT_PAREN qualId RIGHT_PAREN;
methodList: ((methodHeading (SEMI VIRTUAL (SEMI ABSTRACT)?)?) SEMI)*;
methodHeading: (CLASS? (procedureHeading |functionHeading)) |  constructorHeading | destructorHeading;

constructorHeading: CONSTRUCTOR Ident formalParameters?;
destructorHeading: DESTRUCTOR Ident formalParameters?;
objFieldList:  (identList COLON type) SEMI; 

initSection: (INITIALIZATION stmtList (FINALIZATION stmtList)? END) | (BEGIN stmtList END) | END;

//REGION CLASS


classType: CLASS classHeritage?
             classVisibility?
             classFieldList? 

             classMethodList?
             classPropertyList?
             END;
classHeritage: LEFT_PAREN identList RIGHT_PAREN;

classVisibility: (PUBLIC | PROTECTED | PRIVATE | PUBLISHED)?;

classFieldList: (classVisibility objFieldList SEMI)*;

classMethodList: (classVisibility methodList SEMI)*;
classPropertyList: (classVisibility propertyList SEMI)*;

propertyList: PROPERTY_1 Ident propertyInterface? propertySpecifiers? portabilityDirective?;

propertyInterface: propertyParameterList? COLON Ident;
propertyParameterList: LEFT_BRACKET (identList COLON typeId) SEMI* RIGHT_BRACKET;
propertySpecifiers: (INDEX constExpr)?
                      (READ Ident)?
                      (WRITE Ident)?
                      (STORED (Ident | constExpr))?
                      ((DEFAULT constExpr) | NODEFAULT)?
                      (IMPLEMENTS typeId)?;
interfaceType: INTERFACE 
				(interfaceHeritage)?
                 (classMethodList)?
                 (classPropertyList)?        
                 END;

interfaceHeritage: LEFT_PAREN Ident RIGHT_PAREN;


requiresClause: REQUIRES identList+ SEMI;
containsClause: CONTAINS identList+ SEMI;
identList: Ident (COMMA Ident)+;
qualIdList: qualId (COMMA qualId)+;
qualId: (unitId DOT)? (DOT Ident CARET+)?; 
typeId: (unitId DOT)? predefinedType;

predefinedType: INTEGER | REAL | BOOLEAN | CHAR | BYTE;

// Ident* -> <Case-Sensitive> Ident;
//ENDREGION CLASS
//OneChar: (Char |'''' (<character (except quote)> | Quote) '''';
char: CARET (UPPERCASE | LOWERCASE) | SHARP ( integer | radixNumber);             
constExpr: (number | string | char | integer additiveOp integer);
unitId: Ident | Ident DOT Ident;  
labelId: Ident | integer;
string: StringLiteral;
number: signedInteger (DOT integer (E signedInteger)? )? | radixNumber;
radixNumber: hexNumber | octalNumber;
hexNumber: HEXADECIMALDIGIT*;
octalNumber: OCTALDIGIT*;
integer: DIGIT* | radixNumber; 
signedInteger: (PLUS | MINUS) integer; 
