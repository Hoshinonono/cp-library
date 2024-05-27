#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include <bits/stdc++.h>
#include "Math/modint.hpp"
#include "Tree/LinkCutTree.hpp"
using namespace std;
using mint = prime_modint<998244353>;
using ll = long long;

using S = pair<mint,mint>;
S op(S lhs, S rhs){
    return make_pair(lhs.first * rhs.first, rhs.first * lhs.second + rhs.second);
}
S e(){
    return make_pair(1, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    LinkCutTree<S, op, e> LCT(N);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        LCT.set(i, make_pair(a, b));
    }
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        LCT.link(u, v);
    }
    while(Q--){
        int cmd;
        cin >> cmd;
        if(cmd == 0){
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            LCT.cut(u, v);
            LCT.link(w, x);
        }else if(cmd == 1){
            int p, c, d;
            cin >> p >> c >> d;
            LCT.set(p, make_pair(c, d));
        }else{
            int u, v, x;
            cin >> u >> v >> x;
            auto pa = LCT.query(u, v);
            cout << pa.first * x + pa.second << '\n';
        }
    }
}