#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

vector<vector<ll> >tree;

vector<ll> elementos;

vector<ll> mimerge(vector<ll> uno, vector<ll> dos){
  ll tamuno = uno.size();
  ll tamdos = dos.size();
  ll induno = 0;
  ll inddos = 0;

  vector<ll> ans;

  while (induno < tamuno && inddos < tamdos){
    if (uno[induno] < dos[inddos]) {
      ans.push_back(uno[induno]);
      induno++;
    }
    else{
      ans.push_back(dos[inddos]);
      inddos++;
    }
  }

  for (ll i = induno; i < tamuno; i++){
    ans.push_back(uno[i]);
  }
  for (ll i = inddos;  i < tamdos; i++){
    ans.push_back(dos[i]);
  }

  return ans;
}


void build_tree( ll cur , ll l , ll r ){
     if( l==r ){
            //cout << "hola" << endl;
            //cout << distc1.size() << endl;
            //cout << "distc1 aca es " << distc1[l] << endl;
            tree[cur].push_back( elementos[ l ] );
            return ;
     }
     ll mid = l+(r-l)/2;
     build_tree(2*cur+1 , l , mid ); // Build left tree 
     build_tree(2*cur+2 , mid+1 , r ); // Build right tree
     //tree[cur].assign(tree[2*cur+1].size() + tree[2*cur+2].size(), 0);
     //merge( tree[2*cur+1].begin(), tree[2*cur+1].end() , tree[2*cur+2].begin(), tree[2*cur+2].end(), tree[cur].begin() ); //Merging the two sorted arrays
      tree[cur] = mimerge(tree[2*cur+1], tree[2*cur+2]);
}


ll query( ll cur, ll l, ll r, ll x, ll y, ll k){
  if( r < x || l > y ){
    return 0; //out of range
  }
  if( x <= l && y >= r){
    ll ind = upper_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin();
              //Binary search over the current sorted vector to find elements smaller than K
    return ind;
  }
  ll mid=l+(r-l)/2;
  return query(2*cur+1,l,mid,x,y,k)+query(2*cur+2,mid+1,r,x,y,k);
}


int main(){
  // ver problema galatic tranmission.

}