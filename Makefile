all: hello

hello: main.o kruskal.o prims.o
	gcc main.o kruskal.o prims.o -o hello

main.o: main.c
	gcc -c main.c

kruskal.o: kruskal.c
	gcc -c kruskal.c

prims.o: prims.c
	gcc -c prims.c
	
clean:
	rm *o hello