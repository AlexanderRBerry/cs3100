dummy:
	@echo "Valid make options are:"
	@echo "   make null"
	@echo "   make nullgdb"
	@echo "   make nofree"
	@echo "   make bounds"
	@echo "   make datagone"
	@echo "   make freebad"
	@echo "   make clean"

.PHONY: null nullgdb nofree bounds datagone freebad all
null: null.c
	gcc -ggdb -Wall  -o $@ $@.c
	@echo "Running valgrind and logging to $@.log"
	-valgrind --log-file=$@.log --leak-check=yes ./$@
	@echo "----------------valgrind output for $@-----------------"
	@cat $@.log

nullgdb: null
	@echo "Running null under gdb and logging to $@.log"
	@/bin/echo -e "run\n" > $@.cmd
	gdb -batch -x $@.cmd ./null >$@.log 2>&1
	@rm $@.cmd
	@echo "----------------gdb output for $@-----------------"
	@cat $@.log

nofree: nofree.c
	gcc -ggdb -Wall  -o $@ $@.c
	@echo "Running valgrind and logging to $@.log"
	-valgrind --log-file=$@.log --leak-check=yes ./$@
	@echo "----------------valgrind output for $@-----------------"
	@cat $@.log

bounds: bounds.c
	gcc -ggdb -Wall  -o $@ $@.c
	@echo "Running valgrind and logging to $@.log"
	-valgrind --log-file=$@.log --leak-check=yes ./$@
	@echo "----------------valgrind output for $@-----------------"
	@cat $@.log

datagone: datagone.c
	gcc -ggdb -Wall  -o $@ $@.c
	@echo "Running valgrind and logging to $@.log"
	-valgrind --log-file=$@.log --leak-check=yes ./$@
	@echo "----------------valgrind output for $@-----------------"
	@cat $@.log

freebad: freebad.c
	gcc -ggdb -Wall  -o $@ $@.c
	@echo "Running valgrind and logging to $@.log"
	-valgrind --log-file=$@.log --leak-check=yes ./$@
	@echo "----------------valgrind output for $@-----------------"
	@cat $@.log

INFILES = null.c nofree.c bounds.c datagone.c freebad.c

OUTFILES = null.log nullgdb.log nofree.log bounds.log datagone.log freebad.log

clean:
	@echo "Deleting all executables and log files"
	-rm -f $(OUTFILES)
