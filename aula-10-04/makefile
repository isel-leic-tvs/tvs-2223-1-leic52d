all : hello_pthreads usewrite

CFLAGS=-g -Wall

hello_pthreads: hello_pthreads.c
	gcc -o hello_pthreads $(C_FLAGS) hello_pthreads.c
	
mywrite.o: mywrite.s
	gcc -c  mywrite.s
	
usewrite: usewrite.c mywrite.o
	gcc -o usewrite $(CFLAGS) usewrite.c mywrite.o

clean:
	rm -rf *.o usewrite hello_pthreads
