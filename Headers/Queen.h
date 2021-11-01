#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(int, bool);
	int X_arr[4] = { 1, 1, -1, -1 }; // Diagonal move pairs
	int Y_arr[4] = { 1, -1, 1, -1 }; // ...

	vector<int> legal_squares(Board&);
};