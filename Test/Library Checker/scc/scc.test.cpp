#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
#include "Graph/scc.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m, u, v;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for(int i = 0; i < m; i++){
        std::cin >> u >> v;
        g[u].emplace_back(v);
    }
    SCC scc(g);
    auto G = scc.groups();
    std::cout << G.size() << '\n';
    for(auto &&vec : scc.groups()){
        std::cout << vec.size();
        for(auto &&v : vec) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
