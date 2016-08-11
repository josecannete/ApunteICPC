#include <bits/stdc++.h>
using namespace std;

// Algoritmo para saber si un grafo es bipartito
// Se usa para ello la equivalencia bipartito <=> 2-coloreable
// Lo que hacemos es intentar 2-colorear el grafo mediante un BFS

// Vector que contiene el color de cada nodo
vector<int> color;
vector<vector<int> > adj; // Lista de adyacencia
int n; // Cantidad de nodos

// Revisamos si una componente conexa es bipartita
bool esBipartitoConexo(int nodo){
  queue<int> cola;
  cola.push(nodo);
  while( !cola.empty() ){
    int u = cola.front(); cola.pop();
    for (int i = 0; i < adj[u].size(); i++){
      int vecino = adj[u][i];
      if ( color[vecino] == 0 ){
        cola.push(vecino);
        color[vecino] = -1 * color[u];
      }
      // Si llegamos a un vecino cuyo color sea igual que el padre
      // entonces no es 2-coloreable y devolvemos false
      if (color[u] == color[vecino])
        return false;
    }
  }
  // Si coloreamos toda la componente conexa devolvemos true
  return true;
}

// Función para ver si el grafo entero es bipartito
bool esBipartito(){
  bool bipartito = true;
  for (int i = 1; i <= n; i++){
    if (color[i] == 0){
      color[i] = 1;
      bipartito = bipartito & esBipartitoConexo(i);
    }
  }
  return bipartito;
}


// Ejemplo de uso
// Ver problema 687A NP-Hard Problem de codeforces

int main(){

  return 0;
}
