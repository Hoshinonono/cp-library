---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/yukicoder/yuki0114.test.cpp
    title: Test/yukicoder/yuki0114.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/steiner_tree.hpp\"\ntemplate <class T> std::vector<T>\
    \ steiner_tree(std::vector<std::vector<std::pair<int, T>>> &G, \r\n\t\t\t\t\t\t\
    \t\tstd::vector<int> &terminal){\r\n    const int N = G.size(), t = terminal.size();\r\
    \n\tif(t == 0) {\r\n\t\tstd::vector<T> ans(N);\r\n\t\treturn ans;\r\n\t}\r\n\t\
    std::vector<std::vector<T>> dp(1 << t, std::vector<T>(N, std::numeric_limits<T>::max()\
    \ / 2));\r\n\tfor(int i = 0; i < t; i++){\r\n\t\tassert(0 <= terminal[i] && terminal[i]\
    \ < N);\r\n\t\tdp[1 << i][terminal[i]] = 0;\r\n\t}\r\n\tstd::priority_queue<std::pair<T,\
    \ int>, \r\n\t\tstd::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>>\
    \ pq;\r\n\tfor(int S = 1; S < (1 << t); S++){\r\n\t\tfor(int v = 0; v < N; v++){\r\
    \n\t\t\tfor(int U = S & (S - 1); U > 0; U = (U - 1) & S){\r\n\t\t\t\tdp[S][v]\
    \ = std::min(dp[S][v], dp[U][v] + dp[U ^ S][v]);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int\
    \ v = 0; v < N; v++) pq.emplace(dp[S][v], v);\r\n\t\twhile(!pq.empty()){\r\n\t\
    \t\tauto [d, v] = pq.top();\r\n\t\t\tpq.pop();\r\n\t\t\tif(d > dp[S][v])continue;\r\
    \n\t\t\tfor(auto &&[u, w] : G[v]){\r\n\t\t\t\tif(d + w >= dp[S][u]) continue;\r\
    \n\t\t\t\tdp[S][u] = d + w;\r\n\t\t\t\tpq.emplace(dp[S][u], u);\r\n\t\t\t}\r\n\
    \t\t}\r\n\t}\r\n\treturn dp.back();\r\n}\n"
  code: "template <class T> std::vector<T> steiner_tree(std::vector<std::vector<std::pair<int,\
    \ T>>> &G, \r\n\t\t\t\t\t\t\t\tstd::vector<int> &terminal){\r\n    const int N\
    \ = G.size(), t = terminal.size();\r\n\tif(t == 0) {\r\n\t\tstd::vector<T> ans(N);\r\
    \n\t\treturn ans;\r\n\t}\r\n\tstd::vector<std::vector<T>> dp(1 << t, std::vector<T>(N,\
    \ std::numeric_limits<T>::max() / 2));\r\n\tfor(int i = 0; i < t; i++){\r\n\t\t\
    assert(0 <= terminal[i] && terminal[i] < N);\r\n\t\tdp[1 << i][terminal[i]] =\
    \ 0;\r\n\t}\r\n\tstd::priority_queue<std::pair<T, int>, \r\n\t\tstd::vector<std::pair<T,\
    \ int>>, std::greater<std::pair<T, int>>> pq;\r\n\tfor(int S = 1; S < (1 << t);\
    \ S++){\r\n\t\tfor(int v = 0; v < N; v++){\r\n\t\t\tfor(int U = S & (S - 1); U\
    \ > 0; U = (U - 1) & S){\r\n\t\t\t\tdp[S][v] = std::min(dp[S][v], dp[U][v] + dp[U\
    \ ^ S][v]);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int v = 0; v < N; v++) pq.emplace(dp[S][v],\
    \ v);\r\n\t\twhile(!pq.empty()){\r\n\t\t\tauto [d, v] = pq.top();\r\n\t\t\tpq.pop();\r\
    \n\t\t\tif(d > dp[S][v])continue;\r\n\t\t\tfor(auto &&[u, w] : G[v]){\r\n\t\t\t\
    \tif(d + w >= dp[S][u]) continue;\r\n\t\t\t\tdp[S][u] = d + w;\r\n\t\t\t\tpq.emplace(dp[S][u],\
    \ u);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn dp.back();\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/steiner_tree.hpp
  requiredBy: []
  timestamp: '2024-08-03 19:16:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/yukicoder/yuki0114.test.cpp
documentation_of: Graph/steiner_tree.hpp
layout: document
title: "\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728"
---

## 概要
グラフにおいて、いくつかの頂点集合からなる $\text{terminal}$ を連結にするのに必要な最小コストを求める。
<br>

頂点数 $N$, 辺数 $M$, $\text{terminal}$ の個数を $K$ として計算量 $\text{O} (3^{K}N + 2^{K}(N + M) \log M)$
