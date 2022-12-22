#include <iostream>

using namespace std;

#define MAX_CARD 1000

template <typename type>
class Set
{
private:
	int card; //S1 = S2;
	type* elements;
	int capacity;
public:
	Set();
	Set(const Set <type>&);
	~Set();
	int cardinality();
	bool add_element(type);
	void remove_element(type);
	type get_item(int);
	bool is_member(type);
	bool equal(Set<type>);
	bool subset(Set<type>);
	Set<type>& operator=(Set <type>&);
	Set <type> Union(Set <type>);
	Set <type> intersection(Set <type>);
	Set <type> difference(Set <type>);
	Set <type> mutual_difference(Set <type>);
	template <typename typex> friend ostream& operator <<(ostream&, Set <typex>&);
};
