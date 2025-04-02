Feature: Source file must be present, compilable and output correct information

	Scenario: hello.c must be found
		When I run `cp ../../hello.c ../../bin/`
		And OUTPUT is printed
		Then a file named "../../bin/hello.c" should exist
		Then 25 points are awarded

	Scenario: hello.c must be compilable with no errors
		When I run `gcc -o ../../bin/hello ../../bin/hello.c` 
		And OUTPUT is printed
		Then a file named "../../bin/hello" should exist
		Then 25 points are awarded

	Scenario: hello should print "Hello World!"
		When I run `hello`
		And OUTPUT is printed
		Then the output should match /[Hh]ello.*[Ww]orld/
		Then 50 points are awarded
