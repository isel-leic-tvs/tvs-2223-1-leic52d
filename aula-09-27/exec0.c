#include <stdio.h>
#include <unistd.h>

int main() {
	printf("my pid: %d\n", getpid());
	
	execlp("cat", "cat", NULL);
	
	printf("cat done!\n");
	
	return 0;
}
