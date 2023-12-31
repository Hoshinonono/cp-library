---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/dsu_02_max.hpp
    title: "\u7C21\u6613\u7248\u90E8\u5206\u6C38\u7D9A Union Find (\u6700\u5927\u8FBA\
      \u53D6\u5F97\u7528)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"Test/Library Checker/Data Structure/presistent_unionfind01.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\" \r\n\
    \r\n#include <bits/stdc++.h>\r\n#line 1 \"Graph/dsu_02_max.hpp\"\ntemplate <class\
    \ T> struct Kruskal_dsu {\r\n    public:\r\n    Kruskal_dsu() : _n(0) {}\r\n \
    \   Kruskal_dsu(int n) : _n(n), num_component(n), parent_or_size(n, -1), \r\n\
    \                         dat(n, std::numeric_limits<T>::max()) {}\r\n\r\n   \
    \ bool merge(int u, int v, T w) {\r\n        assert(0 <= u && u < _n);\r\n   \
    \     assert(0 <= v && v < _n);\r\n        int x = leader(u), y = leader(v);\r\
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
    \ parent_or_size;\r\n    std::vector<T> dat;\r\n};\r\n#line 5 \"Test/Library Checker/Data\
    \ Structure/presistent_unionfind01.test.cpp\"\nusing namespace std;\r\n\r\nint\
    \ main() {\r\n    cin.tie(0);\r\n    ios::sync_with_stdio(false);\r\n    int N,\
    \ Q;\r\n    cin >> N >> Q;\r\n    Kruskal_dsu<int> uf(N);\r\n    for(int i = 0;\
    \ i < Q; i++){\r\n        int t, k, u, v;\r\n        cin >> t >> k >> u >> v;\r\
    \n        if(t == 0){\r\n            uf.merge(u, v, i);\r\n        }else{\r\n\
    \            cout << (uf.max_edge(u, v) <= k) << '\\n';\r\n        }\r\n    }\r\
    \n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\
    \ \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Graph/dsu_02_max.hpp\"\r\nusing\
    \ namespace std;\r\n\r\nint main() {\r\n    cin.tie(0);\r\n    ios::sync_with_stdio(false);\r\
    \n    int N, Q;\r\n    cin >> N >> Q;\r\n    Kruskal_dsu<int> uf(N);\r\n    for(int\
    \ i = 0; i < Q; i++){\r\n        int t, k, u, v;\r\n        cin >> t >> k >> u\
    \ >> v;\r\n        if(t == 0){\r\n            uf.merge(u, v, i);\r\n        }else{\r\
    \n            cout << (uf.max_edge(u, v) <= k) << '\\n';\r\n        }\r\n    }\r\
    \n}\r\n"
  dependsOn:
  - Graph/dsu_02_max.hpp
  isVerificationFile: true
  path: Test/Library Checker/Data Structure/presistent_unionfind01.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 23:03:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Library Checker/Data Structure/presistent_unionfind01.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Data Structure/presistent_unionfind01.test.cpp
- /verify/Test/Library Checker/Data Structure/presistent_unionfind01.test.cpp.html
title: Test/Library Checker/Data Structure/presistent_unionfind01.test.cpp
---
