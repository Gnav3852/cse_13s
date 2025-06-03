CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: businessdb businessdb_test

businessdb: main.o businessdb.o
	$(CC) $(CFLAGS) main.o businessdb.o -o businessdb

businessdb_test: businessdb_test.o businessdb.o
	$(CC) $(CFLAGS) businessdb_test.o businessdb.o -o businessdb_test

main.o: main.c businessdb.h
	$(CC) $(CFLAGS) -c main.c

businessdb.o: businessdb.c businessdb.h
	$(CC) $(CFLAGS) -c businessdb.c

businessdb_test.o: businessdb_test.c businessdb.h
	$(CC) $(CFLAGS) -c businessdb_test.c

clean:
	rm -f *.o businessdb businessdb_test

format:
	clang-format -i -style=file *.[ch]
