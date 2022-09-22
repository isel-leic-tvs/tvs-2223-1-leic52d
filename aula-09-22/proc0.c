/**
 * creating a new process
 */

#include <stdio.h>
#include <unistd.h>


int main() {
	printf("parent process is %d\n", getpid());
	
	fork();
	
	printf("my process id is %d\n", getpid());
	
	return 0;
}
