FLAGS = gcc -Wall -Wextra -Werror -pedantic

all:build

build: stack.o graph.o other.o polish_not.o graph_lib.o
	$(FLAGS) stack.o graph.o other.o polish_not.o graph_lib.o -o ../build/graph

stack.o: stack.c
	$(FLAGS) -c stack.c -o stack.o

other.o: other.c
	$(FLAGS) -c other.c -o other.o

polish_not.o: polish_not.c
	$(FLAGS) -c polish_not.c -o polish_not.o

graph.o: graph.c
	$(FLAGS) -c graph.c -o graph.o

graph_lib.o: graph_lib.c
	$(FLAGS) -c graph_lib.c -o graph_lib.o

rebuild:
	clean build

clean:
	rm -rf *.o