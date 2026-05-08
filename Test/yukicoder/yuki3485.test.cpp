#define PROBLEM "https://yukicoder.me/problems/no/3485"

#include <bits/stdc++.h>
#include "Math/MillerRabin.hpp"
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l, r;
	cin >> l >> r;
	constexpr int th = 30'000'000;
	vector<ll> p;
	vector<bool> tb(th + 1);
	for(int i = 2; i <= th; i += 2) tb[i] = true;
	for(int i = 3; i <= th; i += 2){
		if(tb[i]) continue;
		p.emplace_back(i);
		for(int j = i, d = 2 * i; j <= th; j += d) tb[j] = true;
	}
	Miller_Rabin MR;
	int idx = 0;
	ll v = p[idx] * p[idx] * p[idx] * p[idx];
	while(v <= r){
		ll v2 = p[idx] * p[idx];
		for(int j = idx + 1; v2 * p[j] * p[j] < r; j++){
			ll v3 = v2 * p[j];
			ll d = (l + v3 - 1) / v3;
			if(d % 2 == 0) d++;
			ll cur = d * v3;
			ll d2 = v3 * 2;
			while(cur <= r){
				if(MR.is_prime(d)){
					assert(l <= cur && cur <= r);
					cout << cur << '\n';
					return 0;
				}
				d += 2;
				cur += d2;
			}
		}
		idx++;
		v = p[idx] * p[idx] * p[idx] * p[idx];
	}
	cout << "-1\n";
}
