#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
  int V; //number of vertices
  vector<int> *adj; //pointer to an array

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::BFS(int s) {
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  queue<int> q;

  visited[s] = true;
  q.push(s);

  while (!q.empty()) {
    s = q.front();
    cout<<s<<" ";
    q.pop();

    for (int j = 0; j < adj[s].size(); j++) {
      int e = adj[s][j];
      if (!visited[e]) {
        visited[e] = true;
        q.push(e);
      }
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(2);
  cout<<"\n";
  return 0;
}
