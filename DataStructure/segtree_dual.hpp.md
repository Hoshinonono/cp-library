---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
    title: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
    title: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/segtree_dual.hpp\"\ntemplate <class S, S (*mapping)(S,\
    \ S), S (*id)()> struct dual_segtree {\r\n    public:\r\n    dual_segtree() :\
    \ dual_segtree(0) {}\r\n    dual_segtree(int n) : dual_segtree(std::vector<S>(n,\
    \ id())) {}\r\n    dual_segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\
    \n        log = ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2\
    \ * size, id());\r\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\r\
    \n    }\r\n    const S& operator[](int p) const {\r\n        assert(0 <= p &&\
    \ p < _n);\r\n        p += size;\r\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\r\n        return d[p];\r\n    }\r\n    S& operator[](int p) { \r\n \
    \       assert(0 <= p && p < _n);\r\n        p += size;\r\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\r\n        return d[p];\r\n    }\r\n    void\
    \ apply(int p, S f) {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\
    \n        for (int i = log; i >= 1; i--) push(p >> i);\r\n        d[p] = mapping(f,\
    \ d[p]);\r\n    }\r\n    void apply(int l, int r, S f) {\r\n        assert(0 <=\
    \ l && l <= r && r <= _n);\r\n        if (l == r) return;\r\n        l += size;\r\
    \n        r += size;\r\n        for (int i = log; i >= 1; i--) {\r\n         \
    \   if (((l >> i) << i) != l) push(l >> i);\r\n            if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\r\n        }\r\n        while (l < r) {\r\n      \
    \      if (l & 1) all_apply(l++, f);\r\n            if (r & 1) all_apply(--r,\
    \ f);\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n    }\r\n\
    \    private:\r\n    int _n, size, log;\r\n    std::vector<S> d;\r\n    void all_apply(int\
    \ k, S f) {\r\n        d[k] = mapping(f, d[k]);\r\n    }\r\n    void push(int\
    \ k) {\r\n        all_apply(2 * k, d[k]);\r\n        all_apply(2 * k + 1, d[k]);\r\
    \n        d[k] = id();\r\n    }\r\n    int ceil_pow2(int n) {\r\n        int x\
    \ = 0;\r\n        while ((1U << x) < (unsigned int)(n)) x++;\r\n        return\
    \ x;\r\n    }\r\n};\r\n"
  code: "template <class S, S (*mapping)(S, S), S (*id)()> struct dual_segtree {\r\
    \n    public:\r\n    dual_segtree() : dual_segtree(0) {}\r\n    dual_segtree(int\
    \ n) : dual_segtree(std::vector<S>(n, id())) {}\r\n    dual_segtree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\r\n        log = ceil_pow2(_n);\r\n        size = 1\
    \ << log;\r\n        d = std::vector<S>(2 * size, id());\r\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\r\n    }\r\n    const S& operator[](int\
    \ p) const {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\n  \
    \      for (int i = log; i >= 1; i--) push(p >> i);\r\n        return d[p];\r\n\
    \    }\r\n    S& operator[](int p) { \r\n        assert(0 <= p && p < _n);\r\n\
    \        p += size;\r\n        for (int i = log; i >= 1; i--) push(p >> i);\r\n\
    \        return d[p];\r\n    }\r\n    void apply(int p, S f) {\r\n        assert(0\
    \ <= p && p < _n);\r\n        p += size;\r\n        for (int i = log; i >= 1;\
    \ i--) push(p >> i);\r\n        d[p] = mapping(f, d[p]);\r\n    }\r\n    void\
    \ apply(int l, int r, S f) {\r\n        assert(0 <= l && l <= r && r <= _n);\r\
    \n        if (l == r) return;\r\n        l += size;\r\n        r += size;\r\n\
    \        for (int i = log; i >= 1; i--) {\r\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\r\n            if (((r >> i) << i) != r) push((r - 1) >> i);\r\
    \n        }\r\n        while (l < r) {\r\n            if (l & 1) all_apply(l++,\
    \ f);\r\n            if (r & 1) all_apply(--r, f);\r\n            l >>= 1;\r\n\
    \            r >>= 1;\r\n        }\r\n    }\r\n    private:\r\n    int _n, size,\
    \ log;\r\n    std::vector<S> d;\r\n    void all_apply(int k, S f) {\r\n      \
    \  d[k] = mapping(f, d[k]);\r\n    }\r\n    void push(int k) {\r\n        all_apply(2\
    \ * k, d[k]);\r\n        all_apply(2 * k + 1, d[k]);\r\n        d[k] = id();\r\
    \n    }\r\n    int ceil_pow2(int n) {\r\n        int x = 0;\r\n        while ((1U\
    \ << x) < (unsigned int)(n)) x++;\r\n        return x;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree_dual.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:41:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
  - Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
documentation_of: DataStructure/segtree_dual.hpp
layout: document
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要
双対セグメント木は区間更新、1点収得を $\text{O}(\log N)$ で求めることができるデータ構造である．<br>
遅延評価セグメント木と比較すると区間収得のための更新を行わないため、定数倍が良い。<br>
実装は AtCoder Library の遅延セグ木から遅延評価のための配列 `lazy` だけを残したようなものになっている。<br><br>
宣言を簡易的にするために、`mapping` と `composition` 、モノイドの型 `S` と写像の型 `F` を同じものとなるように設計しているため、異なるものが欲しい場合は遅延セグ木を使う。<br><br>
以下の3つを宣言する必要がある。
- `S` : 写像の型 
- `S mapping(S after, S before)` : `before` に `after` を作用させる関数。(合成写像と兼用) 
- `S id()` : 恒等写像。 `mapping(id(), f) = mapping(f, id()) = f` が満たされるようにする

<br>
テンプレート引数の例 (区間加算・1点収得)。適宜書き換えて使用する。

```
// dual_segtree<S, mapping, id> seg(size); のように宣言

using S = int;
// bf に af を作用させた時の変化
S mapping(S af, S bf){ return bf + af; }
// 恒等写像
S id(){ return 0; }
```

<br>

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `dual_segtree<S, mapping, id>(int N)` <br> (2) `dual_segtree<S, mapping, id>(std::vector<S> vec)` | (1) $N$ 個の要素を持つ配列を作る。初期値は `id()` <br> (2) 双対セグ木の要素を `vec` で初期化する。| $\text{O}(N)$ |
|`S a[p]`|`a[p]` を収得する。  | $\text{O}(\log N)$|
|(1)`void apply(int p, S f)` <br> (2)`void apply(int l, int r, S f)`|(1) `a[p] = mapping(f, a[p])` を行う。<br>(2) $l \leq i < r$ について`a[i] = mapping(f, a[i])` を行う。 | $\text{O}(\log N)$ |
