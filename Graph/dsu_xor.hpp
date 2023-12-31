template <class T> struct xor_dsu {
    public:
    xor_dsu() : _n(0) {}
    xor_dsu(int n) : _n(n), num_component(n), parent_or_size(n, -1), diff_weight(n) {}

    bool merge(int a, int b, T w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        w ^= diff_weight[a] ^ diff_weight[b];
        if(x == y) return w == 0;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        diff_weight[y] = w;
        num_component--;
        return true;
    }
    T diff(int a, int b) {
        if(!same(a, b)) return -1;
        return diff_weight[a] ^ diff_weight[b];
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        int r = leader(parent_or_size[a]);
        diff_weight[a] ^= diff_weight[parent_or_size[a]];
        return parent_or_size[a] = r;
    }
    int size() {
        return num_component;
    }
    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
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
        std::vector<T> diff_weight;
};