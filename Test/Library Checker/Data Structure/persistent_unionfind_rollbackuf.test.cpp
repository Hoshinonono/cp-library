#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <bits/stdc++.h>
#include "Graph/dsu_03_rollback.hpp"
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> tree(Q + 1);
    vector<pair<int,int>> edge(Q + 1);
    vector<int> ans(Q);
    vector<vector<tuple<int,int,int>>> query(Q + 1);
    auto g = tree.begin() + 1;
    auto e = edge.begin() + 1;
    auto q = query.begin() + 1;
    for(int i = 0; i < Q; i++){
        int t, k, u, v;
        cin >> t >> k >> u >> v;
        if(t == 0){
            g[k].emplace_back(i);
            e[i] = make_pair(u, v);
        }else{
            ans[i] |= 2;
            q[k].emplace_back(u, v, i);
        }
    }
    rollback_dsu uf(N);
    
    auto dfs = [&](auto dfs, int v) -> void {
        uf.merge(e[v].first, e[v].second);
        for(auto &&[x, y, id] : q[v]) ans[id] |= uf.same(x, y);
        for(auto &&u : g[v]) dfs(dfs, u);
        uf.undo();
    };

    dfs(dfs, -1);

    for(auto &&v : ans){
        if(~v & 2) continue;
        cout << (v & 1) << '\n';
    }
}