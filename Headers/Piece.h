#pragma once
#include "Board.h"
#include <vector>

class Piece {
public:

	Piece() : piece_ID(0), square(0), X(0), Y(0), COLOR(false) {}; // Initializing member variables.
	virtual vector<int> legal_squares(Board&) = 0; // Not defining it as a pure virtual function (thus abstract class)
												   // would result in LINKing error. seeks function definition maybe?!
	virtual vector<int> check_squares() { return vector<int>{}; }; // For pawn only. TRUE POWER OF POLYMORPHISM! VIRTUAL!!!
	virtual vector<int> take_squares(Board&) { return vector<int>{}; }; // For pawns
	virtual vector<int> under_control() { return vector<int>{}; }; // For kings

	bool is_legal(Board& board, int dst) {
		for (int x : legal_squares(board)) {
			if (x == dst) return true;
		}
		return false;
	};

	void remove_piece(Board& board) {
		board.removed_pieces.push_back(this);
		board.pieces[Y][X] = nullptr;
	}

	void move(Board& board, int dst) { // No similar function in child classes, so no "virtual" needed.
		if (is_legal(board, dst)) {
			// cout << colors[COLOR] << " " << piece_names[this->piece_ID - 1] << " to square " << dst << endl;
			board.prev_square = square; // saving for taking the move back.
			board.prev_piece = board.pieces[Y][X];
			board.pieces[Y][X] = nullptr;

			square = dst;
			X = (square - 1) % 8;
			Y = (square - 1) / 8;
			if (board.pieces[Y][X])
				board.pieces[Y][X]->remove_piece(board);
			board.pieces[Y][X] = this;
		}
	};

	bool is_checker(Board& board) {
		if (piece_ID == 6) return false;
		vector<int> squares{};

		if (piece_ID == 1) squares = check_squares();
		else squares = legal_squares(board);

		for (auto& sq : squares) {
			int sq_X = (sq - 1) % 8;
			int sq_Y = (sq - 1) / 8;
			if (board.pieces[sq_Y][sq_X])
				if (board.pieces[sq_Y][sq_X]->COLOR != COLOR &&
					board.pieces[sq_Y][sq_X]->piece_ID == 6) // Opposite color king
					return true;
		}
		return false;
	}

	vector<string> piece_names{ "Pawn", "Knight", "Bishop", "Rook", "Queen", "King" };
	vector<string> colors{ "Black", "White" };
	int piece_ID; // Pawn: 1 | Knight: 2 | Bishop: 3 | Rook: 4 | Queen: 5 | King: 6
	int square;   // 1 - 64
	int X; // 0,...,7 // Piece is in board.pieces[Y][X];
	int Y; // 0,...,7
	bool COLOR; // 0, 1
	// ??? Have a board object.
};