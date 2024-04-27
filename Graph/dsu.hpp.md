---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/ALDS1/ALDS1_11_D.test.cpp
    title: Test/Aizu Online Judge/ALDS1/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/DSL/DSL_1_A.test.cpp
    title: Test/Aizu Online Judge/DSL/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Data Structure/unionfind.test.cpp
    title: Test/Library Checker/Data Structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki2696.test.cpp
    title: Test/yukicoder/yuki2696.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/dsu.hpp\"\nstruct dsu {\n    public:\n    dsu() :\
    \ _n(0) {}\n    dsu(int n) : _n(n), num_component(n), parent_or_size(n, -1) {}\n\
    \n    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        num_component--;\n        return x;\n    }\n\n    bool same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return\
    \ a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n    }\n\n\
    \    int size() { \n        return num_component;\n    }\n\n    int size(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \    private:\n    int _n, num_component;\n    // root node: -1 * component size\n\
    \    // otherwise: parent\n    std::vector<int> parent_or_size;\n};\n"
  code: "struct dsu {\n    public:\n    dsu() : _n(0) {}\n    dsu(int n) : _n(n),\
    \ num_component(n), parent_or_size(n, -1) {}\n\n    int merge(int a, int b) {\n\
    \        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n      \
    \  int x = leader(a), y = leader(b);\n        if (x == y) return x;\n        if\
    \ (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        num_component--;\n\
    \        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a) ==\
    \ leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n\
    \        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n\n    int size() { \n        return num_component;\n\
    \    }\n\n    int size(int a) {\n        assert(0 <= a && a < _n);\n        return\
    \ -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \    private:\n    int _n, num_component;\n    // root node: -1 * component size\n\
    \    // otherwise: parent\n    std::vector<int> parent_or_size;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dsu.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:42:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/ALDS1/ALDS1_11_D.test.cpp
  - Test/Aizu Online Judge/DSL/DSL_1_A.test.cpp
  - Test/Library Checker/Data Structure/unionfind.test.cpp
  - Test/yukicoder/yuki2696.test.cpp
documentation_of: Graph/dsu.hpp
layout: document
title: Union Find
---

## 概要
ほぼ AtCoder Library のパクリ。AtCoder Library に加えて連結成分数の取得ができるようにしてある。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。 | $\text{O} (N)$ | 
|`int merge(int a, int b)`|頂点 $a$ と頂点 $b$ を辺で結ぶ。代表元の頂点番号を返す。 | $\text{O} (\alpha(N))$ | 
|`bool same(int a, int b)`|頂点 $a$ と頂点 $b$ が連結であるかを返す。 | $\text{O} (\alpha(N))$ | 
|`int leader(int a)`|頂点 $a$ の属する連結成分の代表元を返す。| $\text{O} (\alpha(N))$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int a)`|頂点 $a$ の属する連結成分のサイズを返す．| $\text{O} (\alpha(N))$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N)$ |
