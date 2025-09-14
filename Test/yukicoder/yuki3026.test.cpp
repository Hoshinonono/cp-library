#define PROBLEM "https://yukicoder.me/problems/no/3026"

#include <bits/stdc++.h>
#include <atcoder/all>
#include <DataStructure/StaticRangeLCM.hpp>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

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
        int l = (a * ans).val() % n, r = (b * ans).val() % n;
        if(l > r) swap(l, r);
        r++;
        ans = RLCM.prod(l, r);
        cout << ans.val() << '\n';
    }
}
