CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -Wextra -Wfloat-conversion -Wfloat-equal
OFLAGS := 
VFLAGS := --leak-check=full --show-leak-kinds=all -q

SRCDIR := ./src/
OBJDIR := ./out/
INCDIR := ./inc/
LIBDIR := ../
OBJS := $(OBJDIR)args.o $(OBJDIR)main.o
STATLIBS := $(LIBDIR)libarr.a
DYNLIBS := $(LIBDIR)libarr.so

.PHONY : stat_lib
stat_lib : $(OBJS) $(STATLIBS)
	$(CC) -o $(LIBDIR)app.exe $^

.PHONY : dyn_lib_1
dyn_lib_1 : $(OBJS) $(DYNLIBS)
	$(CC) -o $(LIBDIR)app.exe $^

.PHONY : dyn_lib_2
dyn_lib_2 : $(OBJS) $(DYNLIBS)
	$(CC) -D DYN_LOAD -o $(LIBDIR)app.exe $^

$(LIBDIR)libarr.a :
	make -C ../lib static

$(LIBDIR)libarr.so :
	make -C ../lib dynamic

$(OBJDIR)args.o : $(SRCDIR)args.c $(INCDIR)args.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -g3 -I inc -c $< -o $@

$(OBJDIR)main.o : $(SRCDIR)main.c $(INCDIR)args.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -g3 -I inc -iquote ../lib/inc -c $< -o $@

.PHONY : func
func : stat_lib
	../func_tests/scripts/func_tests.sh -v


.PHONY : clean
clean :	
	rm -fr ./out
	rm -f ../*.exe ../*.a ../func_tests/data/*_output.txt