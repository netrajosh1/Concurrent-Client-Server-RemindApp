remindapp: main.o numchecker.o printreminder.o setsleepinterval.o
	gcc -o remindapp main.o numchecker.o printreminder.o setsleepinterval.o
main.o: main.c
	gcc -c main.c
numchecker.o: numchecker.c
	gcc -c numchecker.c
printreminder.o: printreminder.c
	gcc -c printreminder.c
setsleepinterval.o: setsleepinterval.c
	gcc -c setsleepinterval.c
