#
# Link
#

CFLAGS = -Wall -g


bin/scale: obj/scale.o
	g++ $(CFLAGS) -lncurses -o $@ obj/scale.o


#
# Objets of TP Lists
#


obj/scale.o: src/scale.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/scale.cpp -o obj/scale.o

#
# Remove files
#

clean :
	rm obj/*.o bin/*


