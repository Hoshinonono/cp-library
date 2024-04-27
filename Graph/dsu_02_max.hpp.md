---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki2642.test.cpp
    title: Test/yukicoder/yuki2642.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/dsu_02_max.hpp\"\ntemplate <class T> struct Kruskal_dsu\
    \ {\r\n    public:\r\n    Kruskal_dsu() : _n(0) {}\r\n    Kruskal_dsu(int n) :\
    \ _n(n), num_component(n), parent_or_size(n, -1), \r\n                       \
    \  dat(n, std::numeric_limits<T>::max()) {}\r\n\r\n    bool merge(int u, int v,\
    \ T w) {\r\n        assert(0 <= u && u < _n);\r\n        assert(0 <= v && v <\
    \ _n);\r\n        int x = leader(u), y = leader(v);\r\n        if (x == y) return\
    \ false;\r\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\r\n        parent_or_size[x] += parent_or_size[y];\r\n        parent_or_size[y]\
    \ = x;\r\n        dat[y] = w;\r\n        num_component--;\r\n        return true;\r\
    \n    }\r\n\r\n    bool same(int u, int v) {\r\n        assert(0 <= u && u < _n);\r\
    \n        assert(0 <= v && v < _n);\r\n        return leader(v) == leader(u);\r\
    \n    }\r\n\r\n    int leader(int v) {\r\n        assert(0 <= v && v < _n);\r\n\
    \        while(parent_or_size[v] >= 0) v = parent_or_size[v];\r\n        return\
    \ v;\r\n    }\r\n\r\n    int size() {\r\n        return num_component;\r\n   \
    \ }\r\n\r\n    int size(int v) {\r\n        assert(0 <= v && v < _n);\r\n    \
    \    return -parent_or_size[leader(v)];\r\n    }\r\n\r\n    T max_edge(int u,\
    \ int v){\r\n        T ans = 0;\r\n        while(u != v){\r\n            if (dat[u]\
    \ > dat[v]) std::swap(u, v);\r\n            ans = dat[u], u = parent_or_size[u];\r\
    \n            if(u < 0) return -1;\r\n        }\r\n        return ans;\r\n   \
    \ }\r\n\r\n    private:\r\n    int _n, num_component;\r\n    // root node: -1\
    \ * component size\r\n    // otherwise: parent\r\n    std::vector<int> parent_or_size;\r\
    \n    std::vector<T> dat;\r\n};\r\n"
  code: "template <class T> struct Kruskal_dsu {\r\n    public:\r\n    Kruskal_dsu()\
    \ : _n(0) {}\r\n    Kruskal_dsu(int n) : _n(n), num_component(n), parent_or_size(n,\
    \ -1), \r\n                         dat(n, std::numeric_limits<T>::max()) {}\r\
    \n\r\n    bool merge(int u, int v, T w) {\r\n        assert(0 <= u && u < _n);\r\
    \n        assert(0 <= v && v < _n);\r\n        int x = leader(u), y = leader(v);\r\
    \n        if (x == y) return false;\r\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\r\n        parent_or_size[x] += parent_or_size[y];\r\n    \
    \    parent_or_size[y] = x;\r\n        dat[y] = w;\r\n        num_component--;\r\
    \n        return true;\r\n    }\r\n\r\n    bool same(int u, int v) {\r\n     \
    \   assert(0 <= u && u < _n);\r\n        assert(0 <= v && v < _n);\r\n       \
    \ return leader(v) == leader(u);\r\n    }\r\n\r\n    int leader(int v) {\r\n \
    \       assert(0 <= v && v < _n);\r\n        while(parent_or_size[v] >= 0) v =\
    \ parent_or_size[v];\r\n        return v;\r\n    }\r\n\r\n    int size() {\r\n\
    \        return num_component;\r\n    }\r\n\r\n    int size(int v) {\r\n     \
    \   assert(0 <= v && v < _n);\r\n        return -parent_or_size[leader(v)];\r\n\
    \    }\r\n\r\n    T max_edge(int u, int v){\r\n        T ans = 0;\r\n        while(u\
    \ != v){\r\n            if (dat[u] > dat[v]) std::swap(u, v);\r\n            ans\
    \ = dat[u], u = parent_or_size[u];\r\n            if(u < 0) return -1;\r\n   \
    \     }\r\n        return ans;\r\n    }\r\n\r\n    private:\r\n    int _n, num_component;\r\
    \n    // root node: -1 * component size\r\n    // otherwise: parent\r\n    std::vector<int>\
    \ parent_or_size;\r\n    std::vector<T> dat;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dsu_02_max.hpp
  requiredBy: []
  timestamp: '2023-12-31 19:46:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/yuki2642.test.cpp
documentation_of: Graph/dsu_02_max.hpp
layout: document
title: "\u7C21\u6613\u7248\u90E8\u5206\u6C38\u7D9A Union Find (\u6700\u5927\u8FBA\u53D6\
  \u5F97\u7528)"
---

## 概要
部分永続 Union Find の簡易版。<br>
辺の追加順が昇順である必要がある。<br>
頂点 $u$ と頂点 $v$ が連結になったときの辺の値を返すことができる。<br>
ここらへんの問題殴る用のライブラリ。
<ul>
    <li>AtCoder：<a href="https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h">
CODE THANKS FESTIVAL 2017「H - Union Sets」</a></li>
    <li>AtCoder：<a href="https://atcoder.jp/contests/past202004-open/tasks/past202004_o">
第二回 アルゴリズム実技検定 過去問「O - 可変全域木」</a></li>
    <li>Codeforces：<a href="https://codeforces.com/contest/1706/problem/E">Codeforces Round #809 (Div. 2)「E. Qpwoeirut and Vertices」</a></li>
</ul>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`Kruskal_dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。<br>辺の型 `T` を渡す。 | $\text{O} (N)$ | 
|`bool merge(int a, int b, T w)`|頂点 $a$ と頂点 $b$ を辺の大きさ $w$ で結ぶ。辺の追加に成功したら`true`、既に連結である場合は`false`が返される。<br>辺は昇順に追加する必要がある。 | $\text{O} (\log N)$ | 
|`bool same(int a, int b)`|頂点 $a$ と頂点 $b$ が連結であるかを返す。 | $\text{O} (\log N)$ | 
|`int leader(int a)`|頂点 $a$ の属する連結成分の代表元を返す。| $\text{O} (\log N)$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int a)`|頂点 $a$ の属する連結成分のサイズを返す．| $\text{O} (\log N)$ | 
|`T max_edge(int u, int v)`|最小全域木上の頂点 $u$ から頂点 $v$ までの単純パスのうち最大辺を返す。<br>・同一頂点の場合は`0`を返す。<br>・非連結の場合は`-1`を返す。| $\text{O} (\log N)$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N)$ |
