struct tecc_graph{
    int N;
    bool TECC_flag = false;
    std::vector<std::vector<int>> &g;
    std::vector<bool> used;
    std::vector<int> order, low, comp;
    std::vector<std::pair<int,int>> bridge;
    tecc_graph(std::vector<std::vector<int>> &G) 
            : N(G.size()), g(G), used(N), order(N), low(N), comp(N, -1) {
        int timer = 0;
        for(int v = 0; v < N; v++){
            if(!used[v]) dfs_lowlink(v, -1, timer);
        }
    }
    int operator[](int p) { 
        assert(TECC_flag && 0 <= p && p < N);
        return comp[p]; 
    }
    void dfs_lowlink(int v, int par, int &timer){
        used[v] = true;
        low[v] = order[v] = timer++;
        bool par_flg = false;
        for(auto &u : g[v]){
            if(!used[u]){
                dfs_lowlink(u, v, timer);
                low[v] = std::min(low[v], low[u]);
                if(order[v] < low[u]) bridge.emplace_back(std::minmax(v, u));
                else merge(u, v);
            }else if(u != par || par_flg){
                low[v] = std::min(low[v], order[u]);
            }
            if(u == par) par_flg = true;
        }
    }
    std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> tecc(){
        TECC_flag = true;
        std::vector<std::vector<int>> Group(N);
        for(int i = 0; i < N; i++){
            if(comp[i] < 0) Group[i].reserve(-comp[i]);
        }
        for(int i = 0; i < N; i++) Group[leader(i)].push_back(i);
        Group.erase(
            std::remove_if(Group.begin(), Group.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            Group.end());
        for(int id = 0; id < Group.size(); id++){
            for(auto &&v : Group[id]) comp[v] = id;
        }
        std::vector<std::vector<int>> result(Group.size());
        for(auto &&e : bridge){
            int u = comp[e.first], v = comp[e.second];
            result[u].push_back(v);
            result[v].push_back(u);
        }
        return std::make_pair(result, Group);
    }
    private:
    int leader(int v){
        if(comp[v] < 0)return v;
        return comp[v] = leader(comp[v]);
    }
    void merge(int u, int v){
        int x = leader(u), y = leader(v);
        if(x == y) return;
        if (-comp[x] < -comp[y]) std::swap(x, y);
        comp[x] += comp[y];
        comp[y] = x;
    }
};