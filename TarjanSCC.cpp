#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> parent;
vector<int> level;
vector<int> low;
vector<int> S;
vector<vector<int> > SCC;
int n;
int numSCC;

// dfs(nodo, level, padre)
void dfs_aux(int u, int l, int p) {
  level[u] = low[u] = l;
  parent[u] = p;
  S.push_back(u);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    // Ignorar al padre
    if (v == parent[u]) continue;
    if (level[v] == -1)
      dfs_aux(v, l+1, u);
    if (level[v] != -1)
      low[u] = min(low[u], low[v]);
  }
  if (low[u] == level[u]) {
    SCC.push_back(vector<int>(0));
    cout << "SCC " << numSCC << endl;
    while(1) {
      int v = S.back(); S.pop_back(); level[v] = -1;
      SCC[numSCC].push_back(v);
      cout << v << " ";
      if (u == v) break;
    }
    numSCC++;
    cout << endl;
  }
}

void tarjanSCC() {
  // aca los nodos van desde 1 hasta n
  for (int i = 1; i <= n; i++)
    if (level[i] == -1)
      dfs_aux(i, 0, -1);
}



int main(){
  // int n
  adj.assign(n+1, vector<int>(0));
  parent.assign(n+1, 0);
  level.assign(n+1, -1);
  low.assign(n+1, -1);
  SCC.clear();
  //int nodo = 1; // nodo donde partira el dfs
  // partimos desde nodo, con level 0 y sin padre (-1)
  tarjanSCC();
}
