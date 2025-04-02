Feature: Source files must be present, compilable and output correct information

	Background: all source files are found and compile without errors or warnings
		Given a file named "../../dining.c" should exist
		Given I run `rm -f ../../bin/*`
		When I run `gcc -ggdb -Wall -Werror -pthread -o ../../bin/dining ../../dining.c ../../dininglib.o` 
		And OUTPUT is printed
		Then a file named "../../bin/dining" should exist
		And 0 points are awarded

	Scenario: No errors found
		Given I run `dining 5 3`
		And OUTPUT is printed
		And the output should match /^Total error count:0\s*$/
		And 40 points are awarded

	Scenario: Ranges < 5%
		Given I run `dining 3 3`
		And OUTPUT is printed
		Then the output should match /Percent Dining Count Range:[0-4]\./
		And 20 points are awarded
		And the output should match /Percent Thinking Count Range:[0-4]\./
		And 20 points are awarded
		And the output should match /Percent Waiting Count Range:[0-4]\./
		And 20 points are awarded
	
	Scenario: All philosophers think, dine and wait (APIs are being used)
		Given I run `dining 9 3`
		And OUTPUT is printed
		Then the stdout should not contain "Lowest Dining Count:0"
		And 20 points are awarded
		And the stdout should not contain "Lowest Thinking Count:0"
		And 20 points are awarded
		And the stdout should not contain "Lowest Waiting Count:0"
		And 20 points are awarded
		And 40 points are awarded
