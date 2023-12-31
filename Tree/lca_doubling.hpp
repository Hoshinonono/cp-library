struct LCA_tree {
    int n, LOGV, root;
    std::vector<std::vector<int>> &g, parent;
    std::vector<int> depth, id;
    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}
    LCA_tree(std::vector<std::vector<int>> &_g, int r) : n(_g.size()), g(_g), root(r), depth(n), id(n, -1) {
        LOGV = std::__lg(std::max(1, n - 1));
        parent.resize(LOGV + 1, std::vector<int>(n, -1));
        std::vector<int> stk;
        stk.reserve(n);
        stk.emplace_back(root);
        depth[root] = 0;
        int cnt = 0;
        while(!stk.empty()){
            int v = stk.back();
            stk.pop_back();
            id[v] = cnt++;
            for(int i = 1; (1 << i) <= depth[v]; i++){
                parent[i][v] = parent[i - 1][parent[i - 1][v]];
            }
            for(auto &&u : g[v]){
                if(id[u] != -1) continue;
                parent[0][u] = v;
                depth[u] = depth[v] + 1;
                stk.emplace_back(u);
            }
        }
    }
    int lca(int u, int v){
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        if(depth[u] > depth[v]) std::swap(u, v);
        int d = depth[v] - depth[u];
        while(d){
            v = parent[std::__lg(d & -d)][v];
            d -= d & -d;
        }
        if(u == v) return u;
        for(int i = std::__lg(depth[v]); i >= 0; i--){
            if(parent[i][u] != parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
    int la(int v, int d){
        if(d > depth[v]) return -1;
        while(d){
            v = parent[std::__lg(d & -d)][v];
            d -= d & -d;
        }
        return v;
    }
    int la(int from, int to, int d){
        int lcav = lca(from, to);
        int len = depth[from] + depth[to] - 2 * depth[lcav];
        if(d > len) return -1;
        return (d <= depth[from] - depth[lcav] ? la(from, d) : la(to, len - d));
    }
    int dist(int u, int v){
        int lcav = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[lcav];
    }
    bool on_path(int from, int to, int mid){
        return dist(from, mid) + dist(mid, to) == dist(from, to);
    }
    int Auxiliary_Tree(std::vector<int> &ver){
        int ret = 0, m = ver.size();
        std::sort(ver.begin(), ver.end(), [&](int va, int vb) {return id[va] < id[vb];});
        for(int i = 0; i < m; i++){
            ret += depth[ver[i]];
            ret -= depth[lca(ver[i], ver[i + 1 == m ? 0 : i + 1])];
        }
        return ret;
    }
};
