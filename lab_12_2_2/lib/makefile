CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal
OFLAGS := 

SRCDIR := ./src/
OBJDIR := ./out/
INCDIR := ./inc/
OBJS := $(OBJDIR)task.o

task.so : CFLAGS += -fPIC
task.so : OFLAGS += -shared
task.so : $(OBJS)
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd/..)
	$(CC) -o ../$@ $(OFLAGS) $^

$(OBJDIR)task.o : $(SRCDIR)task.c $(INCDIR)task.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I inc -c $< -o $@

.PHONY : clean
clean :	
	rm -fr ./out
	rm -f ../*.so  