#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Piece; // Avoiding C4430 Error!

class Board {
public:
	Board();

	int get_squareNum(string);
	int get_pieceID(string);
	bool is_checked();
	void insert_piece(Piece*);
	void setup_board(); // Setting up the pieces
	void play();
	void takeback_move();

	Piece* pieces[8][8];

	vector<string> names{ "Pawn", "Knight", "Bishop", "Rook", "Queen", "King" };
	vector<string> PLAYERS{ "Black", "White" };

	vector<Piece*> removed_pieces{};
	Piece* moved_piece;
	Piece* prev_piece;
	int prev_square; // for taking one move back.

	bool PLAYER_TURN; // White: 1 | Black: 0
	bool GAME_OVER;
	bool IS_CHECKED;
	int WAS_CHECKED;
};