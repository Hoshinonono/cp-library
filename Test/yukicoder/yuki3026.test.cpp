#define PROBLEM "https://yukicoder.me/problems/no/3026"

#include <bits/stdc++.h>
#include "Math/modint.hpp"
#include "DataStructure/StaticRangeLCM.hpp"
using namespace std;
using ll = long long;
using mint = prime_modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &&v : a) cin >> v;
    StaticRangeLCM<mint> RLCM(a);
    int Q;
    cin >> Q;
    mint ans = 1;
    while(Q--){
        int a, b;
        cin >> a >> b;
        int l = (a * ans).v % n, r = (b * ans).v % n;
        if(l > r) swap(l, r);
        r++;
        ans = RLCM.prod(l, r);
        cout << ans << '\n';
    }
}
