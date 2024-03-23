#define PROBLEM "https://yukicoder.me/problems/no/2696"

#include <bits/stdc++.h>
#include "Graph/dsu.hpp"
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<pair<int,int>>> dir(6);
	for(int y = -5; y <= 5; y++){
		for(int x = -5; x <= 5; x++){
			int d = abs(x) + abs(y);
			if(d <= 5) dir[d].emplace_back(y, x);
		}
	}
	int h, w, n, d;
	cin >> h >> w >> n >> d;
	vector<pair<int,int>> a(n);
	for(auto &&[y, x] : a) cin >> y >> x, y--, x--;
	vector<vector<int>> A(h, vector<int>(w, -1));
	for(int i = 0; i < n; i++){
		A[a[i].first][a[i].second] = i;
	}
	dsu uf(n);
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			if(A[y][x] == -1) continue;
			for(int di = 1; di <= d; di++){
				for(auto [ny, nx] : dir[di]){
					ny += y, nx += x;
					if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
					if(A[ny][nx] == -1) continue;
					uf.merge(A[y][x], A[ny][nx]);
				}
			}
		}
	}
	int v = 0;
	vector<int> cnt(n);
	for(auto &&G : uf.groups()){
		int u = uf.leader(G[0]);
		cnt[u] = G.size();
		v += G.size() >= 2;
	}
	int mn = v, mx = v;

	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			if(A[y][x] != -1) continue;
			vector<int> S;
			for(int di = 1; di <= d; di++){
				for(auto [ny, nx] : dir[di]){
					ny += y, nx += x;
					if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
					if(A[ny][nx] == -1) continue;
					S.push_back(uf.leader(A[ny][nx]));
				}
			}
			sort(S.begin(), S.end());
			S.erase(unique(S.begin(), S.end()), S.end());
			int add = 0, num = 1;
			for(auto &&v : S){
				if(num == 1){
					num += cnt[v];
					if(cnt[v] == 1) add++;
				}else{
					num += cnt[v];
					if(cnt[v] == 1) continue;
					add--;
				}
			}
			mx = max(mx, v + add);
			mn = min(mn, v + add);
		}
	}
	cout << mn << " " << mx << '\n';
}