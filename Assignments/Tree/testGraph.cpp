// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#include <iostream>
#include "Graph.h"
#include "Forest.h"
#include "Tree.h"
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	Graph g(6);

	cout << "Graph after initialization" << endl << g;

	//graph from the assignment description
	g.add_edge(1, 2);
	g.add_edge(2, 1);
	g.add_edge(2, 3);
	g.add_edge(2, 4);
	g.add_edge(3, 3);
	g.add_edge(4, 1);
	g.add_edge(4, 3);
	g.add_edge(5, 6);

	//extra edge that will be removed 
	g.add_edge(6, 5);

	cout << "Graph after adding all edges as shown in the pdf and 1 extra edge between 6->5" << endl << g;

	g.remove_edge(6, 5);

	cout << "Graph after remove the extra edge 6->5" << endl << g;

	++g;

	g.add_edge(7, 1);

	cout << "Graph after prefix ++ operator and adding a new edge between 7->1" << endl << g;


	g++;

	cout << "Graph after postfix operator ++" << endl << g;

	--g;

	cout << "Graph after prefix operator --" << endl << g;

	g--;

	cout << "Graph after postfix operator --" << endl << g;

	++g;

	cout << "Graph after prefix ++ operator and seeing if edge 7->1 was succesfully removed by -- operators" << endl << g;

	cout << "expected result is 3 for g.get_degree(2), actual result is: " << g.get_degree(2) << endl;

	cout << "expected result is 1 for g.path_exist(1, 4), actual result is: " << g.path_exist(1, 4) << endl;

	cout << "expected result is 0 for g.path_exist(1, 6), actual result is: " << g.path_exist(1, 6) << endl;

	cout << "expected result is 1 for g.edge_exist(5, 6), actual result is: " << g.edge_exist(5, 6) << endl;

	cout << "expected result is 0 for g.edge_exist(6, 5), actual result is: " << g.edge_exist(6, 5) << endl;

	cout << "expected result for g.BFS(1) is 1, 2, 3, 4 for starting node 1, actual result is: ";
	g.BFS(1);

	cout << "expected result for g.DFS(1) is 3, 4, 2, 1 for starting node 1, actual result is: ";
	g.DFS(1);

	cout << "testing forest" << endl;

	Forest f(5);
	cout << "first" << endl;
	f.add_edge(1, 2);
	cout << "second" << endl;

	f.add_edge(1, 3);
	f.add_edge(2, 3);
	cout << "checking" << f.edge_exist(2, 3) << endl;;
	//f++;

	cout << f;

	Tree t;
	
	t.add_treeVertex(1);
	++t;
	t.add_treeVertex(2);
	t.add_treeVertex(1);
	++t;
	--t;
	t.add_treeVertex(1);
	++t;
	t--;
	
	t.remove_edge(1, 2);
	
	cout << t << endl;
}