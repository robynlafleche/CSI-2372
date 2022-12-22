// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_CARD 1000

template <typename type1y, typename type2y>
struct Pair
{
	//First elementof the pair
	type1y first;
	//Second element of the pair 
	type2y second;
};

template <typename type1, typename type2>
class MappingRelation
{
private:
	//Represents the number of pairs in the relation
	int card;
	//Array of pairs
	Pair<type1,type2>* elements;
	//Capacity of the relation initialized as MAX_CARD of 100
	int capacity;
public:
	//Default constructor that initializes an empty relation with capacity of 100
	MappingRelation();
	//The copy constructor
	MappingRelation(const MappingRelation<type1, type2>&);
	//The destructor
	~MappingRelation();
	//Returns the number of pairs in the relation
	int cardinality();
	//Returns the pair at given index
	 Pair<type1, type2> getElement(int);
	//Adds a pair into the relation and allocates memory if necessary
	bool add_element(type1, type2);
	//Removes an element from the relation
	void remove_element(type1, type2);
	//Checks if an element is in the relation
	bool is_member(type1, type2);
	//Checks if two relations are equal
	bool operator ==(MappingRelation<type1, type2>);
	//For getting union of two relations
	MappingRelation<type1, type2> operator +(MappingRelation<type1, type2>);
	//For difference of two relations
	MappingRelation<type1, type2> operator -(MappingRelation<type1, type2>);
	//Returns the list of elemnts tht the given index is mapped to
	vector<type2> operator [](type1);
	//For getting intersection of two relations
	MappingRelation<type1, type2> intersection(MappingRelation<type1, type2>);
	//Checks if the relation is a is_function
	bool is_function();
	template <typename type1x, typename type2x> friend ostream& operator << (ostream&, MappingRelation<type1x, type2x>&);
	//Returns the inverse of a relation (R^-1)
	MappingRelation<type1, type2> inverse();
	//Returns the combination of two relations or returns an empty relation if the relations are empty
	template <typename type3> MappingRelation<type1, type3> combination(MappingRelation<type2, type3>);
};
