#define PROBLEM "https://yukicoder.me/problems/no/416"

#include <bits/stdc++.h>
#include "Graph/dsu_02_min.hpp"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<int,int>> B(M), C(Q);
    vector<bool> used(M);
    Kruskal_dsu<int> uf(N);
    for(auto &&[u, v] : B){
        cin >> u >> v;
        u--, v--;
    }
    sort(B.begin(), B.end());
    for(auto &&[u, v] : C){
        cin >> u >> v;
        u--, v--;
        int p = lower_bound(B.begin(), B.end(), make_pair(u, v)) - B.begin();
        used[p] = true;
    }
    for(int i = 0; i < M; i++){
        if(used[i]) continue;
        auto &&[u, v] = B[i];
        uf.merge(u, v, Q + 1);
    }
    for(int i = Q - 1; i >= 0; i--){
        auto &&[u, v] = C[i];
        uf.merge(u, v, i + 1);
    }
    for(int i = 1; i < N; i++){
        int res = uf.min_edge(0, i);
        cout << (res == -1 ? 0 : res > Q ? -1 : res) << '\n';
    }
}
