#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define pb push_back
#define ff first
#define ss second

int n = 1e5;

vi Segment(4 * n,0);

void update(int ini, int left, int right, int valor){
  if (left > right)
    return ;

  if (right - left < 2)
    Segment[ini] = valor;

  update(ini * 2,     left,                 (left + right) / 2, valor);
  update(ini * 2 + 1, (left + right) / 2 + 1, right,            valor );

  Segment[ini] = Segment[2 * ini] + Segment[2 * ini + 1];
}

int main(){
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  while(n != 0){
    for (int i = 0; i < n; i++){
      int a;
      cin >> a;
      update(1, i + 1, i + 1, a);
    }

  }



  return 0;
}
