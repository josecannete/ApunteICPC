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
  std::ios::sync_with_stdio(false);



  return 0;
}
