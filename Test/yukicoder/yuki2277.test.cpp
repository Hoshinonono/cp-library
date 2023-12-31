#define PROBLEM "https://yukicoder.me/problems/no/2277"

#include <bits/stdc++.h>
#include "Graph/dsu_01_xor.hpp"
#include "Math/modint.hpp"
using mint = prime_modint<998244353>;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, Q;
    std::cin >> N >> Q;
    xor_dsu<int> uf(N);
    bool flg = true;
    while(Q--){
        int u, v, d;
        std::cin >> u >> v >> d;
        flg &= uf.merge(--u, --v, d);
    }
    std::cout << (flg ? mint(2).pow(uf.size()) : 0) << '\n';
}
