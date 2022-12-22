#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "TexasHoldem.h"

using namespace std;

void TexasHoldem::deal()
{
	for (int i = 0; i < np; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			//Adds first card from deck to the hand of the player at the given index
			playerHands[i].push_back(deck[0]);
			//Removes the card added to the players hand
			deck.erase(deck.begin());
		}
	}

	for (int k = 0; k < 5; ++k)
	{
		table.push_back(deck[0]);
		deck.erase(deck.begin());
	}
}

void TexasHoldem::hands()
{
	vector<int> scores;
	int i, temp = 0;
	vector <string> cards; //place all cards on the table and in the hand of the player into this vector
	vector <int> select(7);
	select[0] = select[1] = 0;
	select[2] = select[3] = select[4] = select[5] = select[6] = 1;
	for (int j = 0; j < np; ++j)
	{
		cards.clear();
		for (int l = 0; l < table.size(); ++l)
			cards.push_back(table[l]);
		for (int k = 0; k < playerHands[j].size(); ++k)
			cards.push_back(playerHands[j][k]);
		do
		{
			vector <string> pick;
			for (i = 0; i < 7; ++i)
				if (select[i] == 1) pick.push_back(cards[i]);
			if (temp < getScore(pick))
				temp = getScore(pick);
		} while (next_permutation(select.begin(), select.end()));
		scores.push_back(temp);
		temp = 0;
	}
	
	cout << "[";
	for (int m = 0; m < np; ++m)
	{
		cout << stringScore[scores[m]];
		if (!(m == np - 1))
			cout << ", ";
	}
	cout << "]" << endl;
}

int TexasHoldem::getScore(vector<string> cards)
{
	int score;
	if (IsStraightFlush(cards)) {
		score = 9;
	}
	else if (IsFourOfAKind(cards)) {
		score = 8;
	}
	else if (IsFullHouse(cards)) {
		score = 7;
	}
	else if (IsFlush(cards)) {
		score = 6;
	}
	else if (IsStraight(cards)) {
		score = 5;
	}
	else if (IsThreeOfAKind(cards)) {
		score = 4;
	}
	else if (IsTwoPairs(cards)) {
		score = 3;
	}
	else if (IsOnePair(cards)) {
		score = 2;
	}
	else {
		score = 1;
	}

	return score;
}