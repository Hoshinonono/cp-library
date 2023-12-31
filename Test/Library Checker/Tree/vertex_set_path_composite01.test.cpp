#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <bits/stdc++.h>
#include "Tree/hld.hpp"
#include "DataStructure/segtree.hpp"
#include "Math/modint.hpp"

//using mint = prime_modint<1000000007>;
using mint = prime_modint<998244353>;

using namespace std;

using S = pair<mint, mint>;
S op1(S lhs, S rhs){
    return {rhs.first * lhs.first, rhs.first * lhs.second + rhs.second};
}
S op2(S lhs, S rhs){
    return {lhs.first * rhs.first, lhs.first * rhs.second + lhs.second};
}
S e(){
    return make_pair(1, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, cmd, u, v, x;
    cin >> N >> Q;
    vector<pair<mint,mint>> a(N), b(N);
    vector<vector<int>> g(N);
    for(int i = 0; i < N; i++){
        cin >> a[i].first.v >> a[i].second.v;
    }
    for(int i = 1; i < N; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    Heavy_Light_Decomposition HLD(g);

    for(int i = 0; i < N; i++){
        b[HLD[i]] = a[i];
    }
    segtree<S, op1, e> seg1(b);
    segtree<S, op2, e> seg2(b);

    auto qf = [&](int l, int r){
        return seg1.prod(l, r);
    };
    auto rev_qf = [&](int l, int r){
        return seg2.prod(l, r);
    };
    auto f = [&](S lhs, S rhs){
        return make_pair(rhs.first * lhs.first, rhs.first * lhs.second + rhs.second);
    };

    while(Q--){
        cin >> cmd >> u >> v >> x;
        if(cmd == 0){
            seg1.set(HLD[u], make_pair(v, x));
            seg2.set(HLD[u], make_pair(v, x));
        }else{
            auto pa = HLD.noncom_query(u, v, e(), qf, rev_qf, f);
            cout << pa.first * x + pa.second << '\n';
        }
    }
}
