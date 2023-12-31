---
title: 強連結成分分解 (SCC, Strongly Connected Component)
documentation_of: ./scc.hpp
---

## 概要
強連結成分（SCC, Strongly Connected Component）に分解するためのライブラリである。(SCC=有向グラフにおいて、互いに行き来が可能な頂点の集合)

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`SCC(std::vector<std::vector<int>> g)`| 有向グラフをコンストラクタに渡して初期化する。渡した時点で強連結成分分解される。 | $\text{O} (N + M)$ | 
|`int [p]`|頂点 $p$ の属する強連結成分の `id` を返す。 $0 \leq p < N$  | $\text{O} (1)$ | 
|`std::vector<std::vector<int>> groups()`|	以下の条件を満たすような，「頂点のリスト」のリストを返す．<br>・全ての頂点がちょうど1つずつ，どれかのリストに含まれる．<br>・内側のリストと強連結成分が一対一に対応する．リスト内での頂点の順序は未定義である．<br>・リストはトポロジカルソートされている．異なる強連結成分の頂点 $u$ , $v$ について $u$ から $v$ に到達できる時, $u$ の属するリストは $v$ の属するリストよりも前にある．| $\text{O} (N)$ |
