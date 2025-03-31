CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal
OFLAGS := 
VFLAGS := --leak-check=full --show-leak-kinds=all -q

SRCDIR := ./
OBJDIR := ./out/
UNITDIR := ../lab_10_03_common/

OBJS := $(OBJDIR)associative_array_impl_2.o $(OBJDIR)record.o $(OBJDIR)vector.o
UNIT_OBJS := $(OBJDIR)check_create.o $(OBJDIR)check_insert.o $(OBJDIR)check_remove.o $(OBJDIR)check_clear.o $(OBJDIR)check_destroy.o $(OBJDIR)check_find.o $(OBJDIR)check_each.o  $(OBJDIR)check_min.o $(OBJDIR)check_max.o
SRCS := $(wildcard $(SRCDIR)*.c)

unit_tests.exe : OFLAGS += -lcheck
unit_tests.exe : CFLAGS += -g3
unit_tests.exe : $(OBJS) $(UNIT_OBJS) $(OBJDIR)check_main.o
	$(CC) -o ./$@ $^ $(OFLAGS)

$(OBJDIR)associative_array_impl_2.o : $(SRCDIR)associative_array_impl_2.c $(UNITDIR)associative_array.h $(SRCDIR)vector.h $(SRCDIR)record.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)record.o : $(SRCDIR)record.c $(SRCDIR)record.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)vector.o : $(SRCDIR)vector.c $(SRCDIR)vector.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_create.o : $(UNITDIR)check_create.c $(UNITDIR)check_create.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_insert.o : $(UNITDIR)check_insert.c $(UNITDIR)check_insert.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_remove.o : $(UNITDIR)check_remove.c $(UNITDIR)check_remove.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_clear.o : $(UNITDIR)check_clear.c $(UNITDIR)check_clear.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_destroy.o : $(UNITDIR)check_destroy.c $(UNITDIR)check_destroy.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_find.o : $(UNITDIR)check_find.c $(UNITDIR)check_find.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_each.o : $(UNITDIR)check_each.c $(UNITDIR)check_each.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_min.o : $(UNITDIR)check_min.c $(UNITDIR)check_min.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_max.o : $(UNITDIR)check_max.c $(UNITDIR)check_max.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)check_main.o : $(UNITDIR)check_main.c $(UNITDIR)check_create.h $(UNITDIR)check_insert.h  $(UNITDIR)check_remove.h $(UNITDIR)check_clear.h $(UNITDIR)check_find.h $(UNITDIR)check_each.h $(UNITDIR)check_min.h $(UNITDIR)check_max.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : coverage
coverage : CFLAGS += -ftest-coverage -fprofile-arcs -g3 --coverage
coverage : OFLAGS += -lgcov 
coverage : clean unit
	gcov -s $(SRCDIR) --object-directory $(OBJDIR) $(SRCS)


.PHONY : | clean unit
unit : unit_tests.exe
	valgrind $(VFLAGS) --log-file=./out/valgrind_log.txt ./unit_tests.exe

.PHONY : clean
clean :	
	rm -fr ./out
	rm -f *.exe $(SRCDIR)*.d ./valgrind_unit_log.txt ./*.gcov