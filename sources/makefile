main : lire.o livres.o clients.o action_client.o gestion.o main.o
	gcc -o main lire.o livres.o clients.o action_client.o gestion.o main.o -L. -lmysqlclient

livres.o : livres.c
	gcc -c livres.c

clients.o : clients.c
	gcc -c clients.c

action_client.o : action_client.c
	gcc -c action_client.c

gestion.o : gestion.c
	gcc -c gestion.c

lire.o : lire.c
	gcc -c lire.c

main.o : main.c
	gcc -c main.c

clean:
	rm *.o main