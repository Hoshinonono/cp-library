#define PROBLEM "https://yukicoder.me/problems/no/2780"

#include <bits/stdc++.h>
#include "Graph/scc.hpp"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        g[i].resize(m);
        for(auto &&v : g[i]){
            cin >> v;
            v--;
        }
    }
    SCC scc(g);
    auto G = scc.groups();
    if(find(G[0].begin(), G[0].end(), 0) == G.end()){
        cout << "No\n";
        return 0;
    }
    vector<int> dp(G.size());
    for(int i = 0; i < G.size(); i++){
        if(dp[i] != i){
            cout << "No\n";
            return 0;
        }
        for(auto &&v : G[i]){
            for(auto &&u : g[v]){
                if(scc[v] == scc[u]) continue;
                dp[scc[u]] = max(dp[scc[u]], dp[scc[v]] + 1);
            }
        }
    }
    cout << "Yes\n" << '\n';
}
