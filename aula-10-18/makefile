all: genintsfile genintsfile2 mapintsfile shreg

CFLAGS=-g -Wall

genintsfile: genintsfile.c filespecs.h
	gcc -o genintsfile $(CFLAGS) genintsfile.c
	
genintsfile2: genintsfile2.c filespecs.h
	gcc -o genintsfile2 $(CFLAGS) genintsfile2.c

mapintsfile: mapintsfile.c filespecs.h
	gcc -o mapintsfile $(CFLAGS) mapintsfile.c


shreg: shreg.c 
	gcc -o shreg $(CFLAGS) shreg.c
	
clean:
	rm -rf genintsfile genintsfile2 mapintsfile shreg
	
