CC := gcc
CFLAGS := -Wall -Werror -pedantic -std=c99



app.exe: main.o array.o
	$(CC) -o $@ $^

main.o: ./src/main.c ./inc/array.h
	$(CC) $(CFLAGS) -I inc -c $@ $<

array.o: ./src/array.c ./inc/array.h
	$(CC) $(CFLAGS) -I inc -c $@ $<

.PHONY : clean
clean:
	rm *.o *.exe