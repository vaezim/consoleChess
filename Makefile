
output: main.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o Board.o
	g++ main.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o Board.o -o output

main.o: main.cpp
	g++ -c main.cpp

Pawn.o: Pawn.cpp Pawn.h Piece.h
	g++ -c Pawn.cpp

Knight.o: Knight.cpp Knight.h Piece.h
	g++ -c Knight.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h
	g++ -c Bishop.cpp

Rook.o: Rook.cpp Rook.h Piece.h
	g++ -c Rook.cpp

Queen.o: Queen.cpp Queen.h Piece.h
	g++ -c Queen.cpp

King.o: King.cpp King.h Piece.h
	g++ -c King.cpp

Board.o: Board.cpp Board.h Piece.h
	g++ -c Board.cpp

clean:
	rm *.o output