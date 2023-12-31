---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki2277.test.cpp
    title: Test/yukicoder/yuki2277.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/dsu_01_xor.hpp\"\ntemplate <class T> struct xor_dsu\
    \ {\r\n    public:\r\n    xor_dsu() : _n(0) {}\r\n    xor_dsu(int n) : _n(n),\
    \ num_component(n), parent_or_size(n, -1), diff_weight(n) {}\r\n\r\n    bool merge(int\
    \ a, int b, T w) {\r\n        assert(0 <= a && a < _n);\r\n        assert(0 <=\
    \ b && b < _n);\r\n        int x = leader(a), y = leader(b);\r\n        w ^= diff_weight[a]\
    \ ^ diff_weight[b];\r\n        if(x == y) return w == 0;\r\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\r\n        parent_or_size[x] += parent_or_size[y];\r\
    \n        parent_or_size[y] = x;\r\n        diff_weight[y] = w;\r\n        num_component--;\r\
    \n        return true;\r\n    }\r\n    T diff(int a, int b) {\r\n        if(!same(a,\
    \ b)) return -1;\r\n        return diff_weight[a] ^ diff_weight[b];\r\n    }\r\
    \n    bool same(int a, int b) {\r\n        assert(0 <= a && a < _n);\r\n     \
    \   assert(0 <= b && b < _n);\r\n        return leader(a) == leader(b);\r\n  \
    \  }\r\n    int leader(int a) {\r\n        assert(0 <= a && a < _n);\r\n     \
    \   if (parent_or_size[a] < 0) return a;\r\n        int r = leader(parent_or_size[a]);\r\
    \n        diff_weight[a] ^= diff_weight[parent_or_size[a]];\r\n        return\
    \ parent_or_size[a] = r;\r\n    }\r\n    int size() {\r\n        return num_component;\r\
    \n    }\r\n    int size(int a) {\r\n        assert(0 <= a && a < _n);\r\n    \
    \    return -parent_or_size[leader(a)];\r\n    }\r\n    std::vector<std::vector<int>>\
    \ groups() {\r\n        std::vector<int> leader_buf(_n), group_size(_n);\r\n \
    \       for (int i = 0; i < _n; i++) {\r\n            leader_buf[i] = leader(i);\r\
    \n            group_size[leader_buf[i]]++;\r\n        }\r\n        std::vector<std::vector<int>>\
    \ result(_n);\r\n        for (int i = 0; i < _n; i++) {\r\n            result[i].reserve(group_size[i]);\r\
    \n        }\r\n        for (int i = 0; i < _n; i++) {\r\n            result[leader_buf[i]].push_back(i);\r\
    \n        }\r\n        result.erase(\r\n            std::remove_if(result.begin(),\
    \ result.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            result.end());\r\n        return result;\r\
    \n    }\r\n    private:\r\n        int _n, num_component;\r\n        std::vector<int>\
    \ parent_or_size;\r\n        std::vector<T> diff_weight;\r\n};\r\n"
  code: "template <class T> struct xor_dsu {\r\n    public:\r\n    xor_dsu() : _n(0)\
    \ {}\r\n    xor_dsu(int n) : _n(n), num_component(n), parent_or_size(n, -1), diff_weight(n)\
    \ {}\r\n\r\n    bool merge(int a, int b, T w) {\r\n        assert(0 <= a && a\
    \ < _n);\r\n        assert(0 <= b && b < _n);\r\n        int x = leader(a), y\
    \ = leader(b);\r\n        w ^= diff_weight[a] ^ diff_weight[b];\r\n        if(x\
    \ == y) return w == 0;\r\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\r\n        parent_or_size[x] += parent_or_size[y];\r\n    \
    \    parent_or_size[y] = x;\r\n        diff_weight[y] = w;\r\n        num_component--;\r\
    \n        return true;\r\n    }\r\n    T diff(int a, int b) {\r\n        if(!same(a,\
    \ b)) return -1;\r\n        return diff_weight[a] ^ diff_weight[b];\r\n    }\r\
    \n    bool same(int a, int b) {\r\n        assert(0 <= a && a < _n);\r\n     \
    \   assert(0 <= b && b < _n);\r\n        return leader(a) == leader(b);\r\n  \
    \  }\r\n    int leader(int a) {\r\n        assert(0 <= a && a < _n);\r\n     \
    \   if (parent_or_size[a] < 0) return a;\r\n        int r = leader(parent_or_size[a]);\r\
    \n        diff_weight[a] ^= diff_weight[parent_or_size[a]];\r\n        return\
    \ parent_or_size[a] = r;\r\n    }\r\n    int size() {\r\n        return num_component;\r\
    \n    }\r\n    int size(int a) {\r\n        assert(0 <= a && a < _n);\r\n    \
    \    return -parent_or_size[leader(a)];\r\n    }\r\n    std::vector<std::vector<int>>\
    \ groups() {\r\n        std::vector<int> leader_buf(_n), group_size(_n);\r\n \
    \       for (int i = 0; i < _n; i++) {\r\n            leader_buf[i] = leader(i);\r\
    \n            group_size[leader_buf[i]]++;\r\n        }\r\n        std::vector<std::vector<int>>\
    \ result(_n);\r\n        for (int i = 0; i < _n; i++) {\r\n            result[i].reserve(group_size[i]);\r\
    \n        }\r\n        for (int i = 0; i < _n; i++) {\r\n            result[leader_buf[i]].push_back(i);\r\
    \n        }\r\n        result.erase(\r\n            std::remove_if(result.begin(),\
    \ result.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            result.end());\r\n        return result;\r\
    \n    }\r\n    private:\r\n        int _n, num_component;\r\n        std::vector<int>\
    \ parent_or_size;\r\n        std::vector<T> diff_weight;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dsu_01_xor.hpp
  requiredBy: []
  timestamp: '2023-12-31 19:45:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/yuki2277.test.cpp
documentation_of: Graph/dsu_01_xor.hpp
layout: document
title: "\u91CD\u307F\u4ED8\u304D Union Find (XOR\u5DEE\u5206)"
---

## 概要
XOR演算を行える型 `T` を定義する必要がある。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`xor_dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。 | $\text{O} (N)$ | 
|`int merge(int a, int b, T w)`| $d_{b} \oplus d_{a} = w$ として頂点 $a$ と頂点 $b$ を辺で結ぶ。辺の追加に成功した場合 `true` 、矛盾が生じた場合 `false` が返る。 | $\text{O} (\alpha(N))$ | 
|`T diff(int a, int b)`| 頂点 $a$ から頂点 $b$ への差分 $d_{b} \oplus d_{a}$ を返す。<br> 頂点 $a$ と頂点 $b$ が連結でない場合、`-1`を返す。 | $\text{O} (\alpha(N))$ |
|`bool same(int a, int b)`|頂点 $a$ と頂点 $b$ が連結であるかを返す。 | $\text{O} (\alpha(N))$ | 
|`int leader(int a)`|頂点 $a$ の属する連結成分の代表元を返す。| $\text{O} (\alpha(N))$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int a)`|頂点 $a$ の属する連結成分のサイズを返す．| $\text{O} (\alpha(N))$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N)$ |
