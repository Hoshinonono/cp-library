struct bcc_graph{
    int N;
    bool BCC_flag = false;
    std::vector<std::vector<int>>& g;
    std::vector<bool> used;
    std::vector<int> order, low, art_point, comp_id;
    std::vector<std::pair<int, int>> tmp;
    std::vector<std::vector<std::pair<int, int>>> BCe;
    bcc_graph(std::vector<std::vector<int>> &G) 
            : N(G.size()), g(G), used(N), order(N, -1), low(N), comp_id(N) {
        int timer = 0;
        for(int v = 0; v < N; v++){
            if(!used[v]) dfs_lowlink(v, -1, timer);
        }
    }
    int operator[](int p) { 
        assert(BCC_flag && 0 <= p && p < N);
        return comp_id[p]; 
    }
    void dfs_lowlink(int v, int par, int &timer){
        used[v] = true;
        low[v] = order[v] = timer++;
        bool is_art_point = false;
        int cnt = 0;
        for(auto &u : g[v]){
            if(u == par) continue;
            if(order[u] < order[v]) tmp.emplace_back(std::minmax(u, v));
            if(!used[u]){
                cnt++;
                dfs_lowlink(u, v, timer);
                low[v] = std::min(low[v], low[u]);
                if(order[v] <= low[u]) {
                    is_art_point |= ~par;
                    BCe.emplace_back();
                    auto pa = std::minmax(v, u);
                    while(true) {
                        auto e = tmp.back();
                        tmp.pop_back();
                        BCe.back().emplace_back(e);
                        if(e.first == pa.first && e.second == pa.second) break;
                    }
                }
            }else{
                low[v] = std::min(low[v], order[u]);
            }
        }
        is_art_point |= par == -1 && cnt > 1;
        if(is_art_point) art_point.push_back(v);
    }
    std::vector<std::vector<int>> bcc(){
        BCC_flag = true;
        std::vector<std::vector<int>> result(BCe.size());
        std::vector<bool> used(N);
        std::vector<int> tmp(1);
        for(int i = 0; i < BCe.size(); i++){
            for(auto &&[u, v] : BCe[i]){
                if(!used[u]){
                    used[u] = true;
                    comp_id[u] = i;
                    result[i].emplace_back(u);
                }
                if(!used[v]){
                    used[v] = true;
                    comp_id[v] = i;
                    result[i].emplace_back(v);
                }
            }
            for(auto &&[u, v] : BCe[i]) used[u] = used[v] = false;
        }
        int id = BCe.size();
        for(int v = 0; v < g.size(); v++){
            if(!g[v].empty()) continue;
            tmp[0] = v;
            comp_id[v] = id++;
            result.emplace_back(tmp);
        }
        return result;
    }
};