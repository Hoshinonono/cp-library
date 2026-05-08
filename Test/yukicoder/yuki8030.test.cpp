#define PROBLEM "https://yukicoder.me/problems/no/8030"

#include <bits/stdc++.h>
#include "Math/MillerRabin.hpp"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Miller_Rabin MR;
    int T;
    cin >> T;
    while(T--){
        unsigned long long v;
        cin >> v;
        cout << v << ' ' << MR.is_prime(v) << '\n';
    }
}
