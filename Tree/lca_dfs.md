---
title: 最小共通祖先 (LCA, Lowest Common Ancestor) (クエリO(1))
documentation_of: ./lca_dfs.hpp
---

## 概要
前計算 $\text{O}(N\log N)$、クエリ $\text{O} (1)$ で最小共通祖先を求める。<br>
SparseTableをベースに深さが最小の頂点を抽出している。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`LCA_tree(Graph g)`| コンストラクタに木を渡すと、LCAのテーブルが作られる。| $\text{O} (N \log N)$ | 
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(1)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(1)$ |
