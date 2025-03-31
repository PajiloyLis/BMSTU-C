CC := gcc

PYTHON := python3

APPDIR := ./app/
LIBDIR := ./lib/

run : $(APPDIR)app.py task.so
	$(PYTHON) $(APPDIR)app.py

task.so : 
	make -C $(LIBDIR)

.PHONY : clean
clean : 
	rm -rf ./app/__pycache__