---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/lowlink_tecc.hpp\"\nstruct tecc_graph{\r\n    int\
    \ N;\r\n    bool TECC_flag = false;\r\n    std::vector<std::vector<int>> &g;\r\
    \n    std::vector<bool> used;\r\n    std::vector<int> order, low, comp;\r\n  \
    \  std::vector<std::pair<int,int>> bridge;\r\n    tecc_graph(std::vector<std::vector<int>>\
    \ &G) \r\n            : N(G.size()), g(G), used(N), order(N), low(N), comp(N,\
    \ -1) {\r\n        int timer = 0;\r\n        for(int v = 0; v < N; v++){\r\n \
    \           if(!used[v]) dfs_lowlink(v, -1, timer);\r\n        }\r\n    }\r\n\
    \    int operator[](int p) { \r\n        assert(TECC_flag && 0 <= p && p < N);\r\
    \n        return comp[p]; \r\n    }\r\n    void dfs_lowlink(int v, int par, int\
    \ &timer){\r\n        used[v] = true;\r\n        low[v] = order[v] = timer++;\r\
    \n        bool par_flg = false;\r\n        for(auto &u : g[v]){\r\n          \
    \  if(!used[u]){\r\n                dfs_lowlink(u, v, timer);\r\n            \
    \    low[v] = std::min(low[v], low[u]);\r\n                if(order[v] < low[u])\
    \ bridge.emplace_back(std::minmax(v, u));\r\n                else merge(u, v);\r\
    \n            }else if(u != par || par_flg){\r\n                low[v] = std::min(low[v],\
    \ order[u]);\r\n            }\r\n            if(u == par) par_flg = true;\r\n\
    \        }\r\n    }\r\n    std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>\
    \ tecc(){\r\n        TECC_flag = true;\r\n        std::vector<std::vector<int>>\
    \ Group(N);\r\n        for(int i = 0; i < N; i++){\r\n            if(comp[i] <\
    \ 0) Group[i].reserve(-comp[i]);\r\n        }\r\n        for(int i = 0; i < N;\
    \ i++) Group[leader(i)].push_back(i);\r\n        Group.erase(\r\n            std::remove_if(Group.begin(),\
    \ Group.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            Group.end());\r\n        for(int id = 0;\
    \ id < Group.size(); id++){\r\n            for(auto &&v : Group[id]) comp[v] =\
    \ id;\r\n        }\r\n        std::vector<std::vector<int>> result(Group.size());\r\
    \n        for(auto &&e : bridge){\r\n            int u = comp[e.first], v = comp[e.second];\r\
    \n            result[u].push_back(v);\r\n            result[v].push_back(u);\r\
    \n        }\r\n        return std::make_pair(result, Group);\r\n    }\r\n    private:\r\
    \n    int leader(int v){\r\n        if(comp[v] < 0)return v;\r\n        return\
    \ comp[v] = leader(comp[v]);\r\n    }\r\n    void merge(int u, int v){\r\n   \
    \     int x = leader(u), y = leader(v);\r\n        if(x == y) return;\r\n    \
    \    if (-comp[x] < -comp[y]) std::swap(x, y);\r\n        comp[x] += comp[y];\r\
    \n        comp[y] = x;\r\n    }\r\n};\n"
  code: "struct tecc_graph{\r\n    int N;\r\n    bool TECC_flag = false;\r\n    std::vector<std::vector<int>>\
    \ &g;\r\n    std::vector<bool> used;\r\n    std::vector<int> order, low, comp;\r\
    \n    std::vector<std::pair<int,int>> bridge;\r\n    tecc_graph(std::vector<std::vector<int>>\
    \ &G) \r\n            : N(G.size()), g(G), used(N), order(N), low(N), comp(N,\
    \ -1) {\r\n        int timer = 0;\r\n        for(int v = 0; v < N; v++){\r\n \
    \           if(!used[v]) dfs_lowlink(v, -1, timer);\r\n        }\r\n    }\r\n\
    \    int operator[](int p) { \r\n        assert(TECC_flag && 0 <= p && p < N);\r\
    \n        return comp[p]; \r\n    }\r\n    void dfs_lowlink(int v, int par, int\
    \ &timer){\r\n        used[v] = true;\r\n        low[v] = order[v] = timer++;\r\
    \n        bool par_flg = false;\r\n        for(auto &u : g[v]){\r\n          \
    \  if(!used[u]){\r\n                dfs_lowlink(u, v, timer);\r\n            \
    \    low[v] = std::min(low[v], low[u]);\r\n                if(order[v] < low[u])\
    \ bridge.emplace_back(std::minmax(v, u));\r\n                else merge(u, v);\r\
    \n            }else if(u != par || par_flg){\r\n                low[v] = std::min(low[v],\
    \ order[u]);\r\n            }\r\n            if(u == par) par_flg = true;\r\n\
    \        }\r\n    }\r\n    std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>\
    \ tecc(){\r\n        TECC_flag = true;\r\n        std::vector<std::vector<int>>\
    \ Group(N);\r\n        for(int i = 0; i < N; i++){\r\n            if(comp[i] <\
    \ 0) Group[i].reserve(-comp[i]);\r\n        }\r\n        for(int i = 0; i < N;\
    \ i++) Group[leader(i)].push_back(i);\r\n        Group.erase(\r\n            std::remove_if(Group.begin(),\
    \ Group.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            Group.end());\r\n        for(int id = 0;\
    \ id < Group.size(); id++){\r\n            for(auto &&v : Group[id]) comp[v] =\
    \ id;\r\n        }\r\n        std::vector<std::vector<int>> result(Group.size());\r\
    \n        for(auto &&e : bridge){\r\n            int u = comp[e.first], v = comp[e.second];\r\
    \n            result[u].push_back(v);\r\n            result[v].push_back(u);\r\
    \n        }\r\n        return std::make_pair(result, Group);\r\n    }\r\n    private:\r\
    \n    int leader(int v){\r\n        if(comp[v] < 0)return v;\r\n        return\
    \ comp[v] = leader(comp[v]);\r\n    }\r\n    void merge(int u, int v){\r\n   \
    \     int x = leader(u), y = leader(v);\r\n        if(x == y) return;\r\n    \
    \    if (-comp[x] < -comp[y]) std::swap(x, y);\r\n        comp[x] += comp[y];\r\
    \n        comp[y] = x;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/lowlink_tecc.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:55:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/lowlink_tecc.hpp
layout: document
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (TECC, Two-Edge-Connected\
  \ Components)"
---

## 概要
二重辺連結成分分解を行うライブラリ。<br>
コンストラクタに無向グラフを渡すとlowlinkの収得, 橋の列挙を行ってくれる。<br>
メンバ関数の`tecc()`を呼び出すと、二重辺連結成分分解が開始される。<br>
<b>多重辺がある場合にも対応</b><br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`tecc_graph(std::vector<std::vector<int>>)`|宣言。 コンストラクタに無向グラフを渡す。 | $\text{O} (N+M)$ | 
|`std::vector<std::pair<int,int>> bridge`|メンバ変数。橋であるような辺を $u < v$ として、pair型で列挙される。<br>順番は未定義| - | 
|`std::pair<std::vector<std::vector<int>>,`<br>`std::vector<std::vector<int>>> tecc()`|二重辺連結成分分解を行う。std::pairの返り値は次の通り。<br>・連結成分ごとにまとめたグラフ。すなわち、橋だけで構成されるグラフ。<br>・連結成分に属する頂点のリストのリスト。| $\text{O} (N)$ |
|`int [p]`|頂点 $p$ が属する連結成分の番号を返す。|$\text{O} (1)$|
