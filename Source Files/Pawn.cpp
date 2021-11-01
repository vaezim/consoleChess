#include "Pawn.h"


Pawn::Pawn(int sq, bool c) {
	// Check sq and error if wrong!!!
	// Check to see that no other pieces exist at that square!!!
	piece_ID = 1;
	square = sq;
	COLOR = c;
	X = (square - 1) % 8;
	Y = (square - 1) / 8;
}

vector<int> Pawn::forward_squares(Board& board) {
	vector<int> legal_sqs{};
	if (COLOR) { /************ White ************/
		switch (Y) {
		case 1:
			if (!board.pieces[Y + 1][X])
				legal_sqs.push_back((Y + 1) * 8 + X + 1);
			if (!board.pieces[Y + 2][X])
				legal_sqs.push_back((Y + 2) * 8 + X + 1);
			break;
		default:
			if (!board.pieces[Y + 1][X])
				legal_sqs.push_back((Y + 1) * 8 + X + 1);
			break;
		}
	}
	else { /************ Black ************/
		switch (Y) {
		case 6:
			if (!board.pieces[Y - 1][X])
				legal_sqs.push_back((Y - 1) * 8 + X + 1);
			if (!board.pieces[Y - 2][X])
				legal_sqs.push_back((Y - 2) * 8 + X + 1);
			break;
		default:
			if (!board.pieces[Y - 1][X])
				legal_sqs.push_back((Y - 1) * 8 + X + 1);
			break;
		}
	}
	return legal_sqs;
}

vector<int> Pawn::take_squares(Board& board) {
	vector<int> legal_sqs{};

	if (COLOR) { /************ White ************/
		if (Y < 7) {
			switch (X) {
			case 0:
				if (board.pieces[Y + 1][X + 1])
					if (!board.pieces[Y + 1][X + 1]->COLOR)
						if (board.pieces[Y + 1][X + 1]->piece_ID != 6) // If it is not a KING
							legal_sqs.push_back((Y + 1) * 8 + X + 2);
				break;
			case 7:
				if (board.pieces[Y + 1][X - 1])
					if (!board.pieces[Y + 1][X - 1]->COLOR)
						if (board.pieces[Y + 1][X - 1]->piece_ID != 6) // If it is not a KING
							legal_sqs.push_back((Y + 1) * 8 + X);
				break;
			default:
				if (board.pieces[Y + 1][X + 1])
					if (!board.pieces[Y + 1][X + 1]->COLOR)
						if (board.pieces[Y + 1][X + 1]->piece_ID != 6)
							legal_sqs.push_back((Y + 1) * 8 + X + 2);
				if (board.pieces[Y + 1][X - 1])
					if (!board.pieces[Y + 1][X - 1]->COLOR)
						if (board.pieces[Y + 1][X - 1]->piece_ID != 6)
							legal_sqs.push_back((Y + 1) * 8 + X);
				break;
			}
		}
	}
	else { /************ Black ************/
		if (Y > 0) {
			switch (X) {
			case 0:
				if (board.pieces[Y - 1][X + 1])
					if (board.pieces[Y - 1][X + 1]->COLOR)
						if (board.pieces[Y - 1][X + 1]->piece_ID != 6) // If it is not a KING
							legal_sqs.push_back((Y - 1) * 8 + X + 2);
				break;
			case 7:
				if (board.pieces[Y - 1][X - 1])
					if (board.pieces[Y - 1][X - 1]->COLOR)
						if (board.pieces[Y - 1][X - 1]->piece_ID != 6) // If it is not a KING
							legal_sqs.push_back((Y - 1) * 8 + X);
				break;
			default:
				if (board.pieces[Y - 1][X + 1])
					if (board.pieces[Y - 1][X + 1]->COLOR)
						if (board.pieces[Y - 1][X + 1]->piece_ID != 6)
							legal_sqs.push_back((Y - 1) * 8 + X + 2);
				if (board.pieces[Y - 1][X - 1])
					if (board.pieces[Y - 1][X - 1]->COLOR)
						if (board.pieces[Y - 1][X - 1]->piece_ID != 6)
							legal_sqs.push_back((Y - 1) * 8 + X);
				break;
			}
		}
	}
	return legal_sqs;
}

vector<int> Pawn::legal_squares(Board& board) {
	vector<int> legal_sqs = forward_squares(board); // initialize it with forward squares
	for (auto& x : take_squares(board)) // add take squares
		legal_sqs.push_back(x);

	return legal_sqs;
}

vector<int> Pawn::check_squares() {
	vector<int> legal_sqs{};
	if (COLOR) { /************ White ************/
		if (Y < 7) {
			switch (X) {
			case 0:
				legal_sqs.push_back((Y + 1) * 8 + X + 2);
				break;
			case 7:
				legal_sqs.push_back((Y + 1) * 8 + X);
				break;
			default:
				legal_sqs.push_back((Y + 1) * 8 + X + 2);
				legal_sqs.push_back((Y + 1) * 8 + X);
				break;
			}
		}
	}
	else { /************ Black ************/
		if (Y > 0) {
			switch (X) {
			case 0:
				legal_sqs.push_back((Y - 1) * 8 + X + 2);
				break;
			case 7:
				legal_sqs.push_back((Y - 1) * 8 + X);
				break;
			default:
				legal_sqs.push_back((Y - 1) * 8 + X + 2);
				legal_sqs.push_back((Y - 1) * 8 + X);
				break;
			}
		}
	}
	return legal_sqs;
}
