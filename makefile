all: driver.o music.o linked_list.o
	gcc -o driver.out driver.o music.o linked_list.o
driver.o: driver.c music.h linked_list.h
	gcc -c -g driver.c music.h linked_list.h
music.o: music.c music.h
	gcc -c -g music.c music.h
linked_list.o: linked_list.c linked_list.h
	gcc -c -g linked_list.c linked_list.h

run:
	make
	./driver.out

clean:
	rm -f *.out *~ *.o *.gch
