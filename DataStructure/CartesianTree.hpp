// https://atcoder.jp/contests/abc407/submissions/66142040 を参考
template <class T> struct CartesianTree {
    struct Node {
        int l, r;
        Node() : l(-1), r(-1) {}
    };
    int n, root;
    std::vector<Node> tree;
    const Node& operator[](int idx) const { return tree[idx]; }
    Node& operator[](int idx) { return tree[idx]; }
    CartesianTree() {}
    CartesianTree(const std::vector<T>& a, bool _max = true) : n(a.size()), tree(n) {
        std::vector<int> stk;
        for (int i = 0, pos; i < n; i++) {
            pos = -1;
            while (!stk.empty() && !((a[stk.back()] < a[i]) ^ _max)) {
                int j = stk.back();
                stk.pop_back();
                tree[j].r = pos; 
                pos = j;
            }
            tree[i].l = pos;
            stk.emplace_back(i);
        }
        for (int i = 0; i + 1 < (int)stk.size(); i++) {
            tree[stk[i]].r = stk[i + 1];
        }
        root = stk[0];
    }
};