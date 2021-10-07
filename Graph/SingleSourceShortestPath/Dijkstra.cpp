//Dijkstra's Algorithm for Adjacency Matrix representation
//Dijkstra's algorithm is a Greedy algorithm
//Dijkstra doesn't work with for Graphs with neagtive weight cycle

#include<iostream>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX, minIndex;

  for (int v = 0; v < V; v++) {
    if (sptSet[v] == false && dist[v] <= min) {
      min = dist[v];
      minIndex = v;
    }
  }

  return minIndex;
}

void printDistance(int dist[]) {
  cout<<"Vertex \t Distance from source"<<endl;
  for (int i = 0; i < V; i++) {
    cout<<i<<"\t\t"<<dist[i]<<endl;
  }
}

void printPath(int parent[], int j) {
  if (parent[j] == -1)
    return;

  printPath(parent, parent[j]);

  cout<<j<<" ";
}

void printSolution(int dist[], int n, int parent[]) {
  int src = 0;
  cout<<"Vertex \t\t Distance \t\t Path\n";
  for (int i = 1; i < V; i++) {
    cout<<src<<"->"<<i<<"\t\t"<<dist[i]<<"\t\t"<<src<<" ";
    printPath(parent, i);
    cout<<endl;
  }
  cout<<endl;
}

/** Time complexity - O(V^2)
 * If the Input graph is represented using adjacency list, it can be reduced to O(ElogV)
 * @param - graph[][] and source
 * Dijkstra's Algorithm doesn't work for graphs with negative weight cycles.
 */

void dijkstra(int graph[V][V], int src) {
  //dist[i] will hold the shortest distance from src to i
  int dist[V];

  //sptSet[i] will be true if vertex i is included in shortest path tree
  //or shortest distance from src to i is finalized
  bool sptSet[V];

  //parent array to store shortest path tree
  int parent[V];
  parent[0] = -1;

  //initialize all distance as Infinite and sptSet[] as false
  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    sptSet[i] = false;
  }

  dist[src] = 0;

  for (int count = 0; count < V - 1; count++) {
    //pick the minimum distance vertex from the set vertices not yet processed
    //u is always equal to src in the first iteration
    int u = minDistance(dist, sptSet);

    //mark the picked vertex as processed
    sptSet[u] = true;

    //update dist value of the adjacent vertices of the picked vertex.
    for (int v = 0; v < V; v++) {
      //update dist[v] only if is not in sptSet, there is an edge from u to v,
      //and total weight of the path from src to v through u is smaller than current value of dist[v]
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v]) < dist[v]) {
        parent[v] = u;
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printSolution(dist, V, parent);
}

int main() {
  int graph[V][V] = {
    { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
  };

  dijkstra(graph, 0);

  return 0;
}
