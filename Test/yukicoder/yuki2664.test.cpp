#define PROBLEM "https://yukicoder.me/problems/no/2664"

#include <bits/stdc++.h>
#include "Graph/dsu_01_xor.hpp"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    xor_dsu<int> uf(n);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        if(!uf.merge(--u, --v, 1)){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}