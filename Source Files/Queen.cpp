#include "Queen.h"


Queen::Queen(int sq, bool c) {
	// Check sq and error if wrong!
	piece_ID = 5;
	square = sq;
	COLOR = c;
	X = (square - 1) % 8;
	Y = (square - 1) / 8;
}

vector<int> Queen::legal_squares(Board& board) {
	vector<int> legal_sqs{};

	/* Rook moves */
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
			if (board.pieces[tmp_Y][tmp_X] && (board.pieces[tmp_Y][tmp_X]->piece_ID != 6)) // If it is not a KING
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
			if (board.pieces[tmp_Y][tmp_X] && (board.pieces[tmp_Y][tmp_X]->piece_ID != 6)) // If it is not a KING
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
			if (board.pieces[tmp_Y][tmp_X] && (board.pieces[tmp_Y][tmp_X]->piece_ID != 6)) // If it is not a KING
				legal_sqs.push_back(tmp_Y * 8 + tmp_X + 1);
			else
				break;
	}
	/**********************/

	/* Bishop Moves */
	for (size_t i = 0; i < 4; i++) {
		tmp_X = X + X_arr[i];
		tmp_Y = Y + Y_arr[i];

		while (tmp_X >= 0 && tmp_X <= 7 && tmp_Y >= 0 && tmp_Y <= 7) {
			if (!board.pieces[tmp_Y][tmp_X]) { // If the square is empty
				legal_sqs.push_back(tmp_Y * 8 + tmp_X + 1);
				tmp_X += X_arr[i];
				tmp_Y += Y_arr[i];
			}
			else { // If there is a piece there
				if (board.pieces[tmp_Y][tmp_X]->COLOR != this->COLOR) {// If they are from different colors
					if (board.pieces[tmp_Y][tmp_X]->piece_ID != 6) { // If it is not a KING
						legal_sqs.push_back(tmp_Y * 8 + tmp_X + 1);
						tmp_X += X_arr[i];
						tmp_Y += Y_arr[i];
					}
				}
				break;
			}
		}
	}
	/**********************/

	return legal_sqs;
}