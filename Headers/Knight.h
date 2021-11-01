#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(int, bool);
	int X_arr[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
	int Y_arr[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };

	vector<int> legal_squares(Board&);
};