#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> parent;
vector<int> level;
vector<int> low;
set<int> puntosArticulacion;
int n;
int hijosRaiz;


// dfs(nodo, level, padre)
void dfs_aux(int u, int l, int p){
  level[u] = low[u] = l;
  parent[u] = p;

  for (int i = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    // Ignorar al padre
    if (v == parent[u]) continue;
    if (level[v] == -1){
      dfs_aux(v, l+1, u);
      low[u] = min(low[u], low[v]);

      // Contamos los hijos de la raiz
      if (parent[u] == -1)
        hijosRaiz++;

      // Si no es la raiz y el low del hijo alcanza un nivel mas bajo
      if (parent[u] != -1 && low[v] >= level[u])
        puntosArticulacion.insert(u);
      if (parent[u] != -1 && low[v] > level[u])
        cout << "la arista " << u << " " << v << " es de articulacion" << endl;

    }
    else if (level[v] < level[u]){
      low[u] = min(low[u], level[v]);
    }
  }
}

void dfs(){
  // aca los nodos van desde 1 hasta n
  for (int i = 1; i <= n; i++){
    if (level[i] == -1){
      hijosRaiz = 0;
      dfs_aux(i, 0, -1);
      // si la raiz tiene mas de un hijo entonces es punto de articulacion
      if (hijosRaiz > 1)
        puntosArticulacion.insert(i);
    }
  }
}



int main(){
  // int n
  adj.assign(n+1, vector<int>(0));
  parent.assign(n+1, 0);
  level.assign(n+1, -1);
  low.assign(n+1, -1);
  puntosArticulacion.clear();
  //int nodo = 1; // nodo donde partira el dfs
  // partimos desde nodo, con level 0 y sin padre (-1)
  dfs();
}
