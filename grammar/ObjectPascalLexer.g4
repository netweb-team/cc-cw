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
ARRAY: 'array';
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
PROTECTED: 'protected';
PRIVATE: 'private';
PUBLISHED: 'published';
PROPERTY: 'property';
INDEX: 'index';
READ: 'read';
WRITE: 'write';
STORED: 'stored';
DEFAULT: 'default';
NODEFAULT: 'nodefault';
IMPLEMENTS: 'implements'; 
VAR: 'var';
ABSOLUTE: 'absolute';
ABSTRACT: 'absctuct';
FUNCTION: 'function';
PROCEDURE: 'procedure';
OUT: 'out';
INHERITED: 'inherited';
GOTO: 'goto';
BEGIN: 'begin';
THEN: 'then';
ELSE: 'else';
IF: 'if';
REPEAT: 'repeat';
UNTIL: 'until';
WHILE: 'while';
TO: 'to';
DOWNTO: 'downto';
FOR: 'for';
DO: 'do';
WITH: 'with';
TRY: 'try';
FINALLY: 'finally';
EXCEPT: 'except';
ON: 'on';
RAISE: 'raise';
AT: 'at';
IS: 'is';
OR: 'or';
XOR: 'xor';
DIV: 'div';
MOD: 'mod';
AND: 'and';
SHL: 'shl';
SHR: 'shr';
NIL: 'nil';
NOT: 'not';
TRUE: 'true';
FALSE: 'false';
UID: 'UID';
NAME: 'NAME';
AS: 'as';
CDECL: 'cdecl';
REGISTER: 'register';
DYNAMIC: 'dynamic';
EXPORT: 'export';
EXTERNAL: 'external';
FAR: 'far';
FORWARD: 'forward';
MESSAGE: 'message';
OVERRIDE: 'override';
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
DOT_DOT: '..';
LEFT_PAREN: '(';
RIGHT_PAREN: ')';
LEFT_BRACKET: '[';
RIGHT_BRACKET: ']';
COMMA: ',';
ASSIGN: '=';
COLON: ':';
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
SINGLE_QUOTE: '\'';

fragment NONDIGIT: [a-zA-Z_];
fragment UPPERCASE: [A-Z];
fragment LOWERCASE: [a-z];

fragment DIGIT: [0-9];

fragment OCTALDIGIT: [0-7];

fragment HEXADECIMALDIGIT: [0-9a-fA-F];

fragment BINARYDIGIT: [01];

fragment IDENT: NONDIGIT (NONDIGIT | DIGIT)*;

Identifier: IDENT (DOT IDENT)*;

Integer: IntegerLiteral | OctLiteral | HexLiteral;

IntegerLiteral: (DIGIT)+;

OctLiteral: '&' (OCTALDIGIT)+;

HexLiteral: '$' (HEXADECIMALDIGIT)+;

//BinaryLiteral: ('0b' | '0B') (BINARYDIGIT)+;

Float: (DIGIT)+ ((DOT (DIGIT)+ (Exponentpart)?)? | Exponentpart);

fragment SIGN: [+-];

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

fragment Exponentpart: 'e' SIGN? (DIGIT)*;

fragment Floatingsuffix: [flFL];

fragment Encodingprefix: 'u8' | 'u' | 'U' | 'L';

fragment Schar:
	~ ["\\\r\n]
	| Escapesequence;

fragment Rawstring: 'R"' (( '\\' ["()] )|~[\r\n (])*? '(' ~[)]*? ')'  (( '\\' ["()]) | ~[\r\n "])*? '"';

Whitespace: [ \t]+ -> skip;
Newline: ('\r' '\n'? | '\n') -> skip;
BlockComment: '/*' .*? '*/' -> skip;
LineComment: '//' ~ [\r\n]* -> skip;

CharacterLiteral:
	('u' | 'U' | 'L')? '\'' Cchar+ '\'';

StringLiteral:
	Encodingprefix?
    (Rawstring
	|'"' Schar* '"');

BooleanLiteral: FALSE | TRUE;

MultiLineMacro:
	'#' (~[\n]*? '\\' '\r'? '\n')+ ~ [\n]+ -> channel (HIDDEN);
