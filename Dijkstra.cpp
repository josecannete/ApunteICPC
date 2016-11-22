#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
typedef pair<int, int> ii;

// Vector que contiene las distancias desde el nodo
// en que partimos el BFS hasta el resto de los nodos
vector<int> d;
vector<int> visited;
vector<vector<ii> > adj; // Lista de adyacencia con pesos
int n; // Cantidad de nodos

void dijkstra(int nodo) {
  // Seteamos d, visited y creamos la cola de prioridad
  d.assign(n+1,inf);
  visited.assign(n+1,0);
  priority_queue<ii, vector<ii>, greater<ii> > cola;

  cola.push(ii(0, nodo));
  d[nodo] = 0;

  while(!cola.empty()) {
    ii u = cola.top(); cola.pop();
    int Actual = u.second;
    visited[Actual] = 1;
    for (int i = 0; i < adj[Actual].size(); i++) {
      ii Vecino = adj[Actual][i];
      int nodoVecino = Vecino.first;
      int pesoVecino = Vecino.second;
      if (!visited[nodoVecino] && d[Actual] + pesoVecino < d[nodoVecino]) {
        d[nodoVecino] = d[Actual] + pesoVecino;
        cola.push(ii(d[nodoVecino],nodoVecino));
      }
    }
  }
}

// Ver el problema 10986 - Sending email de UVa
int main(){

  // RECIBIMOS LOS DATOS CON UNA LISTA DE ADJ ASI:
  // 1 -> (nodo, peso), (nodo, peso)...

  return 0;
}
