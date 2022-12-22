// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#pragma once
#include "Graph.h"
#include "Forest.h"
#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;


Forest::Forest()
{
	numVer = 0;
	cap = 0;
	int n = 2; //(here default will be 2) (graph would be vertices 1 and 2 with no edges)
	vertices = new DoubleLinkedList[n + MAX_ELEM];
	if (vertices == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		numVer = n;
		cap = n + MAX_ELEM;
	}
}

Forest::Forest(int n)
{
	numVer = 0;
	cap = 0;
	vertices = new DoubleLinkedList[n + MAX_ELEM];
	if (vertices == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		numVer = n;
		cap = n + MAX_ELEM;
	}
}


bool Forest::add_edge(int v1, int v2) {


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

			return true;
		}
	}

	return false;
}

bool Forest::edge_exist(int v1, int v2) {
	if (v1 == v2) {

		//since there won't be any cycles in the graph
		return false;
	}
	if (get_degree(v1) == 0) {
		return false;
	}


	return vertices[v1 - 1].search(v2);

}

///when adding an edge do we just add it in the end
bool Forest::remove_edge(int v1, int v2) {

	if (v1 == v2) {
		return false;
	}
	if (v1 <= numVer && v1 > 0 && v2 <= numVer && v2 > 0) {

		//since the vertices array uses 0 based index but the v1 and v2 given is 1 based index
		int v11 = v1 - 1;

		//check if the edge exist before removing
		if (edge_exist(v1, v2)) {
			vertices[v1 - 1].remove_item(v2);
			vertices[v2 - 1].remove_item(v1); // added
			return true;
		}
	}
	return false;
}
