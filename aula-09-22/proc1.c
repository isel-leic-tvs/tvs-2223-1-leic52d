/**
 * creating a new process
 * 
 * Wait (or not) the child termination
 * uncommenting/commenting the define below
 * 
 * check the child state executing  ps ax on another terminal
 * 
 * Confirm the processes isolation checking the observed "val" value 
 * on both processes
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//#define WAIT_CHILD

int main() {
	printf("parent process is %d\n", getpid());
	int val = 3;
	int childproc = fork();
	
	if (childproc == 0) { // child
		printf("child: val = %d\n", val);
		
		sleep(5);
		val = 10;
		printf("child: val after slepp = %d\n", val);
		printf("my process id is %d\n", getpid());
		printf("my parent id is %d\n", getppid());
		printf("child termination...\n");
		exit(0);
	}
	
#ifdef WAIT_CHILD
	waitpid(childproc, NULL, 0);
#endif

	// if >WAIT_CHILD is not defined:
	// what happens if parent ends before child?
	// what happens if child ends before parent?
	printf("parent: press return to terminate...");
	getchar();
#ifdef WAIT_CHILD	
	printf("val after child termination: %d\n", val);
#endif
	return 0;
}
