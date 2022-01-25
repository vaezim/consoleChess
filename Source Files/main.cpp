#include <iostream>
#include "Board.h"
#include "Piece.h" // "Board.h" does not include "Piece.h" (Error C4430).

void disp(vector<int> v) {
	for (auto& x : v)
		cout << x << ", ";
	cout << endl;
}

int main() {

	Board board;
	board.setup_board();
	board.play();
}
