// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#pragma once

#include <iostream>

using namespace std;

class Node
{
	friend class DoubleLinkedList;

	int data;
	Node* next;
	Node* previous;
	//void* operator new[](size_t);
};

class DoubleLinkedList
{
private:
	Node* head;
	Node* tail;
	int dummy;
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList&);
	//~DoubleLinkedList(); 
	//Prof recommend adding operator= and copy constructor for the destructor not 
	// to cause a breakpoint error and memory leaks however it did not solve the problem 
	//DoubleLinkedList& operator =(DoubleLinkedList&);
	Node* getHead();
	bool add_to_front(int);
	bool add_to_back(int);
	int  count_nodes();
	bool insert_item(int, int);
	bool search(int);
	void remove_item(int);
	void remove_from_front();
	void remove_from_back();
	int& operator[](int);
	friend ostream& operator<<(ostream&, DoubleLinkedList&);
};