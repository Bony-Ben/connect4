VPATH=players

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -O3
EXEC = connect4
OBJECTS = main.o game.o board.o human.o
#add graphicsobserver.o window.o for graphic display
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}