#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int B = 33;

ull fast_pow(int a,int n) {
  ull result = 1, power = n, value = a;
  while (power>0) {
    if (power&1) result = result * value;
    value = value * value;
    power >>= 1;
  }
  return result;
}

void construirHash(vector<ull>& h, string s) {
  h.assign(s.size()+1,0);
  for (int i = s.size() - 1; i >= 0; i--)
    h[i] = (ull)s[i] + h[i+1] * B;
}

ull hashval(vector<ull>& h, int i, int j) {
  return h[i] - h[j+1] * fast_pow(B, j+1-i);
}

int main(){
  string s = "abaaababaaab";
  vector<ull> h;
  construirHash(h, s);
  cout << (int)'a' << endl;
  cout << fast_pow(B, 6) << endl;
  cout << hashval(h,0,5) << endl;
  cout << hashval(h,6,11) << endl;
}
