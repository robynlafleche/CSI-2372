#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_ELEMS 100

class Crossword
{
private:
	//Array of string vectors all initialized to " "
	vector<vector<string>> grid;
	//Array of string vectors all initialized to " ", which will be replaced with add_questions values and "false" to show it has not been solve
	vector<vector<string>> ques;
	//number of rows
	int row;
	//number of columns
	int col;
	//number of questions successfully added to the array of ques
	int numQ;

public:
	//Default constructor that creates a Crossword of 10 by 10
	Crossword();
	//User constructor that creates a Crossword of the given n rows by m columns (n and m are given integers)
	Crossword(int, int);
	//Takes 5 arguments and return true or false wether the question was added
	bool add_questions(string, string, int, int, bool);
	//Takes 3 arguments and the answer is added to the 3 argument 
	bool solve(int, int, string);
	//checks to see if there are any un-solved questions that would interfear with the one we're trying to add if so return true, else false
	bool intersectNonSolved(int, int, string, bool, int);
	//For printing the Crossword in the format shown below
	friend ostream& operator <<(ostream&, Crossword&);
};
