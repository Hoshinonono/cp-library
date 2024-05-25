#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3249"

#include <bits/stdc++.h>
#include "String/RollingHash.hpp"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin >> s){
        if(s == "#") break;
        int n = s.size() / 2;
        string fr = s.substr(0, n), ba = s.substr(s.size() - n, n);
        reverse(ba.begin(), ba.end());
        RollingHash RH1(fr), RH2(ba);
        vector<int> dp(n + 1, 1 << 30);
        dp[0] = 0;
        for(int l = 0; l < n; l++){
            for(int r = l + 1; r <= n; r++){
                if(RH1.hash(l, r) == RH2.hash(l, r)) dp[r] = min(dp[r], dp[l]);
                if(RH1.hash(l, r) == RH2.revhash(l, r)) dp[r] = min(dp[r], dp[l] + (r - l) * (r - l));
            }
        }
        if(dp[n] >> 30 & 1) dp[n] = -1;
        cout << dp[n] << '\n';
    }
}