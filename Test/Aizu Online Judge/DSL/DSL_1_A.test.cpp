#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <bits/stdc++.h>
#include "Graph/dsu.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    dsu uf(n);
    while(q--){
        int cmd, u, v;
        std::cin >> cmd >> u >> v;
        if(cmd == 0) {
            uf.merge(u, v);
        } else {
            std::cout << uf.same(u, v) << '\n';
        }
    }
}
