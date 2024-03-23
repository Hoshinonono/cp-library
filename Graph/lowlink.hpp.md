---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/GRL/GRL_3_A.test.cpp
    title: Test/Aizu Online Judge/GRL/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp
    title: Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/lowlink.hpp\"\nstruct lowlink_graph{\r\n    int N;\r\
    \n    std::vector<std::vector<int>>& g;\r\n    std::vector<bool> used;\r\n   \
    \ std::vector<int> order, low, art_point;\r\n    std::vector<std::pair<int,int>>\
    \ bridge;\r\n    lowlink_graph(std::vector<std::vector<int>> &G) \r\n        \
    \    : N(G.size()), g(G), used(N), order(N), low(N) {\r\n        int timer = 0;\r\
    \n        for(int v = 0; v < N; v++){\r\n            if(!used[v]) dfs_lowlink(v,\
    \ -1, timer);\r\n        }\r\n    }\r\n    void dfs_lowlink(int v, int par, int\
    \ &timer){\r\n        used[v] = true;\r\n        low[v] = order[v] = timer++;\r\
    \n        bool is_art_point = false;\r\n        int cnt = 0;\r\n        for(auto\
    \ &u : g[v]){\r\n            if(!used[u]){\r\n                cnt++;\r\n     \
    \           dfs_lowlink(u, v, timer);\r\n                low[v] = std::min(low[v],\
    \ low[u]);\r\n                is_art_point |= ~par && low[u] >= order[v];\r\n\
    \                if(order[v] < low[u]) bridge.emplace_back(std::minmax(v, u));\r\
    \n            }else if(u != par){\r\n                low[v] = std::min(low[v],\
    \ order[u]);\r\n            }\r\n        }\r\n        is_art_point |= par == -1\
    \ && cnt > 1;\r\n        if(is_art_point) art_point.push_back(v);\r\n    }\r\n\
    };\n"
  code: "struct lowlink_graph{\r\n    int N;\r\n    std::vector<std::vector<int>>&\
    \ g;\r\n    std::vector<bool> used;\r\n    std::vector<int> order, low, art_point;\r\
    \n    std::vector<std::pair<int,int>> bridge;\r\n    lowlink_graph(std::vector<std::vector<int>>\
    \ &G) \r\n            : N(G.size()), g(G), used(N), order(N), low(N) {\r\n   \
    \     int timer = 0;\r\n        for(int v = 0; v < N; v++){\r\n            if(!used[v])\
    \ dfs_lowlink(v, -1, timer);\r\n        }\r\n    }\r\n    void dfs_lowlink(int\
    \ v, int par, int &timer){\r\n        used[v] = true;\r\n        low[v] = order[v]\
    \ = timer++;\r\n        bool is_art_point = false;\r\n        int cnt = 0;\r\n\
    \        for(auto &u : g[v]){\r\n            if(!used[u]){\r\n               \
    \ cnt++;\r\n                dfs_lowlink(u, v, timer);\r\n                low[v]\
    \ = std::min(low[v], low[u]);\r\n                is_art_point |= ~par && low[u]\
    \ >= order[v];\r\n                if(order[v] < low[u]) bridge.emplace_back(std::minmax(v,\
    \ u));\r\n            }else if(u != par){\r\n                low[v] = std::min(low[v],\
    \ order[u]);\r\n            }\r\n        }\r\n        is_art_point |= par == -1\
    \ && cnt > 1;\r\n        if(is_art_point) art_point.push_back(v);\r\n    }\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: Graph/lowlink.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:56:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/GRL/GRL_3_A.test.cpp
  - Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp
documentation_of: Graph/lowlink.hpp
layout: document
title: "LowLink\u95A2\u9023 (\u95A2\u7BC0\u70B9, \u6A4B)"
---

## 概要
lowlinkの収得を行うライブラリ。<br>
コンストラクタに無向グラフを渡すと関節点、橋の列挙を行ってくれる。<br>
計算量は、頂点数 $N$ 、辺数 $M$ として記述。<br>
<b>多重辺があるグラフは現段階では非対応。</b>verifyできる問題ないのかな...<br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`lowlink_graph(std::vector<std::vector<int>>)`|宣言。 コンストラクタに無向グラフを渡す。 | $\text{O} (N+M)$ | 
|`std::vector<int> art_point`|メンバ変数。関節点が列挙される。<br>順番は未定義。 | - | 
|`std::vector<std::pair<int,int>> bridge`|メンバ変数。橋であるような辺を $u < v$ として、pair型で列挙される。<br>順番は未定義| - | 
