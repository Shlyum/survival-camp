all: build build_with_static build_with_dynamic

build: main_executable_module.o data_process.o decision.o data_io.o data_stat.o
	gcc -Wall -Werror -Wextra main_executable_module.o data_process.o decision.o data_io.o data_stat.o -o ../../build/Quest_3

build_with_static: main_executable_module.o data_process.o decision.o data_io.o data_stat.o libdata_stat.a
	gcc -Wall -Werror -Wextra main_executable_module.o data_process.o decision.o data_io.o -L. -ldata_stat -o ../../build/Quest_5

build_with_dynamic: data_io.o data_stat.o decision.o main_executable_module.o data_process.so
	gcc -Wall -Werror -Wextra data_io.o data_stat.o decision.o main_executable_module.o -L. -ldata_process -o ../../build/Quest_6

main_executable_module.o:
	gcc -c -fPIC -Wall -Werror -Wextra main_executable_module.c

data_process.o:
	gcc -c ../data_module/data_process.c

decision.o:
	gcc -c -Wall -Werror -Wextra ../yet_another_decision_module/decision.c

data_io.o:
	gcc -c -Wall -Werror -Wextra ../data_libs/data_io.c

data_stat.o:
	gcc -c -Wall -Werror -Wextra ../data_libs/data_stat.c

libdata_stat.a:
	ar rc libdata_stat.a data_stat.o
	ranlib libdata_stat.a

data_process.so: data_stat.o
	gcc -Wall -Werror -Wextra -fPIC -c ../data_module/data_process.c
	gcc -Wall -Werror -Wextra -shared -o libdata_process.so data_process.o data_stat.o



clean: 
	rm -rf *.o *.a *.so ../../build/Quest_3 ../../build/Quest_5 ../../build/Quest_6

rebuild: clean 
	make all
