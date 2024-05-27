#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include <bits/stdc++.h>
#include "Tree/LinkCutTree.hpp"
using namespace std;
using ll = long long;

ll op(ll lhs, ll rhs){ return lhs + rhs; }
ll e(){return 0;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for(auto &&v : a) cin >> v;
    LinkCutTree<ll, op, e> LCT(a);
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
            int p, x;
            cin >> p >> x;
            LCT.set(p, a[p] += x);
        }else{
            int u, v;
            cin >> u >> v;
            cout << LCT.query(u, v) << '\n';
        }
    }
}