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

//structure to represent a min heap node
struct MinHeapNode {
  int v;
  int dist;
};

//structure to represent a min heap
struct MinHeap {
  int size; //number of heap nodes present currently
  int capacity; //capacity of min heap
  int *pos; //this is needed for decreaseKey()
  struct MinHeapNode **array;
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

//function to create a new min heap node
struct MinHeapNode* newMinHeapNode(int v, int dist) {
  struct MinHeapNode* n = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
  n->v = v;
  n->dist = dist;
  return n;
}

//funtion to create a min heap
struct MinHeap* createMinHeap(int capacity) {
  struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
  minHeap->pos = (int*)malloc(capacity * sizeof(int));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
  return minHeap;
}

//function to swap two nodes of min heap
void swapMinHeapNode(struct MinHeapNode** x, struct MinHeapNode** y) {
  struct MinHeapNode *t = *x;
  *x = *y;
  *y = t;
}

void minHeapify(struct MinHeap* minHeap, int index) {
  int smallest, left, right;
  smallest = index;
  left = 2 * index + 1;
  right = 2 * index + 2;

  if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist) {
    smallest = left;
  }

  if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist) {
    smallest = right;
  }

  if (smallest != index) {
    //the nodes to be swapped in min heap
    MinHeapNode *smallestNode = minHeap->array[smallest];
    MinHeapNode *indexNode = minHeap->array[index];

    //swap positions
    minHeap->pos[smallestNode->v] = index;
    minHeap->pos[indexNode->v] = smallest;

    //swap nodes
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);

    minHeapify(minHeap, smallest);
  }
}

//function to check minHeap is empty or not
int isEmpty(struct MinHeap* minHeap) {
  return minHeap->size == 0;
}

//function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
  if (isEmpty(minHeap))
    return NULL;

  //store the root node
  struct MinHeapNode* root = minHeap->array[0];

  //replace root node with last node
  struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
  minHeap->array[0] = lastNode;

  //update position of last node
  minHeap->pos[root->v] = minHeap->size - 1;
  minHeap->pos[lastNode->v] = 0;

  //reduce heap size and heapify root
  --minHeap->size;
  minHeapify(minHeap, 0);

  return root;
}

//function to decrease dist value of a given vertex v
//this function uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
  //get the index of v in heap array
  int i = minHeap->pos[v];

  //get the node and update its dist value
  minHeap->array[i]->dist = dist;

  //travel up while the complete tree is nit heapified
  //this is a O(logN) loop
  while (i && minHeap->array[i]->dist < minHeap->array[(i-1)/2]->dist) {
    //swap this node with its parent
    minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
    minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
    swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i-1)/2]);

    //move the parent index
    i = (i-1)/2;
  }
}

//function to check if a given vectex 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v) {
  if (minHeap->pos[v] < minHeap->size)
    return true;
  return false;
}

void printArr(int dist[], int n) {
  cout<<"Vertex \t Distance from source\n";
  for (int i = 0; i < n; i++)
    cout<<i<<"\t\t"<<dist[i]<<"\n";

  cout<<endl;
}

//function to calculates distances of shortest oaths from source to all vertices
//Time Complexity - O(ElogV)
void dijkstra(struct Graph *graph, int src) {
  int V = graph->V; //number of vertices in graph
  int dist[V];
  struct MinHeap* minHeap = createMinHeap(V); //create minHeap with capacity V
  
  //initialize min heap
  for (int v = 0; v < V; v++) {
    dist[v] = INT_MAX;
    minHeap->array[v] = newMinHeapNode(v, dist[v]);
    minHeap->pos[v] = v;
  }

  //make dist value of src vertex as 0 so that it is extracted first
  minHeap->array[src] = newMinHeapNode(src, dist[src]);
  minHeap->pos[src] = src;
  dist[src] = 0;
  decreaseKey(minHeap, src, dist[src]);

  //intially size of min heap is equal to V
  minHeap->size = V;

  while(!isEmpty(minHeap)) {
    struct MinHeapNode* minHeapNode = extractMin(minHeap);
    int u = minHeapNode->v; //extracted vertex number
    //traverse throught all adjacent vertices of u & update their distance values
    struct AdjListNode* adjList = graph->array[u].head;

    while (adjList != NULL) {
      int v = adjList->dest;
      if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && adjList->weight + dist[u] < dist[v]) {
        dist[v] = dist[u] + adjList->weight;
        decreaseKey(minHeap, v, dist[v]);
      }
      adjList = adjList->next;
    }
  }

  printArr(dist, V);
}

int main() {
  int V = 9;
  struct Graph* graph = createGraph(V);

  addEdge(graph, 0, 1, 4);
  addEdge(graph, 0, 7, 8);
  addEdge(graph, 1, 2, 8);
  addEdge(graph, 1, 7, 11);
  addEdge(graph, 2, 3, 7);
  addEdge(graph, 2, 8, 2);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 4, 9);
  addEdge(graph, 3, 5, 14);
  addEdge(graph, 4, 5, 10);
  addEdge(graph, 5, 6, 2);
  addEdge(graph, 6, 7, 1);
  addEdge(graph, 6, 8, 6);
  addEdge(graph, 7, 8, 7);

  dijkstra(graph, 0);

  return 0;
}
