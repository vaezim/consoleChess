#pragma once
#include "Piece.h"
#include <set>
#include <iterator>

class King : public Piece
{
public:
	King(int, bool);
	const int X_arr[8]{ 1, 1, 1, 0, -1, -1, -1, 0 };
	const int Y_arr[8]{ 1, 0, -1, -1, -1, 0, 1, 1 };

	vector<int> legal_squares(Board&);
	vector<int> under_control() {
		vector<int> uc{};
		for (size_t i{}; i < 8; i++) {
			if (!(((X + X_arr[i]) < 0) || ((X + X_arr[i]) > 7)
				|| ((Y + Y_arr[i]) < 0) || ((Y + Y_arr[i]) > 7)))
				uc.push_back(i);
		}
		return to_square_num(uc);
	};
	vector<int> to_square_num(vector<int> legal) {
		for (auto& x : legal)
			x = (Y + Y_arr[x]) * 8 + X + X_arr[x] + 1;
		return legal;
	}
};