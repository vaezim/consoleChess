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

	/*
	Board board;
	King k1(61, 0);
	King k2(45, 1);
	
	board.insert_piece(&k1);
	board.insert_piece(&k2);

	cout << "King: ";
	for (auto& x : k1.legal_squares(board))
		cout << x << ", ";
	cout << endl;
	cout << "King: ";
	for (auto& x : k2.legal_squares(board))
		cout << x << ", ";
	cout << endl;
	*/
}