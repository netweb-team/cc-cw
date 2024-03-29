#include <iostream>

#include "antlr4-runtime.h"
#include "AstVisitor.h"
#include "libs/ObjectPascalLexer.h"
#include "libs/ObjectPascalParser.h"


using namespace std;
using namespace antlr4;
int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    
    ANTLRInputStream input(stream);
    cout << "input stream created" << endl; 

    ObjectPascalLexer lexer(&input);
    cout << "lexer created" << endl; 

    CommonTokenStream tokens(&lexer);
    cout << tokens.getText() << endl;
    for (int i = 0; i < tokens.getTokens().size(); i++) {
        cout << tokens.getTokens()[i]->getText() << endl;
    }

    ObjectPascalParser parser(&tokens);      
    cout << "parser created" << endl;   
    
    ObjectPascalParser::GoalContext* tree = parser.goal();
    cout << tree->toStringTree(true) << endl;
    AstVisitor visitor;
    try {
        visitor.visitGoal(tree);
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
