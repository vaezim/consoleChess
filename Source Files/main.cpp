#include <iostream>
#include "Board.h"
#include "Piece.h" // "Board.h" does not include "Piece.h" (Error C4430).

int main() {

	Board board;
	board.setup_board();
	board.play();
}
