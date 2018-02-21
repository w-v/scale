#
# Link
#

CFLAGS = -Wall -g


bin/scale: obj/scale.o obj/entity.o obj/utils.o
	g++ $(CFLAGS) -lncurses -o $@ obj/scale.o obj/utils.o obj/entity.o


#
# Objets 
#


obj/scale.o: src/scale.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/scale.cpp -o obj/scale.o

obj/entity.o: src/entity.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/entity.cpp -o obj/entity.o

obj/utils.o: src/utils.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/utils.cpp -o obj/utils.o

#
# Remove files
#

clean :
	rm obj/*.o bin/*


