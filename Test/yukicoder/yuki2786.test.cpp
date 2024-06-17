#define PROBLEM "https://yukicoder.me/problems/no/2786"

#include <bits/stdc++.h>
#include <Graph/dsu_02_max.hpp>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, Q;
    cin >> h >> w;
    Kruskal_dsu<int> uf(h * w);
    vector<int> pre(w), cur(w);
    vector<tuple<int,int,int>> edge;
    edge.reserve((1 << 18) - 1);
    auto f = [&](int y, int x) {return y * w + x;};
    for(int x = 0; x < w; x++){
        cin >> pre[x];
        if(x) edge.emplace_back(max(pre[x], pre[x - 1]), x - 1, x);
    }
    for(int y = 1; y < h; y++){
        for(int x = 0; x < w; x++){
            cin >> cur[x];
            edge.emplace_back(max(cur[x], pre[x]), (y - 1) * w + x, y * w + x);
            if(x) edge.emplace_back(max(cur[x], cur[x - 1]), y * w + x - 1, y * w + x);
        }
        swap(pre, cur);
    }
    sort(edge.begin(), edge.end());
    for(auto &&[w, u, v] : edge) uf.merge(u, v, w);
    cin >> Q;
    while(Q--){
        int sy, sx, ty, tx;
        cin >> sy >> sx >> ty >> tx;
        sy--, sx--, ty--, tx--;
        cout << uf.max_edge(sy * w + sx, ty * w + tx) << '\n';
    }
}