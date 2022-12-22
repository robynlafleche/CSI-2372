#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "Poker.h"
#include "TexasHoldem.h"
using namespace std;

int main() 
{

	Poker p;

	vector<string> v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16;

	v1 = { "AH", "2H", "3H", "4H", "5H" };
	v2 = { "8C", "9C", "TC", "2C", "3C" };

	cout << "isStraightFlush" << endl;;
	if (p.IsStraightFlush(v1)) {
		cout << "test 1 passed" << endl;
	}
	else {
		cout << "test 1 failed" << endl;
	}
	if (!p.IsStraightFlush(v2)) {
		cout << "test 2 passed" << endl;
	}
	else {
		cout << "test 2 failed" << endl;
	}

	v3 = { "9H", "6S", "9D", "9C", "9S" };
	v4 = { "2H", "6S", "5H", "8C", "9S" };

	cout << "isFourofaKind" << endl;
	if (p.IsFourOfAKind(v3)) {
		cout << "test 1 passed" << endl;
	}
	else {
		cout << "test 1 failed" << endl;
	}
	if (!p.IsStraightFlush(v4)) {
		cout << "test 2 passed" << endl;
	}
	else {
		cout << "test 2 failed" << endl;
	}

	v5 = { "JH", "7S", "7D", "JD", "JC" };
	v6 = { "2H", "6D", "5D", "8C", "82" };

	cout << "isFullHouse" << endl;
	if (p.IsFullHouse(v5)) {
		cout << "test 1 passed" << endl;
	}
	else {
		cout << "test 1 failed" << endl;
	}
	if (!p.IsFullHouse(v6)) {
		cout << "test 2 passed" << endl;
	}
	else {
		cout << "test 2 failed" << endl;
	}

	v7 = { "JH", "7H", "8H", "2H", "5H" };
	v8 = { "3D", "6D", "3H", "8C", "8S" };

	cout << "isFlush" << endl;
	if (p.IsFlush(v7)) {
		cout << "test 1 passed" << endl;
	}
	else {
		cout << "test 1 failed" << endl;
	}
	if (!p.IsFlush(v8)) {
		cout << "test 2 passed" << endl;
	}
	else {
		cout << "test 2 failed" << endl;
	}

	v9 = { "AD", "2S", "3D", "4C", "5H" };
	v10 = { "8C", "9D", "TC", "2D", "3H" };

	cout << "isStraight" << endl;;
	if (p.IsStraight(v9)) {
		cout << "test 1 passed" << endl;
	}
	else {
		cout << "test 1 failed" << endl;
	}
	if (!p.IsStraight(v10)) {
		cout << "test 2 passed" << endl;
	}
	else {
		cout << "test 2 failed" << endl;
	}

	v11 = { "TH", "6S", "TD", "TC", "QC" };
	v12 = { "2H", "6S", "KH", "8C", "QS" };

	cout << "isThreeofaKind" << endl;
	if (p.IsThreeOfAKind(v11)) {
		cout << "test 1 passed" << endl;
	}
	else {
		cout << "test 1 failed" << endl;
	}
	if (!p.IsThreeOfAKind(v12)) {
		cout << "test 2 passed" << endl;
	}
	else {
		cout << "test 2 failed" << endl;
	}

	v13 = { "TH", "6S", "AS", "TC", "6D" };
	v14 = { "2H", "6S", "9H", "8C", "QS" };

	cout << "isTwoPairs" << endl;
	if (p.IsTwoPairs(v13)) {
		cout << "test 1 passed" << endl;
	}
	else {
		cout << "test 1 failed" << endl;
	}
	if (!p.IsTwoPairs(v14)) {
		cout << "test 2 passed" << endl;
	}
	else {
		cout << "test 2 failed" << endl;
	}

	v15 = { "TH", "6S", "AS", "KC", "KD" };
	v16 = { "2H", "6S", "9H", "8C", "QS" };

	cout << "isOnePair" << endl;
	if (p.IsOnePair(v15)) {
		cout << "test 1 passed\n";
	}
	else {
		cout << "test 1 failed\n";
	}
	if (!p.IsOnePair(v16)) {
		cout << "test 2 passed\n";
	}
	else {
		cout << "test 2 failed\n";
	}

	TexasHoldem t;

	t.deal();
	t.hands();

	return 0;
}


