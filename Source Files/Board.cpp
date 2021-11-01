#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"


Board::Board() {
	for (int i{}; i < 8; i++) // Initializing it with an empty board
		for (int j{}; j < 8; j++)
			pieces[i][j] = nullptr;
	PLAYER_TURN = 1;
	GAME_OVER = 0;
	IS_CHECKED = 0;
	WAS_CHECKED = 0;
	moved_piece = nullptr;
	prev_piece = nullptr;
	prev_square = 0;
}

int Board::get_squareNum(string s) {
	int square_num = 8 * ((int)s[1] - 49) + (int)s[0] - 96;
	// ASCII conversions
	// a1 --> 1 | b1 --> 9 | h8 --> 64
	try {
		if (s.length() != 2 || square_num < 1 || square_num > 64)
			throw 999;
	}
	catch (...) {
		cout << s << " is an Invalid Square Name!" << endl;
		return -99;
	}
	return square_num;
}

int Board::get_pieceID(string s)
{
	if (s.length() == 2)
		return 1; // Pawn
	switch (s[0]) {
	case 'R':
		return 4; // Rook
	case 'N':
		return 2; // Knight
	case 'B':
		return 3; // Bishop
	case 'Q':
		return 5; // Queen
	case 'K':
		return 6; // King
	default:
		cout << "!!! Invalid Move !!!" << endl;
		return -1;
	}
}

bool Board::is_checked() {
	for (size_t i = 0; i < 8; i++) { // Checking if a CHECK has happened
		for (size_t j = 0; j < 8; j++) {
			if (pieces[i][j]) {
				if (pieces[i][j]->is_checker(*this)) return true;
			}
		}
	}
	return false;
}

void Board::insert_piece(Piece* piece) {
	pieces[piece->Y][piece->X] = piece;
}

void Board::setup_board() {
	/* White Pieces */
	pieces[0][0] = new Rook(1, 1); // square = 1, Color = White
	pieces[0][1] = new Knight(2, 1);
	pieces[0][2] = new Bishop(3, 1);
	pieces[0][3] = new Queen(4, 1);
	pieces[0][4] = new King(5, 1);
	pieces[0][5] = new Bishop(6, 1);
	pieces[0][6] = new Knight(7, 1);
	pieces[0][7] = new Rook(8, 1);
	for (size_t i = 0; i < 8; i++)
		pieces[1][i] = new Pawn(i + 9, 1); // White Pawns start from square 9

	/* Black Pieces */
	pieces[7][0] = new Rook(57, 0); // square = 57, Color = Black
	pieces[7][1] = new Knight(58, 0);
	pieces[7][2] = new Bishop(59, 0);
	pieces[7][3] = new Queen(60, 0);
	pieces[7][4] = new King(61, 0);
	pieces[7][5] = new Bishop(62, 0);
	pieces[7][6] = new Knight(63, 0);
	pieces[7][7] = new Rook(64, 0);
	for (size_t i = 0; i < 8; i++)
		pieces[6][i] = new Pawn(i + 49, 0); // Black Pawns start from square 49
}

void Board::play() {
	cout << "::: Welcome! :::" << endl << endl;
	string move;
	int p_ID;
	int sq;
	bool legal = 0;

	while (!GAME_OVER) {
		cout << PLAYERS[PLAYER_TURN] << "'s move > ";
		cin >> move; if (move == "exit") break;

		// !!! Check Validity of move string
		// !!! White/Black player can only move White/Black pieces.
		// !!! Write garbage collector | removed_piece vector.

		p_ID = get_pieceID(move);
		sq = (move.length() == 2) ? get_squareNum(move) : get_squareNum(move.substr(1, move.length())); // Ternary

		for (size_t i = 0; i < 8; i++) { // Checking if it is a legal move
			for (size_t j = 0; j < 8; j++) {
				if (pieces[i][j]) {
					if (pieces[i][j]->COLOR == PLAYER_TURN && pieces[i][j]->piece_ID == p_ID)
						legal = pieces[i][j]->is_legal(*this, sq);
					if (legal) {
						moved_piece = pieces[i][j];
						pieces[i][j]->move(*this, sq);
						break;
					}
				}
			}
			if (legal) break;
		}

		IS_CHECKED = is_checked();
		WAS_CHECKED += IS_CHECKED;

		if (legal) {
			legal = 0;
			if (!IS_CHECKED) {
				cout << "\t" << names[get_pieceID(move) - 1] << " -> ";
				if (move.length() == 3)
					move = move.substr(1, move.length());
				cout << move << endl;
				PLAYER_TURN = !PLAYER_TURN;
				WAS_CHECKED = 0;
			}
			else {
				if (WAS_CHECKED == 1) { // A check just happened.
					cout << "\t" << names[get_pieceID(move) - 1] << " -> ";
					if (move.length() == 3)
						move = move.substr(1, move.length());
					cout << move << endl;
					cout << "+++" << PLAYERS[!PLAYER_TURN] << "'s king Checked!" << endl;
					PLAYER_TURN = !PLAYER_TURN;
				}
				else { // WAS_CHECKED > 1 then the previous check was not removed.
					cout << "+++ Remove check first!" << endl;
					continue; // continue to the beginning of while loop.
				}
			}
		}
		else cout << "Invalid Move!\n";
	}
}

void Board::takeback_move() {
	moved_piece->square = prev_square;
	pieces[moved_piece->Y][moved_piece->X] = prev_piece;
	moved_piece->X = (moved_piece->square - 1) % 8;
	moved_piece->Y = (moved_piece->square - 1) / 8;
	pieces[moved_piece->Y][moved_piece->X] = moved_piece;
}