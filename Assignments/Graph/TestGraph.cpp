#include <iostream>
#include "Graph.h"
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	Graph gc(3);

	gc.add_edge(1, 2);
	gc.add_edge(2, 3);
	gc.add_edge(3, 1);

	cout << gc;

	cout << "Expected value is 3 for connectivity_type() of gc graph, actual value is: " << gc.connectivity_type() << endl;

	/*Graph guc(3);

	guc.add_edge(1, 2);
	guc.add_edge(2, 3);
	guc.add_edge(3, 1);

	cout << guc;

	cout << "Expected value is 2 for connectivity_type() of guc graph, actual value is: " << guc.connectivity_type() << endl;*/

	//Could not get unilateral check working

	Graph gwc(3);

	gwc.add_edge(1, 2);
	gwc.add_edge(3, 2);

	cout << gwc;

	cout << "Expected value is 1 for connectivity_type() of gwc graph, actual value is: " << gwc.connectivity_type() << endl;

	Graph gnc(4);

	gnc.add_edge(1, 2);
	gnc.add_edge(2, 3);

	cout << gnc;

	cout << "Expected value is 0 for connectivity_type() of gnc graph, actual value is: " << gnc.connectivity_type() << endl;


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

	gc = g;

	cout << "Checking to see if = operator works graph should be the same as the one below" << endl << gc;

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

	

}