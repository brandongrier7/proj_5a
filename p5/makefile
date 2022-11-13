all: part1 part2

part1:part1.o locks.o
	gcc -g part1.o locks.o -o part1 -lpthread
part2:part2.o locks.o
	gcc -g part2.o locks.o -o part2 -lpthread
part1.o:part1.c locks.h
	gcc -g -c part1.c
part2.o:part2.c locks.h
	gcc -g -c part2.c
locks.o:locks.c locks.h
	gcc -g -c locks.c
clean:
	rm -f *.o part1 part2
