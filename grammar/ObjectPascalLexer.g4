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
EXRENDED: 'extended';
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
FUNCTION_1: 'function';
FUNCTION_2: 'Funcrion';
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
FINNALY: 'finnaly';
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
REINTRODUCE: 'reinrtoduce';
SAFECALL: 'safecall';
STDCALL: 'stdcall';

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


fragment NONDIGIT: [a-zA-Z_];

fragment DIGIT: [0-9];

fragment NONZERODIGIT: [1-9];

fragment OCTALDIGIT: [0-7];

fragment HEXADECIMALDIGIT: [0-9a-fA-F];

fragment BINARYDIGIT: [01];