#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll coeficienteBinomial(int n, int k) {
  ll C[n+1][k+1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
  return C[n][k];
}

ll coeficienteBinomialPascal(int n, int k) {
    ll C[k+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;  // n C 0 es 1
    for (int i = 1; i <= n; i++) {
    // Computar una fila usando la anterior del triangulo de pascal
      for (int j = min(i, k); j > 0; j--)
        C[j] = C[j] + C[j-1];
    }
    return C[k];
}
