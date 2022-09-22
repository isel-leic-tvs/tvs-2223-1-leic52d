/**
 * Opening a file twice. Confirm the file content after execution
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
	write(fd, "1234", 4);
	int fd1 = open(OUTFILE, O_WRONLY | O_CREAT, 0666);
	if (fd1 < 0) {
		perror("error creating file");
		return 1;
	}
	write(fd1, "1234", 4);
	close(fd);
	close(fd1);
	return 0;
}
