---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/dynamic_tree_vertex_add_path_sum.test.cpp
    title: Test/Library Checker/Tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp
    title: Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/LinkCutTree.hpp\"\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> class LinkCutTree {\r\n    struct Node {\r\n        Node *l, *r, *p;\r\
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
    \  Node_info[pos]->key = v;\r\n        update(Node_info[pos]);\r\n    }\r\n};\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> class LinkCutTree {\r\n    struct\
    \ Node {\r\n        Node *l, *r, *p;\r\n        int id;\r\n        S key, fsum,\
    \ bsum;\r\n        bool rev;\r\n\r\n        explicit Node(const S &v) : key(v),\
    \ fsum(v), bsum(v), rev(false), l(nullptr), r(nullptr), p(nullptr) {}\r\n    \
    \    bool is_root() const { return not p or (p->l != this and p->r != this); }\r\
    \n    };\r\n\r\n    void update(Node* t) {\r\n        t->fsum = t->key;\r\n  \
    \      t->bsum = t->key;\r\n        if(t->l) {\r\n            t->fsum = op(t->l->fsum,\
    \ t->fsum);\r\n            t->bsum = op(t->bsum, t->l->bsum);\r\n        }\r\n\
    \        if(t->r) {\r\n            t->fsum = op(t->fsum, t->r->fsum);\r\n    \
    \        t->bsum = op(t->r->bsum, t->bsum);\r\n        }\r\n    }\r\n\r\n    void\
    \ rotate_right(Node* t) {\r\n        Node *x = t->p, *y = x->p;\r\n        if((x->l\
    \ = t->r)) t->r->p = x;\r\n        t->r = x, x->p = t;\r\n        update(x), update(t);\r\
    \n        if((t->p = y)) {\r\n            if(y->l == x) y->l = t;\r\n        \
    \    if(y->r == x) y->r = t;\r\n            update(y);\r\n        }\r\n    }\r\
    \n\r\n    void rotate_left(Node* t) {\r\n        Node *x = t->p, *y = x->p;\r\n\
    \        if((x->r = t->l)) t->l->p = x;\r\n        t->l = x, x->p = t;\r\n   \
    \     update(x), update(t);\r\n        if((t->p = y)) {\r\n            if(y->l\
    \ == x) y->l = t;\r\n            if(y->r == x) y->r = t;\r\n            update(y);\r\
    \n        }\r\n    }\r\n\r\n    void toggle(Node* t) {\r\n        std::swap(t->l,\
    \ t->r);\r\n        std::swap(t->fsum, t->bsum);\r\n        t->rev ^= true;\r\n\
    \    }\r\n\r\n    void push(Node* t) {\r\n        if(t->rev) {\r\n           \
    \ if(t->l) toggle(t->l);\r\n            if(t->r) toggle(t->r);\r\n           \
    \ t->rev = false;\r\n        }\r\n    }\r\n\r\n    void splay(Node *t) {\r\n \
    \       push(t);\r\n        while(not t->is_root()) {\r\n            Node* q =\
    \ t->p;\r\n            if(q->is_root()) {\r\n                push(q), push(t);\r\
    \n                q->l == t ? rotate_right(t) : rotate_left(t);\r\n          \
    \  } else {\r\n                Node* r = q->p;\r\n                push(r), push(q),\
    \ push(t);\r\n                if(r->l == q) {\r\n                    if(q->l ==\
    \ t) rotate_right(q), rotate_right(t);\r\n                    else rotate_left(t),\
    \ rotate_right(t);\r\n                } else {\r\n                    if(q->r\
    \ == t) rotate_left(q), rotate_left(t);\r\n                    else rotate_right(t),\
    \ rotate_left(t);\r\n                }\r\n            }\r\n        }\r\n    }\r\
    \n\r\n    int N;\r\n\r\n    public:\r\n    std::vector<Node*> Node_info;\r\n \
    \   LinkCutTree(int n) : LinkCutTree(std::vector<S>(n, e())) {}\r\n    LinkCutTree(const\
    \ std::vector<S> &vec) : N(vec.size()), Node_info(vec.size()){\r\n        for(int\
    \ i = 0; i < N; i++) {\r\n            Node_info[i] = new Node(vec[i]);\r\n   \
    \         Node_info[i]->id = i;\r\n        }\r\n    }\r\n\r\n    int expose(int\
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
    \  Node_info[pos]->key = v;\r\n        update(Node_info[pos]);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Tree/LinkCutTree.hpp
  requiredBy: []
  timestamp: '2024-05-28 04:11:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - Test/Library Checker/Tree/dynamic_tree_vertex_set_path_composite.test.cpp
documentation_of: Tree/LinkCutTree.hpp
layout: document
title: Link Cut Tree
---

## 概要
辺の追加、辺の削除を動的に行いながら木のパスクエリに $\text{O}(\log^{2} N)$ 程度で回答できるデータ構造。<br>

|関数名など|機能|計算量|
|---------|----|-----|
| `LinkCutTree<S, op, e>(int N)` <br>| $N$ 頂点0辺の森を作成する。<br>型 `S` /二項演算 `S op(S a, S b)` /単位元 `S e()` を定義する必要がある．| $\text{O}(N)$ |
|`int expose(int v)`|頂点 $v$ と根のパスを繋げる。| $\text{O}(\log^{2} N)$ |
|`void evert(int v)`|頂点 $v$ を木の根とする。| $\text{O}(\log^{2} N)$ |
|`void link(int u, int v)`|頂点 $u$ と頂点 $v$ を辺で結ぶ。| $\text{O}(\log^{2} N)$ |
|`void cut(int u, int v)`|頂点 $u$ と頂点 $v$ の間の辺を削除する。| $\text{O}(\log^{2} N)$ |
|`bool same(int u, int v)`|頂点 $u$ と頂点 $v$ が連結であるかを判定する。| $\text{O}(\log^{2} N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを求める。| $\text{O}(\log^{2} N)$ |
|`S query(int u, int v)`|頂点 $u$ から頂点 $v$ へ向かう際のパスクエリを求める。| $\text{O}(\log^{2} N)$ |
|`void set(int v, S x)`|頂点 $v$ に値 $x$ をセットする。| $\text{O}(\log^{2} N)$ |