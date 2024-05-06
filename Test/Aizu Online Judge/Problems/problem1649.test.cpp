#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1649"

#include <bits/stdc++.h>
#include "Graph/dsu.hpp"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int w, h;
        cin >> w >> h;
        if(w == 0) break;
        dsu uf(w + h);
        for(int i = 0; i < w + h - 1; i++){
            int x, y, v;
            cin >> x >> y >> v;
            uf.merge(--x, --y + w);
        }
        cout << (uf.size() == 1 ? "YES" : "NO") << '\n';
    }
}
