#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
	printf("my pid: %d\n", getpid());
	
	int fd = open("out.txt", O_CREAT | O_WRONLY, 0666);
	
	printf("file open with descriptor %d\n", fd);
	int child_proc = fork();
	
	if (child_proc == 0) { // child process
		
		fcntl(fd, F_SETFD, FD_CLOEXEC);
		char *parms[] = {
			"cat",
			NULL
		};
		
		//execlp("cat", "cat", NULL);
		execvp("cat", parms);
	
		perror("error execing cmd");
	
		exit(1);
	}
	else {
		int status;
		waitpid(child_proc, &status, 0);
		
		printf("cat done!\n");
	}
	return 0;
}
