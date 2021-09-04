#include<iostream>
#include<map>
#include<list>
#include<stack>
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

void Graph::DFS(int s) {
  stack<int> st;
  st.push(s);
  list<int>::iterator it;

  while (!st.empty()) {
    s = st.top();
    st.pop();
    if (!visited[s]) {
      visited[s] = true;
      cout<<s<<" ";
    }
    //get all adjacent vertices of the popped vertex s
    //if a adjacent has not been visited, then push it to the stack
    for(it = adj[s].begin(); it != adj[s].end(); ++it) {
      if (!visited[*it])
        st.push(*it);    
    }
  }
}

int main() {
  Graph g;
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 4);
  g.DFS(0);
  cout<<endl;
  return 0;
}
