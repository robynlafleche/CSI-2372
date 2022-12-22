// Robyn Lafleche 300017652
// Ghazal Sadeghpour 300096472
#include <iostream>
#include "Graph.h"
#include "DoubleLinkedList.h"

using namespace std;

Graph::Graph()
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

Graph::Graph(int n)
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

Graph::Graph(const Graph& g)
{
	int i;
	cap = 0;
	numVer = 0;
	vertices = NULL;
	DoubleLinkedList* temp;
	temp = new DoubleLinkedList[g.cap];
	if (temp == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		for (i = 0; i < g.numVer; ++i)
			temp[i] = g.vertices[i];
		numVer = g.numVer;
		cap = g.cap;
		delete[] vertices;
		vertices = temp;
	}
}

Graph::~Graph()
{
	delete[] vertices;
}

Graph& Graph::operator=(Graph& ng)
{
	int i;
	cap = 0;
	numVer = 0;
	DoubleLinkedList* temp;
	temp = new DoubleLinkedList[ng.cap];
	if (temp == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		for (i = 0; i < ng.numVer; ++i)
			temp[i] = ng.vertices[i];
		numVer = ng.numVer;
		cap = ng.cap;
		delete[] vertices;
		vertices = temp;
	}
	return *this;
}

bool Graph::add_vertex()
{
	int i;
	if (numVer == cap)
	{
		DoubleLinkedList* temp;
		temp = new DoubleLinkedList[cap + MAX_ELEM / 2];
		if (temp == NULL)
		{
			cout << "Not enough memory!" << endl;
			return false;
		}

		for (i = 0; i < numVer; ++i)
			temp[i] = vertices[i];

		cap = cap + MAX_ELEM / 2;
		delete[] vertices;
		vertices = temp;
	}
	++numVer;
	return true;
}

bool Graph::add_edge(int v2, int v1)
{
	if ((v2 < 0 && v1 < 0) || (v2 > numVer && v1 > numVer))
	{
		cout << "The vertices are invalid, try again with two vertices in the graph between 1 and " << numVer << endl;
		return false;
	}
	else
	{
		if (!(*this).edge_exist(v2, v1) && v2 != v1)
		{
			vertices[v2 - 1].add_to_back(v1); //using add_to_back from DoubleLinkedList

			// Added since it is undirected
			vertices[v1 - 1].add_to_back(v2); //using add_to_back from DoubleLinkedList
		}
		if (v2 == v1 )
			vertices[v2 - 1].add_to_back(v1); //using add_to_back from DoubleLinkedList
		return true;
	}

}

void Graph::remove_edge(int v2, int v1)
{
	if ((v2 < 0 && v1 < 0) || (v2 > numVer && v1 > numVer))
	{
		cout << "The vertices are invalid, try again with two vertices in the graph between 1 and " << numVer << endl;
	}
	else
	{
		if (vertices[v2 - 1].search(v1))
		{
			vertices[v2 - 1].remove_item(v1);
			// Added since the graph is undirected
			vertices[v1 - 1].remove_item(v2);
		}

		else
			cout << "Edge does not exist in graph." << endl;
	}
}

void Graph::remove_vertex()
{
	int i, j;

	for (i = 0; i < numVer - 1; ++i)
	{
		if (vertices[i].search(numVer))
			vertices[i].remove_item(numVer);
	}

	for (j = 0; j < vertices[numVer - 1].count_nodes(); ++j)
		vertices[numVer - 1].remove_from_back();

	--numVer;
}

bool Graph::edge_exist(int v2, int v1)
{
	if ((v2 < 0 && v1 < 0) || (v2 > numVer && v1 > numVer))
	{
		cout << "The vertices are invalid, try again with two vertices in the graph between 1 and " << numVer << endl;
		return false;
	}
	return vertices[v2 - 1].search(v1);
}

int Graph::get_degree(int v)
{
	//Implemented using count_nodes defined in DoubleLinkedList
	if (v < 0 || v > numVer)
	{
		cout << "The vertex is invalid, try again with a vertex in the graph between 1 and " << numVer << endl;
		return 0;
	}
	return vertices[v - 1].count_nodes();
}

Graph Graph::operator++()
{
	(*this).add_vertex();
	return (*this);
}

Graph Graph::operator++(int d)
{
	Graph result = (*this);
	(*this).add_vertex();
	cout << "Number of vertexes in the graph before the result of ++ is returned. Expected should be same as the above case." << endl << result.numVer << endl;
	return result;
}

Graph Graph::operator--()
{
	(*this).remove_vertex();
	return (*this);
}

Graph Graph::operator--(int d)
{
	Graph result = (*this);
	(*this).remove_vertex();
	cout << "Number of vertexes in the graph before the result of -- is returned. Expected should be same as the above case." << endl << result.numVer << endl;
	return result;
}

bool Graph::path_exist(int v2, int v1)
{
	if ((v2 < 0 && v1 < 0) || (v2 > numVer && v1 > numVer))
	{
		cout << "The vertices are invalid, try again with two vertices in the graph between 1 and " << numVer << endl;
		return false;
	}
	else
	{
		if (v2 == v1)
			return true;
		else
		{
			DoubleLinkedList temp, result;

			int i, j;
			bool* vis = new bool[numVer];
			for (int i = 0; i < numVer; i++)
				vis[i] = false;

			vis[v2 - 1] = true;

			temp.add_to_front(v2);

			while (temp.count_nodes() != 0)
			{
				int curr = temp[0];
				temp.remove_from_front();

				for (j = 0; j < vertices[curr - 1].count_nodes(); ++j)
				{
					int adj = vertices[curr - 1][j];

					if (adj == v1)
						return true;
					//else continue searching if we reach the end of the BFS return false
					if (!vis[adj - 1])
					{
						vis[adj - 1] = true;
						temp.add_to_back(adj);

					}
				}
			}
			return false;
		}
	}
}

void Graph::BFS(int start)
{
	DoubleLinkedList temp, result;

	int i, j;
	bool* vis = new bool[numVer];
	for (int i = 0; i < numVer; i++)
		vis[i] = false;

	vis[start - 1] = true;

	temp.add_to_front(start);

	while (temp.count_nodes() != 0)
	{
		int curr = temp[0];
		result.add_to_back(temp[0]);
		temp.remove_from_front();

		for (j = 0; j < vertices[curr - 1].count_nodes(); ++j)
		{
			int adj = vertices[curr - 1][j];
			if (!vis[adj - 1])
			{
				vis[adj - 1] = true;
				temp.add_to_back(adj);

			}
		}
	}
	cout << result << endl;
}

void Graph::DFS(int start)
{
	DoubleLinkedList temp, result;

	int i, j;
	bool* vis = new bool[numVer];
	for (int i = 0; i < numVer; i++)
		vis[i] = false;

	vis[start - 1] = true;

	temp.add_to_front(start);

	while (temp.count_nodes() != 0)
	{
		int curr = temp[0];
		result.add_to_front(temp[0]);
		temp.remove_from_front();

		for (j = 0; j < vertices[curr - 1].count_nodes(); ++j)
		{
			int adj = vertices[curr - 1][j];
			if (!vis[adj - 1])
			{
				vis[adj - 1] = true;
				temp.add_to_front(adj);

			}
		}
	}
	cout << result << endl;
}

ostream& operator<<(ostream& out, Graph& g)
{
	int j;
	//for printing V = { 1, ..., n}
	out << "V = {";
	for (j = 0; j < g.numVer; ++j)
	{
		out << (j + 1);
		if (j != g.numVer - 1)
			out << ", ";
	}
	out << "}" << endl;

	//for printing E = {...}
	out << "E = " << endl << "{" << endl;


	for (j = 0; j < g.numVer; ++j)
	{
		Node* root = g.vertices[j].getHead();
		if (root == NULL)
		{
			out << "  " << (j + 1) << "=> None";
			out << endl;
		}
		else
		{
			out << "  " << (j + 1) << "=> " << g.vertices[j];
			out << endl;
		}
	}
	out << "}" << endl;
	return out;
}