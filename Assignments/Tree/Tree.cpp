// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#pragma once
#include "Graph.h"
#include "Forest.h"
#include "Tree.h"
#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;


Tree::Tree()
{
	root = 0;
	numVer = 0;
	cap = 0;
	int n = 1; //(here default will be 1) (1 vertex no edge and root is 1)
	vertices = new DoubleLinkedList[n + MAX_ELEM];
	if (vertices == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		numVer = n;
		cap = n + MAX_ELEM;
		root = n;
	}
	leafOrNot.resize(100);
	parentList[0] = 0;
	leafOrNot[0] = true;

}
bool Tree::add_edge(int v1, int v2) {


	//checks if the vertices are not the same since cycles are not allowed

	if (v1 == v2) {
		cout << "Please chose 2 different vertices for the edge, a cycle if not allowed" << endl;
		return false;
	}
	//Graph f = *this;
	//Graph f1(*this);
	//Graph g = *this;
	//f1.add_edge(v1, v2);
	//g.Graph::add_edge(v1, v2); //uses parent method
	//if (f1.is_cyclic(v1)) {

	cout << "checking vertices: numVer" << numVer << " v1: " << v1 << " v2: " << v2 << endl;
	if (path_exist(v1, v2)) {
		cout << "The edge" << " v1: " << v1 << " v2: " << v2 << " will add a cycle, try adding another vertex" << endl;
		return false;
	}
	else {
		cout << "testing!!" << " v1: " << v1 << " v2: " << v2 << endl;
		//checks if the vertex is >0 since vertices start at 1
		//checks if vertice number is less than or equal to number of vertices
		if (v1 <= numVer && v1 > 0 && v2 <= numVer && v2 > 0) {

			//since the vertices array uses 0 based index but the v1 and v2 given is 1 based index
			int v11 = v1 - 1;

			//check if it doesn't make a cycle

			vertices[v11].add_to_back(v2);
			vertices[v2 - 1].add_to_back(v1); //added
			parentList[v2 - 1] = v1 - 1;
			leafOrNot[v1 - 1] = false;
			leafOrNot[v2 - 1] = true;
			return true;
		}
	}

	return false;
}

bool Tree::remove_edge(int v1, int v2)
{
	if ((v2 < 0 && v1 < 0) || (v2 > numVer && v1 > numVer))
	{
		cout << "The vertices are invalid, try again with two vertices in the graph between 1 and " << numVer << endl;
		return false;
	}
	else
	{
		cout << "It is not possible to remove an edge without causing the tree to become disconnected (forest)" << endl;
		return false;
	}

}

Tree Tree::operator++()
{
	(*this).add_vertex();
	//adds an edge between the added leaf and last vertex
	(*this).add_edge(numVer - 1, numVer);
	return (*this);
}

Tree Tree::operator++(int x)
{
	Tree result = (*this);
	(*this).add_vertex();
	//adds an edge between the added leaf and last vertex
	(*this).add_edge(numVer - 1, numVer);
	return result;
}

Tree Tree::operator--()
{
	(*this).remove_vertex();
	return (*this);
}

Tree Tree::operator--(int x)
{
	Tree result = (*this);
	(*this).remove_vertex();
	return result;
}

bool Tree::add_treeVertex(int v)
{
	(*this).add_vertex();
	//adds an edge between the added leaf and given vertex
	(*this).add_edge(v, numVer);
	return true;
}

void Tree::set_root(int r)
{
	root = r;
}

ostream& operator<<(ostream& out, Tree& t)
{
	//out << T.root + 1 << T.vertices[0][0];

	int c = 0;
	out << t.root << endl;
	for (int i = 1; i < t.numVer; i++) {
		if (t.leafOrNot[i] == false) {
			//if()

			out << " --" << i + 1 << endl;
		}
		else {
			out << "   ---" << i + 1 << endl;

		}

	}


	return out;
}