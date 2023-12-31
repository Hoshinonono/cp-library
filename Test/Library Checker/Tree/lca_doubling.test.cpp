#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
#include "Tree/lca_doubling.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, v, u;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++){
        cin >> v;
        G[v].emplace_back(i);
        G[i].emplace_back(v);
    }
    LCA_tree g(G);
    while(Q--){
        cin >> u >> v;
        cout << g.lca(u, v) << '\n';
    }
}
