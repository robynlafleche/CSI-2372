// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472

#pragma once

#include <iostream>
#include "DoubleLinkedList.h"
#include "Forest.h"
#include "Graph.h"
#include <vector>
#include <map>
using namespace std;

//A Tree is a forest, which is connected

class Tree : public Forest {
private:
	//root for the tree
	int root;
	vector<bool> leafOrNot = { false,false,false,false,false,false,false,false,false };
	map<int, int> parentList = {};
public:
	//Creates a tree with one vertex and no edges
	Tree();
	bool add_edge(int, int);
	//Removes an edge between two given vertices must be a leaf node
	bool remove_edge(int, int);
	//Adds a leaf and an edge to keep it as a tree (adds it to the last vertex)
	//Prefix 
	//PDF example adding new leaf 3 to 2
	Tree operator ++();
	//Postfix
	Tree operator ++(int);
	//Removes the last leaf and the edge between it
	//Prefix
	Tree operator --();
	//Postfix
	Tree operator --(int);
	//Adds a new vertex/leaf and add an edge between itself and a given vertex 
	//PDF example adding new leaf 4 to 2
	bool add_treeVertex(int);
	//sets the root to a given node
	void set_root(int);
	//For printing the tree
	friend ostream& operator<<(ostream&, Tree&);
};