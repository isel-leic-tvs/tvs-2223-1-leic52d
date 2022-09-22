/**
 * Opening a file and duplicate his descriptor. 
 * Confirm the file content after execution
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
	printf("fd=%d\n", fd);
	write(fd, "1234", 4);
	
	// duplicate file descriptor and 
	// use the new descrptor to write on file
	
	int fd1 = dup(fd);
	printf("fd1=%d\n", fd1);
	
	 
	if (fd1 < 0) {
		perror("error duplicate file");
		return 1;
	}
	write(fd1, "1234", 4);
	close(fd);
	close(fd1);
	return 0;
}
