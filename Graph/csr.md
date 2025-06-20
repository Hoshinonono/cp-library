---
title: Compressed Sparse Row (CSR)
documentation_of: ./csr.hpp
---

## 概要

`std::vector<std::vector<T>>` を1次元でもって定数倍高速化するためのデータ構造。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`csr<T>(int N)`|宣言。 $N$ 頂点 のグラフを形成する。 | $\text{O} (N)$ | 
|`void add_edge(int u, T v)`| 頂点 $u$ から辺 $v$ を追加する。 | $\text{O} (1)$ | 
|`void build()`| 追加した辺をバケットソートして使える状態にする。 | $\text{O} (N + M)$ |
|`Node csr[v]`| 頂点 $v$ から張られている辺を返す。 | - | 
|`T csr[v][i]`| 頂点 $v$ から張られているi番目の辺を返す。 | $\text{O} (1)$ | 
|`int csr[v].size()`| 頂点 $v$ から張られている辺の数を返す。 | $\text{O} (1)$ | 
