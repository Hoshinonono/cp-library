---
title: HL分解 (HLD, Heavy-Light-Decomposition)
documentation_of: ./hld.hpp
---

## 概要
HL分解 (HLD, Heavy-Light-Decomposition) を行うためのライブラリ。<br>
それぞれの頂点に対して、 子の頂点のうち部分木の頂点数が最も大きい頂点を1つ選択して Heavy Edge で結ぶことで $\log N$ 個程度のパスに分解でき、パスの更新クエリに対して高速に処理できる。<br>
実装は <a href = "https://ei1333.github.io/luzhiled/snippets/tree/heavy-light-decomposition.html"> HL分解(Heavy-Light-Decomposition) | Luzhiled's memo </a> をかなり参考にした。<br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`Heavy_Light_Decomposition`<br>`(std::vector<std::vector<int>> g)`| コンストラクタに木を渡すと、HL分解される。| $\text{O} (N)$ | 
|(1) `int la(int v, int d)` <br>(2) `int la(int from, int to, int d)`|(1)頂点 $v$ から根に向かって距離 $d$ 進んだ頂点を返す。<br>(2)頂点 $\text{from}$ から頂点 $\text{to}$ に向かって距離 $d$ 進んだ頂点を返す。<br> 存在しない場合は `-1` を返す。| $\text{O}(\log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log N)$ |
|`int [v]`|頂点 $v$ が行きがけ順で何番目に訪問された頂点であるかを返す。配列などでここに対応する添え字の値を更新すると、頂点 $v$ に対する値を更新したことになる。|$\text{O}(1)$|
|`T query(int u, int v,`<br>`const T &identity,`<br>`const Q &qf, const F &f, bool edge = false)`| 頂点 $u$ - $v$ 間の頂点の値に対して演算を行う。第3引数以降は以下のようなものを渡す。<br>・ `T identity` ：演算に対応する単位元(ラムダ式ではないので注意)<br>・ `T qf(int l, int r)` ：列に対する区間収得クエリ。<br>・ `T f(T lhs, T rhs)` : 列と列の結合クエリ。<br>・ `edge` ：辺に対する演算であるか(省略可能)。省略した場合、頂点に対する演算であるとして計算する。| $O(\log N)$ |
|`T noncom_query(int u, int v,`<br>`const T &identity,`<br>`const Q1 &qf, const Q2 &rev_qf,`<br>`const F &f, bool edge)`|頂点 $u$ - $v$ 間の頂点の値に対して非可換な演算を行う。第3引数以降は以下のようなものを渡す。<br>・ `T identity` ：演算に対応する単位元(ラムダ式ではないので注意)<br>・ `T qf(int l, int r)` ：左辺が子、右辺が親とした区間収得クエリ。<br>・ `T rev_qf(int l, int r)` ：左辺が親、右辺が子とした区間収得クエリ。<br>・ `T f(T lhs, T rhs)` : 左辺が子、右辺が親としたときの列と列の結合クエリ。<br>・ `edge` ：辺に対する演算であるか(省略可能)。省略した場合、頂点に対する演算であるとして計算する。| $O(\log N)$ |
|`void update(int u, int v,`<br>`const Q &q, bool edge)`|頂点 $u$ - $v$ 間の頂点の値に対して更新演算を行う。第3引数以降は以下のようなものを渡す。<br>・ `Q q(int l, int r)` ：区間 $[l, r)$ に対する更新演算。遅延セグ木の seg.apply(l, r) などを入れることを想定。<br>・ `edge` ：辺に対する演算であるか(省略可能)。省略した場合、頂点に対する演算であるとして計算する。| $O(\log N)$ |
