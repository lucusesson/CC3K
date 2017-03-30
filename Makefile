CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -Werror=vla
OBJECTS=main.o Character.o Enemy.o Gold.o grid.o Player.o Potion.o subject.o tile.o window.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q1
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm *.o
.PHONY: clean