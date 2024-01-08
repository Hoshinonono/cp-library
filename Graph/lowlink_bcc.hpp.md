---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Graph/biconnected_components.test.cpp
    title: Test/Library Checker/Graph/biconnected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/lowlink_bcc.hpp\"\nstruct bcc_graph{\r\n    int N;\r\
    \n    bool BCC_flag = false;\r\n    std::vector<std::vector<int>>& g;\r\n    std::vector<bool>\
    \ used;\r\n    std::vector<int> order, low, art_point, comp_id;\r\n    std::vector<std::pair<int,\
    \ int>> tmp;\r\n    std::vector<std::vector<std::pair<int, int>>> BCe;\r\n   \
    \ bcc_graph(std::vector<std::vector<int>> &G) \r\n            : N(G.size()), g(G),\
    \ used(N), order(N, -1), low(N), comp_id(N) {\r\n        int timer = 0;\r\n  \
    \      for(int v = 0; v < N; v++){\r\n            if(!used[v]) dfs_lowlink(v,\
    \ -1, timer);\r\n        }\r\n    }\r\n    int operator[](int p) { \r\n      \
    \  assert(BCC_flag && 0 <= p && p < N);\r\n        return comp_id[p]; \r\n   \
    \ }\r\n    void dfs_lowlink(int v, int par, int &timer){\r\n        used[v] =\
    \ true;\r\n        low[v] = order[v] = timer++;\r\n        bool is_art_point =\
    \ false;\r\n        int cnt = 0;\r\n        for(auto &u : g[v]){\r\n         \
    \   if(u == par) continue;\r\n            if(order[u] < order[v]) tmp.emplace_back(std::minmax(u,\
    \ v));\r\n            if(!used[u]){\r\n                cnt++;\r\n            \
    \    dfs_lowlink(u, v, timer);\r\n                low[v] = std::min(low[v], low[u]);\r\
    \n                if(order[v] <= low[u]) {\r\n                    is_art_point\
    \ |= ~par;\r\n                    BCe.emplace_back();\r\n                    auto\
    \ pa = std::minmax(v, u);\r\n                    while(true) {\r\n           \
    \             auto e = tmp.back();\r\n                        tmp.pop_back();\r\
    \n                        BCe.back().emplace_back(e);\r\n                    \
    \    if(e.first == pa.first && e.second == pa.second) break;\r\n             \
    \       }\r\n                }\r\n            }else{\r\n                low[v]\
    \ = std::min(low[v], order[u]);\r\n            }\r\n        }\r\n        is_art_point\
    \ |= par == -1 && cnt > 1;\r\n        if(is_art_point) art_point.push_back(v);\r\
    \n    }\r\n    std::vector<std::vector<int>> bcc(){\r\n        BCC_flag = true;\r\
    \n        std::vector<std::vector<int>> result(BCe.size());\r\n        std::vector<bool>\
    \ used(N);\r\n        std::vector<int> tmp(1);\r\n        for(int i = 0; i < BCe.size();\
    \ i++){\r\n            for(auto &&[u, v] : BCe[i]){\r\n                if(!used[u]){\r\
    \n                    used[u] = true;\r\n                    comp_id[u] = i;\r\
    \n                    result[i].emplace_back(u);\r\n                }\r\n    \
    \            if(!used[v]){\r\n                    used[v] = true;\r\n        \
    \            comp_id[v] = i;\r\n                    result[i].emplace_back(v);\r\
    \n                }\r\n            }\r\n            for(auto &&[u, v] : BCe[i])\
    \ used[u] = used[v] = false;\r\n        }\r\n        int id = BCe.size();\r\n\
    \        for(int v = 0; v < g.size(); v++){\r\n            if(!g[v].empty()) continue;\r\
    \n            tmp[0] = v;\r\n            comp_id[v] = id++;\r\n            result.emplace_back(tmp);\r\
    \n        }\r\n        return result;\r\n    }\r\n};\n"
  code: "struct bcc_graph{\r\n    int N;\r\n    bool BCC_flag = false;\r\n    std::vector<std::vector<int>>&\
    \ g;\r\n    std::vector<bool> used;\r\n    std::vector<int> order, low, art_point,\
    \ comp_id;\r\n    std::vector<std::pair<int, int>> tmp;\r\n    std::vector<std::vector<std::pair<int,\
    \ int>>> BCe;\r\n    bcc_graph(std::vector<std::vector<int>> &G) \r\n        \
    \    : N(G.size()), g(G), used(N), order(N, -1), low(N), comp_id(N) {\r\n    \
    \    int timer = 0;\r\n        for(int v = 0; v < N; v++){\r\n            if(!used[v])\
    \ dfs_lowlink(v, -1, timer);\r\n        }\r\n    }\r\n    int operator[](int p)\
    \ { \r\n        assert(BCC_flag && 0 <= p && p < N);\r\n        return comp_id[p];\
    \ \r\n    }\r\n    void dfs_lowlink(int v, int par, int &timer){\r\n        used[v]\
    \ = true;\r\n        low[v] = order[v] = timer++;\r\n        bool is_art_point\
    \ = false;\r\n        int cnt = 0;\r\n        for(auto &u : g[v]){\r\n       \
    \     if(u == par) continue;\r\n            if(order[u] < order[v]) tmp.emplace_back(std::minmax(u,\
    \ v));\r\n            if(!used[u]){\r\n                cnt++;\r\n            \
    \    dfs_lowlink(u, v, timer);\r\n                low[v] = std::min(low[v], low[u]);\r\
    \n                if(order[v] <= low[u]) {\r\n                    is_art_point\
    \ |= ~par;\r\n                    BCe.emplace_back();\r\n                    auto\
    \ pa = std::minmax(v, u);\r\n                    while(true) {\r\n           \
    \             auto e = tmp.back();\r\n                        tmp.pop_back();\r\
    \n                        BCe.back().emplace_back(e);\r\n                    \
    \    if(e.first == pa.first && e.second == pa.second) break;\r\n             \
    \       }\r\n                }\r\n            }else{\r\n                low[v]\
    \ = std::min(low[v], order[u]);\r\n            }\r\n        }\r\n        is_art_point\
    \ |= par == -1 && cnt > 1;\r\n        if(is_art_point) art_point.push_back(v);\r\
    \n    }\r\n    std::vector<std::vector<int>> bcc(){\r\n        BCC_flag = true;\r\
    \n        std::vector<std::vector<int>> result(BCe.size());\r\n        std::vector<bool>\
    \ used(N);\r\n        std::vector<int> tmp(1);\r\n        for(int i = 0; i < BCe.size();\
    \ i++){\r\n            for(auto &&[u, v] : BCe[i]){\r\n                if(!used[u]){\r\
    \n                    used[u] = true;\r\n                    comp_id[u] = i;\r\
    \n                    result[i].emplace_back(u);\r\n                }\r\n    \
    \            if(!used[v]){\r\n                    used[v] = true;\r\n        \
    \            comp_id[v] = i;\r\n                    result[i].emplace_back(v);\r\
    \n                }\r\n            }\r\n            for(auto &&[u, v] : BCe[i])\
    \ used[u] = used[v] = false;\r\n        }\r\n        int id = BCe.size();\r\n\
    \        for(int v = 0; v < g.size(); v++){\r\n            if(!g[v].empty()) continue;\r\
    \n            tmp[0] = v;\r\n            comp_id[v] = id++;\r\n            result.emplace_back(tmp);\r\
    \n        }\r\n        return result;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/lowlink_bcc.hpp
  requiredBy: []
  timestamp: '2024-01-09 05:18:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Graph/biconnected_components.test.cpp
documentation_of: Graph/lowlink_bcc.hpp
layout: document
title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (BCC, Bi-Connected\
  \ Components)"
---

## 概要
二重頂点連結成分分解を行うライブラリ。<br>
コンストラクタに無向グラフを渡すとlowlinkの収得, 関節点の列挙を行ってくれる。<br>
メンバ関数の`bcc()`を呼び出すと、二重頂点連結成分分解が開始される。<br>
<b>多重辺がある場合にも対応</b><br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`bcc_graph(std::vector<std::vector<int>>)`|宣言。 コンストラクタに無向グラフを渡す。 | $\text{O} (N+M)$ | 
|`std::vector<int> art_point`|メンバ変数。関節点が列挙される。順番は未定義| - | 
|`std::vector<std::vector<int>> bcc()`|二重頂点連結成分分解を行う。連結成分に属する頂点のリストのリストを返す。| $\text{O} (N+M)$ |
|`int [p]`|頂点 $p$ が属する連結成分の番号を返す。|$\text{O} (1)$|