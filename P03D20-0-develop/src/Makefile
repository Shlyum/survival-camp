all: graph

graph: parcer.h function.h
	gcc -Wall -Werror -Wextra graph.c parcer.c function.c -o ../build/graph

clean:
	rm -f *.o ../build/graph

rebuild: clean all