#include <stdio.h>
#include <unistd.h>

// ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);


#define SELF_FILE "/proc/self"
#define MAX_BUFFER 128

int main() {
	char buf[MAX_BUFFER];
	int path_size = readlink(SELF_FILE, buf, MAX_BUFFER);
	
	 
	printf("my pid is %d\n", getpid());
	buf[path_size] = 0;
	
	if (path_size <= 0)  {
		perror("error reading /proc/self");
		return 1;
	}
	
	printf("/proc/self links to %s\n", buf);
	
	printf("press enter to terminate...");
	getchar();
	return 0;
}
