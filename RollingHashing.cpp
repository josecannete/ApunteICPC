#include <bits/stdc++.h>
using namespace std;

int B = 33;

long long fast_pow(int a,int n){
  long long result = 1, power = n, value = a;
  while(power>0){
    if(power&1)
      result = result*value;
    value = value*value;
    power /= 2;
    //power >>= 1;
  }
  return result;
}

void hashear(vector<long long>& h, string s){
  h.assign(s.size()+1,0);

  for (int i = s.size() - 1; i >= 0; i--){
    h[i] = (long long)s[i] + h[i+1] * B;
  }
}

long long hashval(vector<long long>& h, int i, int j){
  return h[i] - h[j+1] * fast_pow(B, j+1-i);
}

int main(){
  string s = "abaaababaaab";
  vector<long long> h;
  hashear(h, s);
  cout << (int)'a' << endl;
  cout << fast_pow(B, 6) << endl;
  cout << hashval(h,0,5) << endl;
  cout << hashval(h,6,11) << endl;
}
