#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tamano;
bitset<10000010> bs;
vector<int> primos;

void criba (ll n) {
	tamano = n +1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i<= tamano; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= tamano; j += i) bs[j] = 0;
			primos.push_back((int)i);
		}
}


int main(){

	criba(1000000);

	for (int i = 0; i < 50; i++)
		cout << primos[i] << endl;

	return 0;
}
