//Dijkstra's Algorithm for Adjacency List Representation

#include<iostream>
using namespace std;

struct AdjListNode {
  int dest;
  int weight;
  struct AdjListNode* next;
};

struct AdjList {
  struct AdjListNode *head;
};

struct Graph {
  int V;
  struct AdjList *array;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
  struct AdjListNode* n = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  n->dest = dest;
  n->weight = weight;
  n->next = NULL;
  return n;
}

struct Graph* createGraph(int V) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;

  //create an array of adjacency lists. Size of array will be V
  graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

  //intialize each adjacency list as empty by making head as NULL
  for (int i = 0; i < V; i++)
    graph->array[i].head = NULL;

  return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
  struct AdjListNode* n = newAdjListNode(dest, weight);
  n->next = graph->array[src].head;
  graph->array[src].head = n;

  n = newAdjListNode(src, weight);
  n->next = graph->array[dest].head;
  graph->array[dest].head = n;
}

int main() {
  int V = 9;
  struct Graph* graph = createGraph(V);

  return 0;
}
