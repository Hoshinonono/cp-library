#define PROBLEM "https://yukicoder.me/problems/no/114"

#include <bits/stdc++.h>
#include <atcoder/all>
#include "Graph/steiner_tree.hpp"
using ll = long long;

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, T;
	cin >> N >> M >> T;
	vector<int> ter(T);
	if(T <= 16){
		vector<vector<pair<int,int>>> G(N);
		for(int i = 0; i < M; i++){
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			G[u].emplace_back(v, w);
			G[v].emplace_back(u, w);
		}
		for(auto &&v : ter) cin >> v, v--;
		int tmp = ter.back();
		ter.pop_back();
		cout << steiner_tree(G, ter)[tmp] << '\n';
	}else{
		vector<tuple<int,int,int>> edge(M);
		for(auto &&[u, v, w] : edge){
			cin >> u >> v >> w;
			u--, v--;
			swap(u, w);
		}
		long long S = (1ll << N) - 1;
		int ans = 1 << 30;
		for(auto &&v : ter) {
			cin >> v;
			v--;
			S ^= 1ll << v;
		}
		sort(edge.begin(), edge.end());
		for(long long U = S; U >= 0; U = (U - 1) & S){
			int sv = 0;
			atcoder::dsu uf(N);
			for(auto &&[w, u, v] : edge){
				if((U >> u & 1) || (U >> v & 1) || uf.same(u, v)) continue;
				uf.merge(u, v);
				sv += w;
			}
			if(uf.size(ter[0]) + __builtin_popcountll(U) == N){
				ans = min(ans, sv);
			}
			if(U == 0) break;
		}
		cout << ans << '\n';
	}
}
