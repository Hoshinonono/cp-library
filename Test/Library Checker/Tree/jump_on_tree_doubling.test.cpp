#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <bits/stdc++.h>
#include "Tree/lca_doubling.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, u, v, d;
    cin >> N >> Q;
    vector<vector<int>> g(N);
    for(int i = 1; i < N; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    LCA_tree G(g);
    while(Q--){
        cin >> u >> v >> d;
        cout << G.la(u, v, d) << '\n';
    }
}
