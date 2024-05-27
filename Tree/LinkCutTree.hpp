template <class S, S (*op)(S, S), S (*e)()> class LinkCutTree {
    struct Node {
        Node *l, *r, *p;
        int id;
        S key, fsum, bsum;
        bool rev;

        explicit Node(const S &v) : key(v), fsum(v), bsum(v), rev(false), l(nullptr), r(nullptr), p(nullptr) {}
        bool is_root() const { return not p or (p->l != this and p->r != this); }
    };

    void update(Node* t) {
        t->fsum = t->key;
        t->bsum = t->key;
        if(t->l) {
            t->fsum = op(t->l->fsum, t->fsum);
            t->bsum = op(t->bsum, t->l->bsum);
        }
        if(t->r) {
            t->fsum = op(t->fsum, t->r->fsum);
            t->bsum = op(t->r->bsum, t->bsum);
        }
    }

    void rotate_right(Node* t) {
        Node *x = t->p, *y = x->p;
        if((x->l = t->r)) t->r->p = x;
        t->r = x, x->p = t;
        update(x), update(t);
        if((t->p = y)) {
            if(y->l == x) y->l = t;
            if(y->r == x) y->r = t;
            update(y);
        }
    }

    void rotate_left(Node* t) {
        Node *x = t->p, *y = x->p;
        if((x->r = t->l)) t->l->p = x;
        t->l = x, x->p = t;
        update(x), update(t);
        if((t->p = y)) {
            if(y->l == x) y->l = t;
            if(y->r == x) y->r = t;
            update(y);
        }
    }

    void toggle(Node* t) {
        std::swap(t->l, t->r);
        std::swap(t->fsum, t->bsum);
        t->rev ^= true;
    }

    void push(Node* t) {
        if(t->rev) {
            if(t->l) toggle(t->l);
            if(t->r) toggle(t->r);
            t->rev = false;
        }
    }

    void splay(Node *t) {
        push(t);
        while(not t->is_root()) {
            Node* q = t->p;
            if(q->is_root()) {
                push(q), push(t);
                q->l == t ? rotate_right(t) : rotate_left(t);
            } else {
                Node* r = q->p;
                push(r), push(q), push(t);
                if(r->l == q) {
                    if(q->l == t) rotate_right(q), rotate_right(t);
                    else rotate_left(t), rotate_right(t);
                } else {
                    if(q->r == t) rotate_left(q), rotate_left(t);
                    else rotate_right(t), rotate_left(t);
                }
            }
        }
    }

    int N;

    public:
    std::vector<Node*> Node_info;
    LinkCutTree(int n) : LinkCutTree(std::vector<S>(n, e())) {}
    LinkCutTree(const std::vector<S> &vec) : N(vec.size()), Node_info(vec.size()){
        for(int i = 0; i < N; i++) {
            Node_info[i] = new Node(vec[i]);
            Node_info[i]->id = i;
        }
    }

    int expose(int v) {
        Node* t = Node_info[v];
        Node* rp = nullptr;
        for(Node* cur = t; cur; cur = cur->p) {
            splay(cur);
            cur->r = rp;
            update(cur);
            rp = cur;
        }
        splay(t);
        return rp->id;
    }

    void evert(int v) {
        expose(v);
        toggle(Node_info[v]);
        push(Node_info[v]);
    }

    void link(int child_id, int parent_id) {
        Node *child = Node_info[child_id], *parent = Node_info[parent_id];
        evert(child_id);
        expose(parent_id);
        if(child_id == parent_id || child->p) {
            throw std::runtime_error("child and parent must be different connected components");
        }
        child->p = parent;
        parent->r = child;
        update(parent);
    }

    void cut(int child_id) {
        Node *child = Node_info[child_id];
        expose(child_id);
        auto *parent = child->l;
        child->l = nullptr;
        parent->p = nullptr;
    }

    void cut(int child_id, int parent_id){
        evert(parent_id);
        expose(child_id);
        while(Node_info[child_id]->l){
            Node* child = Node_info[child_id];
            Node* parent = child->l;
            child->l = nullptr;
            parent->p = nullptr;
            update(child);
            child_id = parent->id;
        }
    }

    bool same(int u, int v) {
        expose(u), expose(v);
        return u == v or Node_info[u]->p;
    }

    int lca(int u, int v) {
        if(u == v) return u;
        expose(u);
        int lcav = expose(v);
        if(not Node_info[u]->p) return -1;
        return lcav;
    }

    const S &query(int u, int v) {
        evert(u);
        expose(v);
        return Node_info[v]->fsum;
    }

    void set(int pos, S v) {
        expose(pos);
        Node_info[pos]->key = v;
        update(Node_info[pos]);
    }
};