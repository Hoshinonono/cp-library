#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include <bits/stdc++.h>
#include "Graph/dsu_weighted.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    Weighted_dsu uf(n);
    while(q--){
        int cmd, u, v, d;
        std::cin >> cmd >> u >> v;
        if(cmd == 0) {
            std::cin >> d;
            uf.merge(u, v, d);
        } else {
            if(!uf.same(u, v)){
                std::cout << '?' << '\n';
                continue;
            }
            std::cout << uf.diff(u, v) << '\n';
        }
    }
}
