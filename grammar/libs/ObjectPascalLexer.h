
// Generated from ObjectPascalLexer.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  ObjectPascalLexer : public antlr4::Lexer {
public:
  enum {
    PROGRAM = 1, PACKAGE = 2, END = 3, REQUIRES = 4, CONTAINS = 5, LIBRARY = 6, 
    UNIT = 7, INTERFACE = 8, IMPLEMENTATION = 9, INITIALIZATION = 10, USES = 11, 
    IN = 12, LABEL = 13, CONST = 14, TYPE_ = 15, CLASS = 16, OF = 17, REAL = 18, 
    SINGLE = 19, DOUBLE = 20, EXTENDED = 21, CURRENCY = 22, COMP = 23, SHORTINT = 24, 
    SMALLINT = 25, INTEGER = 26, BYTE = 27, LONGINT = 28, WORD = 29, BOOLEAN = 30, 
    CHAR = 31, WIDECHAR = 32, LONGCHAR = 33, PCHAR = 34, VARIANT = 35, OLEVARIANT = 36, 
    STRING = 37, ANSISTRING = 38, WIDESTRING = 39, PACKED = 40, ARRAY_1 = 41, 
    ARRAY_2 = 42, RECORD = 43, CASE = 44, SET = 45, FILE = 46, OBJECT = 47, 
    VIRTUAL = 48, CONSTRUCTOR = 49, DESTRUCTOR = 50, FINALIZATION = 51, 
    PUBLIC = 52, PROTECTED_1 = 53, PROTECTED_2 = 54, PRIVATE = 55, PUBLISHED = 56, 
    PROPERTY_1 = 57, PROPERTY_2 = 58, INDEX = 59, READ = 60, WRITE = 61, 
    STORED = 62, DEFAULT = 63, NODEFAULT = 64, IMPLEMENTS = 65, VAR_1 = 66, 
    VAR_2 = 67, ABSOLUTE = 68, ABSTRACT = 69, FUNCTION_1 = 70, FUNCTION_2 = 71, 
    PROCEDURE_1 = 72, PROCEDURE_2 = 73, OUT = 74, INHERITED = 75, GOTO = 76, 
    BEGIN_1 = 77, BEGIN_2 = 78, THEN = 79, ELSE = 80, IF_1 = 81, IF_2 = 82, 
    REPEAT = 83, UNTIL = 84, WHILE = 85, TO = 86, DOWNTO = 87, FOR_1 = 88, 
    FOR_2 = 89, DO_1 = 90, DO_2 = 91, DO_3 = 92, WITH = 93, TRY = 94, FINALLY = 95, 
    EXCEPT_1 = 96, EXCEPT_2 = 97, ON = 98, RAISE = 99, AT = 100, IS = 101, 
    OR = 102, XOR = 103, DIV_LITTLE = 104, MOD = 105, AND_LITTLE = 106, 
    SHL = 107, SHR = 108, DIV_BIG = 109, AND_BIG = 110, NIL = 111, NOT_1 = 112, 
    NOT_2 = 113, NOT_3 = 114, TRUE_1 = 115, TRUE_2 = 116, FALSE_1 = 117, 
    FALSE_2 = 118, UID = 119, NAME = 120, AS_1 = 121, AS_2 = 122, CDECL = 123, 
    REGISTER = 124, DYNAMIC = 125, EXPORT = 126, EXTERNAL = 127, FAR = 128, 
    FORWARD = 129, MESSAGE = 130, OVERRIDE_1 = 131, OVERRIDE_2 = 132, OVERLOAD = 133, 
    PASCAL = 134, REINTRODUCE = 135, SAFECALL = 136, STDCALL = 137, VARARGS = 138, 
    LOCAL = 139, REAL48 = 140, SEMI = 141, DOT = 142, LEFT_PAREN = 143, 
    RIGHT_PAREN = 144, LEFT_BRACKET = 145, RIGHT_BRACKET = 146, COMMA = 147, 
    ASSIGN = 148, COLON = 149, DOT_DOT = 150, CARET = 151, COLON_ASSIGN = 152, 
    GRATER = 153, LESS = 154, GRATER_EQUAL = 155, LESS_EQUAL = 156, NOT_EQUAL = 157, 
    PLUS = 158, MINUS = 159, STAR = 160, DIV_ = 161, DOG = 162, SHARP = 163, 
    LESS_DIV = 164, NEAR = 165, INLINE = 166, ASSEMBLER = 167, PLATFORM = 168, 
    DEPRECATED = 169, CARDINAL = 170, INT64 = 171, LONGWORD = 172, UNICODESTRING = 173, 
    QUOTE = 174, E = 175, SINGLE_QUOTE = 176, Ident = 177, DecimalLiteral = 178, 
    OctalLiteral = 179, HexadecimalLiteral = 180, BinaryLiteral = 181, Integersuffix = 182, 
    UserDefinedIntegerLiteral = 183, UserDefinedFloatingLiteral = 184, UserDefinedStringLiteral = 185, 
    UserDefinedCharacterLiteral = 186, Whitespace = 187, Newline = 188, 
    BlockComment = 189, LineComment = 190, IntegerLiteral = 191, CharacterLiteral = 192, 
    FloatingLiteral = 193, StringLiteral = 194, BooleanLiteral = 195, UserDefinedLiteral = 196, 
    MultiLineMacro = 197
  };

  explicit ObjectPascalLexer(antlr4::CharStream *input);

  ~ObjectPascalLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

