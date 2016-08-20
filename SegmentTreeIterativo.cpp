#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;  // Tamaño limite del arreglo
int n;  // Tamano arreglo
int t[2 * N]; // En teoria usar 4 * N es mas seguro

void build() {  // Construccion heap-like
  for (int i = n - 1; i > 0; --i) t[i] = t[2 * i] + t[2 * i + 1];
}

// Nota: Si p es un hijo 2*i, p^1 es 2*i + 1 y viceversa (XOR)
void modify(int p, int valor) {  // Setear valor en la posicion p
  for (t[p += n] = valor; p > 1; p /= 2) t[p / 2] = t[p] + t[p^1];
}

int query(int l, int r) {  // Suma del intervalo [l,r)
  int res = 0;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l % 2 == 1) res += t[l++];
    if (r % 2 == 1) res += t[--r];
  }
  return res;
}

// Ver problema Potetiometers de UVA
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t[n+i];
  build();
  modify(0, 1);
  cout << query(3,11) << endl;
  return 0;
}
