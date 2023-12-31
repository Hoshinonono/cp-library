#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C"

#include <bits/stdc++.h>
#include "DataStructure/CumulativeSum2D.hpp"
#include "Math/modint_61bit.hpp"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<mint61> Y(1001), X(1001);
    Y[0] = X[0] = 1;
    for(int y = 0; y < 1000; y++){
        Y[y + 1] = Y[y] * 334;
    }
    for(int x = 0; x < 1000; x++){
        X[x + 1] = X[x] * 114514;
    }
    CumulativeSum2D<mint61> A(h, w);
    for(int y = 0; y < h; y++){
        string s;
        cin >> s;
        for(int x = 0; x < w; x++){
            A.add(y, x, Y[y] * X[x] * s[x]);
        }
    }
    A.build();

    int h2, w2;
    mint61 hash;
    cin >> h2 >> w2;
    for(int y = 0; y < h2; y++){
        string s;
        cin >> s;
        for(int x = 0; x < w2; x++){
            hash += Y[y] * X[x] * s[x];
        }
    }

    for(int y = 0; y + h2 <= h; y++){
        for(int x = 0; x + w2 <= w; x++){
            if(hash * Y[y] * X[x] == A.query(y, x, y + h2, x + w2)){
                cout << y << ' ' << x << '\n';
            }
        }
    }
}
