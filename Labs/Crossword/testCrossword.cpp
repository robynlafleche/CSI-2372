#include <iostream>
#include "Crossword.h"

using namespace std;

int main()
{
	Crossword c(7, 8);

	cout << c << endl;

	c.add_questions("What is the capital of Canada?", "Ottawa", 3, 2, true);

	cout << c << endl;

	c.solve(3, 2, "Toronto");

	cout << c << endl;

	c.add_questions("The last name of the current prime minister of Canada?", "Trudeau", 1, 3, false);

	cout << c << endl;

	c.add_questions("Farm animal with wool?", "Sheep", 4, 8, false);

	cout << c << endl;

	c.add_questions("The only flying mammals?", "Bats", 1, 4, false);

	cout << c << endl;

	c.solve(3, 2, "Ottawa");

	cout << c << endl;

	c.solve(1, 4, "Bats");

	cout << c << endl;
	
	return 0;
}