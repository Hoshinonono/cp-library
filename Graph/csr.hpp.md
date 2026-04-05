---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki3178.test.cpp
    title: Test/yukicoder/yuki3178.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/csr.hpp\"\ntemplate <class T> struct csr {\r\n   \
    \ struct Node {\r\n        csr* g;\r\n        int u;\r\n        template<class...\
    \ Args>\r\n        void emplace_back(Args&&... args){\r\n            g->add_edge(u,\
    \ T(std::forward<Args>(args)...));\r\n        }\r\n        auto begin(){ return\
    \ g->E.begin() + g->start[u]; }\r\n        auto end(){ return g->E.begin() + g->start[u\
    \ + 1]; }\r\n        int size(){ return g->start[u + 1] - g->start[u]; }\r\n \
    \       T& operator[](int p){ return *(begin() + p); }\r\n    };\r\n    int N;\r\
    \n    std::vector<int> start;\r\n    std::vector<T> E;\r\n    std::vector<std::pair<int,T>>\
    \ edge;\r\n    csr(int n) : N(n), start(n + 1) {edge.reserve(n);}\r\n    void\
    \ add_edge(int u, T v){\r\n\t\tassert(0 <= u && u < N);\r\n        start[u + 1]++;\r\
    \n        edge.emplace_back(u, v);\r\n    }\r\n    void build(){\r\n        E.resize(edge.size());\r\
    \n        for(int i = 0; i < N; i++) start[i + 1] += start[i];\r\n        auto\
    \ cnt = start;\r\n        for(auto [u, v] : edge) E[cnt[u]++] = v;\r\n    }\r\n\
    \tconst int size() {return N;}\r\n    Node operator[](int u) {return Node{this,\
    \ u};}\r\n};\r\n"
  code: "template <class T> struct csr {\r\n    struct Node {\r\n        csr* g;\r\
    \n        int u;\r\n        template<class... Args>\r\n        void emplace_back(Args&&...\
    \ args){\r\n            g->add_edge(u, T(std::forward<Args>(args)...));\r\n  \
    \      }\r\n        auto begin(){ return g->E.begin() + g->start[u]; }\r\n   \
    \     auto end(){ return g->E.begin() + g->start[u + 1]; }\r\n        int size(){\
    \ return g->start[u + 1] - g->start[u]; }\r\n        T& operator[](int p){ return\
    \ *(begin() + p); }\r\n    };\r\n    int N;\r\n    std::vector<int> start;\r\n\
    \    std::vector<T> E;\r\n    std::vector<std::pair<int,T>> edge;\r\n    csr(int\
    \ n) : N(n), start(n + 1) {edge.reserve(n);}\r\n    void add_edge(int u, T v){\r\
    \n\t\tassert(0 <= u && u < N);\r\n        start[u + 1]++;\r\n        edge.emplace_back(u,\
    \ v);\r\n    }\r\n    void build(){\r\n        E.resize(edge.size());\r\n    \
    \    for(int i = 0; i < N; i++) start[i + 1] += start[i];\r\n        auto cnt\
    \ = start;\r\n        for(auto [u, v] : edge) E[cnt[u]++] = v;\r\n    }\r\n\t\
    const int size() {return N;}\r\n    Node operator[](int u) {return Node{this,\
    \ u};}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/csr.hpp
  requiredBy: []
  timestamp: '2026-04-05 11:38:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/yuki3178.test.cpp
documentation_of: Graph/csr.hpp
layout: document
title: Compressed Sparse Row (CSR)
---

## 概要

`std::vector<std::vector<T>>` を1次元でもって定数倍高速化するためのデータ構造。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`csr<T>(int N)`|宣言。 $N$ 頂点 のグラフを形成する。 | $\text{O} (N)$ | 
|`void add_edge(int u, T v)`| 頂点 $u$ から辺 $v$ を追加する。 | $\text{O} (1)$ | 
|`void build()`| 追加した辺をバケットソートして使える状態にする。 | $\text{O} (N + M)$ |
|`Node csr[v]`| 頂点 $v$ から張られている辺を返す。 | - | 
|`T csr[v][i]`| 頂点 $v$ から張られているi番目の辺を返す。 | $\text{O} (1)$ | 
|`int csr[v].size()`| 頂点 $v$ から張られている辺の数を返す。 | $\text{O} (1)$ | 
