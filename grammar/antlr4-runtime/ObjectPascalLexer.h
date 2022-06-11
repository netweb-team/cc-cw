
// Generated from c:\iu7\cc-cw\grammar\ObjectPascalLexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  ObjectPascalLexer : public antlr4::Lexer {
public:
  enum {
    PROGRAM = 1, PACKAGE = 2, END = 3, REQUIRES = 4, CONTAINS = 5, LIBRARY = 6, 
    UNIT = 7, INTERFACE = 8, IMPLEMENTATION = 9, INITIALIZATION = 10, USES = 11, 
    IN = 12, LABEL = 13, CONST = 14, TYPE_ = 15, CLASS = 16, OF = 17, REAL = 18, 
    SINGLE = 19, DOUBLE = 20, EXRENDED = 21, CURRENCY = 22, COMP = 23, SHORTINT = 24, 
    SMALLINT = 25, INTEGER = 26, BYTE = 27, LONGINT = 28, WORD = 29, BOOLEAN = 30, 
    CHAR = 31, WIDECHAR = 32, LONGCHAR = 33, PCHAR = 34, VARIANT = 35, OLEVARIANT = 36, 
    STRING = 37, ANSISTRING = 38, WIDESTRING = 39, PACKED = 40, ARRAY_1 = 41, 
    ARRAY_2 = 42, RECORD = 43, CASE = 44, SET = 45, FILE = 46, OBJECT = 47, 
    VIRTUAL = 48, CONSTRUCTOR = 49, DESTRUCTOR = 50, FINALIZATION = 51, 
    PUBLIC = 52, PROTECTED_1 = 53, PROTECTED_2 = 54, PRIVATE = 55, PUBLISHED = 56, 
    PROPERTY_1 = 57, PROPERTY_2 = 58, INDEX = 59, READ = 60, WRITE = 61, 
    STORED = 62, DEFAULT = 63, NODEFAULT = 64, IMPLEMENTS = 65, VAR_1 = 66, 
    VAR_2 = 67, ABSOLUTE = 68, FUNCTION_1 = 69, FUNCTION_2 = 70, PROCEDURE_1 = 71, 
    PROCEDURE_2 = 72, OUT = 73, INHERITED = 74, GOTO = 75, BEGIN_1 = 76, 
    BEGIN_2 = 77, THEN = 78, ELSE = 79, IF_1 = 80, IF_2 = 81, REPEAT = 82, 
    UNTIL = 83, WHILE = 84, TO = 85, DOWNTO = 86, FOR_1 = 87, FOR_2 = 88, 
    DO_1 = 89, DO_2 = 90, DO_3 = 91, WITH = 92, TRY = 93, FINNALY = 94, 
    EXCEPT_1 = 95, EXCEPT_2 = 96, ON = 97, RAISE = 98, AT = 99, IS = 100, 
    OR = 101, XOR = 102, DIV_LITTLE = 103, MOD = 104, AND_LITTLE = 105, 
    SHL = 106, SHR = 107, DIV_BIG = 108, AND_BIG = 109, NIL = 110, NOT_1 = 111, 
    NOT_2 = 112, NOT_3 = 113, TRUE_1 = 114, TRUE_2 = 115, FALSE_1 = 116, 
    FALSE_2 = 117, UID = 118, NAME = 119, AS_1 = 120, AS_2 = 121, CDECL = 122, 
    REGISTER = 123, DYNAMIC = 124, EXPORT = 125, EXTERNAL = 126, FAR = 127, 
    FORWARD = 128, MESSAGE = 129, OVERRIDE_1 = 130, OVERRIDE_2 = 131, OVERLOAD = 132, 
    PASCAL = 133, REINTRODUCE = 134, SAFECALL = 135, STDCALL = 136, SEMI = 137, 
    DOT = 138, LEFT_PAREN = 139, RIGHT_PAREN = 140, LEFT_BRACKET = 141, 
    RIGHT_BRACKET = 142, COMMA = 143, ASSIGN = 144, COLON = 145, DOT_DOT = 146, 
    CARET = 147, COLON_ASSING = 148, GRATER = 149, LESS = 150, GRATER_EQUAL = 151, 
    LESS_EQUAL = 152, NOT_EQUAL = 153, PLUS = 154, MINUS = 155, STAR = 156, 
    DIV_ = 157, DOG = 158, SHARP = 159, LESS_DIV = 160
  };

  explicit ObjectPascalLexer(antlr4::CharStream *input);
  ~ObjectPascalLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

