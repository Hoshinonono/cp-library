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
  bundledCode: "#line 1 \"Graph/dsu_01_weighted.hpp\"\nstruct Weighted_dsu {\n   \
    \ public:\n    Weighted_dsu() : _n(0) {}\n    Weighted_dsu(int n) : _n(n), num_component(n),\
    \ parent_or_size(n, -1), diff_weight(n) {}\n\n    bool merge(int a, int b, long\
    \ long w) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n\
    \        int x = leader(a), y = leader(b);\n        w += diff_weight[a] - diff_weight[b];\n\
    \        if(x == y) return w == 0;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y), w *= -1;\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        diff_weight[y] = w;\n        num_component--;\n\
    \        return true;\n    }\n\n    long long diff(int a, int b) {\n        assert(same(a,\
    \ b));\n        return diff_weight[b] - diff_weight[a];\n    }\n\n    bool same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return\
    \ a;\n        int r = leader(parent_or_size[a]);\n        diff_weight[a] += diff_weight[parent_or_size[a]];\n\
    \        return parent_or_size[a] = r;\n    }\n\n    int size() { \n        return\
    \ num_component;\n    }\n\n    int size(int a) {\n        assert(0 <= a && a <\
    \ _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \    private:\n        int _n, num_component;\n        std::vector<int> parent_or_size;\n\
    \        std::vector<long long> diff_weight;\n};\n"
  code: "struct Weighted_dsu {\n    public:\n    Weighted_dsu() : _n(0) {}\n    Weighted_dsu(int\
    \ n) : _n(n), num_component(n), parent_or_size(n, -1), diff_weight(n) {}\n\n \
    \   bool merge(int a, int b, long long w) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        w += diff_weight[a] - diff_weight[b];\n        if(x == y) return w ==\
    \ 0;\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y), w\
    \ *= -1;\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        diff_weight[y] = w;\n        num_component--;\n        return\
    \ true;\n    }\n\n    long long diff(int a, int b) {\n        assert(same(a, b));\n\
    \        return diff_weight[b] - diff_weight[a];\n    }\n\n    bool same(int a,\
    \ int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n\
    \        return leader(a) == leader(b);\n    }\n\n    int leader(int a) {\n  \
    \      assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n\
    \        int r = leader(parent_or_size[a]);\n        diff_weight[a] += diff_weight[parent_or_size[a]];\n\
    \        return parent_or_size[a] = r;\n    }\n\n    int size() { \n        return\
    \ num_component;\n    }\n\n    int size(int a) {\n        assert(0 <= a && a <\
    \ _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \    private:\n        int _n, num_component;\n        std::vector<int> parent_or_size;\n\
    \        std::vector<long long> diff_weight;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dsu_01_weighted.hpp
  requiredBy: []
  timestamp: '2023-12-31 19:42:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dsu_01_weighted.hpp
layout: document
title: "\u91CD\u307F\u4ED8\u304D Union Find (\u548C\u5DEE\u5206)"
---

## 概要

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`Weighted_dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。 | $\text{O} (N)$ | 
|`int merge(int a, int b, long long w)`| $d_b - d_a = w$ として頂点 $a$ と頂点 $b$ を辺で結ぶ。辺の追加に成功した場合 `true` 、矛盾が生じた場合 `false` が返る。 | $\text{O} (\alpha(N))$ | 
|`long long diff(int a, int b)`| 頂点 $a$ から頂点 $b$ への差分 $d_{b} - d_{a}$ を返す。<br> 頂点 $a$ と頂点 $b$ が連結でない場合、assertにかかる | $\text{O} (\alpha(N))$ |
|`bool same(int a, int b)`|頂点 $a$ と頂点 $b$ が連結であるかを返す。 | $\text{O} (\alpha(N))$ | 
|`int leader(int a)`|頂点 $a$ の属する連結成分の代表元を返す。| $\text{O} (\alpha(N))$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int a)`|頂点 $a$ の属する連結成分のサイズを返す．| $\text{O} (\alpha(N))$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N)$ |
