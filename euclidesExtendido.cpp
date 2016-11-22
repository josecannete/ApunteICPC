#include <bits/stdc++.h>
using namespace std;
// d = gcd(a,b) y ax + by = c tiene soluciones si d divide a c
// (x,y) es la primera solucion para la ecuacion diofantica
// podemos encontrar otras con xg = x + (b/d)*n E yg = y - (a/d)*n Y n varia
int x, y, d;

void extendedEuclid(int a, int b) {
  if (b == 0) { x = 1; y = 0; d = a; return; }
  extendedEuclid(b, a % b);
  int x1 = y;
  int y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}

void modInverse(int a, int m) {
  extendedEuclid(a,m);
  if (d == 1)
    cout << "No existe inverso" << endl;
  else{
    int res = (x % m + m) % m;
    cout << "El inverso modular multiplicativo es" << res << endl;
  }
}
