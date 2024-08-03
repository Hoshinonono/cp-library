---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
    title: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
    title: Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/vertex_add_path_sum01.test.cpp
    title: Test/Library Checker/Tree/vertex_add_path_sum01.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/fenwick_tree.hpp\"\ntemplate <class T> struct\
    \ fenwick_tree {\r\n    using U = T;\r\n\r\n    public:\r\n    fenwick_tree()\
    \ : _n(0) {}\r\n    fenwick_tree(int n) : _n(n), data(n) {}\r\n\r\n    void add(int\
    \ p, T x) {\r\n        assert(0 <= p && p < _n);\r\n        p++;\r\n        while\
    \ (p <= _n) {\r\n            data[p - 1] += U(x);\r\n            p += p & -p;\r\
    \n        }\r\n    }\r\n\r\n    T sum(int l, int r) {\r\n        assert(0 <= l\
    \ && l <= r && r <= _n);\r\n        return sum(r) - sum(l);\r\n    }\r\n\r\n \
    \   private:\r\n    int _n;\r\n    std::vector<U> data;\r\n\r\n    U sum(int r)\
    \ {\r\n        U s = 0;\r\n        while (r > 0) {\r\n            s += data[r\
    \ - 1];\r\n            r -= r & -r;\r\n        }\r\n        return s;\r\n    }\r\
    \n};\r\n"
  code: "template <class T> struct fenwick_tree {\r\n    using U = T;\r\n\r\n    public:\r\
    \n    fenwick_tree() : _n(0) {}\r\n    fenwick_tree(int n) : _n(n), data(n) {}\r\
    \n\r\n    void add(int p, T x) {\r\n        assert(0 <= p && p < _n);\r\n    \
    \    p++;\r\n        while (p <= _n) {\r\n            data[p - 1] += U(x);\r\n\
    \            p += p & -p;\r\n        }\r\n    }\r\n\r\n    T sum(int l, int r)\
    \ {\r\n        assert(0 <= l && l <= r && r <= _n);\r\n        return sum(r) -\
    \ sum(l);\r\n    }\r\n\r\n    private:\r\n    int _n;\r\n    std::vector<U> data;\r\
    \n\r\n    U sum(int r) {\r\n        U s = 0;\r\n        while (r > 0) {\r\n  \
    \          s += data[r - 1];\r\n            r -= r & -r;\r\n        }\r\n    \
    \    return s;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:41:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
  - Test/Library Checker/Tree/vertex_add_path_sum01.test.cpp
  - Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
documentation_of: DataStructure/fenwick_tree.hpp
layout: document
title: "\u30D5\u30A7\u30CB\u30C3\u30AF\u6728 (BIT, Binary Indexed Tree)"
---

## 概要
Fenwick Tree は区間の要素の総和を $\text{O}(\log N)$ で求めることができるデータ構造である．<br>
実装は AtCoder Library のパクリ。

|関数名など|機能|計算量|
|---------|----|-----|
|`fenwick_tree<T>(int N)`| 宣言.  $N$ 個の要素をもつ配列を作る．初期値は0．<br> `T` は `+` と `-` が定義されている構造体を載せることができる。| $\text{O}(N)$ |
|`void add(int p, T x)`| $a[p] += x$ を行う.  $0 \leq p < N$ | $\text{O}(\log N)$|
|`T sum(int l, int r)`| $a[l] + a[l - 1] + \cdots + a[r - 1]$  を返す。 $0 \leq l \leq r < N$ | $\text{O}(\log N)$ |
