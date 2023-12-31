---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Data Structure/staticrmq01.test.cpp
    title: Test/Library Checker/Data Structure/staticrmq01.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.hpp\"\ntemplate <class T, T (*op)(T,\
    \ T), T (*e)()> struct SparseTable {\r\n    const int n, LOGV;\r\n    std::vector<std::vector<T>>\
    \ table;\r\n    std::vector<int> log_table;\r\n    SparseTable(const std::vector<T>\
    \ &v) : n(v.size()), LOGV(std::__lg(std::max(n, 1)) + 1), \r\n               \
    \                            log_table(n + 1), table(LOGV, std::vector<T>(n))\
    \ {\r\n        std::copy(v.begin(), v.end(), table[0].begin());\r\n        for(int\
    \ i = 1; i < LOGV; i++) {\r\n            for(int j = 0; j + (1 << i) <= n; j++)\
    \ {\r\n                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 <<\
    \ (i - 1))]);\r\n            }\r\n        }\r\n        for(int i = 2; i <= n;\
    \ i++) {\r\n            log_table[i] = log_table[i >> 1] + 1;\r\n        }\r\n\
    \    }\r\n    T prod(int l, int r){\r\n        assert(0 <= l && l <= r && r <=\
    \ n);\r\n        if(l == r) return e();\r\n        int b = log_table[r - l];\r\
    \n        return op(table[b][l], table[b][r - (1 << b)]);\r\n    }\r\n};\r\n"
  code: "template <class T, T (*op)(T, T), T (*e)()> struct SparseTable {\r\n    const\
    \ int n, LOGV;\r\n    std::vector<std::vector<T>> table;\r\n    std::vector<int>\
    \ log_table;\r\n    SparseTable(const std::vector<T> &v) : n(v.size()), LOGV(std::__lg(std::max(n,\
    \ 1)) + 1), \r\n                                           log_table(n + 1), table(LOGV,\
    \ std::vector<T>(n)) {\r\n        std::copy(v.begin(), v.end(), table[0].begin());\r\
    \n        for(int i = 1; i < LOGV; i++) {\r\n            for(int j = 0; j + (1\
    \ << i) <= n; j++) {\r\n                table[i][j] = op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\r\n            }\r\n        }\r\n        for(int\
    \ i = 2; i <= n; i++) {\r\n            log_table[i] = log_table[i >> 1] + 1;\r\
    \n        }\r\n    }\r\n    T prod(int l, int r){\r\n        assert(0 <= l &&\
    \ l <= r && r <= n);\r\n        if(l == r) return e();\r\n        int b = log_table[r\
    \ - l];\r\n        return op(table[b][l], table[b][r - (1 << b)]);\r\n    }\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:41:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Data Structure/staticrmq01.test.cpp
documentation_of: DataStructure/SparseTable.hpp
layout: document
redirect_from:
- /library/DataStructure/SparseTable.hpp
- /library/DataStructure/SparseTable.hpp.html
title: DataStructure/SparseTable.hpp
---
