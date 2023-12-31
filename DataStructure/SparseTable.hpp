template <class T, T (*op)(T, T), T (*e)()> struct SparseTable {
    const int n, LOGV;
    std::vector<std::vector<T>> table;
    std::vector<int> log_table;
    SparseTable(const std::vector<T> &v) : n(v.size()), LOGV(std::__lg(std::max(n, 1)) + 1), 
                                           log_table(n + 1), table(LOGV, std::vector<T>(n)) {
        std::copy(v.begin(), v.end(), table[0].begin());
        for(int i = 1; i < LOGV; i++) {
            for(int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
        for(int i = 2; i <= n; i++) {
            log_table[i] = log_table[i >> 1] + 1;
        }
    }
    T prod(int l, int r){
        assert(0 <= l && l <= r && r <= n);
        if(l == r) return e();
        int b = log_table[r - l];
        return op(table[b][l], table[b][r - (1 << b)]);
    }
};
