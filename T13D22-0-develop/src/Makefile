CFLAGS = -Wall -Werror -Wextra

all: cipher logging_cipher

cipher: cipher.o logger.o
	gcc $(FLAGS) logger.o cipher.o -o ../build/cipher

logging_cipher: logger.o cipher.o
	gcc $(FLAGS) logger.o cipher.o -o ../build/logging_cipher

cipher.o:
	gcc -c $(CFLAGS) cipher.c

logger.o:
	gcc -c $(CFLAGS) logger.c

clean: 
	rm -rf *.o ../build/cipher ../build/logging_cipher

rebuild: 
	clean all