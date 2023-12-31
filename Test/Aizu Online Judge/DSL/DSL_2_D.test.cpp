#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"

#include <bits/stdc++.h>
#include "DataStructure/segtree_dual.hpp"

using namespace std;
int op(int af, int bf){ return af == -1 ? bf : af; }
int id(){ return -1; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    dual_segtree<int, op, id> seg(vector<int>(n, numeric_limits<int>::max()));
    while(q--){
        int cmd;
        cin >> cmd;
        if(cmd == 0){
            int l, r, x;
            cin >> l >> r >> x;
            seg.apply(l, r + 1, x);
        }else{
            int p;
            cin >> p;
            cout << seg[p] << '\n';
        }
    }
}
