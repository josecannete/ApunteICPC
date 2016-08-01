#include <bits/stdc++.h>
using namespace std;

// Matriz que contiene al Fenwick Tree 2D
vector<vector<int> > ft;

// Suma acumulada hasta las cordenadas (x,y)
// Podemos obtener el RSQ entre (x1,y1) y (x2,y2)
// con suma(x2, y2) - suma(x2, y1 - 1) - suma(x1 - 1, y2) + suma(x1 - 1, y1 - 1)
// O(log n * log m)
int suma(int x, int y){
	int sum = 0;
	for (int i = x ; i ; i -= (i & -i) )
    for (int j = y ; j ; j -= (j & -j) )
      sum += ft[i][j];
	return sum;
}

// Sumar "valor" al elemento en el indice (x,y)
// O(log n * log m)
void update(int x, int y, int valor){
	for (int i = x; i < ft.size(); i += (i & -i) )
    for (int j = y; j < ft.size(); j += (j & -j) )
			ft[i][j] += valor;
}

// Ejemplo de uso

int main(){

  ft.resize(11,vector<int>(11,0));

  for(int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      update(i, j, i + j);

  cout << suma(3,3) << endl; // (2 + 3 + 4) + (3 + 4 + 5) + (4 + 5 + 6) = 36
  cout << suma(2,5) << endl; // (2 + 3) + (3 + 4) + (4 + 5) + (5 + 6) + (6 + 7) = 45
  cout << suma(4,5) - suma(4,1) - suma(1,5) + suma(1,1) << endl;
  // RSQ entre (2,2) y (4, 5) =
  // (4 + 5 + 6 + 7) + (5 + 6 + 7 + 8) + (6 + 7 + 8 + 9) = 78

  return 0;
}
