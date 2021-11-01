#include "Knight.h"


Knight::Knight(int sq, bool c) {
	// Check sq and error if wrong!
	piece_ID = 2;
	square = sq;
	COLOR = c;
	X = (square - 1) % 8;
	Y = (square - 1) / 8;

}

vector<int> Knight::legal_squares(Board& board) {
	vector<int> legal_sqs{};

	for (size_t i = 0; i < 8; i++) {
		if ((X + X_arr[i]) >= 0 && (X + X_arr[i]) <= 7) {
			if ((Y + Y_arr[i]) >= 0 && (Y + Y_arr[i]) <= 7) {
				if (COLOR) { // If we have a white Knight
					if (!board.pieces[Y + Y_arr[i]][X + X_arr[i]] || // If that square is empty or there is a black piece
						(board.pieces[Y + Y_arr[i]][X + X_arr[i]] &&
							!board.pieces[Y + Y_arr[i]][X + X_arr[i]]->COLOR))
						if (board.pieces[Y + Y_arr[i]][X + X_arr[i]] &&
							board.pieces[Y + Y_arr[i]][X + X_arr[i]]->piece_ID == 6) // If there is a king there
							continue;
						else
							legal_sqs.push_back((Y + Y_arr[i]) * 8 + X + X_arr[i] + 1);
				}
				else { // We have a black Knight
					if (!board.pieces[Y + Y_arr[i]][X + X_arr[i]] || // If that square is empty or there is a white piece
						(board.pieces[Y + Y_arr[i]][X + X_arr[i]] &&
							board.pieces[Y + Y_arr[i]][X + X_arr[i]]->COLOR))
						if (board.pieces[Y + Y_arr[i]][X + X_arr[i]] &&
							board.pieces[Y + Y_arr[i]][X + X_arr[i]]->piece_ID == 6) // If there is a king there
							continue;
						else
							legal_sqs.push_back((Y + Y_arr[i]) * 8 + X + X_arr[i] + 1);
				}
			}
		}
	}
	return legal_sqs;
}