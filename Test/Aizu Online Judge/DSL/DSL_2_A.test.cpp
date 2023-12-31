#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A"

#include <bits/stdc++.h>
#include "DataStructure/segtree.hpp"

int op(int lhs, int rhs) {
    return std::min(lhs, rhs);
}

int e(){
    return std::numeric_limits<int>::max();
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    segtree<int, op, e> seg(n);
    while(q--){
        int cmd, x, y;
        std::cin >> cmd >> x >> y;
        if(cmd == 0) {
            seg.set(x, y);
        } else {
            std::cout << seg.prod(x, ++y) << '\n';
        }
    }
}
