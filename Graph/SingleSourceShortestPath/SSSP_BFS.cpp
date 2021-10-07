/**Input - Given an unweighted graph
 * Output - Sortest path from source to destination
 * 
 * One solution is to solve in O(VE) time using Bellman Ford.
 * If there are no negative weight cycles, then we can solve in O(E+VLogV) time using Dijkstra's algorithm
 * 
 * BFS Algorithm - graph is unweighted, we can solve this problem in O(V+E) time.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int src, int dest) {
  adj[src].push_back(dest);
  adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[]) {
  queue<int> myQ;

  //boolean array visited[] which stores the information whether ith vertex is reached at least once in the BFS
  bool visited[v];

  //initially all vertices are unvisited so v[i] for all i is false
  //and as no path is yet constructed - dist[i] for all i set to infinity
  for (int i = 0; i < v; i++) {
    visited[i] = false;
    dist[i] = INT_MAX;
    pred[i] = -1;
  }

  //source is first to be visited and distance from source to itself should be 0
  visited[src] = true;
  dist[src] = 0;
  myQ.push(src);

  while (!myQ.empty()) {
    int u = myQ.front();
    myQ.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      if (visited[adj[u][i]] == false) {
        visited[adj[u][i]] = true;
        dist[adj[u][i]] = dist[u] + 1;
        pred[adj[u][i]] = u;
        myQ.push(adj[u][i]);

        if(adj[u][i] == dest)
          return true;
      }
    }
  }

  return false;
}

void printShortestPath(vector<int> adj[], int src, int dest, int v) {
  int pred[v], dist[v];

  if (BFS(adj, src, dest, v, pred, dist) == false) {
    cout<<"Given source & destination are not connected"<<endl;
    return;
  }

  vector<int> path;
  int temp = dest;
  path.push_back(temp);
  while (pred[temp] != -1) {
    path.push_back(pred[temp]);
    temp = pred[temp];
  }

  cout<<"Shortest path length is :- "<<dist[dest]<<endl;
  cout<<"Path is :- \n";
  for (int i = path.size() - 1; i >= 0; i--) {
    cout<<path[i]<<" ";
  }
  cout<<endl;
}

int main() {
  int v = 8;
  vector<int> adj[v];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 7);
  addEdge(adj, 4, 5);
  addEdge(adj, 4, 6);
  addEdge(adj, 4, 7);
  addEdge(adj, 5, 6);
  addEdge(adj, 6, 7);

  int src = 2, dest = 6;
  printShortestPath(adj, src, dest, v);

  return 0;
}
