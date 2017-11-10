all: arg_parse.c
	gcc -o "work11" arg_parse.c

run: all
	./work11
clean:
	rm work11
	rm *~