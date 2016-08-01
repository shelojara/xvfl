#include "AST/Program.hpp"
#include "Module/VflModule.hpp"
#include "Demux/Demux.hpp"

Program program;

int main(int argv, char * argc[])
{
    VflModule module;

    Demux demux(module);
}
