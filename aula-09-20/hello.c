#include <stdio.h>
#include <stdlib.h>

char TEMPLATE_MSG[] = "hello to my friend %s\n";

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("usage: hello -u <username>\n");
		exit(1);:q
	}
	
	TEMPLATE_MSG[0] = 'H';
	printf(TEMPLATE_MSG, argv[2]);
	return 0;
}
