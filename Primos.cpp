#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fast_pow(int a,int n){
	ll result = 1, power = n, value = a;
	while(power > 0){
		if(power&1)
	  	result = result*value;
		value = value*value;
	  power /= 2;
	  //power >>= 1;
	}
	return result;
}

ll tamano;
bitset<10000010> bs;
vector<int> primos;

void criba (ll n){
	tamano = n + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i<= tamano; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= tamano; j += i) bs[j] = 0;
			primos.push_back((int) i);
		}
}

vector<int> factorizacionPrima(ll N){
	vector<int> factores;
	ll PF_idx = 0, PF = primos[PF_idx];
	while ( PF * PF <= N ){
		while ( N % PF == 0 ){
			N /= PF;
			factores.push_back(PF);
		}
		PF = primos[++PF_idx];
	}
	if (N != 1) factores.push_back(N);
	return factores;
}

ll numeroDivisores(ll N){
	ll PF_idx = 0, PF = primos[PF_idx], ans = 1;
	while ( PF * PF <= N ){
		ll power = 0;
		while ( N % PF == 0){
			N /= PF;
			power++;
		}
		ans *= (power + 1);
		PF = primos[++PF_idx];
	}
	if (N != 1) ans *= 2;
	return ans;
}

ll sumaDivisores(ll N){
	ll PF_idx = 0, PF = primos[PF_idx], ans = 1;
	while ( PF * PF <= N ){
		ll power = 0;
		while ( N % PF == 0){
			N /= PF;
			power++;
		}
		ans *= (fast_pow(PF, power + 1) - 1) / (PF - 1);
		PF = primos[++PF_idx];
	}
	if (N != 1) ans *= (fast_pow(N, 2) - 1) / (N - 1);
	return ans;
}

ll eulerPhi(ll N){
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
		cout << "Los coprimos para " << i+1 << " son " << eulerPhi(i+1) << endl;
	}

	return 0;
	}
