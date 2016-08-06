cmake_minimum_required(VERSION 2.8)
project(vfl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/Cellar/llvm/3.6.2/include  -fPIC -fvisibility-inlines-hidden -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wmissing-field-initializers -pedantic -Wno-long-long -Wcovered-switch-default -Wnon-virtual-dtor -std=c++11 -DNDEBUG  -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/local/Cellar/llvm/3.6.2/lib -Wl,-search_paths_first -Wl,-headerpad_max_install_names -lLLVMCore -lLLVMSupport -lcurses -lpthread -lz -lm")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -Wno-redundant-move -Wno-deprecated-register")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(SOURCES
        AST/FunctionAST.cpp
        CodeGen/FunctionGen.cpp
        Demux/Demux.cpp
        Module/VflModule.cpp
        AST/NodeAST.cpp
        TypeSystem/TypeSystem.cpp
        Util/NonCopyable.cpp
        AST/ExpressionAST.cpp
        CodeGen/BinaryOpGen.cpp
        CodeGen/FunctionCallGen.cpp
        CodeGen/StringGen.cpp
        CodeGen/IdentifierGen.cpp
        CodeGen/BasicValueGen.cpp
        CodeGen/ArrayGen.cpp
        CodeGen/StructGen.cpp
        AST/StatementAST.cpp
        Parser/Generated/Parser.cpp
        Parser/Generated/Lexer.cpp
        TypeSystem/Types.cpp
        AST/StructAST.cpp
        CodeGen/AssignmentGen.cpp
        CodeGen/VarDeclGen.cpp CodeGen/ForGen.cpp CodeGen/ForGen.hpp CodeGen/BuiltInFuncGen.cpp CodeGen/BuiltInFuncGen.hpp)

add_executable(vflc Main.cpp ${SOURCES})
