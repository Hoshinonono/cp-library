template <class S, S (*mapping)(S, S), S (*id)()> struct dual_segtree {
    public:
    dual_segtree() : dual_segtree(0) {}
    dual_segtree(int n) : dual_segtree(std::vector<S>(n, id())) {}
    dual_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
    }
    const S& operator[](int p) const {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
    S& operator[](int p) { 
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
    void apply(int p, S f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
    }
    void apply(int l, int r, S f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        while (l < r) {
            if (l & 1) all_apply(l++, f);
            if (r & 1) all_apply(--r, f);
            l >>= 1;
            r >>= 1;
        }
    }
    private:
    int _n, size, log;
    std::vector<S> d;
    void all_apply(int k, S f) {
        d[k] = mapping(f, d[k]);
    }
    void push(int k) {
        all_apply(2 * k, d[k]);
        all_apply(2 * k + 1, d[k]);
        d[k] = id();
    }
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
};
