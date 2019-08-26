test: a.out
	time ./a.out 10000

a.out: main.c
	$(CC) $<
