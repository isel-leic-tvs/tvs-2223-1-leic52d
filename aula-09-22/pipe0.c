/**
 * using (anonymous) pipes to child/parent communication
 * Comment the line 36 and explain the observed behaviour
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define WAIT_CHILD
#define MAX_MSG_SIZE 128

int main() {
	printf("parent process is %d\n", getpid());
	int p[2];
	
	pipe(p);
	
	int childproc = fork();
	
	if (childproc == 0) { // child
	 	
		sleep(5);
		
		char sendbuf[MAX_MSG_SIZE];
		
		snprintf(sendbuf,MAX_MSG_SIZE, "Hello parent from child %d", getpid());
		// enviar para o pipe
		write(p[1], sendbuf, strlen(sendbuf) +1);
		 
		printf("child termination...\n");
		exit(0);
	}
	close(p[1]);
	
	char rcvbuf[MAX_MSG_SIZE];
	
	//read(p[0], rcvbuf, MAX_MSG_SIZE);
	
	int tr = 0, nr;
	
	while (tr < MAX_MSG_SIZE && (nr = read(p[0], rcvbuf+tr, MAX_MSG_SIZE - tr)) > 0) {
		tr += nr;
		printf("%d bytes read!\n", nr);
		fflush(stdout);
	}
	
	printf("parent: received msg -> %s\n", rcvbuf);
	
#ifdef WAIT_CHILD
	waitpid(childproc, NULL, 0);
#endif
	
	printf("parent: press return to terminate...");
	getchar();
 
	return 0;
}
