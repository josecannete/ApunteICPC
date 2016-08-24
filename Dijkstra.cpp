#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
typedef pair<int, int> ii;

// Vector que contiene las distancias desde el nodo
// en que partimos el BFS hasta el resto de los nodos
vector<int> d;
vector<vector<ii> > adj; // Lista de adyacencia con pesos
int n; // Cantidad de nodos

void dijsktra(int nodo){
  d.assign(n+1,inf);
  priority_queue<ii> cola;

  cola.push(ii(nodo, 0));
  d[nodo] = 0;

  while(!cola.empty()){
    ii u = cola.top();
    int nodoActual = u.first;
    for (int i = 0; i < adj[nodoActual].size(); i++){
      ii parVecino = adj[nodoActual][i];
      int nodoVecino = parVecino.first;
      int pesoVecino = parVecino.second;
      if (d[nodoActual] + pesoVecino < d[nodoVecino])
        d[nodoVecino] = d[nodoActual] + pesoVecino;
        cola.push(ii(nodoVecino,d[nodoVecino]));
    }
  }
}


int main(){
  return 0;
}
