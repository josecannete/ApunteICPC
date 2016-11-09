#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

vector< pair<int, ii> > EdgeList; // (peso, par de vertices)
// Al leer el input agregar a la edge list como
// EdgeList.push_back(peso, ii(nodo1, nodo2))
int E, mst_cost, n; // E = aristas n = nodos

void kruskal(){
  sort(EdgeList.begin(), EdgeList.end()); // Cambiar el orden para maxST
  UnionFind UF(n);
  for (int i = 0; i < E; i++){
    pair<int, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)){
      mst_cost += front.first;
      UF.unionSet(front.second.first, front.second.second);
    }
  }
}
