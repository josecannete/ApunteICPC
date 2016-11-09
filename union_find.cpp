#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
	vector<int> P, rank;

	UnionFind(int N){
		P.resize(N);
		for (int i = 0; i < N; ++i)
			P[i] = i;
		rank.assign(N,0);
	}

	int findSet(int u){
		return P[u] == u ? u : P[u] = findSet(P[u]);
	}

	bool isSameSet(int u, int v){
		return findSet(u) == findSet(v);
	}

	void unionSet(int u, int v){
		if(isSameSet(u,v)) return;

		int pu = findSet(u), pv = findSet(v);
		if(rank[pu] < rank[pv]){
			P[pu] = pv;
		}
		else{
			P[pv] = pu;
			if(rank[pu] == rank[pv])
				rank[pu]++;
		}
	}
};

int main(){
	ios::sync_with_stdio(0);


	return 0;
}
