struct LCA_tree {
    int n, root;
    std::array<int, 32> log_table{};
    std::vector<std::vector<int>> &g, parent;
    std::vector<int> depth, id;
    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}
    LCA_tree(std::vector<std::vector<int>> &_g, int r)
         : n(_g.size()), g(_g), root(r), depth(n), depth2(n), id(n, -1), edge(n),
           parent_or_size(n, -1), parent(5, std::vector<int>(n)) {
        for(int i = 2; i < 32; i++) log_table[i] = log_table[i >> 1] + 1;
        std::vector<int> stk, par(n, -1);
        stk.reserve(n);
        stk.emplace_back(root);
        int cnt = 0, timer = 0;
        while(!stk.empty()){
            int v = stk.back();
            if(id[v] == -1){
                id[v] = cnt++;
                for(auto &&u : g[v]){
                    if(id[u] != -1) continue;
                    par[u] = v;
                    depth[u] = depth[v] + 1;
                    stk.emplace_back(u);
                }
            }else{
                stk.pop_back();
                if(par[v] == -1) break;
                int x = leader(v), y = leader(par[v]);
                if(-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
                parent_or_size[x] += parent_or_size[y];
                parent_or_size[y] = x;
                parent[0][y] = x;
                depth2[y] = 1;
                edge[y] = std::make_pair(timer++, par[v]);
            }
        }
        for(int i = 1; i < n; i++) leader(i);
        parent[0][leader(0)] = -1;
        for(int i = 1; i < 5; i++){
            for(int j = 0; j < n; j++){
                parent[i][j] = parent[i - 1][j] == -1 ? -1 : parent[i - 1][parent[i - 1][j]];
            }
        }
    }
    int lca(int u, int v){
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        if(u == v) return v;
        if(depth2[u] > depth2[v]) std::swap(u, v);
        int d = std::max(0, depth2[v] - depth2[u] - 1);
        while(d){
            v = parent[log_table[d & -d]][v];
            d -= d & -d;
        }
        if(u == parent[0][v]) return edge[v].second;
        if(depth2[u] != depth2[v]) v = parent[0][v];
        for(int i = log_table[depth2[v]]; i >= 0; i--){
            if(parent[i][u] != parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        if(edge[v].first > edge[u].first) return edge[v].second;
        return edge[u].second;
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
    private:
    std::vector<int> parent_or_size, depth2;
    std::vector<std::pair<int,int>> edge;
    int leader(int v){
        if(parent_or_size[v] < 0) return v;
        int root = leader(parent_or_size[v]);
        depth2[v] += depth2[parent_or_size[v]];
        return parent_or_size[v] = root;
    }
};
