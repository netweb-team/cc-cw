lexer grammar ObjectPascalLexer;

PROGRAM: 'program'; 
PACKAGE: 'package';
END: 'end';
REQUIRES: 'requires';
CONTAINS: 'contains';
LIBRARY: 'library';
UNIT: 'unit';
INTERFACE: 'interface';
IMPLEMENTATION: 'implementation';
INITIALIZATION: 'intitialization';
USES: 'uses';
IN: 'in';
LABEL: 'label';
CONST: 'const';
TYPE_: 'type';
CLASS: 'class';
OF: 'of';
REAL: 'real';
SINGLE:'single';
DOUBLE: 'double';
EXTENDED: 'extended';
CURRENCY: 'currency';
COMP: 'comp';
SHORTINT: 'shortint';
SMALLINT: 'smallint';
INTEGER: 'integer';
BYTE: 'byte';
LONGINT: 'longint';
WORD: 'word';
BOOLEAN: 'boolean';
CHAR: 'char';
WIDECHAR: 'widechar';
LONGCHAR: 'longchar';
PCHAR: 'pchar';
VARIANT: 'variant';
OLEVARIANT: 'olevariant';
STRING: 'string';
ANSISTRING: 'ansistring';
WIDESTRING: 'widestring';
PACKED: 'packed';
ARRAY_1: 'array';
ARRAY_2: 'Array';
RECORD: 'record';
CASE: 'case';
SET: 'set';
FILE: 'file';
OBJECT: 'object';
VIRTUAL: 'virtual';
CONSTRUCTOR: 'constructor';
DESTRUCTOR: 'destructor';
FINALIZATION: 'finalization'; 
PUBLIC: 'public';
PROTECTED_1: 'protected';
PROTECTED_2: 'Protected';
PRIVATE: 'private';
PUBLISHED: 'published';
PROPERTY_1: 'property';
PROPERTY_2: 'Property';
INDEX: 'index';
READ: 'read';
WRITE: 'write';
STORED: 'stored';
DEFAULT: 'default';
NODEFAULT: 'nodefault';
IMPLEMENTS: 'implements'; 
VAR_1: 'var';
VAR_2: 'Var';
ABSOLUTE: 'absolute';
ABSTRACT: 'absctuct';
FUNCTION_1: 'function';
FUNCTION_2: 'Function';
PROCEDURE_1: 'procedure';
PROCEDURE_2: 'Procedure';
OUT: 'out';
INHERITED: 'inherited';
GOTO: 'goto';
BEGIN_1: 'begin';
BEGIN_2: 'Begin';
THEN: 'then';
ELSE: 'else';
IF_1: 'if';
IF_2: 'If';
REPEAT: 'repeat';
UNTIL: 'until';
WHILE: 'while';
TO: 'to';
DOWNTO: 'downto';
FOR_1: 'for';
FOR_2: 'For';
DO_1: 'do';
DO_2: 'Do';
DO_3: 'DO';
WITH: 'with';
TRY: 'try';
FINALLY: 'finally';
EXCEPT_1: 'except';
EXCEPT_2: 'Except';
ON: 'on';
RAISE: 'raise';
AT: 'at';
IS: 'is';
OR: 'or';
XOR: 'xor';
DIV_LITTLE: 'div';
MOD: 'mod';
AND_LITTLE: 'and' ;
SHL: 'shl';
SHR: 'shr';
DIV_BIG: 'DIV';
AND_BIG: 'AND';
NIL: 'nil';
NOT_1: 'not';
NOT_2: 'Not';
NOT_3: 'NOT';
TRUE_1: 'true';
TRUE_2: 'True';
FALSE_1: 'false';
FALSE_2: 'False'; 
UID: 'UID';
NAME: 'NAME';
AS_1: 'as';
AS_2: 'As';
CDECL: 'cdecl';
REGISTER: 'register';
DYNAMIC: 'dynamic';
EXPORT: 'export';
EXTERNAL: 'external';
FAR: 'far';
FORWARD: 'forward';
MESSAGE: 'message';
OVERRIDE_1: 'override';
OVERRIDE_2: 'Override';
OVERLOAD: 'overload';
PASCAL: 'pascal';
REINTRODUCE: 'reintroduce';
SAFECALL: 'safecall';
STDCALL: 'stdcall';
VARARGS: 'varargs';
LOCAL: 'local';
REAL48: 'real48';

SEMI: ';';
DOT: '.';
LEFT_PAREN: '(';
RIGHT_PAREN: ')';
LEFT_BRACKET: '[';
RIGHT_BRACKET: ']';
COMMA: ',';
ASSIGN: '=';
COLON: ':';
DOT_DOT: '..';
CARET: '^';
COLON_ASSIGN: ':=';
GRATER: '>';
LESS: '<';
GRATER_EQUAL: '>=';
LESS_EQUAL: '<=';
NOT_EQUAL: '<>';
PLUS: '+';
MINUS: '-';
STAR: '*';
DIV_: '/';
DOG: '@';
SHARP: '#';
LESS_DIV: '</';
NEAR: 'near';
INLINE: 'inline';
ASSEMBLER: 'assembler';
PLATFORM: 'platform';
DEPRECATED: 'deprecated';
CARDINAL: 'cardinal';
INT64: 'int64';
LONGWORD: 'longword';
UNICODESTRING: 'unicodestring';
QUOTE: '"';
E: 'E';

fragment NONDIGIT: [a-zA-Z_];
fragment UPPERCASE: [A-Z];
fragment LOWERCASE: [a-z];

fragment DIGIT: [0-9];

fragment NONZERODIGIT: [1-9];

fragment OCTALDIGIT: [0-7];

fragment HEXADECIMALDIGIT: [0-9a-fA-F];

fragment BINARYDIGIT: [01];

Ident:
     NONDIGIT (NONDIGIT | DIGIT)*;

DecimalLiteral: NONZERODIGIT ('\''? DIGIT)*;

OctalLiteral: '0' ('\''? OCTALDIGIT)*;

HexadecimalLiteral: ('0x' | '0X') HEXADECIMALDIGIT (
		'\''? HEXADECIMALDIGIT
	)*;

BinaryLiteral: ('0b' | '0B') BINARYDIGIT ('\''? BINARYDIGIT)*;

Integersuffix:
	Unsignedsuffix Longsuffix?
	| Unsignedsuffix Longlongsuffix?
	| Longsuffix Unsignedsuffix?
	| Longlongsuffix Unsignedsuffix?;

fragment Unsignedsuffix: [uU];

fragment Longsuffix: [lL];

fragment Longlongsuffix: 'll' | 'LL';

fragment Cchar:
	~ ['\\\r\n]
	| Escapesequence;

fragment Escapesequence:
	Simpleescapesequence
	| Octalescapesequence
	| Hexadecimalescapesequence;
fragment Simpleescapesequence:
	'\\\''
	| '\\"'
	| '\\?'
	| '\\\\'
	| '\\a'
	| '\\b'
	| '\\f'
	| '\\n'
	| '\\r'
	| ('\\' ('\r' '\n'? | '\n'))
	| '\\t'
	| '\\v';

fragment Octalescapesequence:
	'\\' OCTALDIGIT
	| '\\' OCTALDIGIT OCTALDIGIT
	| '\\' OCTALDIGIT OCTALDIGIT OCTALDIGIT;

fragment Hexadecimalescapesequence: '\\x' HEXADECIMALDIGIT+;

fragment Fractionalconstant:
	Digitsequence? '.' Digitsequence
	| Digitsequence '.';

fragment Exponentpart:
	'e' SIGN? Digitsequence
	| 'E' SIGN? Digitsequence;

fragment SIGN: [+-];

fragment Digitsequence: DIGIT ('\''? DIGIT)*;

fragment Floatingsuffix: [flFL];

fragment Encodingprefix: 'u8' | 'u' | 'U' | 'L';

fragment Schar:
	~ ["\\\r\n]
	| Escapesequence;

fragment Rawstring: 'R"' (( '\\' ["()] )|~[\r\n (])*? '(' ~[)]*? ')'  (( '\\' ["()]) | ~[\r\n "])*? '"';
UserDefinedIntegerLiteral:
	DecimalLiteral Udsuffix
	| OctalLiteral Udsuffix
	| HexadecimalLiteral Udsuffix
	| BinaryLiteral Udsuffix;
UserDefinedFloatingLiteral:
	Fractionalconstant Exponentpart? Udsuffix
	| Digitsequence Exponentpart Udsuffix;
UserDefinedStringLiteral: StringLiteral Udsuffix;
UserDefinedCharacterLiteral: CharacterLiteral Udsuffix;

fragment Udsuffix: Ident;

Whitespace: [ \t]+ -> skip;
Newline: ('\r' '\n'? | '\n') -> skip;
BlockComment: '/*' .*? '*/' -> skip;
LineComment: '//' ~ [\r\n]* -> skip;


IntegerLiteral:
	DecimalLiteral Integersuffix?
	| OctalLiteral Integersuffix?
	| HexadecimalLiteral Integersuffix?
	| BinaryLiteral Integersuffix?;

CharacterLiteral:
	('u' | 'U' | 'L')? '\'' Cchar+ '\'';

FloatingLiteral:
	Fractionalconstant Exponentpart? Floatingsuffix?
	| Digitsequence Exponentpart Floatingsuffix?;

StringLiteral:
	Encodingprefix?
    (Rawstring
	|'"' Schar* '"');

BooleanLiteral: FALSE_1 | FALSE_2 | TRUE_1 | TRUE_2;


UserDefinedLiteral:
	UserDefinedIntegerLiteral
	| UserDefinedFloatingLiteral
	| UserDefinedStringLiteral
	| UserDefinedCharacterLiteral;

MultiLineMacro:
	'#' (~[\n]*? '\\' '\r'? '\n')+ ~ [\n]+ -> channel (HIDDEN);


ARRAY: ARRAY_1 | ARRAY_2;
VAR: VAR_1 | VAR_2;
NOT: NOT_1 | NOT_2 | NOT_3;
DIV: DIV_BIG | DIV_LITTLE;
AND: AND_BIG | AND_LITTLE;
AS: AS_1 | AS_2;
IF: IF_1 | IF_2;
DO: DO_1 | DO_2 | DO_3;
FOR: FOR_1 | FOR_2;
EXCEPT: EXCEPT_1 | EXCEPT_2;
FUNCTION: FUNCTION_1 | FUNCTION_2;
PROCEDURE: PROCEDURE_1 | PROCEDURE_2;
OVERRIDE: OVERRIDE_1 | OVERRIDE_2;
BEGIN: BEGIN_1 | BEGIN_2;

PROTECTED:  PROTECTED_1 | PROTECTED_2;
