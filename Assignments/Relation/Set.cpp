#include <iostream>
#include "Set.h"

using namespace std;

template <typename typex>
ostream& operator<<(ostream& out, Set <typex>& s)
{
	int i;
	out << "{";
	for (i = 0; i < s.cardinality(); ++i)
	{
		if (i != 0) out << ", ";
		out << s.elements[i];
	}
	out << "}";
	return out;
}

template <typename type>
Set <type>::Set()
{
	card = 0;
	capacity = 0;
	elements = new type[MAX_CARD];
	if (elements == NULL)
		cout << "Not enough memory for this set!" << endl;
	else
		capacity = MAX_CARD;
}

template <typename type1>
Set <type1>::Set(const Set <type1>& s)
{
	int i;
	card = s.card;
	elements = new type1[s.capacity];
	if (elements == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		capacity = s.capacity;
		card = s.card;
	}
	for (i = 0; i < s.card; ++i)
		elements[i] = s.elements[i];
}

template <typename type>
Set<type>& Set <type>::operator=(Set <type>& s)
{
	int i;
	int* temp;
	temp = new type[s.capacity];
	if (temp == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		capacity = s.capacity;
		card = s.card;

		for (i = 0; i < s.card; ++i)
			temp[i] = s.elements[i];

		delete[] elements;
		elements = temp;
	}
	return *this;
}

template <typename type>
Set <type>::~Set()
{
	delete[] elements;
}

template <typename type>
int Set <type>::cardinality()
{
	return card;
}

template <typename type>
bool Set <type>::is_member(type x)
{
	int i;
	for (i = 0; i < card; ++i)
		if (elements[i] == x) return true;

	return false;
}

template <typename type>
type Set <type>::get_item(int index)
{
	if (index >= 0 && index < card)
		return elements[index];
	cout << "Index out of Range!" << endl;
	return 0; //just a default
}

template <typename type>
bool Set <type>::add_element(type x)
{
	int i;

	if (card >= MAX_CARD)
		return false;
	if (card == capacity)
	{
		int new_cap = capacity + MAX_CARD / 2;
		type* temp;
		temp = new type[new_cap];
		if (temp == NULL)
		{
			cout << "Not Enough Memory" << endl;
			return false;
		}

		for (i = 0; i < card; ++i)
			temp[i] = elements[i];

		delete[] elements;
		elements = temp;
		capacity = new_cap;
		++card;
		return true;
	}

	for (i = 0; i < card; ++i)
		if (elements[i] == x) return true;

	elements[card++] = x;
	return true;
}

template <typename type>
void Set<type>::remove_element(type x)
{
	int i, p = -1;

	for (i = 0; i < card; ++i)
	{
		if (elements[i] == x)
		{
			p = i;
			break;
		}
	}

	if (p != -1)
	{
		for (i = p; i < card; ++i)
			elements[i] = elements[i + 1];
		--card;
	}
}

template <typename type>
bool Set <type>::subset(Set <type> s)
{
	int i;
	for (i = 0; i < card; ++i)
		if (!s.is_member(elements[i])) return false;

	return true;
}

template <typename type>
bool Set <type>::equal(Set <type> s)
{
	//this --> E
	//int i;
	//this->elements[i];
	//this->card;
	//Set s
	//Set *p;

	//p = &s;
	//s.card;
	//p->card;

	//subset(s) == this->subset(s)
	//E called this method. (E is a set)
	//We want E to be a subset of s
	//And s to be a subset of E
	//this is a pointer that points E
	if (subset(s) && s.subset(*this))
		return true;

	return false;
}

template <typename type>
Set<type> Set <type>::Union(Set <type> s)
{
	int i;
	Set <type> result;
	for (i = 0; i < card; ++i)
		result.add_element(elements[i]);

	for (i = 0; i < s.card; ++i)
		result.add_element(s.elements[i]);

	return result;
}

template <typename type>
Set<type> Set<type>::intersection(Set<type> s)
{
	int i;
	Set <type> result;
	for (i = 0; i < card; ++i)
		if (s.is_member(elements[i])) result.add_element(elements[i]);

	return result;
}

template <typename type>
Set<type> Set<type>::difference(Set<type> s)
{
	int i;
	Set <type> result;
	for (i = 0; i < card; ++i)
		if (!s.is_member(elements[i])) result.add_element(elements[i]);

	return result;
}

template <typename type>
Set<type> Set<type>::mutual_difference(Set <type> s)
{
	int i;
	Set <type> s1 = difference(s);
	Set <type> s2 = s.difference(*this);
	return s1.Union(s2);
}
