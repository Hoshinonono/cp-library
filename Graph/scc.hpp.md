---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Graph/scc.test.cpp
    title: Test/Library Checker/Graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki2780.test.cpp
    title: Test/yukicoder/yuki2780.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/scc.hpp\"\nstruct SCC {\r\n    int n, group_num;\r\
    \n    std::vector<std::vector<int>> &g;\r\n    std::vector<int> ids;\r\n    SCC(std::vector<std::vector<int>>\
    \ &_g) : n(_g.size()), g(_g), ids(n), group_num(0) {\r\n        int now_ord =\
    \ 0;\r\n        std::vector<int> visited, low(n), ord(n, -1);\r\n        visited.reserve(n);\r\
    \n        auto dfs = [&](auto self, int v) -> void {\r\n            low[v] = ord[v]\
    \ = now_ord++;\r\n            visited.emplace_back(v);\r\n            for(auto\
    \ to : g[v]) {\r\n                if (ord[to] == -1) {\r\n                   \
    \ self(self, to);\r\n                    low[v] = std::min(low[v], low[to]);\r\
    \n                } else {\r\n                    low[v] = std::min(low[v], ord[to]);\r\
    \n                }\r\n            }\r\n            if (low[v] == ord[v]) {\r\n\
    \                while (true) {\r\n                    int u = visited.back();\r\
    \n                    visited.pop_back();\r\n                    ord[u] = n;\r\
    \n                    ids[u] = group_num;\r\n                    if (u == v) break;\r\
    \n                }\r\n                group_num++;\r\n            }\r\n     \
    \   };\r\n        for (int i = 0; i < n; i++) {\r\n            if (ord[i] == -1)\
    \ dfs(dfs, i);\r\n        }\r\n        for (auto& x : ids) {\r\n            x\
    \ = group_num - 1 - x;\r\n        }\r\n    }\r\n    const int operator[](int p)\
    \ const {\r\n        assert(0 <= p && p < n);\r\n        return ids[p];\r\n  \
    \  }\r\n    int operator[](int p) { \r\n        assert(0 <= p && p < n);\r\n \
    \       return ids[p];\r\n    }\r\n    std::vector<std::vector<int>> groups(){\r\
    \n        std::vector<int> counts(group_num);\r\n        for (auto x : ids) counts[x]++;\r\
    \n        std::vector<std::vector<int>> groups(group_num);\r\n        for (int\
    \ i = 0; i < group_num; i++) {\r\n            groups[i].reserve(counts[i]);\r\n\
    \        }\r\n        for (int i = 0; i < n; i++) {\r\n            groups[ids[i]].emplace_back(i);\r\
    \n        }\r\n        return groups;\r\n    }\r\n};\r\n"
  code: "struct SCC {\r\n    int n, group_num;\r\n    std::vector<std::vector<int>>\
    \ &g;\r\n    std::vector<int> ids;\r\n    SCC(std::vector<std::vector<int>> &_g)\
    \ : n(_g.size()), g(_g), ids(n), group_num(0) {\r\n        int now_ord = 0;\r\n\
    \        std::vector<int> visited, low(n), ord(n, -1);\r\n        visited.reserve(n);\r\
    \n        auto dfs = [&](auto self, int v) -> void {\r\n            low[v] = ord[v]\
    \ = now_ord++;\r\n            visited.emplace_back(v);\r\n            for(auto\
    \ to : g[v]) {\r\n                if (ord[to] == -1) {\r\n                   \
    \ self(self, to);\r\n                    low[v] = std::min(low[v], low[to]);\r\
    \n                } else {\r\n                    low[v] = std::min(low[v], ord[to]);\r\
    \n                }\r\n            }\r\n            if (low[v] == ord[v]) {\r\n\
    \                while (true) {\r\n                    int u = visited.back();\r\
    \n                    visited.pop_back();\r\n                    ord[u] = n;\r\
    \n                    ids[u] = group_num;\r\n                    if (u == v) break;\r\
    \n                }\r\n                group_num++;\r\n            }\r\n     \
    \   };\r\n        for (int i = 0; i < n; i++) {\r\n            if (ord[i] == -1)\
    \ dfs(dfs, i);\r\n        }\r\n        for (auto& x : ids) {\r\n            x\
    \ = group_num - 1 - x;\r\n        }\r\n    }\r\n    const int operator[](int p)\
    \ const {\r\n        assert(0 <= p && p < n);\r\n        return ids[p];\r\n  \
    \  }\r\n    int operator[](int p) { \r\n        assert(0 <= p && p < n);\r\n \
    \       return ids[p];\r\n    }\r\n    std::vector<std::vector<int>> groups(){\r\
    \n        std::vector<int> counts(group_num);\r\n        for (auto x : ids) counts[x]++;\r\
    \n        std::vector<std::vector<int>> groups(group_num);\r\n        for (int\
    \ i = 0; i < group_num; i++) {\r\n            groups[i].reserve(counts[i]);\r\n\
    \        }\r\n        for (int i = 0; i < n; i++) {\r\n            groups[ids[i]].emplace_back(i);\r\
    \n        }\r\n        return groups;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/scc.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:43:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Graph/scc.test.cpp
  - Test/yukicoder/yuki2780.test.cpp
documentation_of: Graph/scc.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC, Strongly Connected Component)"
---

## 概要
強連結成分（SCC, Strongly Connected Component）に分解するためのライブラリである。(SCC=有向グラフにおいて、互いに行き来が可能な頂点の集合)

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`SCC(std::vector<std::vector<int>> g)`| 有向グラフをコンストラクタに渡して初期化する。渡した時点で強連結成分分解される。 | $\text{O} (N + M)$ | 
|`int [p]`|頂点 $p$ の属する強連結成分の `id` を返す。 $0 \leq p < N$  | $\text{O} (1)$ | 
|`std::vector<std::vector<int>> groups()`|	以下の条件を満たすような，「頂点のリスト」のリストを返す．<br>・全ての頂点がちょうど1つずつ，どれかのリストに含まれる．<br>・内側のリストと強連結成分が一対一に対応する．リスト内での頂点の順序は未定義である．<br>・リストはトポロジカルソートされている．異なる強連結成分の頂点 $u$ , $v$ について $u$ から $v$ に到達できる時, $u$ の属するリストは $v$ の属するリストよりも前にある．| $\text{O} (N)$ |
