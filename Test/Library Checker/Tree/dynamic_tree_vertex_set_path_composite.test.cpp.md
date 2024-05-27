---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Math/modint.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/LinkCutTree.hpp
    title: Link Cut Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#line 1 \"Math/modint.hpp\"\ntemplate<const\
    \ unsigned int MOD> struct prime_modint {\n    using mint = prime_modint;\n  \
    \  unsigned int v;\n    prime_modint() : v(0) {}\n    prime_modint(unsigned int\
    \ a) { a %= MOD; v = a; }\n    prime_modint(unsigned long long a) { a %= MOD;\
    \ v = a; }\n    prime_modint(int a) { a %= (int)(MOD); if(a < 0)a += MOD; v =\
    \ a; }\n    prime_modint(long long a) { a %= (int)(MOD); if(a < 0)a += MOD; v\
    \ = a; }\n    static constexpr int mod() { return MOD; }\n    mint& operator++()\
    \ {v++; if(v == MOD)v = 0; return *this;}\n    mint& operator--() {if(v == 0)v\
    \ = MOD; v--; return *this;}\n    mint operator++(int) { mint result = *this;\
    \ ++*this; return result; }\n    mint operator--(int) { mint result = *this; --*this;\
    \ return result; }\n    mint& operator+=(const mint& rhs) { v += rhs.v; if(v >=\
    \ MOD) v -= MOD; return *this; }\n    mint& operator-=(const mint& rhs) { if(v\
    \ < rhs.v) v += MOD; v -= rhs.v; return *this; }\n    mint& operator*=(const mint&\
    \ rhs) {\n        v = (unsigned int)((unsigned long long)(v) * rhs.v % MOD);\n\
    \        return *this;\n    }\n    mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inv(); }\n    mint operator+() const { return *this; }\n\
    \    mint operator-() const { return mint() - *this; }\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint r = 1, x = *this;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const { assert(v);\
    \ return pow(MOD - 2); }\n    friend mint operator+(const mint& lhs, const mint&\
    \ rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::ostream&\
    \ operator << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v;\
    \ }\n};\n#line 1 \"Tree/LinkCutTree.hpp\"\ntemplate <class S, S (*op)(S, S), S\
    \ (*e)()> class LinkCutTree {\r\n    struct Node {\r\n        Node *l, *r, *p;\r\
    \n        int id;\r\n        S key, fsum, bsum;\r\n        bool rev;\r\n\r\n \
    \       explicit Node(const S &v) : key(v), fsum(v), bsum(v), rev(false), l(nullptr),\
    \ r(nullptr), p(nullptr) {}\r\n        bool is_root() const { return not p or\
    \ (p->l != this and p->r != this); }\r\n    };\r\n\r\n    void update(Node* t)\
    \ {\r\n        t->fsum = t->key;\r\n        t->bsum = t->key;\r\n        if(t->l)\
    \ {\r\n            t->fsum = op(t->l->fsum, t->fsum);\r\n            t->bsum =\
    \ op(t->bsum, t->l->bsum);\r\n        }\r\n        if(t->r) {\r\n            t->fsum\
    \ = op(t->fsum, t->r->fsum);\r\n            t->bsum = op(t->r->bsum, t->bsum);\r\
    \n        }\r\n    }\r\n\r\n    void rotate_right(Node* t) {\r\n        Node *x\
    \ = t->p, *y = x->p;\r\n        if((x->l = t->r)) t->r->p = x;\r\n        t->r\
    \ = x, x->p = t;\r\n        update(x), update(t);\r\n        if((t->p = y)) {\r\
    \n            if(y->l == x) y->l = t;\r\n            if(y->r == x) y->r = t;\r\
    \n            update(y);\r\n        }\r\n    }\r\n\r\n    void rotate_left(Node*\
    \ t) {\r\n        Node *x = t->p, *y = x->p;\r\n        if((x->r = t->l)) t->l->p\
    \ = x;\r\n        t->l = x, x->p = t;\r\n        update(x), update(t);\r\n   \
    \     if((t->p = y)) {\r\n            if(y->l == x) y->l = t;\r\n            if(y->r\
    \ == x) y->r = t;\r\n            update(y);\r\n        }\r\n    }\r\n\r\n    void\
    \ toggle(Node* t) {\r\n        std::swap(t->l, t->r);\r\n        std::swap(t->fsum,\
    \ t->bsum);\r\n        t->rev ^= true;\r\n    }\r\n\r\n    void push(Node* t)\
    \ {\r\n        if(t->rev) {\r\n            if(t->l) toggle(t->l);\r\n        \
    \    if(t->r) toggle(t->r);\r\n            t->rev = false;\r\n        }\r\n  \
    \  }\r\n\r\n    void splay(Node *t) {\r\n        push(t);\r\n        while(not\
    \ t->is_root()) {\r\n            Node* q = t->p;\r\n            if(q->is_root())\
    \ {\r\n                push(q), push(t);\r\n                q->l == t ? rotate_right(t)\
    \ : rotate_left(t);\r\n            } else {\r\n                Node* r = q->p;\r\
    \n                push(r), push(q), push(t);\r\n                if(r->l == q)\
    \ {\r\n                    if(q->l == t) rotate_right(q), rotate_right(t);\r\n\
    \                    else rotate_left(t), rotate_right(t);\r\n               \
    \ } else {\r\n                    if(q->r == t) rotate_left(q), rotate_left(t);\r\
    \n                    else rotate_right(t), rotate_left(t);\r\n              \
    \  }\r\n            }\r\n        }\r\n    }\r\n\r\n    int N;\r\n\r\n    public:\r\
    \n    std::vector<Node*> Node_info;\r\n    LinkCutTree(int n) : LinkCutTree(std::vector<S>(n,\
    \ e())) {}\r\n    LinkCutTree(const std::vector<S> &vec) : N(vec.size()), Node_info(vec.size()){\r\
    \n        for(int i = 0; i < N; i++) {\r\n            Node_info[i] = new Node(vec[i]);\r\
    \n            Node_info[i]->id = i;\r\n        }\r\n    }\r\n\r\n    int expose(int\
    \ v) {\r\n        Node* t = Node_info[v];\r\n        Node* rp = nullptr;\r\n \
    \       for(Node* cur = t; cur; cur = cur->p) {\r\n            splay(cur);\r\n\
    \            cur->r = rp;\r\n            update(cur);\r\n            rp = cur;\r\
    \n        }\r\n        splay(t);\r\n        return rp->id;\r\n    }\r\n\r\n  \
    \  void evert(int v) {\r\n        expose(v);\r\n        toggle(Node_info[v]);\r\
    \n        push(Node_info[v]);\r\n    }\r\n\r\n    void link(int child_id, int\
    \ parent_id) {\r\n        Node *child = Node_info[child_id], *parent = Node_info[parent_id];\r\
    \n        evert(child_id);\r\n        expose(parent_id);\r\n        if(child_id\
    \ == parent_id || child->p) {\r\n            throw std::runtime_error(\"child\
    \ and parent must be different connected components\");\r\n        }\r\n     \
    \   child->p = parent;\r\n        parent->r = child;\r\n        update(parent);\r\
    \n    }\r\n\r\n    void cut(int child_id) {\r\n        Node *child = Node_info[child_id];\r\
    \n        expose(child_id);\r\n        auto *parent = child->l;\r\n        child->l\
    \ = nullptr;\r\n        parent->p = nullptr;\r\n    }\r\n\r\n    void cut(int\
    \ child_id, int parent_id){\r\n        evert(parent_id);\r\n        expose(child_id);\r\
    \n        while(Node_info[child_id]->l){\r\n            Node* child = Node_info[child_id];\r\
    \n            Node* parent = child->l;\r\n            child->l = nullptr;\r\n\
    \            parent->p = nullptr;\r\n            update(child);\r\n          \
    \  child_id = parent->id;\r\n        }\r\n    }\r\n\r\n    bool same(int u, int\
    \ v) {\r\n        expose(u), expose(v);\r\n        return u == v or Node_info[u]->p;\r\
    \n    }\r\n\r\n    int lca(int u, int v) {\r\n        if(u == v) return u;\r\n\
    \        expose(u);\r\n        int lcav = expose(v);\r\n        if(not Node_info[u]->p)\
    \ return -1;\r\n        return lcav;\r\n    }\r\n\r\n    const S &query(int u,\
    \ int v) {\r\n        evert(u);\r\n        expose(v);\r\n        return Node_info[v]->fsum;\r\
    \n    }\r\n\r\n    void set(int pos, S v) {\r\n        expose(pos);\r\n      \
    \  Node_info[pos]->key = v;\r\n        update(Node_info[pos]);\r\n    }\r\n};\n\
    #line 6 \"Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \nusing namespace std;\r\nusing mint = prime_modint<998244353>;\r\nusing ll =\
    \ long long;\r\n\r\nusing S = pair<mint,mint>;\r\nS op(S lhs, S rhs){\r\n    return\
    \ make_pair(lhs.first * rhs.first, rhs.first * lhs.second + rhs.second);\r\n}\r\
    \nS e(){\r\n    return make_pair(1, 0);\r\n}\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q;\r\n    cin >> N >> Q;\r\n    LinkCutTree<S,\
    \ op, e> LCT(N);\r\n    for(int i = 0; i < N; i++){\r\n        int a, b;\r\n \
    \       cin >> a >> b;\r\n        LCT.set(i, make_pair(a, b));\r\n    }\r\n  \
    \  for(int i = 1; i < N; i++){\r\n        int u, v;\r\n        cin >> u >> v;\r\
    \n        LCT.link(u, v);\r\n    }\r\n    while(Q--){\r\n        int cmd;\r\n\
    \        cin >> cmd;\r\n        if(cmd == 0){\r\n            int u, v, w, x;\r\
    \n            cin >> u >> v >> w >> x;\r\n            LCT.cut(u, v);\r\n     \
    \       LCT.link(w, x);\r\n        }else if(cmd == 1){\r\n            int p, c,\
    \ d;\r\n            cin >> p >> c >> d;\r\n            LCT.set(p, make_pair(c,\
    \ d));\r\n        }else{\r\n            int u, v, x;\r\n            cin >> u >>\
    \ v >> x;\r\n            auto pa = LCT.query(u, v);\r\n            cout << pa.first\
    \ * x + pa.second << '\\n';\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Math/modint.hpp\"\r\n#include \"\
    Tree/LinkCutTree.hpp\"\r\nusing namespace std;\r\nusing mint = prime_modint<998244353>;\r\
    \nusing ll = long long;\r\n\r\nusing S = pair<mint,mint>;\r\nS op(S lhs, S rhs){\r\
    \n    return make_pair(lhs.first * rhs.first, rhs.first * lhs.second + rhs.second);\r\
    \n}\r\nS e(){\r\n    return make_pair(1, 0);\r\n}\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q;\r\n    cin >> N >> Q;\r\n    LinkCutTree<S,\
    \ op, e> LCT(N);\r\n    for(int i = 0; i < N; i++){\r\n        int a, b;\r\n \
    \       cin >> a >> b;\r\n        LCT.set(i, make_pair(a, b));\r\n    }\r\n  \
    \  for(int i = 1; i < N; i++){\r\n        int u, v;\r\n        cin >> u >> v;\r\
    \n        LCT.link(u, v);\r\n    }\r\n    while(Q--){\r\n        int cmd;\r\n\
    \        cin >> cmd;\r\n        if(cmd == 0){\r\n            int u, v, w, x;\r\
    \n            cin >> u >> v >> w >> x;\r\n            LCT.cut(u, v);\r\n     \
    \       LCT.link(w, x);\r\n        }else if(cmd == 1){\r\n            int p, c,\
    \ d;\r\n            cin >> p >> c >> d;\r\n            LCT.set(p, make_pair(c,\
    \ d));\r\n        }else{\r\n            int u, v, x;\r\n            cin >> u >>\
    \ v >> x;\r\n            auto pa = LCT.query(u, v);\r\n            cout << pa.first\
    \ * x + pa.second << '\\n';\r\n        }\r\n    }\r\n}"
  dependsOn:
  - Math/modint.hpp
  - Tree/LinkCutTree.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-05-28 04:19:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp.html
title: Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp
---
