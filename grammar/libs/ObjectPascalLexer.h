
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

