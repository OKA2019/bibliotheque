lib :
	ar crs librairie.a main.o sources/lire.o sources/livres.o sources/clients.o sources/action_client.o sources/gestion.o

main : sources/lire.o sources/livres.o sources/clients.o sources/action_client.o sources/gestion.o main.o
	gcc -o main sources/lire.o sources/livres.o sources/clients.o sources/action_client.o sources/gestion.o main.o -L. -lmysqlclient

livres.o : sources/livres.c
	gcc -c sources/livres.c

clients.o : sources/clients.c
	gcc -c sources/clients.c

action_client.o : sources/action_client.c
	gcc -c sources/action_client.c

gestion.o : sources/gestion.c
	gcc -c sources/gestion.c

lire.o : sources/lire.c
	gcc -c sources/lire.c

main.o : sources/main.c
	gcc -c sources/main.c

clean:
	rm main sources/*.o