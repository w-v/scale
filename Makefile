#
# Link
#

CFLAGS = -Wall -g

bin/initialize: obj/initialize.o
	gcc $(CFLAGS) -o bin/initialize obj/initialize.o

bin/tp3: obj/tp3.o
	gcc $(CFLAGS) -o bin/tp3 obj/tp3.o

bin/nettoie: obj/nettoie.o
	gcc $(CFLAGS) -o bin/nettoie obj/nettoie.o

#
# Objets of TP Lists
#

obj/initialize.o: src/initialize.c
	gcc $(CFLAGS) -I./include -c src/initialize.c -o obj/initialize.o

obj/tp3.o: src/tp3.c
	gcc $(CFLAGS) -I./include -c src/tp3.c -o obj/tp3.o

obj/nettoie.o: src/nettoie.c
	gcc $(CFLAGS) -I./include -c src/nettoie.c -o obj/nettoie.o
#
# Remove files
#

clean :
	rm obj/*.o bin/*


