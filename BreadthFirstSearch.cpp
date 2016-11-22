#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

// Vector que contiene las distancias desde el nodo
// en que partimos el BFS hasta el resto de los nodos
vector<int> d;
vector<vector<int> > adj; // Lista de adyacencia
int n; // Cantidad de nodos

void bfs(int nodo) {
  // Seteamos las distancias como infinito
  d.assign(n+1, inf);
  d[nodo] = 0;
  queue<int> cola;
  cola.push(nodo);
  while(!cola.empty()) {
    int u = cola.front(); cola.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int vecino = adj[u][i];
      if (d[vecino] == inf) d[vecino] = d[u] + 1, cola.push(vecino);
    }
  }
}

// Se asume un grafo conexo
void diametro(){
  // BFS desde un nodo arbitrario
  bfs(1);
  int nodoMasLejano = 1;
  // Buscamos el nodo mas lejano al nodo arbitrario
  for (int i = 0; i < n; i++)
    if (d[nodoMasLejano] < d[i])
      nodoMasLejano = i;
  // BFS desde ahi
  bfs(nodoMasLejano);
  // Encontramos el diametro
  int diametro = 0;
  for (int i = 0; i < n; i++)
    diametro = max(diametro, d[i]);
  cout << diametro << endl;
}


// Ejemplo de uso

int main(){

  return 0;
}
