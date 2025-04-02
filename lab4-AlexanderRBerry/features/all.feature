Feature: Source files must be present, compilable and output correct information

	Scenario: required files must be found in the root of the repo
		When a file named "../../null.c" should exist
		And a file named "../../nofree.c" should exist
		And a file named "../../bounds.c" should exist
		And a file named "../../datagone.c" should exist
		And a file named "../../freebad.c" should exist
		Then 5 points are awarded

	Scenario: all source files compile without errors
		Given I run `rm -f ../../bin/*`
		When I run `gcc -ggdb -Wall  -o ../../bin/null ../../null.c` 
		And OUTPUT is printed
		And I run `gcc -ggdb -Wall  -o ../../bin/nofree ../../nofree.c` 
		And OUTPUT is printed
		And I run `gcc -ggdb -Wall  -o ../../bin/bounds ../../bounds.c` 
		And OUTPUT is printed
		And I run `gcc -ggdb -Wall  -o ../../bin/datagone ../../datagone.c` 
		And OUTPUT is printed
		And I run `gcc -ggdb -Wall  -o ../../bin/freebad ../../freebad.c` 
		And OUTPUT is printed
		Then a file named "../../bin/null" should exist
		And a file named "../../bin/nofree" should exist
		And a file named "../../bin/bounds" should exist
		And a file named "../../bin/datagone" should exist
		And a file named "../../bin/freebad" should exist
		Then 20 points are awarded

	Scenario: null crashes when run
		When I run `null`
		And OUTPUT is printed
		Then the exit status should not be 0
		Then 25 points are awarded

	Scenario: null.log contains "Invalid write of size 4"
		When I run `valgrind --log-file=null.log --leak-check=yes null`
		And OUTPUT is printed
		Then the file named "null.log" should contain "Invalid write of size 4"
		Then 25 points are awarded

	Scenario: nofree.log contains "1,024 bytes in 1 blocks are definitely lost"
		When I run `valgrind --log-file=nofree.log --leak-check=yes nofree`
		And OUTPUT is printed
		Then the file named "nofree.log" should contain "1,024 bytes in 1 blocks are definitely lost"
		Then 25 points are awarded

	Scenario: bounds.log contains "Invalid write of size 4"
		When I run `valgrind --log-file=bounds.log --leak-check=yes bounds`
		And OUTPUT is printed
		Then the file named "bounds.log" should contain "Invalid write of size 4"
		Then 25 points are awarded

	Scenario: datagone.log contains "Invalid read of size 4"
		When I run `valgrind --log-file=datagone.log --leak-check=yes datagone`
		And OUTPUT is printed
		Then the file named "datagone.log" should contain "Invalid read of size 4"
		Then 25 points are awarded

	Scenario: freebad.log contains "Invalid free()"
		When I run `valgrind --log-file=freebad.log --leak-check=yes freebad`
		And OUTPUT is printed
		Then the file named "freebad.log" should contain "Invalid free()"
		Then 25 points are awarded

	Scenario: nullgdb.log contains "Program received signal SIGSEGV"
		Given a file named "nullgdb.cmd" with:
		"""
		run
		"""
		When I run `gdb -batch -x nullgdb.cmd null`
		And OUTPUT is printed
		Then the output should contain "Program received signal SIGSEGV"
		Then 25 points are awarded



