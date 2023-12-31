---
title: 双対セグメント木
documentation_of: ./segtree_dual.hpp
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
