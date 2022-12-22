#pragma once
#include <iostream>
#include <map>
#include <set>

using namespace std;

template <typename type1, typename type2>
class Mapping
{
	private:
		map<type1, set<type2> > mp;
		int size;
	public:
		//Default constructor 
		Mapping();
		//Copy constructor
		Mapping(const Mapping<type1, type2>&);
		//The destructor (might not be necessary)
		//~Mapping();
		//Adds the second arg to the set of type2.
		bool add_item(type1, type2);
		//Removes the second arg from the set of the first arg, do nothing if it doesn't exist
		void remove_item(type1, type2);
		//Removes arg one completly from the mapping
		void clear_item(type1);
		//Returns the set of the given type1
		set<type2> find_item(type1);
		//Returns the set of the given type1
		set<type2> operator[](type1);
		//For assigning a mapping to another Mapping
		Mapping& operator=(Mapping<type1, type2>&);
		//For printing all elements of the mapping
		//template <typename type1x, typename type2x> friend ostream& operator<<(ostream&, Mapping<type1x, set<type2x> >&);
		void print();
		

};