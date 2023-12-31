#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include <bits/stdc++.h>
#include "DataStructure/fenwick_tree.hpp"


int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n), ca;
    for(auto &&v : a) std::cin >> v;
    ca = a;
    sort(ca.begin(), ca.end());
    ca.erase(std::unique(ca.begin(), ca.end()), ca.end());
    int m = ca.size();
    fenwick_tree<int> fw(m);
    long long ans = 0;
    for(auto &&v : a){
        v = std::distance(ca.begin(), std::lower_bound(ca.begin(), ca.end(), v));
        ans += fw.sum(v + 1, m);
        fw.add(v, 1);
    }
    std::cout << ans << '\n';
}
