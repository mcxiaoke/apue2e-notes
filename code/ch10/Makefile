a.out : abort_demo.c libabort.a
	gcc abort_demo.c -L. -labort

libabort.a : abort.o
	ar crvs libabort.a abort.o

abort.o : abort.h

.PHONY: lib demo clean

lib : libabort.a

run : a.out
	./a.out

clean :
	-rm *.a *.o a.out
