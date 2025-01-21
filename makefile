all: compilador

compilador: lex.yy.c y.tab.c 
	gcc lex.yy.c y.tab.c ./lib/*.c -o compiler

lex.yy.c: lexer.l
	flex lexer.l

y.tab.c: parser.y  
	bison parser.y -Wcounterexamples -d -v -o y.tab.c

clean:
	rm -rf lex.yy.c y.tab.* compiler output.txt y.output