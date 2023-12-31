---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/lca_ufdoubling.test.cpp
    title: Test/Library Checker/Tree/lca_ufdoubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/lca_ufdoubling.hpp\"\nstruct LCA_tree {\r\n    int\
    \ n, root;\r\n    std::array<int, 32> log_table{};\r\n    std::vector<std::vector<int>>\
    \ &g, parent;\r\n    std::vector<int> depth, id;\r\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g) : LCA_tree(_g, 0){}\r\n    LCA_tree(std::vector<std::vector<int>> &_g,\
    \ int r)\r\n         : n(_g.size()), g(_g), root(r), depth(n), depth2(n), id(n,\
    \ -1), edge(n),\r\n           parent_or_size(n, -1), parent(5, std::vector<int>(n))\
    \ {\r\n        for(int i = 2; i < 32; i++) log_table[i] = log_table[i >> 1] +\
    \ 1;\r\n        std::vector<int> stk, par(n, -1);\r\n        stk.reserve(n);\r\
    \n        stk.emplace_back(root);\r\n        int cnt = 0, timer = 0;\r\n     \
    \   while(!stk.empty()){\r\n            int v = stk.back();\r\n            if(id[v]\
    \ == -1){\r\n                id[v] = cnt++;\r\n                for(auto &&u :\
    \ g[v]){\r\n                    if(id[u] != -1) continue;\r\n                \
    \    par[u] = v;\r\n                    depth[u] = depth[v] + 1;\r\n         \
    \           stk.emplace_back(u);\r\n                }\r\n            }else{\r\n\
    \                stk.pop_back();\r\n                if(par[v] == -1) break;\r\n\
    \                int x = leader(v), y = leader(par[v]);\r\n                if(-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\r\n                parent_or_size[x]\
    \ += parent_or_size[y];\r\n                parent_or_size[y] = x;\r\n        \
    \        parent[0][y] = x;\r\n                depth2[y] = 1;\r\n             \
    \   edge[y] = std::make_pair(timer++, par[v]);\r\n            }\r\n        }\r\
    \n        for(int i = 1; i < n; i++) leader(i);\r\n        parent[0][leader(0)]\
    \ = -1;\r\n        for(int i = 1; i < 5; i++){\r\n            for(int j = 0; j\
    \ < n; j++){\r\n                parent[i][j] = parent[i - 1][j] == -1 ? -1 : parent[i\
    \ - 1][parent[i - 1][j]];\r\n            }\r\n        }\r\n    }\r\n    int lca(int\
    \ u, int v){\r\n        assert(0 <= u && u < n);\r\n        assert(0 <= v && v\
    \ < n);\r\n        if(u == v) return v;\r\n        if(depth2[u] > depth2[v]) std::swap(u,\
    \ v);\r\n        int d = std::max(0, depth2[v] - depth2[u] - 1);\r\n        while(d){\r\
    \n            v = parent[log_table[d & -d]][v];\r\n            d -= d & -d;\r\n\
    \        }\r\n        if(u == parent[0][v]) return edge[v].second;\r\n       \
    \ if(depth2[u] != depth2[v]) v = parent[0][v];\r\n        for(int i = log_table[depth2[v]];\
    \ i >= 0; i--){\r\n            if(parent[i][u] != parent[i][v]){\r\n         \
    \       u = parent[i][u];\r\n                v = parent[i][v];\r\n           \
    \ }\r\n        }\r\n        if(edge[v].first > edge[u].first) return edge[v].second;\r\
    \n        return edge[u].second;\r\n    }\r\n    int dist(int u, int v){\r\n \
    \       int lcav = lca(u, v);\r\n        return depth[u] + depth[v] - 2 * depth[lcav];\r\
    \n    }\r\n    bool on_path(int from, int to, int mid){\r\n        return dist(from,\
    \ mid) + dist(mid, to) == dist(from, to);\r\n    }\r\n    int Auxiliary_Tree(std::vector<int>\
    \ &ver){\r\n        int ret = 0, m = ver.size();\r\n        std::sort(ver.begin(),\
    \ ver.end(), [&](int va, int vb) {return id[va] < id[vb];});\r\n        for(int\
    \ i = 0; i < m; i++){\r\n            ret += depth[ver[i]];\r\n            ret\
    \ -= depth[lca(ver[i], ver[i + 1 == m ? 0 : i + 1])];\r\n        }\r\n       \
    \ return ret;\r\n    }\r\n    private:\r\n    std::vector<int> parent_or_size,\
    \ depth2;\r\n    std::vector<std::pair<int,int>> edge;\r\n    int leader(int v){\r\
    \n        if(parent_or_size[v] < 0) return v;\r\n        int root = leader(parent_or_size[v]);\r\
    \n        depth2[v] += depth2[parent_or_size[v]];\r\n        return parent_or_size[v]\
    \ = root;\r\n    }\r\n};\r\n"
  code: "struct LCA_tree {\r\n    int n, root;\r\n    std::array<int, 32> log_table{};\r\
    \n    std::vector<std::vector<int>> &g, parent;\r\n    std::vector<int> depth,\
    \ id;\r\n    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}\r\
    \n    LCA_tree(std::vector<std::vector<int>> &_g, int r)\r\n         : n(_g.size()),\
    \ g(_g), root(r), depth(n), depth2(n), id(n, -1), edge(n),\r\n           parent_or_size(n,\
    \ -1), parent(5, std::vector<int>(n)) {\r\n        for(int i = 2; i < 32; i++)\
    \ log_table[i] = log_table[i >> 1] + 1;\r\n        std::vector<int> stk, par(n,\
    \ -1);\r\n        stk.reserve(n);\r\n        stk.emplace_back(root);\r\n     \
    \   int cnt = 0, timer = 0;\r\n        while(!stk.empty()){\r\n            int\
    \ v = stk.back();\r\n            if(id[v] == -1){\r\n                id[v] = cnt++;\r\
    \n                for(auto &&u : g[v]){\r\n                    if(id[u] != -1)\
    \ continue;\r\n                    par[u] = v;\r\n                    depth[u]\
    \ = depth[v] + 1;\r\n                    stk.emplace_back(u);\r\n            \
    \    }\r\n            }else{\r\n                stk.pop_back();\r\n          \
    \      if(par[v] == -1) break;\r\n                int x = leader(v), y = leader(par[v]);\r\
    \n                if(-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\r\
    \n                parent_or_size[x] += parent_or_size[y];\r\n                parent_or_size[y]\
    \ = x;\r\n                parent[0][y] = x;\r\n                depth2[y] = 1;\r\
    \n                edge[y] = std::make_pair(timer++, par[v]);\r\n            }\r\
    \n        }\r\n        for(int i = 1; i < n; i++) leader(i);\r\n        parent[0][leader(0)]\
    \ = -1;\r\n        for(int i = 1; i < 5; i++){\r\n            for(int j = 0; j\
    \ < n; j++){\r\n                parent[i][j] = parent[i - 1][j] == -1 ? -1 : parent[i\
    \ - 1][parent[i - 1][j]];\r\n            }\r\n        }\r\n    }\r\n    int lca(int\
    \ u, int v){\r\n        assert(0 <= u && u < n);\r\n        assert(0 <= v && v\
    \ < n);\r\n        if(u == v) return v;\r\n        if(depth2[u] > depth2[v]) std::swap(u,\
    \ v);\r\n        int d = std::max(0, depth2[v] - depth2[u] - 1);\r\n        while(d){\r\
    \n            v = parent[log_table[d & -d]][v];\r\n            d -= d & -d;\r\n\
    \        }\r\n        if(u == parent[0][v]) return edge[v].second;\r\n       \
    \ if(depth2[u] != depth2[v]) v = parent[0][v];\r\n        for(int i = log_table[depth2[v]];\
    \ i >= 0; i--){\r\n            if(parent[i][u] != parent[i][v]){\r\n         \
    \       u = parent[i][u];\r\n                v = parent[i][v];\r\n           \
    \ }\r\n        }\r\n        if(edge[v].first > edge[u].first) return edge[v].second;\r\
    \n        return edge[u].second;\r\n    }\r\n    int dist(int u, int v){\r\n \
    \       int lcav = lca(u, v);\r\n        return depth[u] + depth[v] - 2 * depth[lcav];\r\
    \n    }\r\n    bool on_path(int from, int to, int mid){\r\n        return dist(from,\
    \ mid) + dist(mid, to) == dist(from, to);\r\n    }\r\n    int Auxiliary_Tree(std::vector<int>\
    \ &ver){\r\n        int ret = 0, m = ver.size();\r\n        std::sort(ver.begin(),\
    \ ver.end(), [&](int va, int vb) {return id[va] < id[vb];});\r\n        for(int\
    \ i = 0; i < m; i++){\r\n            ret += depth[ver[i]];\r\n            ret\
    \ -= depth[lca(ver[i], ver[i + 1 == m ? 0 : i + 1])];\r\n        }\r\n       \
    \ return ret;\r\n    }\r\n    private:\r\n    std::vector<int> parent_or_size,\
    \ depth2;\r\n    std::vector<std::pair<int,int>> edge;\r\n    int leader(int v){\r\
    \n        if(parent_or_size[v] < 0) return v;\r\n        int root = leader(parent_or_size[v]);\r\
    \n        depth2[v] += depth2[parent_or_size[v]];\r\n        return parent_or_size[v]\
    \ = root;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Tree/lca_ufdoubling.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:46:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/lca_ufdoubling.test.cpp
documentation_of: Tree/lca_ufdoubling.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30C0\
  \u30D6\u30EA\u30F3\u30B0+UF)"
---

## 概要
構築 $\text{O}(N\log \log N)$ 、クエリ $\text{O}(\log \log N)$ で最小共通祖先 (Lowest Common Ancestor) を習得できるライブラリである。<br>
実装はDFSの行きがけ順と帰りがけ順のみを使用していて場合分けをやや簡潔にしている。<br>

|関数名など|機能|計算量|
|---------|----|-----|
|`LCA_tree(std::vector<std::vector<int>> G, int root)`|`root` を根とする LCA のダブリングテーブルを構築する。<br>・第1引数には無向辺の木もしくは根付き木を G としてコンストラクタに渡す。<br>・第2引数は省略可能。省略した場合 `0` を根とする。| $\text{O}(N\log \log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log \log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log \log N)$ |
|`bool on_path(int from, int to, int mid)`|頂点 $\text{mid}$ が頂点 $\text{from}$ と頂点 $\text{to}$ の単純パス上にあるかを判定する。| $\text{O}(\log \log N)$ |
|`int Auxiliary_Tree(std::vector<int> ver)`|頂点集合 $\text{ver}$ を連結にするために必要な辺の数を出力する。|頂点集合の大きさを $\|S\|$ として<br> $\text{O}(\|S\|\log \log N)$|
