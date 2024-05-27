---
title: Link Cut Tree
documentation_of: ./LinkCutTree.hpp
---

## 概要
辺の追加、辺の削除を動的に行いながら木のパスクエリに $\text{O}(\log^{2} N)$ 程度で回答できるデータ構造。<br>

|関数名など|機能|計算量|
|---------|----|-----|
| `LinkCutTree<S, op, e>(int N)` <br>| $N$ 頂点0辺の森を作成する。<br>型 `S` /二項演算 `S op(S a, S b)` /単位元 `S e()` を定義する必要がある．| $\text{O}(N)$ |
|`int expose(int v)`|頂点 $v$ と根のパスを繋げる。| $\text{O}(\log^{2} N)$ |
|`void evert(int v)`|頂点 $v$ を木の根とする。| $\text{O}(\log^{2} N)$ |
|`void link(int u, int v)`|頂点 $u$ と頂点 $v$ を辺で結ぶ。| $\text{O}(\log^{2} N)$ |
|`void cut(int u, int v)`|頂点 $u$ と頂点 $v$ の間の辺を削除する。| $\text{O}(\log^{2} N)$ |
|`bool same(int u, int v)`|頂点 $u$ と頂点 $v$ が連結であるかを判定する。| $\text{O}(\log^{2} N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを求める。| $\text{O}(\log^{2} N)$ |
|`S query(int u, int v)`|頂点 $u$ から頂点 $v$ へ向かう際のパスクエリを求める。| $\text{O}(\log^{2} N)$ |
|`void set(int v, S x)`|頂点 $v$ に値 $x$ をセットする。| $\text{O}(\log^{2} N)$ |