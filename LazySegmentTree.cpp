#include <bits/stdc++.h>
using namespace std;

vector<int> tree, lazy, vec;

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {
    if (lazy[si] != 0) {
        tree[si] += (se-ss+1)*lazy[si];       // cambiar en caso distinto
        if (ss != se) {
            lazy[si*2 + 1]   += lazy[si];     // cambiar en caso distinto
            lazy[si*2 + 2]   += lazy[si];     // cambiar en caso distinto
        }
        lazy[si] = 0;
    }

    if (se<ss || ue<ss || se<us)
        return ;
    if (ss>=us && se<=ue) {
        tree[si] += (se-ss+1)*diff;       // cambiar en caso distinto

        if (ss != se) {
            lazy[si*2 + 1]   += diff;      // cambiar en caso distinto
            lazy[si*2 + 2]   += diff;      // cambiar en caso distinto
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

    tree[si] = tree[si*2+1] + tree[si*2+2];      // cambiar en caso distinto
}

int getUtil(int ss, int se, int qs, int qe, int si) {
    if (lazy[si] != 0) {
        tree[si] += (se-ss+1)*lazy[si];       // cambiar en caso distinto

        if (ss != se) {
            lazy[si*2+1] += lazy[si];        // cambiar en caso distinto
            lazy[si*2+2] += lazy[si];        // cambiar en caso distinto
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (qs<=ss && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    int a = getUtil(ss, mid, qs, qe, 2*si+1);
    int b = getUtil(mid+1, se, qs, qe, 2*si+2);

    return  a + b;     // cambiar en caso distinto
}

// query: ini, fin indices 0 a n-1
int query(int n, int ini, int fin) {
    return getUtil(0, n-1, ini, fin, 0);
}

// update: i, j indices 0 a n-1
void update(int n, int i, int j, int diff) {
   updateRangeUtil(0, 0, n-1, i, j, diff);
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, q;

  while(true) {
    cin >> n >> q;
    if(n==-1) break;

    vec.assign(n, 0);
    lazy.assign(3*n+10, 0);
    tree.assign(3*n+10, 0);
    for(int i=0; i<n; i++) {
      cin >> vec[i];
      update(n, i, i, vec[i]);
    }

    for(int i=0; i<q; i++) {
      char c; int ini, fin, diff;
      cin >> c;
      if(c == 'U') { // update
        cin >> ini >> fin >> diff;
        update(n, ini, fin, diff);
      } else { // query
        cin >> ini >> fin;
        cout << query(n, ini, fin) << endl;
      }
    }
  }

  return 0;
}
