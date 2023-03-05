

but : taquin

OFILES = menu.o \
				 partie.o\
				 main_taquin.o

CC = gcc



CFLAGS =  -pedantic -g -lgraph  

menu.o : menu.h


main_taquin.o : menu.h  partie.h

 

taquin : $(OFILES)
	$(CC) -o taquin $(OFILES)  $(CFLAGS) 


clean :
	-rm -f $(OFILES) taquin

run: 
	./taquin


.PHONY : but clean
