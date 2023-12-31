#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_11_D"

#include <bits/stdc++.h>
#include "Graph/dsu.hpp"
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, q, u, v;
    cin >> n >> m;
    dsu uf(n);
    while(m--){
        cin >> u >> v;
        uf.merge(u, v);
    }
    cin >> q;
    while(q--){
        cin >> u >> v;
        cout << (uf.same(u, v) ? "yes" : "no") << '\n';
    }
}
