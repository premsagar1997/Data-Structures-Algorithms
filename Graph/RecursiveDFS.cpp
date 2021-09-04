#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph {
  public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void DFS(int s);
};

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w); //add w to v's list
}

//Time complexity - O(V+E), where V is the number of vertices and E is the number of edges in the graph
//Space complexity - O(V) - Since an extra visited array is needed of size V
void Graph::DFS(int s) {
  visited[s] = true;
  cout<<s<<" ";

  list<int>::iterator it;
  for (it = adj[s].begin(); it != adj[s].end(); ++it) {
    if (!visited[*it])
      DFS(*it);
  }
}

int main() {
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.DFS(2);
  cout<<endl;
  return 0;
}
