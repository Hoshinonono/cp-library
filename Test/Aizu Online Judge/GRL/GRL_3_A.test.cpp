#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include <bits/stdc++.h>
#include "Graph/lowlink.hpp"
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
    auto ans = lowlink_graph(g).art_point;
    sort(ans.begin(), ans.end());
    for(auto &&v : ans) cout << v << '\n';
}
