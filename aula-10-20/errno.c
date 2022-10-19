#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
 

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("usage: errno <num>\n");
		return 1;
	}
	
	errno = atoi(argv[1]);
	perror("error");
	
	return 0;
}
