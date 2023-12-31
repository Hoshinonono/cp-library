#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <bits/stdc++.h>
#include "Tree/hld.hpp"
#include "DataStructure/fenwick_tree.hpp"

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, cmd, u, v;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    vector<int> a(N);
    vector<vector<int>> g(N);
    for(auto &&v : a) cin >> v;
    for(int i = 1; i < N; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto qf = [&](int l, int r){
        return fw.sum(l, r);
    };
    auto f = [&](ll lhs, ll rhs){
        return lhs + rhs;
    };

    Heavy_Light_Decomposition HLD(g);
    for(int i = 0; i < N; i++){
        fw.add(HLD[i], a[i]);
    }

    while(Q--){
        cin >> cmd >> u >> v;
        if(cmd == 0) fw.add(HLD[u], v);
        else cout << HLD.query(u, v, 0ll, qf, f) << '\n';
    }
}
