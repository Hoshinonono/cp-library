#define PROBLEM "https://yukicoder.me/problems/no/2764"

#include <bits/stdc++.h>
#include "DataStructure/LiChaoTree_min.hpp"
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    LiChaoTree LCT(0, 1 << 30);
    vector<ll> dp(n, 1ll << 60);
    vector<vector<pair<int,ll>>> g(n);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for(auto &&v : w) cin >> v;
    for(int i = 0; i < m; i++){
        int u, v;
        ll t;
        cin >> u >> v >> t;
        u--, v--;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
    }
    dp[0] = 0;
    pq.emplace(0, 0);
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if(d > dp[v]) continue;
        LCT.add_line(w[v], d);
        for(auto &&[u, w] : g[v]){
            if(d + w >= dp[u]) continue;
            dp[u] = d + w;
            pq.emplace(dp[u], u);
        }
    }
    for(int i = 0; i < n; i++){
        ll d = LCT.get(w[i]);
        if(d < dp[i]){
            dp[i] = d;
            pq.emplace(dp[i], i);
        }
    }
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if(d > dp[v]) continue;
        LCT.add_line(w[v], d);
        for(auto &&[u, w] : g[v]){
            if(d + w >= dp[u]) continue;
            dp[u] = d + w;
            pq.emplace(dp[u], u);
        }
    }
    cout << dp[n - 1] << '\n';
}
