#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

vector<vector<int> > d; // matriz de adyacencia con peso inf por defecto
int n; // nodos

void floyd_warshall() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
