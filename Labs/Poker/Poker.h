#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Poker
{
protected:
	vector<string> rank{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K" };
	vector<string> suit{ "D", "C", "S", "H" };
	map<char, int> rankInts = { {'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};
	int np;
	vector<string> table;
	vector<string> deck;
	//vector containing 2 vectors of strings one for each players hand
	vector<vector<string>> playerHands; 


public:
	//The default constructor
	Poker();
	//The user constructor
	Poker(int);
	//Adds a card to the players hand when passing their index, removes 1 card from deck
	void add_card(int);
	//Adds a card to the table from the top of the deck
	void add_to_table();
	//Sorts the cards of the given hand
	vector<string> sort_hand(vector<string>);
	//Returns true if all cards are from the same suit and their rank is in order
	bool IsStraightFlush(vector<string>);
	//Returns true is there are four cards of the same rank
	bool IsFourOfAKind(vector<string>);
	//Returns true if there are cards of the same rank and two cards of another rank
	bool IsFullHouse(vector<string>);
	//Returns true if all five cards have the sme suit
	bool IsFlush(vector<string>);
	//Returns true if the five cards are in order of their rank of an suit 
	bool IsStraight(vector<string>);
	//Returns true if there are three cards of the same rank
	bool IsThreeOfAKind(vector<string>);
	//Returns true if there are two pairs of cards same rank
	bool IsTwoPairs(vector<string>);
	//Returns true if there is a pair of cards of the same rank
	bool IsOnePair(vector<string>);
};