#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
#include "DataStructure/SparseTable.hpp"

using namespace std;

int op(int a, int b){ return min(a, b); }
int e(){ return 1 << 30; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, l, r;
    cin >> N >> Q;
    vector<int> a(N);
    for(auto &&v : a) cin >> v;
    SparseTable<int, op, e> st(a);
    
    while(Q--){
        cin >> l >> r;
        cout << st.prod(l, r) << '\n';
    }
}
