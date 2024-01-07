---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp
    title: Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/dsu_03_rollback.hpp\"\nstruct rollback_dsu {\r\n \
    \   public:\r\n    rollback_dsu() : _n(0) {}\r\n    rollback_dsu(int n) : _n(n),\
    \ num_component(n), parent_or_size(n, -1) {}\r\n\r\n    int merge(int a, int b)\
    \ {\r\n        assert(0 <= a && a < _n);\r\n        assert(0 <= b && b < _n);\r\
    \n        int x = leader(a), y = leader(b);\r\n        if (x == y) {\r\n     \
    \       history.emplace_back(-1, -1);\r\n            return x;\r\n        }\r\n\
    \        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\r\n   \
    \     history.emplace_back(y, parent_or_size[y]);\r\n        parent_or_size[x]\
    \ += parent_or_size[y];\r\n        parent_or_size[y] = x;\r\n        num_component--;\r\
    \n        return x;\r\n    }\r\n\r\n    bool same(int a, int b) {\r\n        assert(0\
    \ <= a && a < _n);\r\n        assert(0 <= b && b < _n);\r\n        return leader(a)\
    \ == leader(b);\r\n    }\r\n\r\n    int leader(int a) {\r\n        assert(0 <=\
    \ a && a < _n);\r\n        while(parent_or_size[a] >= 0) a = parent_or_size[a];\r\
    \n        return a;\r\n    }\r\n\r\n    int size() { \r\n        return num_component;\r\
    \n    }\r\n\r\n    int size(int a) {\r\n        assert(0 <= a && a < _n);\r\n\
    \        return -parent_or_size[leader(a)];\r\n    }\r\n\r\n    void undo(){\r\
    \n        if(history.empty()) return;\r\n        int v, sz, par;\r\n        std::tie(v,\
    \ sz) = history.back();\r\n        history.pop_back();\r\n        if(v == -1)\
    \ return;\r\n        par = parent_or_size[v];\r\n        parent_or_size[v] = sz;\r\
    \n        parent_or_size[par] -= sz;\r\n        num_component++;\r\n    }\r\n\r\
    \n    void rollback(int cnt = -1){\r\n        if(cnt == -1) cnt = history.size();\r\
    \n        while(cnt--) undo();\r\n    }\r\n\r\n    std::vector<std::vector<int>>\
    \ groups() {\r\n        std::vector<int> leader_buf(_n), group_size(_n);\r\n \
    \       for (int i = 0; i < _n; i++) {\r\n            leader_buf[i] = leader(i);\r\
    \n            group_size[leader_buf[i]]++;\r\n        }\r\n        std::vector<std::vector<int>>\
    \ result(_n);\r\n        for (int i = 0; i < _n; i++) {\r\n            result[i].reserve(group_size[i]);\r\
    \n        }\r\n        for (int i = 0; i < _n; i++) {\r\n            result[leader_buf[i]].push_back(i);\r\
    \n        }\r\n        result.erase(\r\n            std::remove_if(result.begin(),\
    \ result.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            result.end());\r\n        return result;\r\
    \n    }\r\n\r\n    private:\r\n    int _n, num_component;\r\n    std::vector<int>\
    \ parent_or_size;\r\n    std::vector<std::pair<int,int>> history;\r\n};\r\n"
  code: "struct rollback_dsu {\r\n    public:\r\n    rollback_dsu() : _n(0) {}\r\n\
    \    rollback_dsu(int n) : _n(n), num_component(n), parent_or_size(n, -1) {}\r\
    \n\r\n    int merge(int a, int b) {\r\n        assert(0 <= a && a < _n);\r\n \
    \       assert(0 <= b && b < _n);\r\n        int x = leader(a), y = leader(b);\r\
    \n        if (x == y) {\r\n            history.emplace_back(-1, -1);\r\n     \
    \       return x;\r\n        }\r\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\r\n        history.emplace_back(y, parent_or_size[y]);\r\n\
    \        parent_or_size[x] += parent_or_size[y];\r\n        parent_or_size[y]\
    \ = x;\r\n        num_component--;\r\n        return x;\r\n    }\r\n\r\n    bool\
    \ same(int a, int b) {\r\n        assert(0 <= a && a < _n);\r\n        assert(0\
    \ <= b && b < _n);\r\n        return leader(a) == leader(b);\r\n    }\r\n\r\n\
    \    int leader(int a) {\r\n        assert(0 <= a && a < _n);\r\n        while(parent_or_size[a]\
    \ >= 0) a = parent_or_size[a];\r\n        return a;\r\n    }\r\n\r\n    int size()\
    \ { \r\n        return num_component;\r\n    }\r\n\r\n    int size(int a) {\r\n\
    \        assert(0 <= a && a < _n);\r\n        return -parent_or_size[leader(a)];\r\
    \n    }\r\n\r\n    void undo(){\r\n        if(history.empty()) return;\r\n   \
    \     int v, sz, par;\r\n        std::tie(v, sz) = history.back();\r\n       \
    \ history.pop_back();\r\n        if(v == -1) return;\r\n        par = parent_or_size[v];\r\
    \n        parent_or_size[v] = sz;\r\n        parent_or_size[par] -= sz;\r\n  \
    \      num_component++;\r\n    }\r\n\r\n    void rollback(int cnt = -1){\r\n \
    \       if(cnt == -1) cnt = history.size();\r\n        while(cnt--) undo();\r\n\
    \    }\r\n\r\n    std::vector<std::vector<int>> groups() {\r\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\r\n        for (int i = 0; i < _n; i++) {\r\n\
    \            leader_buf[i] = leader(i);\r\n            group_size[leader_buf[i]]++;\r\
    \n        }\r\n        std::vector<std::vector<int>> result(_n);\r\n        for\
    \ (int i = 0; i < _n; i++) {\r\n            result[i].reserve(group_size[i]);\r\
    \n        }\r\n        for (int i = 0; i < _n; i++) {\r\n            result[leader_buf[i]].push_back(i);\r\
    \n        }\r\n        result.erase(\r\n            std::remove_if(result.begin(),\
    \ result.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            result.end());\r\n        return result;\r\
    \n    }\r\n\r\n    private:\r\n    int _n, num_component;\r\n    std::vector<int>\
    \ parent_or_size;\r\n    std::vector<std::pair<int,int>> history;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dsu_03_rollback.hpp
  requiredBy: []
  timestamp: '2024-01-07 20:45:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp
documentation_of: Graph/dsu_03_rollback.hpp
layout: document
title: "Rollback\u4ED8\u304DUnion Find"
---

## 概要
経路圧縮しない代わりにrollbackができるUnion Find。<br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`rollback_dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。 | $\text{O} (N)$ | 
|`int merge(int a, int b)`|頂点 $a$ と頂点 $b$ を辺で結ぶ。代表元の頂点番号を返す。 | $\text{O} (\log N)$ | 
|`bool same(int a, int b)`|頂点 $a$ と頂点 $b$ が連結であるかを返す。 | $\text{O} (\log N)$ | 
|`int leader(int a)`|頂点 $a$ の属する連結成分の代表元を返す。| $\text{O} (\log N)$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int a)`|頂点 $a$ の属する連結成分のサイズを返す。| $\text{O} (\log N)$ | 
|`void undo()`|直前の辺追加操作を巻き戻してなかったことにする。| $\text{O} (1)$ | 
|`void rollback(int cnt)`|${\rm cnt}$ 回だけ辺追加操作を呼び出してなかったことにする。<br>${\rm cnt} == -1$ を与えると初期化動作となる。| $\text{O} ({\rm cnt})$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N \log N)$ |
