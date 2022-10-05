
#include <unistd.h>

int my_write(int fd, const void *buf, int size);

int main() {
	my_write(1, "hello again!\n", 13);
	return 0;
}
