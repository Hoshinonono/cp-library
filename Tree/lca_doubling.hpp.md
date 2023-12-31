---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/jump_on_tree_doubling.test.cpp
    title: Test/Library Checker/Tree/jump_on_tree_doubling.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/lca_doubling.test.cpp
    title: Test/Library Checker/Tree/lca_doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/lca_doubling.hpp\"\nstruct LCA_tree {\r\n    int n,\
    \ LOGV, root;\r\n    std::vector<std::vector<int>> &g, parent;\r\n    std::vector<int>\
    \ depth, id;\r\n    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g,\
    \ 0){}\r\n    LCA_tree(std::vector<std::vector<int>> &_g, int r) : n(_g.size()),\
    \ g(_g), root(r), depth(n), id(n, -1) {\r\n        LOGV = std::__lg(std::max(1,\
    \ n - 1));\r\n        parent.resize(LOGV + 1, std::vector<int>(n, -1));\r\n  \
    \      std::vector<int> stk;\r\n        stk.reserve(n);\r\n        stk.emplace_back(root);\r\
    \n        depth[root] = 0;\r\n        int cnt = 0;\r\n        while(!stk.empty()){\r\
    \n            int v = stk.back();\r\n            stk.pop_back();\r\n         \
    \   id[v] = cnt++;\r\n            for(int i = 1; (1 << i) <= depth[v]; i++){\r\
    \n                parent[i][v] = parent[i - 1][parent[i - 1][v]];\r\n        \
    \    }\r\n            for(auto &&u : g[v]){\r\n                if(id[u] != -1)\
    \ continue;\r\n                parent[0][u] = v;\r\n                depth[u] =\
    \ depth[v] + 1;\r\n                stk.emplace_back(u);\r\n            }\r\n \
    \       }\r\n    }\r\n    int lca(int u, int v){\r\n        assert(0 <= u && u\
    \ < n);\r\n        assert(0 <= v && v < n);\r\n        if(depth[u] > depth[v])\
    \ std::swap(u, v);\r\n        int d = depth[v] - depth[u];\r\n        while(d){\r\
    \n            v = parent[std::__lg(d & -d)][v];\r\n            d -= d & -d;\r\n\
    \        }\r\n        if(u == v) return u;\r\n        for(int i = std::__lg(depth[v]);\
    \ i >= 0; i--){\r\n            if(parent[i][u] != parent[i][v]){\r\n         \
    \       u = parent[i][u];\r\n                v = parent[i][v];\r\n           \
    \ }\r\n        }\r\n        return parent[0][u];\r\n    }\r\n    int la(int v,\
    \ int d){\r\n        if(d > depth[v]) return -1;\r\n        while(d){\r\n    \
    \        v = parent[std::__lg(d & -d)][v];\r\n            d -= d & -d;\r\n   \
    \     }\r\n        return v;\r\n    }\r\n    int la(int from, int to, int d){\r\
    \n        int lcav = lca(from, to);\r\n        int len = depth[from] + depth[to]\
    \ - 2 * depth[lcav];\r\n        if(d > len) return -1;\r\n        return (d <=\
    \ depth[from] - depth[lcav] ? la(from, d) : la(to, len - d));\r\n    }\r\n   \
    \ int dist(int u, int v){\r\n        int lcav = lca(u, v);\r\n        return depth[u]\
    \ + depth[v] - 2 * depth[lcav];\r\n    }\r\n    bool on_path(int from, int to,\
    \ int mid){\r\n        return dist(from, mid) + dist(mid, to) == dist(from, to);\r\
    \n    }\r\n    int Auxiliary_Tree(std::vector<int> &ver){\r\n        int ret =\
    \ 0, m = ver.size();\r\n        std::sort(ver.begin(), ver.end(), [&](int va,\
    \ int vb) {return id[va] < id[vb];});\r\n        for(int i = 0; i < m; i++){\r\
    \n            ret += depth[ver[i]];\r\n            ret -= depth[lca(ver[i], ver[i\
    \ + 1 == m ? 0 : i + 1])];\r\n        }\r\n        return ret;\r\n    }\r\n};\r\
    \n"
  code: "struct LCA_tree {\r\n    int n, LOGV, root;\r\n    std::vector<std::vector<int>>\
    \ &g, parent;\r\n    std::vector<int> depth, id;\r\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g) : LCA_tree(_g, 0){}\r\n    LCA_tree(std::vector<std::vector<int>> &_g,\
    \ int r) : n(_g.size()), g(_g), root(r), depth(n), id(n, -1) {\r\n        LOGV\
    \ = std::__lg(std::max(1, n - 1));\r\n        parent.resize(LOGV + 1, std::vector<int>(n,\
    \ -1));\r\n        std::vector<int> stk;\r\n        stk.reserve(n);\r\n      \
    \  stk.emplace_back(root);\r\n        depth[root] = 0;\r\n        int cnt = 0;\r\
    \n        while(!stk.empty()){\r\n            int v = stk.back();\r\n        \
    \    stk.pop_back();\r\n            id[v] = cnt++;\r\n            for(int i =\
    \ 1; (1 << i) <= depth[v]; i++){\r\n                parent[i][v] = parent[i -\
    \ 1][parent[i - 1][v]];\r\n            }\r\n            for(auto &&u : g[v]){\r\
    \n                if(id[u] != -1) continue;\r\n                parent[0][u] =\
    \ v;\r\n                depth[u] = depth[v] + 1;\r\n                stk.emplace_back(u);\r\
    \n            }\r\n        }\r\n    }\r\n    int lca(int u, int v){\r\n      \
    \  assert(0 <= u && u < n);\r\n        assert(0 <= v && v < n);\r\n        if(depth[u]\
    \ > depth[v]) std::swap(u, v);\r\n        int d = depth[v] - depth[u];\r\n   \
    \     while(d){\r\n            v = parent[std::__lg(d & -d)][v];\r\n         \
    \   d -= d & -d;\r\n        }\r\n        if(u == v) return u;\r\n        for(int\
    \ i = std::__lg(depth[v]); i >= 0; i--){\r\n            if(parent[i][u] != parent[i][v]){\r\
    \n                u = parent[i][u];\r\n                v = parent[i][v];\r\n \
    \           }\r\n        }\r\n        return parent[0][u];\r\n    }\r\n    int\
    \ la(int v, int d){\r\n        if(d > depth[v]) return -1;\r\n        while(d){\r\
    \n            v = parent[std::__lg(d & -d)][v];\r\n            d -= d & -d;\r\n\
    \        }\r\n        return v;\r\n    }\r\n    int la(int from, int to, int d){\r\
    \n        int lcav = lca(from, to);\r\n        int len = depth[from] + depth[to]\
    \ - 2 * depth[lcav];\r\n        if(d > len) return -1;\r\n        return (d <=\
    \ depth[from] - depth[lcav] ? la(from, d) : la(to, len - d));\r\n    }\r\n   \
    \ int dist(int u, int v){\r\n        int lcav = lca(u, v);\r\n        return depth[u]\
    \ + depth[v] - 2 * depth[lcav];\r\n    }\r\n    bool on_path(int from, int to,\
    \ int mid){\r\n        return dist(from, mid) + dist(mid, to) == dist(from, to);\r\
    \n    }\r\n    int Auxiliary_Tree(std::vector<int> &ver){\r\n        int ret =\
    \ 0, m = ver.size();\r\n        std::sort(ver.begin(), ver.end(), [&](int va,\
    \ int vb) {return id[va] < id[vb];});\r\n        for(int i = 0; i < m; i++){\r\
    \n            ret += depth[ver[i]];\r\n            ret -= depth[lca(ver[i], ver[i\
    \ + 1 == m ? 0 : i + 1])];\r\n        }\r\n        return ret;\r\n    }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: Tree/lca_doubling.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:46:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/jump_on_tree_doubling.test.cpp
  - Test/Library Checker/Tree/lca_doubling.test.cpp
documentation_of: Tree/lca_doubling.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30BF\
  \u30D6\u30EA\u30F3\u30B0)"
---

## 概要
構築 $\text{O}(N\log N)$ 、クエリ $\text{O}(\log N)$ で最小共通祖先 (Lowest Common Ancestor) を習得できるライブラリである。<br>
実装はDFSの行きがけ順のみを使用していて場合分けを簡潔にしている。<br>

|関数名など|機能|計算量|
|---------|----|-----|
|`LCA_tree(std::vector<std::vector<int>> G, int root)`|`root` を根とする LCA のダブリングテーブルを構築する。<br>・第1引数には無向辺の木もしくは根付き木を G としてコンストラクタに渡す。<br>・第2引数は根を指定する(省略可能)。省略した場合 `0` を根とする。| $\text{O}(N\log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log N)$ |
|(1) `int la(int v, int d)` <br>(2) `int la(int from, int to, int d)`|(1)頂点 $v$ から根に向かって距離 $d$ 進んだ頂点を返す。<br>(2)頂点 $\text{from}$ から頂点 $\text{to}$ に向かって距離 $d$ 進んだ頂点を返す。<br> 存在しない場合は `-1` を返す。| $\text{O}(\log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log N)$ |
|`bool on_path(int from, int to, int mid)`|頂点 $\text{mid}$ が頂点 $\text{from}$ と頂点 $\text{to}$ の単純パス上にあるかを判定する。| $\text{O}(\log N)$ |
|`int Auxiliary_Tree(std::vector<int> ver)`|頂点集合 $\text{ver}$ を連結にするために必要な辺の数を出力する。|頂点集合の大きさを $\|S\|$ として<br> $\text{O}(\|S\|\log N)$|
