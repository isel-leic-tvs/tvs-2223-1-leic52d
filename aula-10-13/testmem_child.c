/**
 * Build normally (without static linking)
 *  
 * Use /proc/meminfo to observe avaiable memory on waiting points
 * from child and parent. 
 * Note the COW (Copy on Write) semantics applied to .data region
 * 
 * Repeat observation using now the more detailed /proc/<parent_pid>/smaps
 * and /proc/<child_pid>/smaps, namely the Rss: line from both parent and child
 * at waiting points.
 */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
 

#define PAGE_SIZE 4096
#define DATA_SIZE (30*1024*1024)

long data[DATA_SIZE]  = { 4 };


void  susp_point(char *msg) {
	printf("%s: press return to  continue...", msg);
	getchar();
}


void fill_data(int start, int size, int val) {
	for(int i = start; i < size; ++i) {
		data[i] = val;
	}
}


long sum_data(int start, int size) {
	long sum = 0;
	for(int i=start; i < size; ++i) {
		sum += data[i];
	}
	return sum;
}


int main() {
	char pidmsg[64];  
	snprintf(pidmsg, 64, "my pid is %d\n", getpid());
	write(STDOUT_FILENO, pidmsg, strlen(pidmsg));
	
	printf("main address = %p\n", main);
	printf("data address = %p\n", data);
	
	susp_point("on start");
	
	long res = sum_data(0, DATA_SIZE/2);
	printf("data region sum = %ld\n", res);
 
	susp_point("after data sum");
	 
	
	if (fork()==0) { // child
		printf("child: main address = %p\n", main);
		printf("child: data address = %p\n", data);
		susp_point("child: on start");
		long res = sum_data(0, DATA_SIZE/2);
		printf("child: data region sum = %ld\n", res);
	
		susp_point("child: after data sum");
		
		fill_data(0, DATA_SIZE/2, 1);
	 
		susp_point("child: after data fill");
		exit(0);
	}
	
	wait(NULL);
	
	susp_point("parent: terminate");
	return 0;
}
