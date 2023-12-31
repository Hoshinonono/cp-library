struct SCC {
    int n, group_num;
    std::vector<std::vector<int>> &g;
    std::vector<int> ids;
    SCC(std::vector<std::vector<int>> &_g) : n(_g.size()), g(_g), ids(n), group_num(0) {
        int now_ord = 0;
        std::vector<int> visited, low(n), ord(n, -1);
        visited.reserve(n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.emplace_back(v);
            for(auto to : g[v]) {
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
    }
    const int operator[](int p) const {
        assert(0 <= p && p < n);
        return ids[p];
    }
    int operator[](int p) { 
        assert(0 <= p && p < n);
        return ids[p];
    }
    std::vector<std::vector<int>> groups(){
        std::vector<int> counts(group_num);
        for (auto x : ids) counts[x]++;
        std::vector<std::vector<int>> groups(group_num);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < n; i++) {
            groups[ids[i]].emplace_back(i);
        }
        return groups;
    }
};
