cmake_minimum_required (VERSION 2.8)
project (vfl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/Cellar/llvm/3.6.2/include  -fPIC -fvisibility-inlines-hidden -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wmissing-field-initializers -pedantic -Wno-long-long -Wcovered-switch-default -Wnon-virtual-dtor -std=c++11 -DNDEBUG  -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -Wno-redundant-move -Wno-deprecated-register")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(SOURCES
        AST/FunctionAST.cpp
        CodeGen/FunctionGen.cpp
        Demux/Demux.cpp
        Module/VflModule.cpp
        Module/Scope.cpp
        AST/Program.cpp AST/NodeAST.cpp AST/NodeAST.hpp AST/ExpressionAST.hpp TypeSystem/TypeSystem.cpp TypeSystem/TypeSystem.hpp Util/NonCopyable.cpp Util/NonCopyable.hpp AST/ExpressionAST.cpp CodeGen/BinaryOpGen.cpp CodeGen/BinaryOpGen.hpp CodeGen/FunctionCallGen.cpp CodeGen/FunctionCallGen.hpp CodeGen/StringGen.cpp CodeGen/StringGen.hpp CodeGen/IdentifierGen.cpp CodeGen/IdentifierGen.hpp CodeGen/BasicValueGen.cpp CodeGen/BasicValueGen.hpp CodeGen/ArrayGen.cpp CodeGen/ArrayGen.hpp CodeGen/StructGen.cpp CodeGen/StructGen.hpp)

add_executable(vflc Main.cpp ${SOURCES})
