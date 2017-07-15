/*
Programmer: John Zavisa
Description: This program uses maps and graphs to build graph, add node, add edge, BFS, DFS, and Shortest Path
*/

#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iostream>

using std::cout;
using std::endl;


class GraphException : public std::exception
{
public:
	GraphException(std::string msg = "Graph Exception")
		: exception(msg.c_str())
	{}
};


class Graph
{
public:

	Graph::Graph();

	// Add a vertex
	

	void addVertex(const std::string& node);

	// Add an edge.
	// Throw a GraphException if vertices of this
	// node are not in this graph
	// pre-cond: the edge between sourceName and targetName does not exist
	void addEdge(std::string sourceName, std::string targetName, int weight)
		throw (GraphException);


	// Depth-first traversal: visit ALL vertices once
	// During the visit, print edges in the order they are visited
	// If graph has no edge, print some information
	void DFS(const std::string& source);

	// Breadth-first traversal: visit ALL vertices once
	// During the visit, print edges in the order they are visited
	// If graph has no edge, print some information
	void BFS(const std::string& source);

	//Private DFS to be used within DFS
	void privateDFS(const std::string& source, std::set<std::string>& visited);

	//Declaration for printing graph 
	void printGraph();

	void shortestPath(std::string source, int count);

	//overload the << operator
	friend std::ostream& operator << (std::ostream&, const Graph&);

	
	std::map< std::string, std::map<std::string, int> >    graph;			//Graph member
	std::map< std::string, std::map<std::string, int> >    printGraph1;		//display graph member
	std::map< std::string, bool >    nodes;									//nodes 

};
