---
title: 遅延評価セグメント木
documentation_of: ./segtree_lazy.hpp
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
