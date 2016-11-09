#include <bits/stdc++.h>

using namespace std;

string Pat, Str;
vector<int> b;
int n, m;
#define MAX_N 100010

void KMP_preproces() {
  int i=0, j=-1; b[0]=-1;
  while(i < m) {
    while(j >= 0 && Pat[i] != Pat[j]) j=b[j];
    i++; j++;
    b[i]=j;
  }
}

bool KMP_search() {
  int i=0, j=0;
  while(i < n) {
    while(j >= 0 && Str[i] != Pat[j]) j=b[j];
    i++; j++;
    if(j == m) {
      return true;
      //return (i - j);  // Para determinar el lugar donde esta la repeticion.
    }
  }
  return false;
}

int main() {
  cin >> Pat >> Str;
  b.assign(MAX_N, 0);
  n = Str.size(); m = Pat.size();

  KMP_preproces();
  bool t = KMP_search();
  cout << t << endl;
}
