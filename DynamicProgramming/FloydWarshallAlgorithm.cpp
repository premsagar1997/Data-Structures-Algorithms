/** Floyd Warshall Algorithm
 * The Floyd Warshall Algorithm is for solving All Pairs Shortest Path problem.
 * The problem is to find shortest distances between every pair of vertices in a given edge weighted directed graph
 * 
 * Input - A graph(Adjacency Matrix Representation)
 * Output - Shortest distance matrix
 * Time Complexity - O(V^3)
 * 
 * Algorithm-
 * We Initialize the solution matrix same as the input graph matrix as a first step.
 * Then we Update the solution matrix by considering all vertices as an intermediate vertex.
 * The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the sortest path.
 * When we pick vertex number K as an intermediate vertex, we already have considered vertices {0, 1, 2, 3, ...k-1} as intermediate vertices.
 * For every pair (i, j) of the source & destination vertices respectively, there are two possible cases-
 * 1. K is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
 * 2. K is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
 * 
 */

#include<iostream>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF)
        cout<<"INF"<<"  ";
      else
        cout<<dist[i][j]<<"  ";
    }
    cout<<endl;
  }
}

void floydWarshall(int graph[][V]) {
  int dist[V][V];

  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      dist[i][j] = graph[i][j];

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if ((dist[i][k] != INF && dist[k][j] != INF) && dist[i][j] > (dist[i][k] + dist[k][j])) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  printSolution(dist);
}

int main() {
  int graph[V][V] = {
    { 0, 5, INF, 10 },
    { INF, 0, 3, INF },
    { INF, INF, 0, 1 },
    { INF, INF, INF, 0 },
  };

  floydWarshall(graph);
  cout<<endl;

  return 0;
}
