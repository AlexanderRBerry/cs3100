Feature: Source file must be present, compilable and output correct information

	Background: disksked.c compilable w/o errors or warnings
		When I run `rm ../../bin/*`
		Then I run `cp ../../disksked.c ../../bin/`
		Then a file named "../../bin/disksked.c" should exist
		When I run `gcc -std=c99 -Wall -Werror -o ../../bin/disksked ../../bin/disksked.c` 
		And OUTPUT is printed
		Then a file named "../../bin/disksked" should exist

	Scenario: disksked correctly reports FCFS multiple times
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		Then 25 points are awarded

	Scenario: disksked correctly reports SSTF multiple times
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SSTF report
		Then 25 points are awarded

	Scenario: disksked correctly reports SCAN multiple times
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct SCAN report
		Then 25 points are awarded

	Scenario: disksked correctly reports C_SCAN multiple times
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		And OUTPUT is printed
		Then the stdout should contain the correct C_SCAN report
		Then 25 points are awarded

