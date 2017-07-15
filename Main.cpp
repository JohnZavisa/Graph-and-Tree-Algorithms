/*
Programmer: John Zavisa
Description: This program uses maps and graphs to build graph, add node, add edge, BFS, DFS, and Shortest Path
*/

#include "Graph.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{
	Graph Graph1;		//Create object of Graph class
	int count = 0;
	//Add vertices
	Graph1.addVertex("A");
	Graph1.addVertex("B");
	Graph1.addVertex("C");
	Graph1.addVertex("D");
	Graph1.addVertex("E");
	Graph1.addVertex("F");
	Graph1.addVertex("G");
	Graph1.addVertex("H");
	Graph1.addVertex("I");

	//Add Edges
	Graph1.addEdge("A", "B", 6);
	Graph1.addEdge("A", "F", 4);
	Graph1.addEdge("A", "I", 2);
	Graph1.addEdge("B", "C", 7);
	Graph1.addEdge("B", "E", 9);
	Graph1.addEdge("C", "D", 4);
	Graph1.addEdge("C", "E", 3);
	Graph1.addEdge("D", "G", 5);
	Graph1.addEdge("D", "H", 1);
	Graph1.addEdge("E", "G", 8);
	Graph1.addEdge("F", "G", 2);
	
	//Display Graph
	Graph1.printGraph();

	//DFS
	cout << "Depth first search(A): " << endl;
	Graph1.DFS("A");

	cout << endl << endl;

	//BFS
	cout << "Breadth first search(A): " << endl;
	Graph1.BFS("A");

	cout << endl;

	

	
	return 0;
}
