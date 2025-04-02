Feature: Source file must be present, compilable and output correct information

	Scenario: lab1.c must be found
		When I run `rm ../../bin/*`
		And OUTPUT is printed
		Then I run `cp ../../lab1.c ../../bin/`
		And OUTPUT is printed
		Then a file named "../../bin/lab1.c" should exist
		Then 10 points are awarded

	Scenario: lab1.c must be compilable with no errors
		When I run `gcc -o ../../bin/lab1 ../../bin/lab1.c` 
		And OUTPUT is printed
		Then a file named "../../bin/lab1" should exist
		Then 10 points are awarded

	Scenario: lab1 should issue no stderr messages if rc=0
		When I run `lab1 -n someoldstring`
		And OUTPUT is printed
		Then the exit status should be 0
		And the stderr should not contain anything 
		Then 10 points are awarded
		
	Scenario: lab1 should issue error message if -n STRING is missing
		When I run `lab1`
		And OUTPUT is printed
		Then the exit status should not be 0
		And the output should contain "Usage:"
		And I run `lab1 -n`
		And the exit status should not be 0
		And the output should contain "Usage:"
		Then 15 points are awarded

	Scenario: lab1 should print Welcome to Lab1, writen by USER
		When I run `lab1 -n fozziebear`
		And OUTPUT is printed
		And the output should contain the pid/ppid
		Then 10 points are awarded

	Scenario: lab1 should print the welcome string
		When I run `lab1 -n fozziebear`
		And OUTPUT is printed
		And the output should match /Welcome to [Ll]ab 1, written by fozziebear/
		Then 10 points are awarded

	Scenario: lab1 should print the hostname
		When I run `lab1 -n fozziebear`
		And OUTPUT is printed
		And the output should contain the host name 
		Then 10 points are awarded

	Scenario: lab1 should correctly print its pgm name from argv[0]
		When I run `cp ../../bin/lab1 ../../bin/lab1renamed`
		And I run `lab1renamed -n teddy`
		And OUTPUT is printed
		And the output should contain "Program: "
		And the output should contain "lab1renamed"
		Then 10 points are awarded

	Scenario: lab1 should contain a function called usage(char *)
		When I run `gcc -c ../../bin/lab1.c -o lab1.o`
		And OUTPUT is printed
		And I run `nm lab1.o`
		And the output should contain "T usage"
		Then 15 points are awarded
