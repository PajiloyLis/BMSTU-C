CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal
OFLAGS := 
VFLAGS := --leak-check=full --show-leak-kinds=all -q

SRCDIR := ./src/
OBJDIR := ./out/
INCDIR := ./inc/
OBJS := $(OBJDIR)arrio.o $(OBJDIR)algorithms.o

libarr.a : $(OBJS)
	ar cr ../$@ $^
	ranlib ../$@

libarr.so : CFLAGS += -fPIC
libarr.so : OFLAGS += -shared
libarr.so : $(OBJS)
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd/..)
	$(CC) -o ../$@ $(OFLAGS) $^


$(OBJDIR)arrio.o : $(SRCDIR)arrio.c $(INCDIR)arrlib.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -g3 -I inc -c $< -o $@

$(OBJDIR)algorithms.o : $(SRCDIR)algorithms.c $(INCDIR)arrlib.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -g3 -I inc -c $< -o $@

.PHONY : static
static : libarr.a

.PHONY : dynamic
dynamic : libarr.so

.PHONY : clean
clean :	
	rm -fr ./out
	rm -f ../*.a ../*.so