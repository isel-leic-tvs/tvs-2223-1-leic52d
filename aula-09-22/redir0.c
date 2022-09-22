/**
 * redirecting arbitrary descriptors by closing and duplication 
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define OUTFILE "out.txt"

int main() {
	int fd = open(OUTFILE, O_WRONLY | O_CREAT, 0666);
	if (fd < 0) {
		perror("error creating file");
		return 1;
	}
	
	
	// redireccionar output standard
	//close(STDOUT_FILENO);
	//dup(fd);
	dup2(fd, 1);
	
	printf("redirected output\n");
	fflush(stdout);
	
	//recover original standard output from standard error
	dup2(2, 1);
	printf("output to original stdout\n");
	
	fprintf(stderr, "where is my error displyaed?\n");
	close(fd);
	 
	return 0;
}
