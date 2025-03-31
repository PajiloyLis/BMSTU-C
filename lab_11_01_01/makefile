CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal
OFLAGS := 
VFLAGS := --leak-check=full --show-leak-kinds=all -q

SRCDIR := ./src/
OBJDIR := ./out/
UNITDIR := ./unit_tests/

OBJS := $(OBJDIR)my_snprintf.o 
UNIT_OBJS := $(OBJDIR)check_snprintf.o 

unit_tests.exe : OFLAGS += -lcheck
unit_tests.exe : CFLAGS += -g3
unit_tests.exe : $(OBJS) $(UNIT_OBJS) $(OBJDIR)check_main.o
	$(CC) -o ./$@ $^ $(OFLAGS)

$(OBJDIR)my_snprintf.o : $(SRCDIR)my_snprintf.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I inc -c $< -o $@

$(OBJDIR)check_snprintf.o : $(UNITDIR)check_snprintf.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I inc  -c $< -o $@

$(OBJDIR)check_main.o : $(UNITDIR)check_main.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : coverage
coverage : CFLAGS += -ftest-coverage -fprofile-arcs -g3 --coverage
coverage : OFLAGS += -lgcov 
coverage : clean unit
	gcov -s $(SRCDIR) --object-directory $(OBJDIR) my_snprintf.c


.PHONY : | clean unit
unit : unit_tests.exe
	valgrind $(VFLAGS) --log-file=./out/valgrind_log.txt ./unit_tests.exe

.PHONY : clean
clean :	
	rm -fr ./out
	rm -f *.exe $(SRCDIR)*.d ./valgrind_unit_log.txt ./*.gcov