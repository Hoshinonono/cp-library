---
title: セグメント木
documentation_of: ./segtree.hpp
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
