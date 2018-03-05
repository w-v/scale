#
# Link
#

CFLAGS = -Wall -g

single: obj/scale.o obj/world.o
	g++ $(CFLAGS) -lncurses -o $@ obj/scale.o obj/world.o

bin/scale: obj/scale.o obj/entity.o obj/utils.o obj/vec2.o obj/displayable.o obj/world.o
	g++ $(CFLAGS) -lncurses -o $@ obj/scale.o obj/utils.o obj/entity.o obj/vec2.o obj/displayable.o obj/world.o


#
# Objets 
#


obj/scale.o: src/scale.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/scale.cpp -o obj/scale.o

obj/entity.o: src/entity.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/entity.cpp -o obj/entity.o

obj/utils.o: src/utils.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/utils.cpp -o obj/utils.o

obj/vec2.o: src/vec2.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/vec2.cpp -o obj/vec2.o

obj/displayable.o: src/displayable.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/displayable.cpp -o obj/displayable.o

obj/world.o: src/world.cpp
	g++ $(CFLAGS) -lncurses -I./include -c src/world.cpp -o obj/world.o

#
# Remove files
#

clean :
	rm obj/*.o bin/*


