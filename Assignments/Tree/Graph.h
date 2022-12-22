// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#pragma once
#include <iostream>
#include "DoubleLinkedList.h"

#define MAX_ELEM 100

using namespace std;


class Graph
{
protected:
	//number of vertices in the graph
	int numVer;
	//capacity of the array (max number od vertices)
	int cap;
	//Dynamic array of ints will be updated to accomodate linked linsts
	DoubleLinkedList* vertices;

public:
	//The default constructor that initializes a graph of any default number of nodes without any edges 
	Graph();
	//The user constructor, which initializes the graph with a given number of nodes without any edges
	Graph(int);
	//The copy constructor 
	Graph(const Graph&);
	//The destructor
	~Graph();
	//= operator added as per prof recommendation to fix a memory leak
	Graph& operator =(Graph&);
	//Adds a vertex to the graph nothing sent as param since the next vertex would be n + 1
	bool add_vertex();
	//Add an edge between two given vetices
	bool add_edge(int, int);
	//Remove an edge between two given edges
	void remove_edge(int, int);
	//Removes the last vertex from the graph, also removing it from all DLL where it appears
	void remove_vertex();
	//Check if there is an edge between two given vertices
	bool edge_exist(int, int);
	//returns the degree of a vertex (the number of vertices it is connected to)
	int get_degree(int);
	//Adds a vertex to the graph prefix
	Graph operator++();
	//Adds a vertex to the graph postfix
	Graph operator++(int);
	//Removes the last vertex of the graph prefix
	Graph operator--();
	///Removes the last vertex of the graph postfix
	Graph operator--(int);
	//Checks if a path exists between two given vertices
	bool path_exist(int, int);
	//Prints a list of integers, which show the breadth first search of the graph starting from a given node
	void BFS(int);
	//Prints a list of integers, which show the depth first search of the graph starting from a given node
	void DFS(int);
	//For printing the graph
	friend ostream& operator<<(ostream&, Graph&);
};