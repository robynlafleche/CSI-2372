// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472

#pragma once

#include <iostream>
#include "DoubleLinkedList.h"
#include "Forest.h"
#include "Graph.h"
using namespace std;
//A forest is a graph, which does not have a cycle
//need to overide add vertex

class Forest : public Graph {
public:
	Forest();
	Forest(int f);
	bool add_edge(int, int);
	bool edge_exist(int, int);
	bool remove_edge(int, int);



};