#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <bits/stdc++.h>
#include <atcoder/all>
#include "Polynomial/01_inv_of_polynomial.hpp"
using namespace std;
using mint = atcoder::modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, v;
    cin >> n;
    vector<mint> a(n);
    for(int i = 0; i < n; i++){
        cin >> v;
        a[i] = mint::raw(v);
    }
    auto ans = inverse(a);
    for(int i = 0; i < n; i++) cout << ans[i].val() << (i + 1 == n ? '\n' : ' ');
}

