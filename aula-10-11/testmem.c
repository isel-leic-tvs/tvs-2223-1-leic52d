#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 

#define PAGE_SIZE 4096
#define DATA_SIZE (30*1024*1024)

long data[DATA_SIZE]  = { 4 };


void  susp_point(char *msg) {
	printf("%s: press return to  continue...", msg);
	getchar();
}


void fill_data(int start, int size, int val) {
	for(int i=0; i < size; ++i) {
		data[i] = val;
	}
}


long sum_data(int start, int size) {
	long sum = 0;
	for(int i=0; i < size; ++i) {
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
	
	fill_data(0, DATA_SIZE/2, 1);
	 
	susp_point("after data fill");
	
	return 0;
}
