---
title: フェニック木 (BIT, Binary Indexed Tree)
documentation_of: ./fenwick_tree.hpp
---

## 概要
Fenwick Tree は区間の要素の総和を $\text{O}(\log N)$ で求めることができるデータ構造である．<br>
実装は AtCoder Library のパクリ。

|関数名など|機能|計算量|
|---------|----|-----|
|`fenwick_tree<T>(int N)`| 宣言.  $N$ 個の要素をもつ配列を作る．初期値は0．<br> `T` は `+` と `-` が定義されている構造体を載せることができる。| $\text{O}(N)$ |
|`void add(int p, T x)`| $a[p] += x$ を行う.  $0 \leq p < N$ | $\text{O}(\log N)$|
|`T sum(int l, int r)`| $a[l] + a[l - 1] + \cdots + a[r - 1]$  を返す。 $0 \leq l \leq r < N$ | $\text{O}(\log N)$ |
