// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#include <iostream>
#include "MappingRelation.h"
#include <string>
#include <vector>

using namespace std;

template <typename type1, typename type2>
MappingRelation<type1, type2>::MappingRelation()
{
	card = 0;
	capacity = 0;
	elements = new Pair<type1, type2>[MAX_CARD];
	if (elements == NULL)
		cout << "Not enough memory for this set!" << endl;
	else
		capacity = MAX_CARD;
}
template <typename type1, typename type2>
MappingRelation<type1, type2>::MappingRelation(const MappingRelation<type1, type2>& mr)
{
	int i;
	card = 0;
	capacity = 0;
	elements = new Pair<type1, type2>[mr.capacity];
	if (elements == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		capacity = mr.capacity;
		card = mr.card;
		
		for (i = 0; i < mr.card; ++i)
			elements[i] = mr.elements[i];
	}
}

template <typename type1, typename type2>
MappingRelation<type1, type2>::~MappingRelation<type1, type2>()
{
	delete[] elements;
}

template <typename type1, typename type2>
int MappingRelation<type1, type2>::cardinality()
{
	return card;
}

template <typename type1, typename type2>
Pair<type1, type2> MappingRelation<type1, type2>::getElement(int index)
{
	return elements[index];
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::add_element(type1 t1, type2 t2)
{
	int i;
	Pair<type1, type2> p;
	p.first = t1;
	p.second = t2;

	if (card == capacity)
	{
		int new_cap = capacity + MAX_CARD / 2;
		Pair<type1, type2>* temp;
		temp = new Pair<type1, type2>[new_cap];
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
	}

	elements[card++] = p;
	return true;
}

template <typename type1, typename type2>
void MappingRelation<type1, type2>::remove_element(type1 t1, type2 t2)
{
	int i, j = -1;
	Pair<type1, type2> p;
	p.first = t1;
	p.second = t2;


	for (i = 0; i < card; ++i)
	{
		if (elements[i].first == p.first && elements[i].second == p.second)
		{
			j = i;
			break;
		}
	}

	if (j != -1)
	{
		for (i = j; i < card; ++i)
			elements[i] = elements[i + 1];
		--card;
	}
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::is_member(type1 t1, type2 t2)
{
	int i;


	for (i = 0; i < card; ++i)
	{
		if (elements[i].first == t1 && elements[i].second == t2)
		{
			return true;
		}
	}
	return false;
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::operator==(MappingRelation<type1, type2> mr)
{
	if (card == mr.card) {
		int i;
		for (i = 0; i < card; ++i)
		{
			if (!(*this).is_member(mr.elements[i].first, mr.elements[i].second))
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::operator+(MappingRelation<type1, type2> mr)
{
	MappingRelation<type1, type2> result;

	int i, j;

	for (i = 0; i < card; ++i)
	{
		result.add_element(elements[i].first, elements[i].second);
	}

	for (j = 0; j < mr.card; ++j)
	{
		if (!(*this).is_member(mr.elements[j].first, mr.elements[j].second))
			result.add_element(mr.elements[j].first, mr.elements[j].second);
			
	}
	return result;
}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::operator-(MappingRelation<type1, type2> mr)
{
	MappingRelation<type1, type2> result;

	int i;

	for (i = 0; i < card; ++i)
	{
		if (!mr.is_member(elements[i].first, elements[i].second))
			result.add_element(elements[i].first, elements[i].second);
	}
	return result;
}

template <typename type1, typename type2>
vector<type2> MappingRelation<type1, type2>::operator[](type1 index)
{
	vector<type2> v;
	for (int i = 0; i < card; i++) {
		if (elements[i].first == index) 
		{
			v.insert(v.begin(), elements[i].second);
		}
	}
	return v;
}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::intersection(MappingRelation<type1, type2> mr)
{
	MappingRelation<type1, type2> result;
	
	int i;

	for (i = 0; i < card; ++i)
	{
		if (mr.is_member(elements[i].first, elements[i].second))
			result.add_element(elements[i].first, elements[i].second);
	}
	return result;
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::is_function()
{
	int i, j;
	for (i = 0; i < card; ++i)
	{
		for (j = i + 1; j < card - 1; ++j)
		{
			if (elements[i].first == elements[j].first && elements[i].second != elements[j].second)
				return false;
		}
	}
	return true;
}

template <typename type1x, typename type2x>
ostream& operator << (ostream& out, MappingRelation<type1x, type2x>& mr)
{
	int i;
	out << "{ ";
	for (i = 0; i < mr.card; ++i)
	{
		if (i != 0) out << ", ";
		out << "(" << mr.elements[i].first << ", " << mr.elements[i].second << ")";
	}
	out << " }";
	return out;
}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::inverse()
{
	MappingRelation<type1, type2> result;
	int i;


	for (i = 0; i < card; ++i)
	{
		result.add_element(elements[i].second, elements[i].first);
	}
	return result;
}

template <typename type1, typename type2> template <typename type3>
 MappingRelation<type1, type3> MappingRelation<type1, type2>::combination(MappingRelation<type2, type3> mr)
{
	MappingRelation<type1, type3> result;

	int i, j;

	for (i = 0; i < card; ++i)
	{
		for (j = 0; j < mr.cardinality(); ++j)
		{
			if (elements[i].second == mr.getElement(j).first)
				result.add_element(elements[i].first, mr.getElement(j).second);
		}
	}
	return result;
}