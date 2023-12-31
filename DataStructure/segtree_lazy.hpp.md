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
  bundledCode: "#line 1 \"DataStructure/segtree_lazy.hpp\"\ntemplate <class S,\r\n\
    \            S (*op)(S, S),\r\n            S (*e)(),\r\n            class F,\r\
    \n            S (*mapping)(F, S),\r\n            F (*composition)(F, F),\r\n \
    \           F (*id)()>\r\nstruct lazy_segtree {\r\n    public:\r\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\r\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\r\n    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\
    \n        log = ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2\
    \ * size, e());\r\n        lz = std::vector<F>(size, id());\r\n        for (int\
    \ i = 0; i < _n; i++) d[size + i] = v[i];\r\n        for (int i = size - 1; i\
    \ >= 1; i--) {\r\n            update(i);\r\n        }\r\n    }\r\n    void set(int\
    \ p, S x) {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\n   \
    \     for (int i = log; i >= 1; i--) push(p >> i);\r\n        d[p] = x;\r\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\r\n    }\r\n    S get(int\
    \ p) {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\r\n        return d[p];\r\n    }\r\n\
    \    const S operator[](int p) const { return get(p); }\r\n    S operator[](int\
    \ p) { return get(p); }\r\n    S prod(int l, int r) {\r\n        assert(0 <= l\
    \ && l <= r && r <= _n);\r\n        if (l == r) return e();\r\n        l += size;\r\
    \n        r += size;\r\n        for (int i = log; i >= 1; i--) {\r\n         \
    \   if (((l >> i) << i) != l) push(l >> i);\r\n            if (((r >> i) << i)\
    \ != r) push(r >> i);\r\n        }\r\n        S sml = e(), smr = e();\r\n    \
    \    while (l < r) {\r\n            if (l & 1) sml = op(sml, d[l++]);\r\n    \
    \        if (r & 1) smr = op(d[--r], smr);\r\n            l >>= 1;\r\n       \
    \     r >>= 1;\r\n        }\r\n        return op(sml, smr);\r\n    }\r\n    S\
    \ all_prod() { return d[1]; }\r\n    void apply(int p, F f) {\r\n        assert(0\
    \ <= p && p < _n);\r\n        p += size;\r\n        for (int i = log; i >= 1;\
    \ i--) push(p >> i);\r\n        d[p] = mapping(f, d[p]);\r\n        for (int i\
    \ = 1; i <= log; i++) update(p >> i);\r\n    }\r\n    void apply(int l, int r,\
    \ F f) {\r\n        assert(0 <= l && l <= r && r <= _n);\r\n        if (l == r)\
    \ return;\r\n        l += size;\r\n        r += size;\r\n        for (int i =\
    \ log; i >= 1; i--) {\r\n            if (((l >> i) << i) != l) push(l >> i);\r\
    \n            if (((r >> i) << i) != r) push((r - 1) >> i);\r\n        }\r\n \
    \       {\r\n            int l2 = l, r2 = r;\r\n            while (l < r) {\r\n\
    \                if (l & 1) all_apply(l++, f);\r\n                if (r & 1) all_apply(--r,\
    \ f);\r\n                l >>= 1;\r\n                r >>= 1;\r\n            }\r\
    \n            l = l2;\r\n            r = r2;\r\n        }\r\n        for (int\
    \ i = 1; i <= log; i++) {\r\n            if (((l >> i) << i) != l) update(l >>\
    \ i);\r\n            if (((r >> i) << i) != r) update((r - 1) >> i);\r\n     \
    \   }\r\n    }\r\n    template <bool (*g)(S)> int max_right(int l) {\r\n     \
    \   return max_right(l, [](S x) { return g(x); });\r\n    }\r\n    template <class\
    \ G> int max_right(int l, G g) {\r\n        assert(0 <= l && l <= _n);\r\n   \
    \     assert(g(e()));\r\n        if (l == _n) return _n;\r\n        l += size;\r\
    \n        for (int i = log; i >= 1; i--) push(l >> i);\r\n        S sm = e();\r\
    \n        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!g(op(sm,\
    \ d[l]))) {\r\n                while (l < size) {\r\n                    push(l);\r\
    \n                    l = (2 * l);\r\n                    if (g(op(sm, d[l])))\
    \ {\r\n                        sm = op(sm, d[l]);\r\n                        l++;\r\
    \n                    }\r\n                }\r\n                return l - size;\r\
    \n            }\r\n            sm = op(sm, d[l]);\r\n            l++;\r\n    \
    \    } while ((l & -l) != l);\r\n        return _n;\r\n    }\r\n    template <bool\
    \ (*g)(S)> int min_left(int r) {\r\n        return min_left(r, [](S x) { return\
    \ g(x); });\r\n    }\r\n    template <class G> int min_left(int r, G g) {\r\n\
    \        assert(0 <= r && r <= _n);\r\n        assert(g(e()));\r\n        if (r\
    \ == 0) return 0;\r\n        r += size;\r\n        for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\r\n        S sm = e();\r\n        do {\r\n            r--;\r\
    \n            while (r > 1 && (r % 2)) r >>= 1;\r\n            if (!g(op(d[r],\
    \ sm))) {\r\n                while (r < size) {\r\n                    push(r);\r\
    \n                    r = (2 * r + 1);\r\n                    if (g(op(d[r], sm)))\
    \ {\r\n                        sm = op(d[r], sm);\r\n                        r--;\r\
    \n                    }\r\n                }\r\n                return r + 1 -\
    \ size;\r\n            }\r\n            sm = op(d[r], sm);\r\n        } while\
    \ ((r & -r) != r);\r\n        return 0;\r\n    }\r\n    private:\r\n    int _n,\
    \ size, log;\r\n    std::vector<S> d;\r\n    std::vector<F> lz;\r\n    void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n    void all_apply(int k, F f)\
    \ {\r\n        d[k] = mapping(f, d[k]);\r\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\r\n    }\r\n    void push(int k) {\r\n        all_apply(2 * k, lz[k]);\r\
    \n        all_apply(2 * k + 1, lz[k]);\r\n        lz[k] = id();\r\n    }\r\n \
    \   int ceil_pow2(int n) {\r\n        int x = 0;\r\n        while ((1U << x) <\
    \ (unsigned int)(n)) x++;\r\n        return x;\r\n    }\r\n};\r\n"
  code: "template <class S,\r\n            S (*op)(S, S),\r\n            S (*e)(),\r\
    \n            class F,\r\n            S (*mapping)(F, S),\r\n            F (*composition)(F,\
    \ F),\r\n            F (*id)()>\r\nstruct lazy_segtree {\r\n    public:\r\n  \
    \  lazy_segtree() : lazy_segtree(0) {}\r\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\r\n    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\
    \n        log = ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2\
    \ * size, e());\r\n        lz = std::vector<F>(size, id());\r\n        for (int\
    \ i = 0; i < _n; i++) d[size + i] = v[i];\r\n        for (int i = size - 1; i\
    \ >= 1; i--) {\r\n            update(i);\r\n        }\r\n    }\r\n    void set(int\
    \ p, S x) {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\n   \
    \     for (int i = log; i >= 1; i--) push(p >> i);\r\n        d[p] = x;\r\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\r\n    }\r\n    S get(int\
    \ p) {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\r\n        return d[p];\r\n    }\r\n\
    \    const S operator[](int p) const { return get(p); }\r\n    S operator[](int\
    \ p) { return get(p); }\r\n    S prod(int l, int r) {\r\n        assert(0 <= l\
    \ && l <= r && r <= _n);\r\n        if (l == r) return e();\r\n        l += size;\r\
    \n        r += size;\r\n        for (int i = log; i >= 1; i--) {\r\n         \
    \   if (((l >> i) << i) != l) push(l >> i);\r\n            if (((r >> i) << i)\
    \ != r) push(r >> i);\r\n        }\r\n        S sml = e(), smr = e();\r\n    \
    \    while (l < r) {\r\n            if (l & 1) sml = op(sml, d[l++]);\r\n    \
    \        if (r & 1) smr = op(d[--r], smr);\r\n            l >>= 1;\r\n       \
    \     r >>= 1;\r\n        }\r\n        return op(sml, smr);\r\n    }\r\n    S\
    \ all_prod() { return d[1]; }\r\n    void apply(int p, F f) {\r\n        assert(0\
    \ <= p && p < _n);\r\n        p += size;\r\n        for (int i = log; i >= 1;\
    \ i--) push(p >> i);\r\n        d[p] = mapping(f, d[p]);\r\n        for (int i\
    \ = 1; i <= log; i++) update(p >> i);\r\n    }\r\n    void apply(int l, int r,\
    \ F f) {\r\n        assert(0 <= l && l <= r && r <= _n);\r\n        if (l == r)\
    \ return;\r\n        l += size;\r\n        r += size;\r\n        for (int i =\
    \ log; i >= 1; i--) {\r\n            if (((l >> i) << i) != l) push(l >> i);\r\
    \n            if (((r >> i) << i) != r) push((r - 1) >> i);\r\n        }\r\n \
    \       {\r\n            int l2 = l, r2 = r;\r\n            while (l < r) {\r\n\
    \                if (l & 1) all_apply(l++, f);\r\n                if (r & 1) all_apply(--r,\
    \ f);\r\n                l >>= 1;\r\n                r >>= 1;\r\n            }\r\
    \n            l = l2;\r\n            r = r2;\r\n        }\r\n        for (int\
    \ i = 1; i <= log; i++) {\r\n            if (((l >> i) << i) != l) update(l >>\
    \ i);\r\n            if (((r >> i) << i) != r) update((r - 1) >> i);\r\n     \
    \   }\r\n    }\r\n    template <bool (*g)(S)> int max_right(int l) {\r\n     \
    \   return max_right(l, [](S x) { return g(x); });\r\n    }\r\n    template <class\
    \ G> int max_right(int l, G g) {\r\n        assert(0 <= l && l <= _n);\r\n   \
    \     assert(g(e()));\r\n        if (l == _n) return _n;\r\n        l += size;\r\
    \n        for (int i = log; i >= 1; i--) push(l >> i);\r\n        S sm = e();\r\
    \n        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!g(op(sm,\
    \ d[l]))) {\r\n                while (l < size) {\r\n                    push(l);\r\
    \n                    l = (2 * l);\r\n                    if (g(op(sm, d[l])))\
    \ {\r\n                        sm = op(sm, d[l]);\r\n                        l++;\r\
    \n                    }\r\n                }\r\n                return l - size;\r\
    \n            }\r\n            sm = op(sm, d[l]);\r\n            l++;\r\n    \
    \    } while ((l & -l) != l);\r\n        return _n;\r\n    }\r\n    template <bool\
    \ (*g)(S)> int min_left(int r) {\r\n        return min_left(r, [](S x) { return\
    \ g(x); });\r\n    }\r\n    template <class G> int min_left(int r, G g) {\r\n\
    \        assert(0 <= r && r <= _n);\r\n        assert(g(e()));\r\n        if (r\
    \ == 0) return 0;\r\n        r += size;\r\n        for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\r\n        S sm = e();\r\n        do {\r\n            r--;\r\
    \n            while (r > 1 && (r % 2)) r >>= 1;\r\n            if (!g(op(d[r],\
    \ sm))) {\r\n                while (r < size) {\r\n                    push(r);\r\
    \n                    r = (2 * r + 1);\r\n                    if (g(op(d[r], sm)))\
    \ {\r\n                        sm = op(d[r], sm);\r\n                        r--;\r\
    \n                    }\r\n                }\r\n                return r + 1 -\
    \ size;\r\n            }\r\n            sm = op(d[r], sm);\r\n        } while\
    \ ((r & -r) != r);\r\n        return 0;\r\n    }\r\n    private:\r\n    int _n,\
    \ size, log;\r\n    std::vector<S> d;\r\n    std::vector<F> lz;\r\n    void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n    void all_apply(int k, F f)\
    \ {\r\n        d[k] = mapping(f, d[k]);\r\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\r\n    }\r\n    void push(int k) {\r\n        all_apply(2 * k, lz[k]);\r\
    \n        all_apply(2 * k + 1, lz[k]);\r\n        lz[k] = id();\r\n    }\r\n \
    \   int ceil_pow2(int n) {\r\n        int x = 0;\r\n        while ((1U << x) <\
    \ (unsigned int)(n)) x++;\r\n        return x;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree_lazy.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/segtree_lazy.hpp
layout: document
title: "\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要
遅延評価セグメント木はモノイド $(S, \cdot: S \times S \to S, e \in S)$ と， $S$ から $S$ への写像の集合 $F$ であって，以下の条件を満たすようなものについて使用できるデータ構造である．
- $F$ は恒等写像 $\mathrm{id}$ を含む．つまり，任意の $x \in S$ に対し $\mathrm{id}(x) = x$ をみたす．
- $F$ は写像の合成について閉じている．つまり，任意の $f, g \in F$ に対し $f \circ g \in F$ である．
- 任意の $f \in F, x, y \in S$ に対し $f(x \cdot y) = f(x) \cdot f(y)$ をみたす．

長さ $N$ の $S$ の配列に対し、<br>

- 区間の要素に一括で $F$ の要素\(f\)を作用 ( $x = f(x)$ )
- 区間の要素の総積の取得

を $\text{O}(\log N)$ で行うことが出来る．<br>

また，このライブラリはオラクルとしてop, e, mapping, composition, idを使用するが、これらが定数時間で動くものと仮定したときの計算量を記述する．オラクル内部の計算量が $\text{O}(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる．<br>

テンプレート引数の例 (区間min演算・区間min更新)。適宜書き換えて使用する。
```
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(200000);

using S = int;
using F = int;
// 単位元
S e(){return 1 << 30;}
// 区間演算
S op(S lhs, S rhs){ return min(lhs, rhs); }
// x に f を作用させた時の変化
S mapping(F f, S x){return min(x, f);}
// bf を作用させた後に af を作用させる
F composition(F af, F bf){return min(af, bf);}
// 恒等写像
F id(){return 1 << 30;}
```

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `lazy_segtree<S, op, e, F, mapping, composition, id>(int N)` <br>(2) `lazy_segtree<S, op, e, F, mapping, composition, id>(std::vector<T> v)`|(1) 長さ $N$ の配列を作る。<br>(2) 長さ `v.size()` の配列を作る。`v` の内容が初期値になる。<br>・モノイドの型`S` <br>・ $\cdot: S \times S \to S$ を計算する関数 `S op(S a, S b)` <br>・ $e$ を返す関数 `S e()` <br>・写像の型 `F` <br>・ $f(x)$ を返す関数 `S mapping(F f, S x)` <br>・ $f \circ g$ を返す関数 `F composition(F f, F g)` <br>・ $id$ を返す関数 `F id()` <br> を定義する必要がある。| $\text{O}(N)$ |
|`void set(int p, S x)`| a[p] に x を代入する． $0 \leq p < N$ | $\text{O}(\log N)$ |
|(1) `S seg.get(int p)` <br>(2) `S a[p]`| a[p]を返す． $0 \leq p < N$ | $\text{O}(\log N)$ |
|`S prod(int l, int r)`| $\text{op}(a[l], \ldots, a[r - 1])$ をモノイドの性質を満たしていると仮定して計算する．l = r のときは e() を返す． $0 \leq l \leq r \leq N$ | $\text{O}(\log N)$ |
|`S seg.all_prod()`| $op(a[0], ..., a[n - 1])$ を計算する．n = 0 のときは e() を返す．| $\text{O}(1)$ |
|(1) `void seg.apply(int p, F x)` <br>(2) `void seg.apply(int l, int r, F x)` | (1) `a[p] = mapping(x, a[p])` を行う。<br>(2) $l \leq i < r$ について `a[i] = mapping(x, a[i])` を行う。| $O(\log N)$ |
|(1) `int max_right<f>(int l)` <br> (2) `int max_right<F>(int l, F f)` | (1) 関数 bool f(S x) を定義する必要がある．segtreeの上で二分探索をする．<br> (2) Sを引数にとりboolを返す関数オブジェクトを渡して使用する．<br> 以下の条件を両方満たす r を(いずれか一つ)返す。 <br>・r = l もしくは f(op(a[l], a[l + 1], ..., a[r - 1])) = true <br>・r = N もしくは f(op(a[l], a[l + 1], ..., a[r])) = false <br> 制約 <br>・fを同じ引数で呼んだ時、返り値は等しい(=副作用はない) <br>・f(e()) = true <br>・ $0 \leq l \leq N$ |$\text{O}(\log N)$|
|(1) `int min_left<f>(int r)` <br> (2) `int min_left<F>(int r, F f)` |(1) 関数 bool f(S x) を定義する必要がある．segtreeの上で二分探索をする．<br>(2) Sを引数にとりboolを返す関数オブジェクトを渡して使用する．<br> 以下の条件を両方満たす l を(いずれか一つ)返します。<br>・l = r もしくは f(op(a[l], a[l + 1], ..., a[r - 1])) = true<br>・l = 0 もしくは f(op(a[l - 1], a[l + 1], ..., a[r - 1])) = false<br>制約<br>・fを同じ引数で呼んだ時、返り値は等しい(=副作用はない)<br>・f(e()) = true<br>・ $0 \leq r \leq N$ | $\text{O}(\log N)$ |
