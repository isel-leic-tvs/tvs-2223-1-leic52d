#include <stdio.h>
#include <unistd.h>

#include <signal.h>


void sigint_handler(int signal) {
	printf("signal %d received\n", signal);
}

int main() {
	signal(SIGINT, sigint_handler);
	
	printf("start prog!\n");
	
	
	sleep(5);
	
	
	printf("end prog!\n");
}
