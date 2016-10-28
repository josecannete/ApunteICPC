#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int> > adj;
vector<int> topo;

void Toposort(int nodo){
  visited[nodo] = 1;

  for (int i = 0; i < adj[nodo].size(); i++){
    int v = adj[nodo][i];
    if (!visited[v])
      Toposort(v);
  }

  topo.push_back(nodo);
}

int main(){
  // hacer toposort
  // toposort va a quedar con los nodos de arriba al final
  // lo arreglamos para que queden al principio con

  reverse(topo.begin(), topo.end());
}
