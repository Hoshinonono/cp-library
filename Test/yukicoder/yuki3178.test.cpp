#define PROBLEM "https://yukicoder.me/problems/no/3187"

#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
#include <Graph/csr.hpp>
#include <DataStructure/segtree_dual.hpp>
using namespace std;
using mint = atcoder::modint;
using S = mint;
// bf に af を作用させた時の変化
S mapping(S af, S bf){ return bf + af; }
// 恒等写像
S id(){ return 0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    mint::set_mod(p);
    csr<int> dv(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 2 * i; j <= n; j += i) dv.add_edge(j, i);
    }
    dv.build();
    vector<mint> coef(n + 1), prv(n + 1);
    mint ans;
    int mn = n;
    for(int i = 1; i <= n; i++){
        int v = n - (n % i);
        coef[v]++;
        mn = min(mn, v);
    }
    dual_segtree<S, mapping, id> seg(n + 1);
    prv[n] = 1;
    for(int i = n; i >= 3; i--){
        mint div = mint::raw(i - 1 - dv[i].size()).inv();
        ans += prv[i] * mint(i) * div;
        seg.apply(mn, i, prv[i] * div);
        for(int j = 0; j < dv[i].size(); j++){
            int d = dv[i][j];
            int v = i - d;
            prv[v] += seg[v] * coef[v];
            seg[v] = 0;
            coef[v]++;
            mn = min(mn, v);
        }
    }
    cout << ans.val() << '\n';
}
