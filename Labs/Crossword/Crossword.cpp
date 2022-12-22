#include <iostream>
#include "Crossword.h"

using namespace std;

Crossword::Crossword()
{
	for (int i = 0; i < 10; i++)
	{
		vector<string> v;
		for (int j = 0; j < 10; j++) {
			v.push_back(" ");
		}
		grid.push_back(v);
	}

	for (int i = 0; i < MAX_ELEMS; i++)
	{
		vector<string> vq;
		for (int j = 0; j < 6; j++) {
			vq.push_back(" ");
		}
		ques.push_back(vq);
	}

	row = 10;
	col = 10;
	numQ = 0;
}

Crossword::Crossword(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		vector<string> v;
		for (int j = 0; j < m; j++) {
			v.push_back(" ");
		}
		grid.push_back(v);
	}

	for (int i = 0; i < MAX_ELEMS; i++)
	{
		vector<string> vq;
		for (int j = 0; j < 6; j++) {
			vq.push_back(" ");
		}
		ques.push_back(vq);
	}

	row = n;
	col = m;
	numQ = 0;
}

bool Crossword::add_questions(string q, string a, int n, int m, bool dir)
{
	int index2, index3, index4, c = 0;
	//Check if size is not bigger than MAX_ELEM and resize but I don't know how to do that yet
	if (dir)
	{
		//horizontal
		for (index2 = m; index2 < a.length() + m; ++index2)
		{
			if (a.length() + m - 1 > col)
				return false;
			if (grid[n][index2] != " " || grid[n][index2] != " " && grid[n][index2] != string(1, a[c]) || grid[m][index2] == " " && !intersectNonSolved(n, m, a, dir, index2))
				return false;
			++c;
		}
		ques[numQ][0] = "true";
		ques[numQ][1] = to_string(n);
		ques[numQ][2] = to_string(m);
		ques[numQ][3] = q;
		ques[numQ][4] = a;
		ques[numQ][5] = "false";
		
		++numQ;

		return true;
	}
	else
	{
		//vertical
		for (index4 = n; index4 < a.length() + n; ++index4)
		{
			if (a.length() + n - 1 > row)
				return false;
			if (grid[m][index4] != " " || grid[m][index4] != " " && grid[m][index4] != string(1, a[c]) || grid[m][index4] == " " && !intersectNonSolved(n, m, a, dir, index4))
				return false;
			++c;
		}
		ques[numQ][0] = "false";
		ques[numQ][1] = to_string(n);
		ques[numQ][2] = to_string(m);
		ques[numQ][3] = q;
		ques[numQ][4] = a;
		ques[numQ][5] = "false";

		++numQ;

		return true;
	}
}

bool Crossword::intersectNonSolved(int n, int m, string a, bool dir, int index)
{
	int i;
	for (i = 0; i < numQ; ++i)
	{
		if (ques[i][5] == "false" && ques[i][0] == "false" && dir == true && stoi(ques[i][2]) == index)
		{
			if (ques[i][4][index - stoi(ques[i][1]) + 1] == a[index - n])
				return true;
			else
				return false;
		}
		if (ques[i][5] == "false" && ques[i][0] == "true" && dir == false && stoi(ques[i][1]) == index)
		{
			if (ques[i][4][index - stoi(ques[i][2]) + 1] == a[index - n])
				return true;
			else
				return false;
		}
		else
			return true; 
	}
}

bool Crossword::solve(int n, int m, string answer)
{
	//check to see what the answer is and if it is equal to answer sent as param if so true else false
	int index, index1,c = 0;
	for (index = 0; index < numQ; ++index)
	{
		if (n == stoi(ques[index][1]) && m == stoi(ques[index][2]) && "false" == ques[index][5] && answer == ques[index][4])
		{
			if (ques[index][0] == "true")
			{
				for (index1 = m; index1 < answer.length() + m; ++index1)
				{
					grid[n - 1][index1 - 1] = answer[c];
					++c;
				}
				ques[index][5] = "true";
				return true;
			}
			else
			{
				for (index1 = n; index1 < answer.length() + n; ++index1)
				{
					grid[index1 - 1][m - 1] = answer[c];
					++c;
				}
				ques[index][5] = "true";
				return true;
			}
		}
	}
	return false;
}

ostream& operator<<(ostream& out, Crossword& c)
{
	int m, l, k, r;
	out << "Puzzle: " << endl << endl;
	out << "   ";
	for (m = 0; m < c.col; ++m)
		out << m + 1 << "  ";
		out << endl;
	for (l = 0; l < c.row; ++l)
	{
		if (l < 9)
			out << l + 1 << "  ";
		else
			out << l + 1 << " ";
		for (k = 0; k < c.col; ++k)
			out << c.grid[l][k] << "  ";
		out << endl;
	}

	
	out << endl << "Questions: " << endl;
	for (r = 0; r < c.numQ; ++r)
	{
		out << "(" << c.ques[r][1] << ", " << c.ques[r][2];
		out << ") - " << c.ques[r][3];
		out << " (";
		if (c.ques[r][0] == "true")
			out << "Horizontal)";
		else
			out << "Vertical)";
		out << endl;
	}
	return out;
}