all: reader writer libmath.so errno client client_dyn waster

CFLAGS= -g -Wall 

reader: reader.c
	gcc -o reader $(CFLAGS) reader.c

writer: writer.c
	gcc -o writer $(CFLAGS) writer.c
	
errno: errno.c
	gcc -o errno $(CFLAGS) errno.c
	
libmath.so: math.c
	gcc -o libmath.so $(CFLAGS) -fpic math.c -shared
		
client: client.c
	gcc -o client $(CFLAGS) client.c ./libmath.so


client_dyn: client_dyn.c
	gcc -o client_dyn $(CFLAGS) client_dyn.c
	
waster: waster.c
	gcc -o waster $(CFLAGS) waster.c
	
clean:
	rm -rf reader writer libmath.so errno client client_dyn waster
