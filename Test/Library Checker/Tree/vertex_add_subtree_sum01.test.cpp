#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <bits/stdc++.h>
#include "Tree/hld.hpp"
#include "DataStructure/segtree_dual.hpp"

using namespace std;
using ll = long long;
ll op(ll af, ll bf){ return af + bf; }
ll e(){return 0;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, cmd, u, v;
    cin >> N >> Q;
    vector<ll> a(N), b(N);
    vector<int> par(N);
    vector<vector<int>> g(N);
    for(auto &&v : a) cin >> v;
    for(int i = 1; i < N; i++){
        cin >> par[i];
        g[par[i]].emplace_back(i);
    }
    Heavy_Light_Decomposition HLD(g);
    for(int i = N - 1; i >= 1; i--){
        a[par[i]] += a[i];
        b[HLD[i]] = a[i];
    }
    b[0] = a[0];
    dual_segtree<ll, op, e> seg(b);
    auto update = [&](int l, int r){
        seg.apply(l, r, v);
    };
    while(Q--){
        cin >> cmd >> u;
        if(cmd == 0){
            cin >> v;
            HLD.update(0, u, update);
        }else{
            cout << seg[HLD[u]] << '\n';
        }
    }
}
