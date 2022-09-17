#include "AstVisitor.h"
#include "ast.h"

std::any AstVisitor::visitGoal(ObjectPascalParser::GoalContext *ctx)
{
    if (ctx->program())
    {
        ExprAST *program = std::any_cast<ExprAST *>(visitProgram(ctx->program()));
        program->codegen();
        delete program;
        return true;
    }
    return visitChildren(ctx);
}

std::any AstVisitor::visitProgram(ObjectPascalParser::ProgramContext *ctx)
{
    std::vector<ExprAST *> decls;
    for (auto decl : ctx->declSection())
    {
        auto d = std::any_cast<ExprAST *>(visitDeclSection(decl));
        decls.push_back(d);
    }
    ExprAST *section = new ExprListAST(decls);
    ExprAST *stmts = std::any_cast<ExprAST *>(visitCompoundStmt(ctx->compoundStmt()));
    ExprAST *result = new ProgramExprAST(ctx->Identifier()->getText(), section, stmts);
    return result;
}

std::any AstVisitor::visitDeclSection(ObjectPascalParser::DeclSectionContext *ctx)
{
    if (ctx->constSection())
        return visitConstSection(ctx->constSection());
    else if (ctx->varSection())
        return visitVarSection(ctx->varSection());
    else if (ctx->procedureDeclSection())
        return visitProcedureDeclSection(ctx->procedureDeclSection());
    return visitChildren(ctx);
}

std::any AstVisitor::visitCompoundStmt(ObjectPascalParser::CompoundStmtContext *ctx)
{
    return visitStmtList(ctx->stmtList());
}

std::any AstVisitor::visitStmtList(ObjectPascalParser::StmtListContext *ctx)
{
    std::vector<ExprAST *> stmts;
    for (auto s : ctx->statement())
    {
        stmts.push_back(std::any_cast<ExprAST *>(visitStatement(s)));
    }
    ExprAST *result = new ExprListAST(stmts);
    return result;
}

std::any AstVisitor::visitStatement(ObjectPascalParser::StatementContext *ctx)
{
    if (ctx->simpleStatement())
        return visitSimpleStatement(ctx->simpleStatement());
    else if (ctx->structStmt())
        return visitStructStmt(ctx->structStmt());
    return visitChildren(ctx);
}

std::any AstVisitor::visitSimpleStatement(ObjectPascalParser::SimpleStatementContext *ctx)
{
    if (ctx->assignmentStmt())
        return visitAssignmentStmt(ctx->assignmentStmt());
    else if (ctx->procedureCall())
        return visitProcedureCall(ctx->procedureCall());
    return visitChildren(ctx);
}

std::any AstVisitor::visitAssignmentStmt(ObjectPascalParser::AssignmentStmtContext *ctx)
{
    ExprAST *design = std::any_cast<ExprAST *>(visitDesignator(ctx->designator()));
    ExprAST *expr = std::any_cast<ExprAST *>(visitExpression(ctx->expression()));
    ExprAST *result = new BinaryExprAST(ASSIGN, design, expr);
    return result;
}

std::any AstVisitor::visitProcedureCall(ObjectPascalParser::ProcedureCallContext *ctx)
{
    std::string name = std::any_cast<std::string>(visitQualId(ctx->qualId()));
    std::vector<ExprAST *> args;
    if (ctx->exprList())
        args = std::any_cast<std::vector<ExprAST *>>(visitExprList(ctx->exprList()));

    ExprAST *result;
    if (Library[name])
    {
        std::vector<std::string> argnames;
        for (auto arg : args)
            argnames.push_back(dynamic_cast<VariableExprAST*>(arg)->getName());
        result = new LibraryExprAST(name, argnames);
    }
    else
        result = new CallExprAST(name, args);
    return result;
}

std::any AstVisitor::visitStructStmt(ObjectPascalParser::StructStmtContext *ctx)
{
    if (ctx->compoundStmt())
        return visitCompoundStmt(ctx->compoundStmt());
    else if (ctx->conditionalStmt())
        return visitConditionalStmt(ctx->conditionalStmt());
    else if (ctx->loopStmt())
        return visitLoopStmt(ctx->loopStmt());
    return visitChildren(ctx);
}

std::any AstVisitor::visitConditionalStmt(ObjectPascalParser::ConditionalStmtContext *ctx)
{
    if (ctx->ifStmt())
        return visitIfStmt(ctx->ifStmt());
    return visitChildren(ctx);
}

std::any AstVisitor::visitIfStmt(ObjectPascalParser::IfStmtContext *ctx)
{
    ExprAST *cond, *then, *els, *result;
    cond = std::any_cast<ExprAST *>(visitExpression(ctx->expression()));
    then = std::any_cast<ExprAST *>(visitStatement(ctx->statement()[0]));
    if (ctx->statement().size() > 1)
        els = std::any_cast<ExprAST *>(visitStatement(ctx->statement()[1]));
    else
        els = new NumberExprAST(0);
    result = new IfExprAST(cond, then, els);
    return result;
}

std::any AstVisitor::visitWhileStmt(ObjectPascalParser::WhileStmtContext *ctx)
{
    ExprAST *cond, *body, *result;
    cond = std::any_cast<ExprAST *>(visitExpression(ctx->expression()));
    body = std::any_cast<ExprAST *>(visitStatement(ctx->statement()));
    result = new WhileExprAST(cond, body);
    return result;
}

std::any AstVisitor::visitRepeatStmt(ObjectPascalParser::RepeatStmtContext *ctx)
{
    ExprAST *cond, *body, *result;
    cond = std::any_cast<ExprAST *>(visitExpression(ctx->expression()));
    body = std::any_cast<ExprAST *>(visitStmtList(ctx->stmtList()));
    result = new RepeatExprAST(cond, body);
    return result;
}

std::any AstVisitor::visitForStmt(ObjectPascalParser::ForStmtContext *ctx)
{
    ExprAST *start, *end, *step, *body, *result;
    std::string var = std::any_cast<std::string>(visitQualId(ctx->qualId()));
    start = std::any_cast<ExprAST *>(visitExpression(ctx->expression()[0]));
    end = std::any_cast<ExprAST *>(visitExpression(ctx->expression()[1]));
    if (ctx->TO())
        step = new NumberExprAST(1);
    else if (ctx->DOWNTO())
        step = new NumberExprAST(-1);
    body = std::any_cast<ExprAST *>(visitStatement(ctx->statement()));
    result = new ForExprAST(var, start, end, step, body);
    return result;
}

std::any AstVisitor::visitConstSection(ObjectPascalParser::ConstSectionContext *ctx)
{
    std::vector<ExprAST *> consts;
    for (auto s : ctx->constantDecl())
        consts.push_back(std::any_cast<ExprAST *>(visitConstantDecl(s)));
    ExprAST *result = new ExprListAST(consts);
    return result;
}

std::any AstVisitor::visitConstantDecl(ObjectPascalParser::ConstantDeclContext *ctx)
{
    if (ctx->constExpr())
    {
        // TODO: add string values
        TypeName t = Integer;
        const double d = std::any_cast<double>(visitConstExpr(ctx->constExpr()));
        ExprAST *result = new ConstExprAST(ctx->Identifier()->getText(), new NumberExprAST(d));
        return result;
    }
    return visitChildren(ctx);
}

std::any AstVisitor::visitConstExpr(ObjectPascalParser::ConstExprContext *ctx)
{
    if (ctx->number().size())
    {
        std::vector<double> nums;
        for (auto n : ctx->number())
            nums.push_back(std::stod(n->getText()));
        char op;
        if (ctx->additiveOp())
            op = ctx->additiveOp()->getText()[0];
        double val;
        switch (op)
        {   
            case '+':
                val = nums[0] + nums[1]; break;
            case '-':
                val = nums[0] - nums[1]; break;
            case '*':
                val = nums[0] * nums[1]; break;
            default:
                val = nums[0]; break;
        }
        return val;
    }
    // TODO: visit string values
    return visitChildren(ctx);
}

std::any AstVisitor::visitVarSection(ObjectPascalParser::VarSectionContext *ctx)
{
    std::vector<ExprAST *> vars;
    for (auto v : ctx->varDecl())
        vars.push_back(std::any_cast<ExprAST *>(visitVarDecl(v)));

    ExprAST *result = new ExprListAST(vars);
    return result;
}

std::any AstVisitor::visitVarDecl(ObjectPascalParser::VarDeclContext *ctx)
{
    std::vector<ExprAST *> vars;
    std::vector<std::string> ids = std::any_cast<std::vector<std::string>>(visitIdentList(ctx->identList()));
    std::string type = ctx->type()->getText();
    // TODO: get typename
    TypeName t = Integer;
    for (auto id : ids)
        vars.push_back(new DeclareExprAST(id, t));
    ExprAST *result = new ExprListAST(vars);
    return result;
}

std::any AstVisitor::visitProcedureDecl(ObjectPascalParser::ProcedureDeclContext *ctx)
{
    PrototypeAST *proto = std::any_cast<PrototypeAST *>(visitProcedureHeading(ctx->procedureHeading()));
    std::vector<ExprAST *> body;
    body.push_back(std::any_cast<ExprAST *>(visitBlock(ctx->block())));
    body.push_back(new NumberExprAST(0));
    ExprAST *result = new FunctionAST(proto, body);
    return result;
}

std::any AstVisitor::visitFunctionDecl(ObjectPascalParser::FunctionDeclContext *ctx)
{
    PrototypeAST *proto = std::any_cast<PrototypeAST *>(visitFunctionHeading(ctx->functionHeading()));
    std::vector<ExprAST *> body;
    body.push_back(new DeclareExprAST(proto->Name, proto->ReturnType));
    body.push_back(std::any_cast<ExprAST *>(visitBlock(ctx->block())));
    body.push_back(new VariableExprAST(proto->Name));
    ExprAST *result = new FunctionAST(proto, body);
    return result;
}

std::any AstVisitor::visitProcedureHeading(ObjectPascalParser::ProcedureHeadingContext *ctx)
{
    std::string name = ctx->Identifier()->getText();
    auto args = std::any_cast<std::vector<std::pair<std::string, TypeName>>>(visitFormalParameters(ctx->formalParameters()));
    std::vector<std::string> argnames;
    std::vector<TypeName> argtypes;
    for (auto arg : args)
    {
        argnames.push_back(arg.first);
        argtypes.push_back(arg.second);
    }
    ExprAST *result = new PrototypeAST(name, argnames, argtypes);
    return result;
}

std::any AstVisitor::visitFunctionHeading(ObjectPascalParser::FunctionHeadingContext *ctx)
{
    std::string name = ctx->Identifier()->getText();
    auto args = std::any_cast<std::vector<std::pair<std::string, TypeName>>>(visitFormalParameters(ctx->formalParameters()));
    std::vector<std::string> argnames;
    std::vector<TypeName> argtypes;
    for (auto arg : args)
    {
        argnames.push_back(arg.first);
        argtypes.push_back(arg.second);
    }
    // TODO: get return type instead of integer
    ExprAST *result = new PrototypeAST(name, argnames, argtypes, Integer);
    return result;
}

std::any AstVisitor::visitTypeSection(ObjectPascalParser::TypeSectionContext *ctx)
{
    std::vector<RecordAST *> decls;
    for (auto type : ctx->typeDecl())
        decls.push_back(std::any_cast<RecordAST *>(visitTypeDecl(type)));
    ExprAST *result = new TypeExprAST(decls);
    return result;
}

std::any AstVisitor::visitTypeDecl(ObjectPascalParser::TypeDeclContext *ctx)
{
    std::string tname = ctx->Identifier()->getText();
    if (typenames.count(tname))
        throw std::runtime_error("Unable to redefine existing type");
    typenames.insert(tname);

    ExprAST *t = nullptr;
    if (ctx->type())
        t = std::any_cast<ExprAST *>(visitType(ctx->type()));
    else if (ctx->restrictedType())
        t = std::any_cast<ExprAST *>(visitRestrictedType(ctx->restrictedType()));

    std::vector<ExprAST *> body = {t};
    RecordAST *result = new RecordAST(tname, body);
    return result;
}

std::any AstVisitor::visitType(ObjectPascalParser::TypeContext *ctx)
{
    if (ctx->typeId())
        return visitTypeId(ctx->typeId());
    else if (ctx->simpleType())
        return visitSimpleType(ctx->simpleType());
    else if (ctx->strucType())
        return visitStrucType(ctx->strucType());
    else if (ctx->stringType())
        return visitStringType(ctx->stringType());
    else if (ctx->procedureType())
        return visitProcedureType(ctx->procedureType());
    return visitChildren(ctx);
}

std::any AstVisitor::visitSimpleType(ObjectPascalParser::SimpleTypeContext *ctx) 
{
    if (ctx->ordinalType())
        return visitOrdinalType(ctx->ordinalType());
    else if (ctx->realType())
        return visitRealType(ctx->realType());
}

std::any AstVisitor::visitOrdinalType(ObjectPascalParser::OrdinalTypeContext *ctx)
{
    if (ctx->subrangeType())
        return visitSubrangeType(ctx->subrangeType());
    else if (ctx->ordIdent())
        return visitOrdIdent(ctx->ordIdent());
    return visitChildren(ctx);
}

std::any AstVisitor::visitSubrangeType(ObjectPascalParser::SubrangeTypeContext *ctx)
{
    if (ctx->subrangeType2())
        return visitSubrangeType2(ctx->subrangeType2());

    double first = std::any_cast<double>(visitConstExpr(ctx->constExpr()[0]));
    double second = std::any_cast<double>(visitConstExpr(ctx->constExpr()[1]));
    std::pair<double, double>result(first, second);
    return result;
}

std::any AstVisitor::visitSubrangeType2(ObjectPascalParser::SubrangeType2Context *ctx)
{
    if (ctx->subrangeType3())
        return visitSubrangeType3(ctx->subrangeType3());

    std::string first = ctx->Identifier()[0]->getText();
    std::string second = ctx->Identifier()[1]->getText();
    std::pair<std::string, std::string>result(first, second);
    return result;
}

std::any AstVisitor::visitSubrangeType3(ObjectPascalParser::SubrangeType3Context *ctx)
{
    if (ctx->subrangeType4())
        return visitSubrangeType4(ctx->subrangeType4());

    double second = std::any_cast<double>(visitConstExpr(ctx->constExpr()));
    std::string first = ctx->Identifier()->getText();
    std::pair<std::string, double>result(first, second);
    return result;
}

std::any AstVisitor::visitSubrangeType4(ObjectPascalParser::SubrangeType4Context *ctx)
{
    double first = std::any_cast<double>(visitConstExpr(ctx->constExpr()));
    std::string second = ctx->Identifier()->getText();
    std::pair<double, std::string>result(first, second);
    return result;
}

std::any AstVisitor::visitOrdIdent(ObjectPascalParser::OrdIdentContext *ctx)
{
    if (ctx->BOOLEAN())
        return Boolean;
    else if (ctx->SHORTINT())
        return ShortInt;
    else if (ctx->SMALLINT())
        return SmallInt;
    else if (ctx->INTEGER())
        return Integer;
    else if (ctx->BYTE())
        return Byte;
    else if (ctx->LONGINT())
        return LongInt;
    else if (ctx->CHAR())
        return Char;
    else if (ctx->WORD())
        return Word;
    else if (ctx->PCHAR())
        return PChar;
    return visitChildren(ctx);
}

std::any AstVisitor::visitRealType(ObjectPascalParser::RealTypeContext *ctx)
{
    if (ctx->REAL())
        return Real;
    else if (ctx->SINGLE())
        return Single;
    else if (ctx->DOUBLE())
        return Double;
    return visitChildren(ctx);
}

std::any AstVisitor::visitStrucType(ObjectPascalParser::StrucTypeContext *ctx)
{
    if (ctx->arrayType())
        return visitArrayType(ctx->arrayType());
    else if (ctx->recType())
        return visitRecType(ctx->recType());
    return visitChildren(ctx);
}

std::any AstVisitor::visitArrayType(ObjectPascalParser::ArrayTypeContext *ctx)
{
    std::vector<ExprAST *>sizes;
    for (auto size : ctx->ordinalType())
        sizes.push_back(std::any_cast<ExprAST *>(visitOrdinalType(size)));

    ExprAST *t = std::any_cast<ExprAST *>(visitType(ctx->type()));
    // TODO: add adequate array constructing
    std::pair<ExprAST *, TypeName> result(sizes[0], t->type);
    return result;
}

std::any AstVisitor::visitRecType(ObjectPascalParser::RecTypeContext *ctx)
{
    if (ctx->fieldList())
        return visitFieldList(ctx->fieldList());

    return visitChildren(ctx);
}

std::any AstVisitor::visitFieldList(ObjectPascalParser::FieldListContext *ctx)
{
    std::vector<ExprAST *>fields;
    for (auto f : ctx->fieldDecl())
        fields.push_back(std::any_cast<ExprAST *>(visitFieldDecl(f)));
    return fields;
}

std::any AstVisitor::visitFieldDecl(ObjectPascalParser::FieldDeclContext *ctx)
{
    std::vector<std::string> ids;
    ids = std::any_cast<std::vector<std::string>>(visitIdentList(ctx->identList()));
    ExprAST *t = std::any_cast<ExprAST *>(visitType(ctx->type()));
    std::vector<ExprAST *>field;
    for (auto id : ids)
        field.push_back(new DeclareExprAST(id, t->type));
    ExprAST *result = new ExprListAST(field); 
    return result;
}

std::any AstVisitor::visitStringType(ObjectPascalParser::StringTypeContext *ctx)
{
    if (ctx->STRING())
    {
        ExprAST *len = nullptr;
        if (ctx->constExpr())
        {
            len = std::any_cast<ExprAST *>(visitConstExpr(ctx->constExpr()));
            // TODO: do something with len
            delete len;
        }
        return String;
    }
    return visitChildren(ctx);
}

std::any AstVisitor::visitProcedureType(ObjectPascalParser::ProcedureTypeContext *ctx)
{
    if (ctx->procedureHeading())
        return visitProcedureHeading(ctx->procedureHeading());
    else if (ctx->functionHeading())
        return visitFunctionHeading(ctx->functionHeading());
}

std::any AstVisitor::visitRestrictedType(ObjectPascalParser::RestrictedTypeContext *ctx)
{
    return visitChildren(ctx);
}

std::any AstVisitor::visitBlock(ObjectPascalParser::BlockContext *ctx)
{
    std::vector<ExprAST *> block;
    if (ctx->declSection())
        block.push_back(std::any_cast<ExprAST *>(visitDeclSection(ctx->declSection())));
    block.push_back(std::any_cast<ExprAST *>(visitCompoundStmt(ctx->compoundStmt())));
    ExprAST *result = new ExprListAST(block);
    return result;
}

std::any AstVisitor::visitIdentList(ObjectPascalParser::IdentListContext *ctx)
{
    std::vector<std::string> result;
    for (auto id : ctx->Identifier())
        result.push_back(id->getText());
    return result;
}

std::any AstVisitor::visitExprList(ObjectPascalParser::ExprListContext *ctx)
{
    std::vector<ExprAST *> result;
    for (auto e : ctx->expression())
    {
        result.push_back(std::any_cast<ExprAST *>(visitExpression(e)));
    }
    return result;
}

std::any AstVisitor::visitExpression(ObjectPascalParser::ExpressionContext *ctx)
{
    std::vector<ExprAST *> operands;
    std::vector<std::string> operators;
    for (auto op : ctx->simpleGrouped())
        operands.push_back(std::any_cast<ExprAST *>(visitSimpleGrouped(op)));
    for (auto sign : ctx->relOp())
        operators.push_back(sign->getText());
    while (operands.size() > 1)
    {
        OperEnum op;
        if (operators[0] == ">")
            op = GT;
        else if (operators[0] == "<")
            op = LT;
        else if (operators[0] == "<=")
            op = LE;
        else if (operators[0] == ">=")
            op = GE;
        else if (operators[0] == "<>")
            op = NE;
        else if (operators[0] == "=")
            op = EQ;
        operands[1] = new BinaryExprAST(op, operands[0], operands[1]);
        operands.erase(operands.begin());
        operators.erase(operators.begin());
    }
    return operands[0];
}

std::any AstVisitor::visitSimpleGrouped(ObjectPascalParser::SimpleGroupedContext *ctx)
{
    return visitSimpleExpression(ctx->simpleExpression());
}

std::any AstVisitor::visitSimpleExpression(ObjectPascalParser::SimpleExpressionContext *ctx) 
{
    std::vector<ExprAST *> operands;
    std::vector<std::string> operators;

    for (auto t : ctx->term())
        operands.push_back(std::any_cast<ExprAST *>(visitTerm(t)));
    if (ctx->MINUS())
        operands[0] = new BinaryExprAST(MUL, operands[0], new NumberExprAST(-1));
    for (auto sign : ctx->addOp())
        operators.push_back(sign->getText());
    while (operands.size() > 1)
    {
        OperEnum op;
        if (operators[0] == "+")
            op = ADD;
        else if (operators[0] == "-")
            op = SUB;
        else if (operators[0] == "or")
            op = OR;
        operands[1] = new BinaryExprAST(op, operands[0], operands[1]);
        operands.erase(operands.begin());
        operators.erase(operators.begin());
    }
    return operands[0];
}

std::any AstVisitor::visitTerm(ObjectPascalParser::TermContext *ctx) 
{
    std::vector<ExprAST *> operands;
    std::vector<std::string> operators;
    for (auto f : ctx->factor())
        operands.push_back(std::any_cast<ExprAST *>(visitFactor(f)));
    for (auto sign : ctx->mulOp())
        operators.push_back(sign->getText());
    while (operands.size() > 1)
    {
        OperEnum op;
        if (operators[0] == "*")
            op = MUL;
        else if (operators[0] == "div")
            op = DIV;
        else if (operators[0] == "mod")
            op = MOD;
        else if (operators[0] == "and")
            op = AND;
        operands[1] = new BinaryExprAST(op, operands[0], operands[1]);
        operands.erase(operands.begin());
        operators.erase(operators.begin());
    }
    return operands[0];
}

std::any AstVisitor::visitFactor(ObjectPascalParser::FactorContext *ctx)
{
    if (ctx->number())
        return visitNumber(ctx->number());
    else if (ctx->string())
        return visitString(ctx->string());
    else if (ctx->expression())
        return visitExpression(ctx->expression());
    else if (ctx->designator())
        return visitDesignator(ctx->designator());
    // TODO: visit another expressions
    return visitChildren(ctx);
}

std::any AstVisitor::visitDesignator(ObjectPascalParser::DesignatorContext *ctx)
{
    std::string name = std::any_cast<std::string>(visitQualId(ctx->qualId()));
    std::vector<ExprAST *> index;
    ExprAST *result;
    // TODO: get all exprList
    if (ctx->exprList().size())
    {
        index = std::any_cast<std::vector<ExprAST *>>(visitExprList(ctx->exprList()[0]));
        result = new ArrayExprAST(name, new ExprListAST(index));
    }
    else
        result = new VariableExprAST(name);
    return result;
}

std::any AstVisitor::visitFormalParameters(ObjectPascalParser::FormalParametersContext *ctx)
{
    std::vector<std::pair<std::string, TypeName>> params;
    for (auto fp : ctx->formalParm())
        params.push_back(std::any_cast<std::pair<std::string, TypeName>>(visitFormalParm(fp)));
    return params;
}

std::any AstVisitor::visitParameter(ObjectPascalParser::ParameterContext *ctx)
{
    // TODO: get param type instead of integer
    return std::pair<std::string, TypeName>(ctx->Identifier()->getText(), Integer);
}

std::any AstVisitor::visitString(ObjectPascalParser::StringContext *ctx)
{
    // TODO::проверить на ковычки и другие лишние вещи
    ExprAST *result = new StringExprAST(ctx->StringLiteral()->getText(), String);
    return result;
}

std::any AstVisitor::visitNumber(ObjectPascalParser::NumberContext *ctx)
{
    const double d = std::stod(ctx->getText());
    TypeName type = Double;
    if (int(d) == d)
    {
        type = Integer;
    }
    else if (short(d) == d)
    {
        type = SmallInt;
    }
    ExprAST *result = new NumberExprAST(d, type);
    return result;
}

std::any AstVisitor::visitQualId(ObjectPascalParser::QualIdContext *ctx) 
{
    std::string unit = "";
    if (ctx->unitId())
        unit = std::any_cast<std::string>(visitUnitId(ctx->unitId())) + "/";

    std::vector<std::string> ids;
    for (auto id : ctx->Identifier())
        ids.push_back(id->getText());

    std::ostringstream buf;
    std::string result;
    if (ids.size() > 1)
    {
        std::copy(ids.begin(), ids.end(), std::ostream_iterator<std::string>(buf, "."));
        result = buf.str();
    }
    else 
        result = ids[0];
    return unit + result;
}

std::any AstVisitor::visitQualIdList(ObjectPascalParser::QualIdListContext *ctx) 
{
    std::vector<std::string> result;
    for (auto id : ctx->qualId())
        result.push_back(std::any_cast<std::string>(visitQualId(id)));
    return result;
}

std::any AstVisitor::visitTypeId(ObjectPascalParser::TypeIdContext *ctx) 
{
    std::string unit = "";
    if (ctx->unitId())
        unit = std::any_cast<std::string>(visitUnitId(ctx->unitId())) + "/";

    return unit + ctx->Identifier()->getText();
}

std::any AstVisitor::visitUnitId(ObjectPascalParser::UnitIdContext *ctx)
{
    return ctx->getText();
}
