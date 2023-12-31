#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind" 

#include <bits/stdc++.h>
#include "Graph/dsu_02_max.hpp"
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    Kruskal_dsu<int> uf(N);
    for(int i = 0; i < Q; i++){
        int t, k, u, v;
        cin >> t >> k >> u >> v;
        if(t == 0){
            uf.merge(u, v, i);
        }else{
            cout << (uf.max_edge(u, v) <= k) << '\n';
        }
    }
}
