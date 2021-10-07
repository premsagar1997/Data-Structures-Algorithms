/** Bellman-Ford Algorithm
 * Input - Graph and a source vertex src
 * Output - Shortest distance to all vertices from src.
 * If there is a neagtive weight cycle, then shortest distance are not calculated, negative weight cycle is reported
 * Time Complexity - O(VE) which is more tham Dijkstra
 * Bellman-Ford works with negative weight cycle
 */

#include<iostream>
using namespace std;

//structure to represent a weighted edge in graph
struct Edge {
  int src;
  int dest;
  int weight;
};

//structure to represent a connected, directed and weighted graph
struct Graph {
  int V, E;
  struct Edge* edge;
};

//create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
  return graph;
}

void printArr(int dist[], int n) {
  cout<<"Vertex \t\t Distance from source\n";
  for (int i = 0; i < n; i++)
    cout<<i<<"\t\t"<<dist[i]<<endl;
  cout<<endl;
}

void bellmanFord(struct Graph* graph, int src) {
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  //initialize distances from src to all other vertices as INFINITE
  for(int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  //calculates shortest distances
  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if (dist[u] != INT_MAX && (dist[u] + weight) < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  //check for negative-weight cycles
  //the above steps guarantees shortest distance if graph doesn't contain negative weight cycle
  //If we get a shorter path, then there is a cycle
  for (int i = 0; i < E; i++) {
    int u = graph->edge[i].src;
    int v = graph->edge[i].dest;
    int weight = graph->edge[i].weight;
    if (dist[u] != INT_MAX && (dist[u] + weight) < dist[v]) {
      cout<<"Graph contains negative weight cycle!!!\n";
      break;
    }
  }

  printArr(dist, V);
}

int main() {
  int V = 5;
  int E = 8;
  struct Graph* graph = createGraph(V, E);

  //edge 0->1
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[0].weight = -1;

  //edge 0->2
  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[1].weight = 4;

  //edge 1->2
  graph->edge[2].src = 1;
  graph->edge[2].dest = 2;
  graph->edge[2].weight = 3;

  //edge 1->3
  graph->edge[3].src = 1;
  graph->edge[3].dest = 3;
  graph->edge[3].weight = 2;

  //edge 1->4
  graph->edge[4].src = 1;
  graph->edge[4].dest = 4;
  graph->edge[4].weight = 2;

  //edge 3->2
  graph->edge[5].src = 3;
  graph->edge[5].dest = 2;
  graph->edge[5].weight = 5;

  //edge 3->1
  graph->edge[6].src = 3;
  graph->edge[6].dest = 1;
  graph->edge[6].weight = 1;

  //edge 4->3
  graph->edge[7].src = 4;
  graph->edge[7].dest = 3;
  graph->edge[7].weight = -3;

  bellmanFord(graph, 0);

  return 0;
}
