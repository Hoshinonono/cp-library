template <class T> struct csr {
    struct Node {
        csr* g;
        int u;
        template<class... Args>
        void emplace_back(Args&&... args){
            g->add_edge(u, T(std::forward<Args>(args)...));
        }
        auto begin(){ return g->E.begin() + g->start[u]; }
        auto end(){ return g->E.begin() + g->start[u + 1]; }
        int size(){ return g->start[u + 1] - g->start[u]; }
        T& operator[](int p){ return *(begin() + p); }
    };
    int N;
    std::vector<int> start;
    std::vector<T> E;
    std::vector<std::pair<int,T>> edge;
    csr(int n) : N(n), start(n + 1) {edge.reserve(n);}
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
	const int size() {return N;}
    Node operator[](int u) {return Node{this, u};}
};