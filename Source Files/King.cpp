#include "King.h"


King::King(int sq, bool c) {
	// Check sq and error if wrong!
	piece_ID = 6;
	square = sq;
	COLOR = c;
	X = (square - 1) % 8;
	Y = (square - 1) / 8;
}

vector<int> King::legal_squares(Board& board) {
	vector<int> legal_sqs{ 0, 1, 2, 3, 4, 5, 6, 7 };
	vector<int> tmp{};
	set<int, less<int>> illegal_sqs; // std::set<> | Iterators.
	vector<int> under_attack_sqs;

	/* Removing other king's squares. Cannot use it's legal_squares(). Infinite loop! */
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (board.pieces[i][j]) {
				if (board.pieces[i][j]->piece_ID == 6 && board.pieces[i][j]->COLOR != COLOR) {
					vector<int> uc = board.pieces[i][j]->under_control();
					vector<int> legal_num = to_square_num(legal_sqs);
					for (size_t i{}; i < legal_num.size(); i++) {
						if (std::find(uc.begin(), uc.end(), legal_num[i]) == uc.end())
							tmp.push_back(i);
					}
				}
			}
		}
	}
	legal_sqs = tmp;
	tmp.clear();

	/* Removing Out-of-board squares */
	for (auto& i : legal_sqs) {
		if (((X + X_arr[i]) < 0) || ((X + X_arr[i]) > 7)
			|| ((Y + Y_arr[i]) < 0) || ((Y + Y_arr[i]) > 7))
			illegal_sqs.insert(i);
	}
	for (auto& x : legal_sqs) {
		if (std::find(illegal_sqs.begin(), illegal_sqs.end(), x) == illegal_sqs.end())
			tmp.push_back(x);
	}
	legal_sqs = tmp;
	tmp.clear();
	/*******************/

	/* Removing non-empty squares with a same color piece */
	for (auto& i : legal_sqs) {
		if (board.pieces[Y + Y_arr[i]][X + X_arr[i]])
			if (board.pieces[Y + Y_arr[i]][X + X_arr[i]]->COLOR == COLOR)
				illegal_sqs.insert(i);
	}
	for (auto& x : legal_sqs) {
		if (std::find(illegal_sqs.begin(), illegal_sqs.end(), x) == illegal_sqs.end())
			tmp.push_back(x);
	}
	legal_sqs = tmp;
	tmp.clear();
	/*******************/

	if (!legal_sqs.size()) // If no other squares left, return.
		return to_square_num(legal_sqs);

	/* Removing Under attack squares */
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (board.pieces[i][j]) { // If there is a piece there
				if (board.pieces[i][j]->piece_ID == 6) // Will fall into an infinite loop. Calling a function inside itself from the same object!
					continue;
				if (board.pieces[i][j]->COLOR != COLOR) { // If that piece has opposite color
					under_attack_sqs = board.pieces[i][j]->legal_squares(board); // sqaures attacked by that piece
					if (board.pieces[i][j]->piece_ID == 1) // If it's a pawn use it's take squares.
						under_attack_sqs = board.pieces[i][j]->check_squares();

					for (auto& k : legal_sqs) {
						if (std::find(under_attack_sqs.begin(), under_attack_sqs.end(),
							(Y + Y_arr[k]) * 8 + X + X_arr[k] + 1) != under_attack_sqs.end()) { // STL: If key is found in that vector
							cout << "Threatened by " << piece_names[board.pieces[i][j]->piece_ID - 1] << endl;
							illegal_sqs.insert(k);
						}
					}
					for (auto& x : legal_sqs) {
						if (std::find(illegal_sqs.begin(), illegal_sqs.end(), x) == illegal_sqs.end())
							tmp.push_back(x);
					}
					legal_sqs = tmp;
					tmp.clear();
					if (!legal_sqs.size()) // If no other squares left, return.
						return to_square_num(legal_sqs);
				}
			}
		}
	}
	/*******************/

	return to_square_num(legal_sqs);
}