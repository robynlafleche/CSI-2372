#pragma once
#include <iostream>

using namespace std;

#define MAX_ELEM 100

template <typename type>
class Array
{
private:
	type* elements;
	int capacity;
	int lowerbound;
	int upperbound;
	int dummy;
public:
	//User constructor that creates an empty array whose indexes start from 0
	Array();
	//User constructor that receives the number of elements of the array(0 to n – 1 indexes)
	Array(int);
	//User constructor that receives the lower bound and upper bound constructor. (Inclusive)
	Array(int, int);
	//The copy constructor
	Array(const Array <type>&);
	//Release all memories allocated for the array
	~Array();
	//Add an element to the end of the array (Increasing the upper bound)
	bool add_item(type);
	//For removing the last element of the array (Decreasing the upper bound)
	void remove_item();
	//For removing the first occurrence of a given value from the array if it exists in the array (Decreasing the upper bound)
	void remove_item(type);
	//Insert an element at the given position (Increasing the upper bound)
	bool insert_item(int, type);
	//Removing the element at a given position (Decreasing the upper bound)
	void erase_item(int);
	//for finding an item in the array, your method should be able to say that the item is in the array or not and at what position
	bool find_item(type, int&);
	//For assigning an array to another array
	Array <type>& operator=(Array <type>&);
	//For indexing the elements of the list
	type& operator[](int);
	//For printing all elements of the array Example: 25, 12, 29, 35
	template <typename typex> friend ostream& operator <<(ostream&, Array <typex>&);
};