/** -------------------- GRAPH ------------------
 * A graph is a data structure that consists of the following two components:
 * 1. A finite set of vertices also called as nodes
 * 2. A finite set of ordered pair of the form (u, v) called as edge.
 * The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph.
 * The pair of the form (u, v) indicated that there is an edge from vertex u to vertex v.
 * The edge may contain weight/value/cost.
 * Graph are used to represent many real-life applications - graph are used to represent networks.
 * The networks may include paths in a city or telephone network or circuit network.
 * Graph are also used in social networks like linkedIn, Facebook.


 * Graph terminology
 * Adjacency - A vertex is said to be adjacent to another vertex if there is an edge connecting them
 * Path - A sequence of edges that allows you to go from vertex A to vertex B is called a path.
 * Directed Graph - A graph in which an edge (u, v) doesn't necessarily mean that there is an edge(v, u) as well. The edges is such a graph represented by arrows to show the direction of the edge.
 

 * Graph Representation
 *
 * Adjacency Matrix:- 
 * Adjacency matrix is a 2D array of size VxV where V is the number of vertices in a graph.
 * Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j.
 * Adjacency matrix for undirected graph is always symmetric.
 * Adjacency matrix is also used to represent weighted graphs.
 * If adj[i][j] = w, then there is an edge from vertex i to j woth weight w.
 * 
 * Adjacency List:-
 * An array of lists is used. The size of the array is equal to the number of vertices.
 * Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex.
 * This representation can also be used to represent a weighted graph.
 * The weights of edge can be represented as lists of pairs.
 */

#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) {
  for (int v = 0; v < V; ++v) {
    cout<<"\nAdjacency list of vertex - "<<v<<endl;
    for (int i = 0; i < adj[v].size(); i++) {
      cout<<v<<"->"<<adj[v][i]<<" ";
    }
    cout<<endl;
  }
}

int main() {
  int V = 5;
  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 4);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  printGraph(adj, V);
  return 0;
}
