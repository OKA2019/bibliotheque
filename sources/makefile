SIGL_biblio : livres.o adherants.o emprunter.o deposer.o bibliotheque.o 
	gcc -o SIGL_biblio livres.o adherants.o emprunter.o deposer.o bibliotheque.o -L. -lmysqlclient

livres.o : livres.c
	gcc -c livres.c

adherants.o : adherants.c
	gcc -c adherants.c

emprunter.o : emprunter.c
	gcc -c emprunter.c

deposer.o : deposer.c
	gcc -c deposer.c

bibliotheque.o : bibliotheque.c
	gcc -c bibliotheque.c

clean:
	rm *.o SIGL_biblio