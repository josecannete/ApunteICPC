#include <bits/stdc++.h>
using namespace std;

// Vectores en los que guardaremos tiempos de llegada y de salida
vector<int> st;
vector<int> ft;
vector<vector<int> > adj; // Lista de adyacencia
int n; // Cantidad de nodos
int tiempo = 0;

void dfs(int nodo){
  stack<int> pila;
  pila.push(nodo);
  while( !pila.empty() ){
    int u = pila.top(); pila.pop();
    st[u] = tiempo++;
    for (int i = 0; i < adj[u].size(); i++){
      int vecino = adj[u][i];
      if ( st[vecino] != 0 )
        pila.push(vecino);
    }
    ft[u] = tiempo;
  }
}



// Ejemplo de uso

int main(){

  return 0;
}
