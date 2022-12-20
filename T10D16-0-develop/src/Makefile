CFLAGS = -Wall -Werror -Wextra
SOURCES = s21_string.c s21_string_test.c

all : build

build : s21_string.o s21_string_test.o
	gcc $(CFLAGS) $^ -o ../build/Quest_All

strlen_tests: s21_string.o s21_string_test_strlen.o
	gcc $(CFLAGS) s21_string.o s21_string_test.o -o ../build/Quest_1

strcmp_tests: s21_string.o s21_string_test_strcmp.o
	gcc $(CFLAGS) s21_string.o s21_string_test.o -o ../build/Quest_2

strcpy_tests: s21_string.o s21_string_test_strcpy.o
	gcc $(CFLAGS) s21_string.o s21_string_test.o -o ../build/Quest_3

strcat_tests: s21_string.o s21_string_test_strcat.o
	gcc $(CFLAGS) s21_string.o s21_string_test.o -o ../build/Quest_4

strchr_tests: s21_string.o s21_string_test_strchr.o
	gcc $(CFLAGS) s21_string.o s21_string_test.o -o ../build/Quest_5

strstr_tests: s21_string.o s21_string_test_strstr.o
	gcc $(CFLAGS) s21_string.o s21_string_test.o -o ../build/Quest_6

s21_string.o:
	gcc -c -Wall -Werror -Wextra s21_string.c

s21_string_test.o:
	gcc -c -Wall -Werror -Wextra -D STRLEN_TESTS -D STRCMP_TESTS -D STRCPY_TESTS -D STRCAT_TESTS -D STRCHR_TESTS -D STRSTR_TESTS  s21_string_test.c

s21_string_test_strlen.o :
	gcc -c -Wall -Werror -Wextra -D STRLEN_TESTS s21_string_test.c

s21_string_test_strcmp.o :
	gcc -c -Wall -Werror -Wextra -D STRCMP_TESTS s21_string_test.c

s21_string_test_strcpy.o :
	gcc -c -Wall -Werror -Wextra -D STRCPY_TESTS s21_string_test.c

s21_string_test_strcat.o :
	gcc -c -Wall -Werror -Wextra -D STRCAT_TESTS s21_string_test.c

s21_string_test_strchr.o :
	gcc -c -Wall -Werror -Wextra -D STRCHR_TESTS s21_string_test.c

s21_string_test_strstr.o :
	gcc -c -Wall -Werror -Wextra -D STRSTR_TESTS s21_string_test.c



clean :
	rm -rf *.o ../build/Quest_All ../build/Quest_1 ../build/Quest_2 ../build/Quest_3 ../build/Quest_4 ../build/Quest_5 ../build/Quest_6 

rebuild :
	clean all
