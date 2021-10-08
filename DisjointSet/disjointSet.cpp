#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<int> ds;

//FIND operation
//Time complexity - O(n)
int find(int v) {
  if (ds[v] == -1)
    return v;

  return find(ds[v]);
}

//UNION operation
//Time complexity - O(n)
void unionOp(int fromP, int toP) {
  fromP = find(fromP);
  toP = find(toP);
  ds[fromP] = toP;
}

bool isCyclic(vector<pair<int, int> > &edgeList) {
  for (auto p: edgeList) {
    int fromP = find(p.first); //FIND absolute parent of subset
    int toP = find(p.second);

    if (fromP == toP)
      return true;

    //UNION operation
    unionOp(fromP, toP); //UNION of 2 sets
  }
  return false;
}

int main() {
  int V = 5, E = 4;
  ds.resize(V, -1); //Mark all vertices as seperate subsets with only 1 element
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
