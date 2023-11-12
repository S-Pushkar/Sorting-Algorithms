a.exe : main.o sorting.o graphs.o
	gcc main.o sorting.o graphs.o
main.o : sorting.o graphs.o
	gcc -c main.c sorting.c graphs.c
sorting.o : sorting.c sorting.h
	gcc -c sorting.c
graphs.o : graphs.c graphs.h
	gcc -c graphs.h