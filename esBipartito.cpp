#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

// Vector que contiene las distancias desde el nodo
// en que partimos el BFS hasta el resto de los nodos
vector<int> d;
// Vector que contiene el color de cada nodo
vector<int> color;
vector<vector<int> > adj; // Lista de adyacencia
int n; // Cantidad de nodos

// Algoritmo para saber si un grafo es bipartito
// Se usa para ello la equivalencia bipartito <=> 2-coloreable
// Lo que hacemos es intentar 2-colorear el grafo mediante un BFS
bool esBipartito(int nodo){
  // Asumimos que el grafo es conexo, en caso de no serlo basta con setear
  // las distancias como infinito fuera de esta función y luego solo usar la
  // funcion en cada componente conexa
  for(int i = 0; i < n; i++)
    d[i] = inf;

  d[nodo] = 0;
  color[nodo] = 1;

  queue<int> cola;
  cola.push(nodo);
  while( !cola.empty() ){
    int u = cola.front(); cola.pop();
    for (int i = 0; i < adj[u].size(); i++){
      int vecino = adj[u][i];
      if ( d[vecino] == inf ){
        d[vecino] = d[u] + 1;
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


// Ejemplo de uso

int main(){

  return 0;
}
