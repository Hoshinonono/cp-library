#define PROBLEM "https://yukicoder.me/problems/no/2642"

#include <bits/stdc++.h>
#include <Graph/dsu_02_max.hpp>
using namespace std;
using ll = long long;
using T = tuple<int,int,int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K, C, c = 0;
    cin >> N >> K >> C;
    vector<T> edge(K);
    for(auto &&[u, v, w, p] : edge){
        cin >> u >> v >> w >> p;
        u--, v--;
    }
    sort(edge.begin(), edge.end(), [&](T lhs, T rhs){return get<2>(lhs) < get<2>(rhs);});
    Kruskal_dsu<int> uf(N);
    int ans = 0;
    for(auto &&[u, v, w, p] : edge){
        if(uf.merge(u, v, w)) c += w;
    }
    if(c > C || uf.size() != 1){
        cout << -1 << '\n';
        return 0;
    }
    for(auto &&[u, v, w, p] : edge){
        if(c - uf.max_edge(u, v) + w <= C) ans = max(ans, p);
    }
    cout << ans << '\n';
}