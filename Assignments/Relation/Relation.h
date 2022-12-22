#pragma once
#include <iostream>
#include "Set.h"

using namespace std;


template <typename type>
struct Pair
{
	//First elementof the pair
	type first;
	//Second element of the pair 
	type second;
};

template <typename type>
class Relation
{
private:
	//SetA
	Set<type> root;
	//Represents the number of pairs in the relation
	int card;
	//Array of pairs
	Pair<type>* elements;
	//Capacity of the relation initialized as MAX_CARD of 100
	int capacity;
public:
	//Default constructor that initializes an empty relation with capacity of 100
	Relation();
	//The copy constructor
	Relation(const Relation<type>&);
	//The destructor
	~Relation();
	//Adds an element to the set
	bool add_to_set(type);
	//Returns the number of pairs in the relation
	int cardinality();
	//Adds a pair into the relation and allocates memory if necessary
	bool add_element(Pair<type>);
	//Removes an element from the relation
	void remove_element(Pair<type>);
	//Checks if an element is in the relation
	bool is_member(Pair<type>);
	//Checks if two relations are equal
	bool operator ==(Relation<type>);
	//Returns the list of elements that the given index mapped to
	//Pair<type> operator [](int);
	//= operator
	Relation<type>& operator=(Relation<type>);
	//Checks if the relation is reflexive
	bool reflexive();
	//Checks if the relation is irreflexive
	bool irreflexive();
	//Checks if the relation is symmetric
	bool symmetric();
	//Checks if the relation is asymmetric
	bool asymmetric();
	//Checks if the relation is transitive
	bool transitive();
	//Checks if the relation is a is_function
	bool is_function();
	//Printing the relation { (2, 5), (3, 3), (3, 4) }
	template <typename typex> friend ostream& operator <<(ostream&, Relation<typex>&);
	//Returns the inverse of a relation (R^-1)
	Relation<type> inverse();
	//Returns the combination of two relations or returns an empty relation if the relations are empty
	Relation<type> combination(Relation<type>);
};