CFLAGS = -Wall -Werror -Wextra

all: state_sort state_search

state_sort: state_sort.o binary_files_common_functions.o
	gcc $(CFLAGS) state_sort.o binary_files_common_functions.o -o ../build/Quest_1

state_search: state_search.o binary_files_common_functions.o
	gcc $(CFLAGS) state_search.o binary_files_common_functions.o -o ../build/Quest_2

state_sort.o:
	gcc -c $(CFLAGS) state_sort.c

binary_files_common_functions.o:
	gcc -c $(CFLAGS) ../code-samples/binary_files_common_functions.c

state_search.o:
	gcc -c $(CFLAGS) state_search.c

clean:
	rm -rf *.o ../build/Quest_1 ../build/Quest_2

rebuild:
	clean all

