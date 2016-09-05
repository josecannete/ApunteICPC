#include <bits/stdc++.h>
using namespace std;

#define ll long long


// Por ahora esta implementada la criba y la funcion phi de Euler 
// que usa factorizacion prima, falta completar con el resto de 
// aplicaciones de factorizacion prima


ll tamano;
bitset<10000010> bs;
vector<int> primos;

void criba (ll n){
	tamano = n +1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i<= tamano; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= tamano; j += i) bs[j] = 0;
			primos.push_back((int) i);
		}
}

ll euler(ll N){
	ll PF_idx = 0, PF = primos[PF_idx], ans = N;
	while ( PF * PF <= N ){
		if ( N % PF == 0) ans -= ans / PF;
		while ( N % PF == 0) {
			N /= PF;
			 }
		PF = primos[++PF_idx];
		}
		if ( N != 1 ) ans -= ans / N;
		return ans;
	}

int main(){
	
	criba(1000000);
	
	for (int i = 0; i < 50; i++){
		cout << "El primo " << i << " es " << primos[i] << endl;
		cout << "Los coprimos para " << i+1 << " son " << euler(i+1) << endl;
	}
	
	return 0;
	}

