class LiChaoTree{
    struct Line{
        long long a, b;
        long long get(long long x){return a * x + b; }
        Line(long long a, long long b) : a(a), b(b) {}
    };
    struct Node {
        Node *left, *right;
        Line line;
        Node(Line line) : left(nullptr), right(nullptr), line(line) {}
    };
    const long long inf = 1ll << 60;
    const Line inf_line = Line{0, inf};

    Node *root;
    long long lx, rx;
    Node* _add_line(Node *nd, Line line, long long l, long long r){
        if(l == r) return nullptr;
        if(nd == nullptr) return new Node(line);
        long long m = (l + r) >> 1;

        bool left = (line.get(l) <= nd->line.get(l));
        bool mid = (line.get(m) <= nd->line.get(m));
        bool right = (line.get(r) <= nd->line.get(r));
        if(left && right)nd->line = line;
        if(left == right)return nd;
        if(mid) std::swap(nd->line, line);
        if(left != mid){
            nd->left = _add_line(nd->left, line, l, m);
        }else{
            nd->right = _add_line(nd->right, line, m, r);
        }
        return nd;
    }
    Node* _add_segment_line(long long a, long long b, Node *nd, Line line, long long l, long long r) {
        if(r <= a || b <= l) return nd;
        if(a <= l && r <= b) return _add_line(nd, line, l, r);
        if(nd == nullptr) nd = new Node(inf_line);
        long long m = (l + r) >> 1;
        nd->left = _add_segment_line(a, b, nd->left, line, l, m);
        nd->right = _add_segment_line(a, b, nd->right, line, m, r);
        return nd;
    }
    long long query(long long x, long long l, long long r){
        Node *nd = root;
        long long res = inf;
        while(r > l && nd != nullptr) {
            long long m = (l + r) >> 1;
            res = std::min(res, nd->line.get(x));
            if(x < m) {
                r = m;
                nd = nd->left;
            } else {
                l = m;
                nd = nd->right;
            }
        }
        return res;
    }
    public:
    LiChaoTree(long long lx, long long rx) : lx(lx), rx(rx), root(nullptr) {}
    void add_line(long long a, long long b) {
        Line line(a, b);
        root = _add_line(root, line, lx, rx);
    }
    void add_segment_line(long long a, long long b, long long l, long long r) {
        Line line = Line{a, b};
        root = _add_segment_line(l, r, root, line, lx, rx);
    }
    long long get(long long x) {
        return query(x, lx, rx);
    }
};