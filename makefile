# cphex\makefile

LIBS=-lsocket -lnsl
all:	cli	ser	udplib.o admin LibSerLPBB.o

udplib.o:	../udplib/udplib.h	../udplib/udplib.c
	echo "Compilation de udplib.o"
	gcc -c ../udplib/udplib.c	

cli:	cli.c	udplib.o LibSerLPBB.o
	echo "Compilation de client"
	gcc  -o cli  cli.c udplib.o LibSerLPBB.o $(LIBS)

ser:	ser.c	udplib.o LibSerLPBB.o
	echo "Compilation de serveur"
	gcc -o ser  ser.c udplib.o	LibSerLPBB.o $(LIBS)

LibSerLPBB.o: LibSerLPBB.c LibSerLPBB.h data.h
	echo "compilation de LibSerLPBB"
	gcc -c LibSerLPBB.c -Wall -m64

admin: data.h admin.c LibSerLPBB.o
	echo "Compilation de admin"
	gcc -o admin admin.c LibSerLPBB.o -Wall -m64
