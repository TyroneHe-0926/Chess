CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Wno-narrowing -g
EXEC = chess
OBJECTS = main.o bishop.o board.o cell.o chesspiece.o computer.o game.o gui.o human.o king.o knight.o moves.o pawn.o player.o queen.o rook.o textdisplay.o types.o sdl_wrap.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lSDL2 -lSDL2_image -lSDL2_ttf

-include ${DEPENDS}


.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
