#pragma once
#include <vector>
#include <utility>

template<class Graph> struct LCA_tree {
    int N, LOGV;
    std::vector<int> depth;
    std::vector<int> start, ent, sparse_tbl;
    LCA_tree() {}
    LCA_tree(Graph g) : N(g.size()), LOGV(std::__lg(2 * N) + 1), depth(N), start(LOGV + 1), ent(N) {
        sparse_tbl.reserve(2 * N * LOGV);
        auto dfs = [&](auto dfs, int v, int p) -> void {
            ent[v] = start[1];
            start[1]++;
            sparse_tbl.emplace_back(v);
            for(int i = 0; i < (int)g[v].size(); i++){
                int u = g[v][i];
                if(u == p) continue;
                depth[u] = depth[v] + 1;
                dfs(dfs, u, v);
                if(i + 1 < g[v].size()){
                    start[1]++;
                    sparse_tbl.emplace_back(v);
                }
            }
        };
        dfs(dfs, 0, -1);
        int SZ = start[1];
        for(int i = 1; i < LOGV; i++){
            int md = 1 << (i - 1), len = md * 2;
            start[i + 1] = start[i];
            for(int l = 0; l + len <= SZ; l++){
                start[i + 1]++;
                sparse_tbl.emplace_back(compare(sparse_tbl[l + start[i - 1]], sparse_tbl[l + md + start[i - 1]]));
            }
        }
    }
    int compare(int lhs, int rhs){
        return depth[lhs] < depth[rhs] ? lhs : rhs;
    }
    int lca(int u, int v){
        if(u == v) return u;
        if(ent[u] > ent[v]) std::swap(u, v);
        int b = std::__lg(ent[v] - ent[u] + 1);
        return compare(sparse_tbl[start[b] + ent[u]], sparse_tbl[start[b] + ent[v] - (1 << b) + 1]);
    }
    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
