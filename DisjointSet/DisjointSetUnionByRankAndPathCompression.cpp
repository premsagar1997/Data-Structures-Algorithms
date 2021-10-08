#include<iostream>
#include<vector>
#include<utility>
using namespace std;

struct node {
  int parent;
  int rank;
};

vector<node> ds;

//FIND operation
//Time Complexity - O(logN)
int find(int v) {
  if (ds[v].parent == -1)
    return v;

  return ds[v].parent = find(ds[v].parent); //PATH COMPRESSION
}

//UNION operation
//Time Complexity - O(logN)
void unionOp(int fromP, int toP) {
  //UNION by RANK
  if (ds[fromP].rank > ds[toP].rank) { //fromP has higher rank
    ds[toP].parent = fromP;
  } else if (ds[fromP].rank < ds[toP].rank) { //toP has higher rank
    ds[fromP].parent = toP;
  } else { //Both have same rank and so anyone can be made as parent
    ds[fromP].parent = toP;
    ds[toP].rank += 1; //Increase rank of parent
  }
}

bool isCyclic(vector<pair<int, int> > &edgeList) {
  for (auto e: edgeList) {
    int fromP = find(e.first); //FIND absolute parent of subsets
    int toP = find(e.second);

    if (fromP == toP)
      return true;

    //UNION operation
    unionOp(fromP, toP); //UNION of 2 sets
  }
  return false;
}

int main() {
  int V = 5; //No. of vertices (0 to V-1)
  int E = 4; //No. of edges

  ds.resize(V); //Mark all vertices as seperate subsets with only 1 element
  for (int i = 0; i < V; i++) {
    ds[i].parent = -1;
    ds[i].rank = 0;
  }
  
  vector<pair<int, int> > edgeList;
  edgeList.push_back({0, 1});
  edgeList.push_back({1, 2});
  edgeList.push_back({2, 3});
  edgeList.push_back({3, 4});
  edgeList.push_back({0, 4});

  if(isCyclic(edgeList))
    cout<<"TRUE\n";
  else
    cout<<"FALSE\n";

  return 0;
}
