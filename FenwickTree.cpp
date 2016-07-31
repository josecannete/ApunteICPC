#include <bits/stdc++.h>
using namespace std;


// Vector que contiene al Fenwick Tree
vector<int> ft;

// Suma acumulada hasta el indice "x"
// Podemos obtener el RSQ entre "a" y "b" con suma(b) - suma(a-1)
// O(log n)
int suma(int x){
	int sum = 0;
	for ( ; x; x -= (x & -x) )
		sum += ft[x];
	return sum;
}

// Sumar "valor" al elemento en el indice "x"
// O(log n)
void update(int x, int valor){
	for ( ; x < ft.size(); x += (x & -x) )
			ft[x] += valor;
}

// Ejemplo de uso

int main(){

  ft.resize(11,0);

  for(int i = 1; i <= 10; i++)
    update(i, i * i);

  cout << suma(2) << endl; // 1 * 1 + 2 * 2 = 5
  cout << suma(5) << endl; // 1 * 1 + 2 * 2 + 3 * 3 + 4 * 4 + 5 * 5 = 55
  cout << suma(5) - suma(2) << endl; // RSQ(3,5) = 50


  return 0;
}
