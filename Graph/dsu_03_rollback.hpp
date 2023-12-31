struct rollback_dsu {
    public:
    rollback_dsu() : _n(0) {}
    rollback_dsu(int n) : _n(n), num_component(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) {
            history.emplace_back(-1, -1);
            return x;
        }
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        history.emplace_back(y, parent_or_size[y]);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        num_component--;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        while(parent_or_size[a] >= 0) a = parent_or_size[a];
        return a;
    }

    int size() { 
        return num_component;
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    void undo(){
        if(history.empty()) return;
        int v, sz, par;
        std::tie(v, sz) = history.back();
        history.pop_back();
        if(v == -1) return;
        par = parent_or_size[v];
        parent_or_size[v] = sz;
        parent_or_size[par] -= sz;
        num_component++;
    }

    void rollback(int cnt = -1){
        if(cnt == -1) cnt = history.size();
        while(cnt--) undo();
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

    private:
    int _n, num_component;
    std::vector<int> parent_or_size;
    std::vector<std::pair<int,int>> history;
};
