#include "AST/Program.hpp"
#include "Module/VflModule.hpp"
#include "Demux/Demux.hpp"
#include "AST/FunctionAST.hpp"
#include "AST/StructAST.hpp"
#include "Parser/Generated/Parser.hpp"


extern int yyparse();


Program program;


int main(int argv, char * argc[])
{
    VflModule module;

    freopen(argc[1], "r", stdin);
    yyparse();

    Demux demux(module);
    demux.walkAST(program);
}
