Feature: Source files must be present, compilable and output correct information

	Scenario: required files must have been found in the root directory
		When a file named "../../syscall.c" should exist
		And a file named "../../syscall.h" should exist
		And a file named "../../sysproc.c" should exist
		And a file named "../../trap.c" should exist
		And a file named "../../user.h" should exist
		And a file named "../../usys.S" should exist
		And I run `bash -c 'cp ../../peep.c ../../syscall.c ../../syscall.h ../../sysproc.c ../../trap.c ../../user.h ../../usys.S ../../xv6-public/ '`
		Then 10 points are awarded

	Scenario: xv6 must be compilable with no errors
		When I run `bash -c 'cd ../../xv6-public; make clean; make'` 
		And OUTPUT is printed
		Then a file named "../../xv6-public/xv6.img" should exist
		Then 10 points are awarded
		Then I run `killall qemu-system-i386`

	Scenario: xv6 under qemu should issue the appropriate prompt
		When I run `bash -c 'cd ../../xv6-public; make qemu-nox'` interactively
		And OUTPUT is printed
		Then the output should contain "$"
		Then 10 points are awarded
		Then I run `killall qemu-system-i386`
		
	Scenario: peep should return success
		When I run `bash -c 'cd ../../xv6-public; make qemu-nox'` interactively
		# qemu eats the first character typed for some reason
		And I type " "
		And I type "peep 50"
		And OUTPUT is printed
		Then the output should contain "Success"
		Then 170 points are awarded
		Then I run `killall qemu-system-i386`
		
