---
title: 二重辺連結成分分解 (TECC, Two-Edge-Connected Components)
documentation_of: ./lowlink_tecc.hpp
---

## 概要
二重辺連結成分分解を行うライブラリ。<br>
コンストラクタに無向グラフを渡すとlowlinkの収得, 橋の列挙を行ってくれる。<br>
メンバ関数の`tecc()`を呼び出すと、二重辺連結成分分解が開始される。<br>
<b>多重辺がある場合にも対応</b><br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`tecc_graph(std::vector<std::vector<int>>)`|宣言。 コンストラクタに無向グラフを渡す。 | $\text{O} (N+M)$ | 
|`std::vector<std::pair<int,int>> bridge`|メンバ変数。橋であるような辺を $u < v$ として、pair型で列挙される。<br>順番は未定義| - | 
|`std::pair<std::vector<std::vector<int>>,`<br>`std::vector<std::vector<int>>> tecc()`|二重辺連結成分分解を行う。std::pairの返り値は次の通り。<br>・連結成分ごとにまとめたグラフ(木)。すなわち、橋だけで構成されるグラフ。<br>・連結成分に属する頂点のリストのリスト。| $\text{O} (N)$ |
|`int [p]`|頂点 $p$ が属する連結成分の番号を返す。|$\text{O} (1)$|
