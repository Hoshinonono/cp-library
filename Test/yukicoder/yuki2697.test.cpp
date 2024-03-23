#define PROBLEM "https://yukicoder.me/problems/no/2697"

#include <bits/stdc++.h>
#include "DataStructure/segtree_lazy.hpp"
using namespace std;
using ll = long long;

using S = array<array<int,4>,4>;
using F = int;

S op(S lS, S rS){
	S tmp{};
	for(int i = 0; i < 4; i++){
		for(int j = i; j < 4; j++){
			for(int k = j; k < 4; k++){
				for(int l = k; l < 4; l++){
					tmp[i][l] = max(tmp[i][l], lS[i][j] + rS[k][l]);
				}
			}
		}
	}
	return tmp;
}

S e(){
	S tmp{};
	return tmp;
}

// x に f を作用させた時の変化
S mapping(F f, S x){
	if(f == -1) return x;
	int c = 0;
	for(int i = 0; i < 4; i++){
		c += x[i][i];
		for(int j = i; j < 4; j++){
			x[i][j] = 0;
		}
	}
	x[f][f] = c;
	return x;
}

F composition(F af, F bf){
	if(af == -1) return bf;
	return af;
}

F id(){return -1;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<S> a(n);
	S tmp{};
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		v--;
		tmp[v][v]++;
		a[i] = tmp;
		tmp[v][v]--;
	}
	lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
	int Q;
	cin >> Q;
	while(Q--){
		int cmd, l, r;
		cin >> cmd >> l >> r;
		l--;
		if(cmd == 1){
			auto v = seg.prod(l, r);
			int ans = 0, sv = 0;
			for(int i = 0; i < 4; i++){
				for(int j = i; j < 4; j++){
					ans = max(ans, v[i][j]);
				}
			}
			cout << ans << '\n';
		}else{
			int v;
			cin >> v;
			v--;
			seg.apply(l, r, v);
		}
	}
}