struct Heavy_Light_Decomposition{
    int N, tim = 0;
    std::vector<int> sz, ent, leader, order, par;
    std::vector<std::vector<int>> &G;
    Heavy_Light_Decomposition(std::vector<std::vector<int>> &g) : 
            N(g.size()), G(g), sz(N), ent(N), leader(N), order(N), par(N) {
        dfs_size(0, -1);
        dfs_hld(0);
    }
    const int operator[](int v) const {
        assert(0 <= v && v < N);
        return ent[v];
    }
    int operator[](int v) { 
        assert(0 <= v && v < N);
        return ent[v];
    }
    int la(int v, int k) {
        while(true) {
            int u = leader[v];
            if(ent[v] - k >= ent[u]) return order[ent[v] - k];
            k -= ent[v] - ent[u] + 1;
            v = par[u];
        }
    }
    int la(int from, int to, int d){
        int d1 = 0, d2 = 0;
        int v = from, u = to;
        do{
            if(ent[u] < ent[v]){
                if(leader[u] == leader[v]){
                    d1 += ent[v] - ent[u];
                    break;
                }
                d1 += ent[v] - ent[leader[v]] + 1;
                v = par[leader[v]];
            }else{
                if(leader[u] == leader[v]){
                    d2 += ent[u] - ent[v];
                    break;
                }
                d2 += ent[u] - ent[leader[u]] + 1;
                u = par[leader[u]];
            }
        }while(true);
        if(d > d1 + d2) return -1;
        return d <= d1 ? la(from, d) : la(to, d1 + d2 - d);
    }
    int lca(int u, int v) {
        do{
            if(ent[u] > ent[v]) std::swap(u, v);
            if(leader[u] == leader[v]) return u;
            v = par[leader[v]];
        }while(true);
    }
    int dist(int u, int v){
        int ans = 0;
        do{
            if(ent[u] > ent[v]) std::swap(u, v);
            if(leader[u] == leader[v]) return ans + ent[v] - ent[u];
            ans += ent[v] - ent[leader[v]] + 1;
            v = par[leader[v]];
        }while(true);
    }
    template< typename T, typename Q, typename F >
    T query(int u, int v, const T &identity, const Q &qf, const F &f, bool edge = false) {
        T ans = identity;
        do{
            if(ent[u] > ent[v]) std::swap(u, v);
            if(leader[u] == leader[v]) break;
            ans = f( qf(ent[leader[v]], ent[v] + 1), ans);
            v = par[leader[v]];
        }while(true);
        return f( qf(ent[u] + edge, ent[v] + 1), ans);
    }
    template< typename T, typename Q1, typename Q2, typename F >
    T noncom_query(int u, int v, const T &identity, 
                   const Q1 &qf, const Q2 &rev_qf, const F &f, bool edge = false) {
        T sml = identity, smr = identity;
        do{
            if(leader[u] == leader[v]) break;
            if(ent[u] < ent[v]){
                smr = f( qf(ent[leader[v]], ent[v] + 1), smr);
                v = par[leader[v]];
            }else{
                sml = f( sml, rev_qf(ent[leader[u]], ent[u] + 1));
                u = par[leader[u]];
            }
        }while(true);
        if(ent[u] < ent[v]){
            return f(sml,  f( qf(ent[u] + edge, ent[v] + 1), smr));
        }else{
            return f(f(sml, rev_qf(ent[v] + edge, ent[u] + 1)), smr);
        }
    }
    template< typename Q >
    void update(int u, int v, const Q &q, bool edge = false) {
        do{
            if(ent[u] > ent[v]) std::swap(u, v);
            if(leader[u] == leader[v]) break;
            q(ent[leader[v]], ent[v] + 1);
            v = par[leader[v]];
        }while(true);
        q(ent[u] + edge, ent[v] + 1);
    }
    private:
    void dfs_size(int v, int p){
        par[v] = p;
        sz[v] = 1;
        if(!G[v].empty() && G[v][0] == p) std::swap(G[v][0], G[v].back());
        for(auto &u : G[v]){
            if(u == p) continue;
            dfs_size(u, v);
            sz[v] += sz[u];
            if(sz[u] > sz[G[v][0]]) std::swap(G[v][0], u);
        }
    }
    void dfs_hld(int v){
        ent[v] = tim++;
        order[ent[v]] = v;
        for(auto &u : G[v]) {
            if(u == par[v]) continue;
            leader[u] = (G[v][0] == u ? leader[v] : u);
            dfs_hld(u);
        }
    }
};
