#include "Rook.h"


Rook::Rook(int sq, bool c) {
	// Check sq and error if wrong!
	piece_ID = 4;
	square = sq;
	COLOR = c;
	X = (square - 1) % 8;
	Y = (square - 1) / 8;
}

vector<int> Rook::legal_squares(Board& board) {
	vector<int> legal_sqs{};

	int tmp_X = X;
	int tmp_Y = Y;
	while (tmp_X > 0) { // Down
		tmp_X--;
		if (!board.pieces[tmp_Y][tmp_X] || (board.pieces[tmp_Y][tmp_X] &&
			board.pieces[tmp_Y][tmp_X]->COLOR != COLOR))
			if (board.pieces[tmp_Y][tmp_X] && (board.pieces[tmp_Y][tmp_X]->piece_ID != 6)) // If it is not a KING
				legal_sqs.push_back(tmp_Y * 8 + tmp_X + 1);
		else
			break;
	}

	tmp_X = X;
	tmp_Y = Y;
	while (tmp_X < 7) { // Up
		tmp_X++;
		if (!board.pieces[tmp_Y][tmp_X] || (board.pieces[tmp_Y][tmp_X] &&
			board.pieces[tmp_Y][tmp_X]->COLOR != COLOR))
			if (board.pieces[tmp_Y][tmp_X] && (board.pieces[tmp_Y][tmp_X]->piece_ID == 6)) // If it is not KING
				legal_sqs.push_back(tmp_Y * 8 + tmp_X + 1);
		else
			break;
	}

	tmp_X = X;
	tmp_Y = Y;
	while (tmp_Y > 0) { // Left
		tmp_Y--;
		if (!board.pieces[tmp_Y][tmp_X] || (board.pieces[tmp_Y][tmp_X] &&
			board.pieces[tmp_Y][tmp_X]->COLOR != COLOR))
			if (board.pieces[tmp_Y][tmp_X] && (board.pieces[tmp_Y][tmp_X]->piece_ID == 6)) // If it is not a KING
				legal_sqs.push_back(tmp_Y * 8 + tmp_X + 1);
		else
			break;
	}

	tmp_X = X;
	tmp_Y = Y;
	while (tmp_Y < 7) { // Right
		tmp_Y++;
		if (!board.pieces[tmp_Y][tmp_X] || (board.pieces[tmp_Y][tmp_X] &&
			board.pieces[tmp_Y][tmp_X]->COLOR != COLOR))
			if (board.pieces[tmp_Y][tmp_X] && (board.pieces[tmp_Y][tmp_X]->piece_ID == 6)) // If it is not a KING
				legal_sqs.push_back(tmp_Y * 8 + tmp_X + 1);
		else
			break;
	}

	return legal_sqs;
}