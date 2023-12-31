---
title: 簡易版部分永続 Union Find (最小辺取得用)
documentation_of: ./dsu_02_min.hpp
---

## 概要
部分永続 Union Find の簡易版。<br>
辺の追加順が降順である必要がある。<br>
頂点 $u$ と頂点 $v$ が連結になったときの辺の値 (最小)を返すことができる。<br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`Kruskal_dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。<br>辺の型 `T` を渡す。 | $\text{O} (N)$ | 
|`bool merge(int u, int v, T w)`|頂点 $u$ と頂点 $v$ を辺の大きさ $w$ で結ぶ。辺の追加に成功したら`true`、既に連結である場合は`false`が返される。<br>辺は降順に追加する必要がある。 | $\text{O} (\log N)$ | 
|`bool same(int u, int v)`|頂点 $u$ と頂点 $v$ が連結であるかを返す。 | $\text{O} (\log N)$ | 
|`int leader(int v)`|頂点 $v$ の属する連結成分の代表元を返す。| $\text{O} (\log N)$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int v)`|頂点 $v$ の属する連結成分のサイズを返す．| $\text{O} (\log N)$ | 
|`T min_edge(int u, int v)`|最小全域木上の頂点 $u$ から頂点 $v$ までの単純パスのうち最小辺を返す。<br>・同一頂点の場合は`std::numeric_limits<T>::max()`を返す。<br>・非連結の場合は`-1`を返す。| $\text{O} (\log N)$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N \log N)$ |
