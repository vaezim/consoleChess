#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(int, bool);

	vector<int> forward_squares(Board&);
	vector<int> take_squares(Board&);
	vector<int> legal_squares(Board&);
	vector<int> check_squares();
};