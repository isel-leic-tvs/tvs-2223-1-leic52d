/**----------------------------------------------
 * utilização da API tradicional de acesso a ficheiros
 * para criar um ficheiro binário de inteiros de 1 a NUMBERS_COUNT
 * 
 * JMartins, outubro de 2022
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "filespecs.h"

 
int main() {
	int fd = open(INTS_FILENAME, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0) {
		perror("error creating numbers file");
		return 1;
	}
	for(int i= 0; i < NUMBERS_COUNT; ++i) {
		write(fd, &i, sizeof(int));
	}
	
	close(fd);
	return 0;
}
