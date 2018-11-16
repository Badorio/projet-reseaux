
# cphex\makefile

LIBS=
all:	admin	LibSerLPBB.o


LibSerLPBB.o:	LibSerLPBB.c	LibSerLPBB.h	data.h	
	echo "compilation de LibSerLPBB"
	gcc -c LibSerLPBB.c

admin:	data.h	admin.c	LibSerLPBB.o			
	echo "Compilation de admin"
	gcc -o admin	admin.c	LibSerLPBB.o 

