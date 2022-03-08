biblio_num : ajouter_livres.o livres.o adherants.o emprunter.o deposer.o liste_emprunts.o liste_adherants.o gestion.o bibliotheque.o 
	gcc -o biblio_num ajouter_livres.o livres.o adherants.o emprunter.o deposer.o liste_emprunts.o liste_adherants.o gestion.o bibliotheque.o -L. -lmysqlclient

ajouter_livres.o : ajouter_livres.c
	gcc -c ajouter_livres.c

livres.o : livres.c
	gcc -c livres.c

adherants.o : adherants.c
	gcc -c adherants.c

emprunter.o : emprunter.c
	gcc -c emprunter.c

deposer.o : deposer.c
	gcc -c deposer.c

liste_emprunts.o : liste_emprunts.c
	gcc -c liste_emprunts.c

liste_adherants.o : liste_adherants.c
	gcc -c liste_adherants.c

gestion.o : gestion.c
	gcc -c gestion.c

bibliotheque.o : bibliotheque.c
	gcc -c bibliotheque.c

clean:
	rm *.o biblio_num