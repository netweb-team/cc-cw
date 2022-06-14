#include <iostream>

#include "antlr4-runtime.h"
#include "libs/ObjectPascalParserBaseVisitor.h"
#include "libs/ObjectPascalParserVisitor.h"
#include "libs/ObjectPascalLexer.h"
#include "libs/ObjectPascalParser.h"


using namespace std;
using namespace antlr4;
int main(int argc, const char* argv[]) {
    // std::ifstream stream;
    // stream.open("input.scene");
    
    // ANTLRInputStream input(stream);
    std::cout << "Hello"<< endl;
    
    antlr4::ANTLRInputStream input("6*(2+3)");

    cout << "input stream created" << endl; 
    ObjectPascalLexer lexer(&input);
    
    cout << "lexer created" << endl; 
    CommonTokenStream tokens(&lexer);
    cout << "common token created" << endl; 
    ObjectPascalParser parser(&tokens);  
    
    cout << "parser created" << endl;   
    //ObjectPascalParser::FileContext* tree = parser.file();
    //ImageVisitor visitor;
    //Scene scene = visitor.visitFile(tree).as<Scene>();
    //scene.draw();
    return 0;
}