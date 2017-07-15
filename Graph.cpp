/*
Programmer: John Zavisa
Assignment: Open Lab 7
Class: CSCI3110
Course Instructor: Dr. Dong
Due Date: 4:00AM, Monday, 4/24/17
Description: This program uses maps and graphs to build graph, add node, add edge, BFS, DFS, and Shortest Path
*/

#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <iterator>
#include <iostream>
#include <list>
#include <vector>
#include "Graph.h"

using namespace std;

Graph::Graph()
{
}

//Definition for addVertex function
void Graph::addVertex(const string &node)
{
	pair<string, map<string, int>> vertex;		//Create pair for storing node name

	vertex.first = node;		//Set first in pair to node input

	graph.insert(vertex);
}

//Definition for add edge function
void Graph::addEdge(std::string sourceName, std::string targetName, int weight) throw (GraphException)
{
	//if graph does not have source node, throw an exception
	if (graph.find(sourceName) == graph.end() || graph.find(targetName) == graph.end())
	{
		throw GraphException("Edge does not exist. One of the endpoints is invalid.");
	}

	//Create pair for storing edge
	pair<string, int> edge;

	//set first in pair to target node, and 2nd in pair to weight
	edge.first = targetName;
	edge.second = weight;

	graph[sourceName].insert(edge);

}

//Depth First Search
void Graph::DFS(const std::string& source)
{
	set<string> visited;		//Create a set of visited nodes
	visited.insert(source);		//Insert starting node
	privateDFS(source, visited);	//Perform Depth first search based on starting node

}
//Depth first search function for making the calculation
void Graph::privateDFS(const std::string& source, set<string>& visited)
{
	visited.insert(source);			
		
	for (auto i : graph[source])
	{
		if (visited.find(i.first) == visited.end())	
		{
			cout << "(" << source << "," << i.first << ") ";
			privateDFS(i.first, visited);
		}
	}

}

//Breadth First Search
void Graph::BFS(const std::string& source)
{

	queue<string> needToTraverse;	//queue for storing un traversed nodes
	needToTraverse.push(source);	

	set<string> visited;		//set for storing visited nodes
	visited.insert(source);

	/*	commented out because crashed ?????
	if (graph.find(source) == graph.end())
	{
	throw GraphException("Source not in graph");
	}*/

	while (!needToTraverse.empty()) //while needToTraverse is not empty, traverse through and edit set/queue
	{
		for (auto it = graph[needToTraverse.front()].begin(); it != graph[needToTraverse.front()].end(); ++it)
		{
			if (visited.find(it->first) == visited.end())
			{
				visited.insert(it->first);
				needToTraverse.push(it->first);

				cout << "(" << needToTraverse.front() << ", " << it->first << ") ";
			}
		}

		//cout << needToTraverse.front() << endl;
		needToTraverse.pop();
	}

	//removes source to check if bfs is empty
	visited.erase(source);

	if (visited.empty())
	{
		throw GraphException("Empty BFS");
	}

}

//Display graph
void Graph::printGraph()
{
	cout << "*********************Graph*********************" << endl;
	cout << "Vertices: " << endl;;

	//Loop and display vertices
	for (auto it = graph.begin(); it != graph.end(); ++it)
	{
		cout << it->first << "    ";
	}

	cout << endl;
	cout << endl;
	cout << "Edges: " << endl;

	//Loop and display edges
	for (auto it = graph.begin(); it != graph.end(); ++it)
	{
		for (auto it2 = graph[it->first].begin(); it2 != graph[it->first].end(); ++it2)
		{
			cout << " (" << it->first << ", ";
			cout << it2->first << ", ";
			cout << it2->second << ")";
		}
		cout << endl;
	}

	cout << "______________________________________________" << endl;
}

//This method will print Vertices & Edges
std::ostream& operator<<(std::ostream& ostream, const Graph& graph)
{
	ostream << "*********************Graph*********************" << endl;
	ostream << "Vertices:" << endl;

	//Print Vertices
	for (std::map< std::string, bool >::const_iterator it = graph.nodes.begin(); it != graph.nodes.end(); it++)
	{
		ostream << it->first << "\t";
	}

	// Print Edges
	ostream << endl << "Edges:" << endl;
	map< string, map<string, int> >::const_iterator it = graph.printGraph1.begin();

	//for-loop to print with printGraph
	for (; it != graph.printGraph1.end(); it++)
	{
		map<string, int>::const_iterator it2 = it->second.begin();
		for (; it2 != it->second.end(); it2++)
		{
			ostream << "(" << it->first << ", " << it2->first << ", " << it2->second << ")\t";	// print of the format (a, b, 6)
		}
		ostream << endl;
	}

	ostream << "*********************Graph*********************" << endl;
	return ostream;
}

void Graph::shortestPath(std::string source, int count)
{
	

	for (auto it = graph.begin(); it != graph.end(); ++it)
	{
		
		for (auto it2 = graph[it->first].begin(); it2 != graph[it->first].end(); ++it2)
		{
			
			bool flag = false;
			int tempDist = it2->second;
			
			if (count > 0)
			{
				int currDist = it2->second;
				if ( currDist < tempDist)
				{
					
					cout << " (" << it->first << ", ";
					cout << it2->first << ", ";
					cout << it2->second << ")";
				}
				else
				{
					cout << " (" << it->first << ", ";
					cout << it2->first << ", ";
					cout << it2->second << ")";
				}
			}
			
			count++;


			/*cout << " (" << it->first << ", ";
			cout << it2->first << ", ";
			cout << it2->second << ")";*/
		}
		cout << endl;
	}

	cout << endl;
}
