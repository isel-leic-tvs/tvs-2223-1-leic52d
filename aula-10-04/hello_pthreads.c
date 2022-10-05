#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *func(void * arg) {
	pthread_t *parent = (pthread_t*) arg;
	
	sleep(3);
	printf("hello from pthread %ld with parent %ld (pid=%d)\n", pthread_self(), *parent, getpid() );
	return NULL;
}

int main() {
	pthread_t pthread;
	
	pthread_t parent = pthread_self();
	
	printf("main thread = %ld, pid=%d\n", pthread_self(), getpid());
	if (pthread_create(&pthread, NULL, func, &parent) != 0) {
		perror("error creating pthread");
		return 1;
	}

	
	if (pthread_join(pthread, NULL) != 0) {
		perror("error joining pthread");
	}
	
	return 0;
}
	
	
