---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
    title: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/segtree.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\r\n    public:\r\n    segtree() : segtree(0)\
    \ {}\r\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\r\n    segtree(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\r\n        log = ceil_pow2(_n);\r\n\
    \        size = 1 << log;\r\n        d = std::vector<S>(2 * size, e());\r\n  \
    \      for (int i = 0; i < _n; i++) d[size + i] = v[i];\r\n        for (int i\
    \ = size - 1; i >= 1; i--) {\r\n            update(i);\r\n        }\r\n    }\r\
    \n\r\n    void set(int p, S x) {\r\n        assert(0 <= p && p < _n);\r\n    \
    \    p += size;\r\n        d[p] = x;\r\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\r\n    }\r\n\r\n    S get(int p) {\r\n        assert(0 <= p\
    \ && p < _n);\r\n        return d[p + size];\r\n    }\r\n    const S operator[](int\
    \ p) const { return get(p); }\r\n    S operator[](int p) { return get(p); }\r\n\
    \r\n    S prod(int l, int r) {\r\n        assert(0 <= l && l <= r && r <= _n);\r\
    \n        S sml = e(), smr = e();\r\n        l += size;\r\n        r += size;\r\
    \n\r\n        while (l < r) {\r\n            if (l & 1) sml = op(sml, d[l++]);\r\
    \n            if (r & 1) smr = op(d[--r], smr);\r\n            l >>= 1;\r\n  \
    \          r >>= 1;\r\n        }\r\n        return op(sml, smr);\r\n    }\r\n\r\
    \n    S all_prod() { return d[1]; }\r\n\r\n    template <bool (*f)(S)> int max_right(int\
    \ l) {\r\n        return max_right(l, [](S x) { return f(x); });\r\n    }\r\n\
    \    template <class F> int max_right(int l, F f) {\r\n        assert(0 <= l &&\
    \ l <= _n);\r\n        assert(f(e()));\r\n        if (l == _n) return _n;\r\n\
    \        l += size;\r\n        S sm = e();\r\n        do {\r\n            while\
    \ (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm, d[l]))) {\r\n           \
    \     while (l < size) {\r\n                    l = (2 * l);\r\n             \
    \       if (f(op(sm, d[l]))) {\r\n                        sm = op(sm, d[l]);\r\
    \n                        l++;\r\n                    }\r\n                }\r\
    \n                return l - size;\r\n            }\r\n            sm = op(sm,\
    \ d[l]);\r\n            l++;\r\n        } while ((l & -l) != l);\r\n        return\
    \ _n;\r\n    }\r\n\r\n    template <bool (*f)(S)> int min_left(int r) {\r\n  \
    \      return min_left(r, [](S x) { return f(x); });\r\n    }\r\n    template\
    \ <class F> int min_left(int r, F f) {\r\n        assert(0 <= r && r <= _n);\r\
    \n        assert(f(e()));\r\n        if (r == 0) return 0;\r\n        r += size;\r\
    \n        S sm = e();\r\n        do {\r\n            r--;\r\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\r\n            if (!f(op(d[r], sm))) {\r\n     \
    \           while (r < size) {\r\n                    r = (2 * r + 1);\r\n   \
    \                 if (f(op(d[r], sm))) {\r\n                        sm = op(d[r],\
    \ sm);\r\n                        r--;\r\n                    }\r\n          \
    \      }\r\n                return r + 1 - size;\r\n            }\r\n        \
    \    sm = op(d[r], sm);\r\n        } while ((r & -r) != r);\r\n        return\
    \ 0;\r\n    }\r\n\r\n    private:\r\n    int _n, size, log;\r\n    std::vector<S>\
    \ d;\r\n    int ceil_pow2(int n) {\r\n        int x = 0;\r\n        while ((1U\
    \ << x) < (unsigned int)(n)) x++;\r\n        return x;\r\n    }\r\n    void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n};\r\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> struct segtree {\r\n    public:\r\
    \n    segtree() : segtree(0) {}\r\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\r\n    segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\n \
    \       log = ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2\
    \ * size, e());\r\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\r\n\
    \        for (int i = size - 1; i >= 1; i--) {\r\n            update(i);\r\n \
    \       }\r\n    }\r\n\r\n    void set(int p, S x) {\r\n        assert(0 <= p\
    \ && p < _n);\r\n        p += size;\r\n        d[p] = x;\r\n        for (int i\
    \ = 1; i <= log; i++) update(p >> i);\r\n    }\r\n\r\n    S get(int p) {\r\n \
    \       assert(0 <= p && p < _n);\r\n        return d[p + size];\r\n    }\r\n\
    \    const S operator[](int p) const { return get(p); }\r\n    S operator[](int\
    \ p) { return get(p); }\r\n\r\n    S prod(int l, int r) {\r\n        assert(0\
    \ <= l && l <= r && r <= _n);\r\n        S sml = e(), smr = e();\r\n        l\
    \ += size;\r\n        r += size;\r\n\r\n        while (l < r) {\r\n          \
    \  if (l & 1) sml = op(sml, d[l++]);\r\n            if (r & 1) smr = op(d[--r],\
    \ smr);\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n     \
    \   return op(sml, smr);\r\n    }\r\n\r\n    S all_prod() { return d[1]; }\r\n\
    \r\n    template <bool (*f)(S)> int max_right(int l) {\r\n        return max_right(l,\
    \ [](S x) { return f(x); });\r\n    }\r\n    template <class F> int max_right(int\
    \ l, F f) {\r\n        assert(0 <= l && l <= _n);\r\n        assert(f(e()));\r\
    \n        if (l == _n) return _n;\r\n        l += size;\r\n        S sm = e();\r\
    \n        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm,\
    \ d[l]))) {\r\n                while (l < size) {\r\n                    l = (2\
    \ * l);\r\n                    if (f(op(sm, d[l]))) {\r\n                    \
    \    sm = op(sm, d[l]);\r\n                        l++;\r\n                  \
    \  }\r\n                }\r\n                return l - size;\r\n            }\r\
    \n            sm = op(sm, d[l]);\r\n            l++;\r\n        } while ((l &\
    \ -l) != l);\r\n        return _n;\r\n    }\r\n\r\n    template <bool (*f)(S)>\
    \ int min_left(int r) {\r\n        return min_left(r, [](S x) { return f(x); });\r\
    \n    }\r\n    template <class F> int min_left(int r, F f) {\r\n        assert(0\
    \ <= r && r <= _n);\r\n        assert(f(e()));\r\n        if (r == 0) return 0;\r\
    \n        r += size;\r\n        S sm = e();\r\n        do {\r\n            r--;\r\
    \n            while (r > 1 && (r % 2)) r >>= 1;\r\n            if (!f(op(d[r],\
    \ sm))) {\r\n                while (r < size) {\r\n                    r = (2\
    \ * r + 1);\r\n                    if (f(op(d[r], sm))) {\r\n                \
    \        sm = op(d[r], sm);\r\n                        r--;\r\n              \
    \      }\r\n                }\r\n                return r + 1 - size;\r\n    \
    \        }\r\n            sm = op(d[r], sm);\r\n        } while ((r & -r) != r);\r\
    \n        return 0;\r\n    }\r\n\r\n    private:\r\n    int _n, size, log;\r\n\
    \    std::vector<S> d;\r\n    int ceil_pow2(int n) {\r\n        int x = 0;\r\n\
    \        while ((1U << x) < (unsigned int)(n)) x++;\r\n        return x;\r\n \
    \   }\r\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:41:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
documentation_of: DataStructure/segtree.hpp
layout: document
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要
Segment Tree は長さ $n$ の `S` 型の配列において、区間の1点変更、区間の要素の総積の習得を $\text{O}(\log n)$ で行えるデータ構造である．<br><br>
ほぼ AtCoder Library のパクリ。AtCoder Library に加えて`[id]` で値の収得ができるようにしてある。<br>


|関数名など|機能|計算量|
|---------|----|-----|
|(1) `segtree<S, op, e>(int N)` <br> (2) `segtree<S, op, e>(std::vector<S> v)` | 型 `S` /二項演算 `S op(S a, S b)` /単位元 `S e()` を定義する必要がある．<br> (1) 長さ $N$ の配列を作る．初期値は `e()` となる．<br> (2) 長さ `v.size()` の配列を作る．`v` の内容が初期値となる. | $\text{O}(N)$ |
| `void set(int p, S x)` | `a[p]` に `x` を代入する.   $0 \leq p < N$  | $\text{O}(\log N)$ |
|(1) `S get(int p)` <br> (2) `S a[p]` | `a[p]` を返す. $0 \leq p < N$  | $\text{O}(1)$ |
| `S prod(int l, int r)`| $\text{op}(a[l], \ldots, a[r - 1])$ をモノイドの性質を満たしていると仮定して計算する. $l = r$ のときは、 `e()` を返す. | $\text{O}(\log N)$ |
| `S all_prod()` | $\text{op}(a[l], \ldots, a[N - 1])$ を計算する.  $n = 0$ のときは `e()` を返す．| $\text{O}(1)$ |
|(1) `int max_right<f>(int l)` <br> (2) `int max_right<F>(int l, F f)` | (1) 関数 bool f(S x) を定義する必要がある．segtreeの上で二分探索をする．<br> (2) Sを引数にとりboolを返す関数オブジェクトを渡して使用する．<br> 以下の条件を両方満たす r を(いずれか一つ)返す。 <br>・r = l もしくは f(op(a[l], a[l + 1], ..., a[r - 1])) = true <br>・r = N もしくは f(op(a[l], a[l + 1], ..., a[r])) = false <br> 制約 <br>・fを同じ引数で呼んだ時、返り値は等しい(=副作用はない) <br>・f(e()) = true <br>・ $0 \leq l \leq N$ |$\text{O}(\log N)$|
|(1) `int min_left<f>(int r)` <br> (2) `int min_left<F>(int r, F f)` |(1) 関数 bool f(S x) を定義する必要がある．segtreeの上で二分探索をする．<br>(2) Sを引数にとりboolを返す関数オブジェクトを渡して使用する．<br> 以下の条件を両方満たす l を(いずれか一つ)返します。<br>・l = r もしくは f(op(a[l], a[l + 1], ..., a[r - 1])) = true<br>・l = 0 もしくは f(op(a[l - 1], a[l + 1], ..., a[r - 1])) = false<br>制約<br>・fを同じ引数で呼んだ時、返り値は等しい(=副作用はない)<br>・f(e()) = true<br>・ $0 \leq r \leq N$ | $\text{O}(\log N)$ |
