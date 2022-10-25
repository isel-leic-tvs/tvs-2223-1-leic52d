// client for libmath.so with dynamic linking in execution time
// observe smaps file in various pause points


#include <stdio.h>
#include <dlfcn.h>


typedef int (*count_calls_ptr)();

void  susp_point(char *msg) {
	printf("%s: press return to  continue...", msg);
	getchar();
}

int main() {
	susp_point("start");
	
	void *lib = dlopen("./libmath.so", RTLD_LAZY);
	if (lib == NULL) {
		perror("error loading library");
		return 1;
	}
	
	susp_point("after dl_open");
	
	count_calls_ptr ct_func  = (count_calls_ptr) dlsym(lib, "count_calls");
	if (ct_func == NULL) {
		perror("error getting func address");
		return 1;
	}
	
	susp_point("load symbol");

	
	int v= ct_func();
	printf("count_calls()=%d\n", v);
	
	dlclose(lib);
	
	susp_point("after close library");
	return 0;
}
