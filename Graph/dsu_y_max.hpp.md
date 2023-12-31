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
  bundledCode: "#line 1 \"Graph/dsu_y_max.hpp\"\ntemplate <class T> struct Kruskal_dsu\
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
  path: Graph/dsu_y_max.hpp
  requiredBy: []
  timestamp: '2023-12-31 19:30:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dsu_y_max.hpp
layout: document
redirect_from:
- /library/Graph/dsu_y_max.hpp
- /library/Graph/dsu_y_max.hpp.html
title: Graph/dsu_y_max.hpp
---
