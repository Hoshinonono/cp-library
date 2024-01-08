#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include <bits/stdc++.h>
#include "Graph/lowlink_bcc.hpp"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while(m--){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto ans = bcc_graph(g).bcc();
    cout << ans.size() << '\n';
    for(auto &&G : ans){
        cout << G.size();
        for(auto &&v : G) cout << ' ' << v;
        cout << '\n';
    }
}