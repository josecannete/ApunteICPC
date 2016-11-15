#include <bits/stdc++.h>
using namespace std;
// indexado desde 0, se guardan valores en t[n+i] o bien usando modify(i, val)
const int N = 2e5 + 5;  // Tamaño limite del arreglo
int n;  // Tamano arreglo
int neutro = 0; // Definimos el neutro para la operacion que vamos a hacer
vector<int> t(2 * N, neutro);

int combine(int a, int b){
  return (a + b); // min(a,b), max(a,b), (a+b), (a*b), etc
}

void build() {  // Construccion heap-like
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[2 * i], t[2 * i + 1]);
}

// Nota: Si p es un hijo 2*i, p^1 es 2*i + 1 y viceversa (XOR)
void modify(int p, int valor) {  // Setear valor en la posicion p
  for (t[p += n] = valor; p > 1; p /= 2) t[p / 2] = combine(t[p], t[p^1]);
}

int query(int l, int r) {  // Suma del intervalo [l,r)
  int resl = neutro, resr = neutro;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
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
