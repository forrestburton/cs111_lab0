#NAME: Forrest Burton
#EMAIL: burton.forrest10@gmail.com
#ID: 005324612


default:
		gcc -g -Wall -Wextra -o lab0 lab0.c

clean:
		rm -f lab0 *tar.gz

dist:
		tar -czvf lab0-005324612.tar.gz lab0.c Makefile README backtrace.png breakpoint.png

check:
		./test.sh
		
	




		



