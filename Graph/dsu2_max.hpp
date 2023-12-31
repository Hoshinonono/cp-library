template <class T> struct Kruskal_dsu {
    public:
    Kruskal_dsu() : _n(0) {}
    Kruskal_dsu(int n) : _n(n), num_component(n), parent_or_size(n, -1), 
                         dat(n, std::numeric_limits<T>::max()) {}

    bool merge(int u, int v, T w) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        int x = leader(u), y = leader(v);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        dat[y] = w;
        num_component--;
        return true;
    }

    bool same(int u, int v) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        return leader(v) == leader(u);
    }

    int leader(int v) {
        assert(0 <= v && v < _n);
        while(parent_or_size[v] >= 0) v = parent_or_size[v];
        return v;
    }

    int size() {
        return num_component;
    }

    int size(int v) {
        assert(0 <= v && v < _n);
        return -parent_or_size[leader(v)];
    }

    T max_edge(int u, int v){
        T ans = 0;
        while(u != v){
            if (dat[u] > dat[v]) std::swap(u, v);
            ans = dat[u], u = parent_or_size[u];
            if(u < 0) return -1;
        }
        return ans;
    }

    private:
    int _n, num_component;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
    std::vector<T> dat;
};