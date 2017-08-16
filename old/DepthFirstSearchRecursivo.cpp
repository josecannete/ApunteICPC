#include <bits/stdc++.h>
using namespace std;

// Vectores en los que guardaremos tiempos de llegada y de salida
vector<int> st;
vector<int> ft;
vector<vector<int> > adj; // Lista de adyacencia
int n; // Cantidad de nodos
int tiempo = 0;

void dfs(int nodo) {
  st[nodo] = tiempo++;
  for (int i = 0; i < adj[nodo].size(); i++) {
    int vecino = adj[nodo][i];
    if (st[vecino] == 0)
      dfs(vecino);
  }
  ft[nodo] = tiempo;
}


// Ejemplo de uso

int main(){

  return 0;
}
