CFLAGS = -Wall -Werror -Wextra

all : door_struct list_test

door_struct : dmanager_module.o
	gcc $(CFLAGS) dmanager_module.o -o ../build/Quest_1

list_test : list_test.o list.o
	gcc $(CFLAGS) list_test.o list.o -o ../build/Quest_2

dmanager_module.o:
	gcc -c $(CFLAGS) dmanager_module.c

list_test.o:
	gcc -c $(CFLAGS) list_test.c

list.o:
	gcc -c $(CFLAGS) list.c

clean:
	rm -rf *.o ../build/Quest_1 ../build/Quest_2

rebuild:
	clean all