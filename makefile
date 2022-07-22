CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = chess
OBJECTS = main.o bishop.o board.o cell.o chesspiece.o computer.o game.o gui.o human.o king.o knight.o moves.o observer.o pawn.o player.o queen.o rook.o subject.o textdisplay.o types.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}


.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
