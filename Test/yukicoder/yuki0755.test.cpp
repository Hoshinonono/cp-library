#define PROBLEM "https://yukicoder.me/problems/no/755"

#include <bits/stdc++.h>
#include "DataStructure/CumulativeSum2D.hpp"
#include "DataStructure/CumulativeSum2D_imos.hpp"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> A(m, vector<ll>(m));
    for(int y = 0; y < m; y++){
        for(int x = 0; x < m; x++){
            cin >> A[y][x];
        }
    }
    
    CumulativeSum2D<ll> CS(A);
    imos2D<int> imos(m, m);

    for(int ly = 0; ly < m; ly++){
        for(int ry = ly + 1; ry <= m; ry++){
            vector<pair<ll, int>> tmp(m + 1);
            for(int rx = 0; rx <= m; rx++){
                tmp[rx] = {CS.query(ly, 0, ry, rx), rx};
            }
            sort(tmp.begin(), tmp.end());
            for(int x = 0; x < m; ){
                int pre = x;
                while(x <= m && tmp[x].first == tmp[pre].first) x++;
                for(int l = pre; l < x; l++){
                    for(int r = l + 1; r < x; r++){
                        imos.add(ly, tmp[l].second, ry, tmp[r].second, 1);
                    }
                }
            }
        }
    }
    imos.build();
    while(n--){
        int y, x;
        cin >> y >> x;
        cout << imos[y - 1][x - 1] << '\n';
    }
}
