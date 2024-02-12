---
title: 最小共通祖先 (LCA, Lowest Common Ancestor) (ダブリング+UF)
documentation_of: ./lca_ufdoubling.hpp
---

## 概要
構築 $\text{O}(N\log \log N)$ 、クエリ $\text{O}(\log \log N)$ で最小共通祖先 (Lowest Common Ancestor) を習得できるライブラリである。<br>
実装はDFSの行きがけ順と帰りがけ順のみを使用していて場合分けをやや簡潔にしている。<br>

|関数名など|機能|計算量|
|---------|----|-----|
|`LCA_tree(std::vector<std::vector<int>> G, int root)`|`root` を根とする LCA のダブリングテーブルを構築する。<br>・第1引数には無向辺の木もしくは根付き木を G としてコンストラクタに渡す。<br>・第2引数は省略可能。省略した場合 `0` を根とする。| $\text{O}(N\log \log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log \log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log \log N)$ |
|`bool on_path(int from, int to, int mid)`|頂点 $\text{mid}$ が頂点 $\text{from}$ と頂点 $\text{to}$ の単純パス上にあるかを判定する。| $\text{O}(\log \log N)$ |
|`int Auxiliary_Tree(std::vector<int> ver)`|頂点集合 $\text{ver}$ を連結にするために必要な辺の数を出力する。|頂点集合の大きさを $\|S\|$ として<br> $\text{O}(\|S\| \(\log \|S\| + \log \log N\))$|
