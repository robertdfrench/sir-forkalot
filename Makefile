test: a.out
	time ./a.out

a.out: main.c
	$(CC) $<
