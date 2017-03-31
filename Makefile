CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -Werror=vla
OBJECTS=main.o Character.o Item.o Enemy.o Gold.o Player.o Potion.o subject.o game.o grid.o tile.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=CC3K
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
-include ${DEPENDS}

clean:
	rm *.o
.PHONY: clean
