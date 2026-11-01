#define PROBLEM "https://yukicoder.me/problems/no/74"

#include <Math/BitMatrix.hpp>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    BitMatrix<101> B(n);
    vector<int> d(n), w(n);
    for(auto &&v : d) cin >> v;
    for(auto &&v : w) cin >> v;
    for(int i = 0; i < n; i++){
        B[(i + d[i]) % n][i] = 1;
        B[((i - d[i]) % n + n) % n][i] = 1;
        w[i] ^= 1;
    }
    auto ans = B.linear_equation(w);
    cout << (ans.first != -1 ? "Yes" : "No") << '\n';
}
