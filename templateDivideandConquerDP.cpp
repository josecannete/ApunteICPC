#include <bits/stdc++.h>
using namespace std;

#define inf 1e16

typedef long long ll;

vector<vector<ll> > DP;

vector<ll> sumkck, sumck, masder;

ll cost(ll i, ll j){
}

void solve(ll k, ll l, ll r, ll optl, ll optr){
  if (l > r) return;
  ll m = (l+r) / 2;
  ll optm = l;
  DP[k][m] = inf;
  for (ll i = optl; i <= min(r-1, optr); i++){
    if (DP[k-1][i] + cost(i,m) < DP[k][m]){
      DP[k][m] = DP[k-1][i] + cost(i,m);
      optm = i;
    }
  }

  solve(k, l, m-1, optl, optm);
  solve(k, m+1, r, optm, optr);
}




int main(){
  // calcular el primer nivel de la dp, luego calcular con solve desde 2 hasta k
}
