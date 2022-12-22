#pragma once
#include <iostream>
#include "Poker.h"

class TexasHoldem : public Poker {

private:
	map<int, string> stringScore = { {1, "High Card"}, {2, "One Pair"}, {3, "Two Pair"}, {4, "Three OF A Kind"}, {5, "Straight"}, {6, "Flush"}, {7, "Full House"}, {8, "Four Of A Kind"}, {9, "Straight Flush"} };
public:
	TexasHoldem(): Poker() {};
	TexasHoldem(int f): Poker(f) {};
	void deal();
	void hands();
	int getScore(vector<string>);
};