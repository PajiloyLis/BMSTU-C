.NOTPARALLEL: unit unit_tests.exe debug release clean

CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla
OFLAGS := -lm
VFLAGS := --leak-check=yes -q

SRCDIR := ./src/
OBJDIR := ./out/
UNITDIR := ./func_tests/

OBJS := $(OBJDIR)args.o $(OBJDIR)array_algo.o $(OBJDIR)fileio.o 
UNIT_OBJS := $(OBJDIR)check_args.o $(OBJDIR)check_find.o $(OBJDIR)check_sort.o
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
	rm -f *.exe $(SRCDIR)*.d ./func_tests/data/*_output.txt *.lastbuildstate ./valgrind_log.txt

.PHONY : debug_asan
debug_asan: OFLAGS += -fsanitize=address -fno-omit-frame-pointer -g3
debug_asan : debug

.PHONY : debug_msan
debug_msan : OFLAGS += -g3 -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer
debug_msan : $(OBJS) $(OBJDIR)main.o
	clang $(OFLAGS) $^ -o app.exe

.PHONY : debug_ubsan
debug_ubsan : OFLAGS += -g3 -fsanitize=undefined -fno-omit-frame-pointer
debug_ubsan : app.exe

.PHONY : coverage
coverage : CFLAGS += -ftest-coverage -fprofile-arcs -g3
coverage : OFLAGS += -lgcov --coverage
coverage : func unit
	gcov $(SRCS) -o $(OBJDIR) -n
