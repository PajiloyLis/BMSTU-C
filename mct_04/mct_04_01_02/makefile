CC := gcc
CFLAGS := -Wall -Werror -pedantic -std=c99


OBJDIR := ./out/
SRCDIR := ./src/

app.exe: $(OBJDIR)main.o $(OBJDIR)list.o
	$(CC) -o $@ $^

$(OBJDIR)main.o: $(SRCDIR)main.c ./inc/list.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I inc -o $@  -c $<

$(OBJDIR)list.o: $(SRCDIR)list.c ./inc/list.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I inc -o $@ -c $<

valgrind : app.exe
	valgrind --leak-check=full ./app.exe

run : app.exe
	./app.exe

.PHONY : clean
clean:
	rm -rf ./out
	rm -f *.o *.exe
