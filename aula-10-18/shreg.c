/**--------------------------------------------
 * Utilização de mmap para criar uma região de memória
 * partilhada (anónima) entre pai e filho
 * 
 * JMartins, outubro 2022
 *-------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdlib.h>

#include <stdint.h>

#define REG_SIZE (1000*1000*32)

typedef uint8_t byte;


// para poder observar os efeitos no correspondente "smaps"
void  susp_point(char *msg) {
	printf("%s: press return to  continue...", msg);
	getchar();
}

void fill_data(byte* data, int size, int val) {
	for(int i=0; i < size; ++i) {
		data[i] = val;
	}
}

int sum_data(byte* data, int size) {
	int sum = 0;
	for(int i=0; i < size; ++i) {
		sum += data[i];
	}
	return sum;
}

int main() {
 
	printf("my pid is %d\n", getpid());
	 
	susp_point("initial()");
		
	byte *mapbase = (byte*) mmap(NULL, REG_SIZE, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1 ,0);
	if (mapbase == MAP_FAILED) {
		perror("error mapping numbers file");
		return 3;
	}
	printf("memory papped at %p\n", mapbase);
	susp_point("after memory mapping");
	
	// pai: escrever na região de memória partilhada
	fill_data(mapbase, REG_SIZE, 1);
	
	susp_point("after memory fill");
	
	int pid;
	if ((pid=fork()) == 0) {
		susp_point("child: on start");
		
		byte *mapbasec = (byte*) mmap(NULL, REG_SIZE, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1 , 0);
		if (mapbasec == MAP_FAILED) {
			perror("child: error mapping numbers file");
			exit(1);  
		}
		// ler da região de meória partilhada
		int res = sum_data(mapbase, REG_SIZE);
		printf("child: data region sum = %d\n", res);
	
		susp_point("child: after data sum");
		
		// escrever na região de memória partilhada
		fill_data(mapbase, REG_SIZE/2, 2);
	 
		susp_point("child: after data fill");
		exit(0);
	}
	else {
		printf("parent: child pid is %d\n", pid);
		wait(NULL);
	}
	susp_point("parent: after child termination");
	
	// pai: ler da região de meória partilhada
	int res = sum_data(mapbase, REG_SIZE);	
	printf("parent: data region sum = %d\n", res);
	
	susp_point("parent: before termination");
	return 0;
	
}

