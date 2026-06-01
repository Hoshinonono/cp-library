---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/lca_dfs.test.cpp
    title: Test/Library Checker/Tree/lca_dfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tree/lca_dfs.hpp\"\n#include <vector>\n#include <utility>\n\
    \ntemplate<class Graph> struct LCA_tree {\n    int N, LOGV;\n    std::vector<int>\
    \ depth;\n    std::vector<int> start, ent, sparse_tbl;\n    LCA_tree() {}\n  \
    \  LCA_tree(Graph g) : N(g.size()), LOGV(std::__lg(2 * N) + 1), depth(N), start(LOGV\
    \ + 1), ent(N) {\n        sparse_tbl.reserve(2 * N * LOGV);\n        auto dfs\
    \ = [&](auto dfs, int v, int p) -> void {\n            ent[v] = start[1];\n  \
    \          start[1]++;\n            sparse_tbl.emplace_back(v);\n            for(int\
    \ i = 0; i < (int)g[v].size(); i++){\n                int u = g[v][i];\n     \
    \           if(u == p) continue;\n                depth[u] = depth[v] + 1;\n \
    \               dfs(dfs, u, v);\n                if(i + 1 < g[v].size()){\n  \
    \                  start[1]++;\n                    sparse_tbl.emplace_back(v);\n\
    \                }\n            }\n        };\n        dfs(dfs, 0, -1);\n    \
    \    int SZ = start[1];\n        for(int i = 1; i < LOGV; i++){\n            int\
    \ md = 1 << (i - 1), len = md * 2;\n            start[i + 1] = start[i];\n   \
    \         for(int l = 0; l + len <= SZ; l++){\n                start[i + 1]++;\n\
    \                sparse_tbl.emplace_back(compare(sparse_tbl[l + start[i - 1]],\
    \ sparse_tbl[l + md + start[i - 1]]));\n            }\n        }\n    }\n    int\
    \ compare(int lhs, int rhs){\n        return depth[lhs] < depth[rhs] ? lhs : rhs;\n\
    \    }\n    int lca(int u, int v){\n        if(u == v) return u;\n        if(ent[u]\
    \ > ent[v]) std::swap(u, v);\n        int b = std::__lg(ent[v] - ent[u] + 1);\n\
    \        return compare(sparse_tbl[start[b] + ent[u]], sparse_tbl[start[b] + ent[v]\
    \ - (1 << b) + 1]);\n    }\n    int dist(int u, int v){\n        return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\ntemplate<class Graph>\
    \ struct LCA_tree {\n    int N, LOGV;\n    std::vector<int> depth;\n    std::vector<int>\
    \ start, ent, sparse_tbl;\n    LCA_tree() {}\n    LCA_tree(Graph g) : N(g.size()),\
    \ LOGV(std::__lg(2 * N) + 1), depth(N), start(LOGV + 1), ent(N) {\n        sparse_tbl.reserve(2\
    \ * N * LOGV);\n        auto dfs = [&](auto dfs, int v, int p) -> void {\n   \
    \         ent[v] = start[1];\n            start[1]++;\n            sparse_tbl.emplace_back(v);\n\
    \            for(int i = 0; i < (int)g[v].size(); i++){\n                int u\
    \ = g[v][i];\n                if(u == p) continue;\n                depth[u] =\
    \ depth[v] + 1;\n                dfs(dfs, u, v);\n                if(i + 1 < g[v].size()){\n\
    \                    start[1]++;\n                    sparse_tbl.emplace_back(v);\n\
    \                }\n            }\n        };\n        dfs(dfs, 0, -1);\n    \
    \    int SZ = start[1];\n        for(int i = 1; i < LOGV; i++){\n            int\
    \ md = 1 << (i - 1), len = md * 2;\n            start[i + 1] = start[i];\n   \
    \         for(int l = 0; l + len <= SZ; l++){\n                start[i + 1]++;\n\
    \                sparse_tbl.emplace_back(compare(sparse_tbl[l + start[i - 1]],\
    \ sparse_tbl[l + md + start[i - 1]]));\n            }\n        }\n    }\n    int\
    \ compare(int lhs, int rhs){\n        return depth[lhs] < depth[rhs] ? lhs : rhs;\n\
    \    }\n    int lca(int u, int v){\n        if(u == v) return u;\n        if(ent[u]\
    \ > ent[v]) std::swap(u, v);\n        int b = std::__lg(ent[v] - ent[u] + 1);\n\
    \        return compare(sparse_tbl[start[b] + ent[u]], sparse_tbl[start[b] + ent[v]\
    \ - (1 << b) + 1]);\n    }\n    int dist(int u, int v){\n        return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Tree/lca_dfs.hpp
  requiredBy: []
  timestamp: '2026-06-02 01:57:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/lca_dfs.test.cpp
documentation_of: Tree/lca_dfs.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30AF\
  \u30A8\u30EAO(1))"
---

## 概要
前計算 $\text{O}(N\log N)$、クエリ $\text{O} (1)$ で最小共通祖先を求める。<br>
SparseTableをベースに深さが最小の頂点を抽出している。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`LCA_tree(Graph g)`| コンストラクタに木を渡すと、LCAのテーブルが作られる。| $\text{O} (N \log N)$ | 
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(1)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(1)$ |
