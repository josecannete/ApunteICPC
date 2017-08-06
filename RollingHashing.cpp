#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull B = 127; // 131
ull mod = 1e9+7; // 1e9+9
ull maxstrlen = 5*1e5+5;
vector<ull> fp;

void precompPow(ull x){
  fp.assign(maxstrlen, 0);
  fp[0] = 1;
  for (int i = 1; i < maxstrlen; i++){
    fp[i] = x * fp[i-1]; 
    fp[i] %= modd;
  }
}

void construirHash(vector<ull>& h, string& s) {
  h.assign(s.size()+1,0);
  for (int i = s.size() - 1; i >= 0; i--){
    h[i] = (ull)s[i] % mod + (h[i+1] * B) % mod;
    h[i] %= mod;
  }
}

ull hashval(vector<ull>& h, ull i, ull j) {
  return (h[i] % mod - (h[j+1] * fast_pow(B, j+1-i)) % mod + mod) % mod;
}
/*
  Uso: precomputar potencias al menos una vez
  Se debe entregar indices de la primera letra y ultima del substring
  que queremos usar
*/

int main(){
  precompPow(B);
  string s = "abcaababcaab";
  string s2 = "abcaababcaababcaababcaababcaababcaab";
  vector<ull> h;
  construirHash(h, s);
  vector<ull> h2;
  construirHash(h2, s2);
  cout << (int)'a' << endl;
  cout << fast_pow(B, 6) << endl;
  cout << s.substr(0, 11) << endl;
  cout << hashval(h, 0, 11) << endl;
  cout << s2.substr(0, 11) << endl;
  cout << hashval(h2, 0, 11) << endl;
  cout << hashval(h, 0, 4)  << endl;
  cout << hashval(h2, 0, 4) << endl;
  cout << hashval(h,0,5) << endl;
  cout << hashval(h,6,11) << endl;
  cout << hashval(h, 2, 3) << endl;
  cout << hashval(h, 8, 9) << endl;
}
