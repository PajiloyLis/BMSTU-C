.NOTPARALLEL: unit unit_tests.exe debug release clean

CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal
OFLAGS := -lm
VFLAGS := --leak-check=full --show-leak-kinds=all -q

SRCDIR := ./src/
OBJDIR := ./out/
UNITDIR := ./func_tests/

OBJS := $(OBJDIR)args.o $(OBJDIR)book.o $(OBJDIR)list.o $(OBJDIR)vector.o
UNIT_OBJS := $(OBJDIR)check_front_back_split.o $(OBJDIR)check_remove_duplicates.o $(OBJDIR)check_sorted_merge.o $(OBJDIR)check_sort.o $(OBJDIR)check_find.o $(OBJDIR)check_insert.o
SRCS := $(wildcard $(SRCDIR)*.c)

.PHONY : debug
debug: debug.lastbuildstate
debug : CFLAGS += -g3
debug : app.exe

.PHONY : release
release : release.lastbuildstate
release : CFLAGS += -g0 -DNDEBUG
release : app.exe

%.lastbuildstate :
	rm -f $(OBJDIR)*.o *.exe *.lastbuildstate
	touch $@

app.exe : $(OBJS) $(OBJDIR)main.o
	$(CC) $^ -o $@ $(OFLAGS)

$(OBJDIR)%.o : ./*/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I inc -c $< -o $@


$(OBJDIR)%.d : $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) -MM -MT $(OBJDIR)$*.o -I inc $< > $@

-include $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.d)

.PHONY : func
func : debug
	./func_tests/scripts/func_tests.sh -v


.PHONY : coverage
coverage : CFLAGS += -ftest-coverage -fprofile-arcs -g3 --coverage
coverage : OFLAGS += -lgcov 
coverage : func
	gcov -s $(SRCDIR) --object-directory $(OBJDIR) $(SRCS)


.PHONY : unit
unit : | debug.lastbuildstate unit_tests.exe
	valgrind $(VFLAGS) --log-file=./out/valgrind_log.txt ./unit_tests.exe

unit_tests.exe : SRCS += $(wildcard $(UNITDIR)*.c)
unit_tests.exe : OFLAGS += -lcheck
unit_tests.exe : CFLAGS += -g3
unit_tests.exe : $(OBJS) $(UNIT_OBJS) $(OBJDIR)check_main.o
	$(CC) -o ./$@ $^ $(OFLAGS)

.PHONY : clean
clean :	
	rm -fr ./out
	rm -f *.exe $(SRCDIR)*.d ./func_tests/data/*_output.txt *.lastbuildstate ./valgrind_unit_log.txt ./*.gcov