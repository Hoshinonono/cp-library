#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
#include "DataStructure/fenwick_tree.hpp"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, cmd, l, r, v;
    cin >> N >> Q;
    fenwick_tree<long long> fw(N);
    for(int i = 0; i < N; i++){
        cin >> v;
        fw.add(i, v);
    }
    while(Q--){
        cin >> cmd >> l >> r;
        if(cmd == 0){
            fw.add(l, r);
        }else{
            cout << fw.sum(l, r) << '\n';
        }
    }
}
