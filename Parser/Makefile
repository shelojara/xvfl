all: main

Generated/Parser.cpp:
	bison -d -o Generated/Parser.cpp Parser.y

Generated/Lexer.cpp:
	lex -o Generated/Lexer.cpp lexer.l

clean:
	rm -f Generated/*.cpp Generated/*.hpp

main: clean Generated/Parser.cpp Generated/Lexer.cpp

debug:
	bison --debug --verbose -d -o Generated/Parser.cpp Parser.y