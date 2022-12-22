#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Poker.h"

using namespace std;

Poker::Poker()
{
	np = 2;
	//Empty vectors for the cards 
	vector<string> h1, h2;

	//Empty string that will store temp cards before being added to the deck
	string temp = " ";

	//Adding both empty vectors to the playerHands vector 
	playerHands.push_back(h2);
	playerHands.push_back(h1);

	//Initialize the deck and shuffle it 
	for (int j = 0; j < 13; ++j)
	{
		for (int k = 0; k < 4; ++k)
		{
			temp = rank[j] + suit[k];
			deck.push_back(temp);
		}

	}
	//Shuffling the deck so that it is randomized
	random_shuffle(deck.begin(), deck.end());
}

Poker::Poker(int numPlayers)
{
	np = numPlayers;
	//Empty string that will store temp cards before being added to the deck
	string temp = " ";

	for (int i = 0; i < numPlayers; ++i)
	{
		//Empty vector for each players hand
		vector<string> v;
		//Adding each paleyrs hand to the vector playerHands
		playerHands.push_back(v);
	}

	//Initialize the deck and shuffle it 
	for (int j = 0; j < 13; ++j)
	{
		for (int k = 0; k < 4; ++k)
		{
			temp = rank[j] + suit[k];
			deck.push_back(temp);
		}

	}
	//Shuffling the deck so it is randomized
	random_shuffle(deck.begin(), deck.end());
}

void Poker::add_card(int index)
{
	//Adds first card from deck to the hand of the player at the given index
	playerHands[index].push_back(deck[0]);
	//Removes the card added to the players hand
	deck.erase(deck.begin());
}

void Poker::add_to_table()
{
	//Adds first card of deck to the table and removes it
	table.push_back(deck[0]);
	deck.erase(deck.begin());
}

vector<string> Poker::sort_hand(vector<string> hand)
{
	vector<string> result;
	string temp = "";
	for (int i = 0; i < hand.size(); ++i)
	{
		for (int j = i; j < hand.size(); ++j)
		{
			if (rankInts[hand[i][0]] > rankInts[hand[j][0]])
			{
				temp = hand[i];
				hand[i] = hand[j];
				hand[j] = temp;
			}
		}
	}
	for (int k = 0; k < hand.size(); ++k)
		result.push_back(hand[k]);
	return result;
}

bool Poker::IsStraightFlush(vector<string> hand)
{
	return IsFlush(hand) && IsStraight(hand);
}

bool Poker::IsFourOfAKind(vector<string> hand)
{
	hand = sort_hand(hand);
	if (hand[0][0] == hand[1][0] && hand[1][0] == hand[2][0] && hand[2][0] == hand[3][0])
		return true;

	if (hand[1][0] == hand[2][0] && hand[2][0] == hand[3][0] && hand[3][0] == hand[4][0])
		return true;

	else
		return false;
}

bool Poker::IsFullHouse(vector<string> hand)
{
	hand = sort_hand(hand);
	if (hand[0][0] == hand[1][0] && hand[1][0] == hand[2][0] && hand[3][0] == hand[4][0])
		return true;

	if (hand[0][0] == hand[1][0] && hand[2][0] == hand[3][0] && hand[3][0] == hand[4][0])
		return true;

	else
		return false;
}

bool Poker::IsFlush(vector<string> hand)
{
	hand = sort_hand(hand);
	if (hand[0][1] == hand[1][1] && hand[1][1] == hand[2][1] && hand[2][1] == hand[3][1] && hand[3][1] == hand[4][1])
		return true;

	else
		return false;
}

bool Poker::IsStraight(vector<string> hand)
{
	hand = sort_hand(hand);
	if (rankInts[hand[0][0]] == rankInts[hand[1][0]] - 1 && rankInts[hand[1][0]] == rankInts[hand[2][0]] - 1
		&& rankInts[hand[2][0]] == rankInts[hand[3][0]] - 1 && rankInts[hand[3][0]] == rankInts[hand[4][0]] - 1)
		return true;
	if (hand[0][0] == 'A' && hand[1][0] == 'T' && rankInts[hand[1][0]] == rankInts[hand[2][0]] - 1
		&& rankInts[hand[2][0]] == rankInts[hand[3][0]] - 1 && rankInts[hand[3][0]] == rankInts[hand[4][0]] - 1)
		return true;
	else
		return false;
}

bool Poker::IsThreeOfAKind(vector<string> hand)
{
	hand = sort_hand(hand);
	if (hand[0][0] == hand[1][0] && hand[1][0] == hand[2][0])
		return true;

	if (hand[1][0] == hand[2][0] && hand[2][0] == hand[3][0])
		return true;

	if (hand[2][0] == hand[3][0] && hand[3][0] == hand[4][0])
		return true;
	else
		return false;
}

bool Poker::IsTwoPairs(vector<string> hand)
{
	hand = sort_hand(hand);
	if (hand[0][0] == hand[1][0] && hand[2][0] == hand[3][0])
		return true;

	if (hand[0][0] == hand[1][0] && hand[3][0] == hand[4][0])
		return true;

	if (hand[1][0] == hand[2][0] && hand[3][0] == hand[4][0])
		return true;
	else
		return false;
}

bool Poker::IsOnePair(vector<string> hand)
{
	hand = sort_hand(hand);
	int pairs = 0;
	for (int i = 0; i < hand.size() - 1; i++) {

		if (hand[i][0] == hand[i + 1][0])
			++pairs;

	}
	if (pairs == 1)
		return true;
	else
		return false;
}


