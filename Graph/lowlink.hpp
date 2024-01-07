struct lowlink_graph{
    int N;
    std::vector<std::vector<int>>& g;
    std::vector<bool> used;
    std::vector<int> order, low, art_point;
    std::vector<std::pair<int,int>> bridge;
    lowlink_graph(std::vector<std::vector<int>> &G) 
            : N(G.size()), g(G), used(N), order(N), low(N) {
        int timer = 0;
        for(int v = 0; v < N; v++){
            if(!used[v]) dfs_lowlink(v, -1, timer);
        }
    }
    void dfs_lowlink(int v, int par, int &timer){
        used[v] = true;
        low[v] = order[v] = timer++;
        bool is_art_point = false;
        int cnt = 0;
        for(auto &u : g[v]){
            if(!used[u]){
                cnt++;
                dfs_lowlink(u, v, timer);
                low[v] = std::min(low[v], low[u]);
                is_art_point |= ~par && low[u] >= order[v];
                if(order[v] < low[u]) bridge.emplace_back(std::minmax(v, u));
            }else if(u != par){
                low[v] = std::min(low[v], order[u]);
            }
        }
        is_art_point |= par == -1 && cnt > 1;
        if(is_art_point) art_point.push_back(v);
    }
};