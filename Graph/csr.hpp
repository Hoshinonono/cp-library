template <class T> struct csr {
    using itr = typename std::vector<T>::iterator;
    struct Node {
        itr st, en;
        itr begin() { return st; }
        itr end() { return en; }
        int size() { return en - st; }
        T operator[](int p){ return st[p]; }
    };
    const int N;
    std::vector<int> start;
    std::vector<T> E;
    std::vector<std::pair<int,T>> edge;
    csr(int n) : N(n), start(n + 1) {}
    void add_edge(int u, T v){
        assert(0 <= u && u < N);
        start[u + 1]++;
        edge.emplace_back(u, v);
    }
    void build(){
        E.resize(edge.size());
        for(int i = 0; i < N; i++) start[i + 1] += start[i];
        auto cnt = start;
        for(auto [u, v] : edge) E[cnt[u]++] = v;
    }
    Node operator[](int p) {
        return Node{E.begin() + start[p], E.begin() + start[p + 1]};
    }
};