#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(int, bool);

	vector<int> legal_squares(Board&);
};