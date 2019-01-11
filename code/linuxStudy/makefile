
objects = main.o open.o fcntl_write.o

linuxStudy: $(objects) 

	gcc -o linuxStudy $(objects)

main.o:main.c
	gcc -c main.c

open.o:open.c
	gcc -c open.c open.h

fcntl_write.o:fcntl_write.c fcntl_write.h
	gcc -c fcntl_write.c fcntl_write.h

clean:
	-rm linuxStudy $(objects)
