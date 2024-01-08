---
title: 二重頂点連結成分分解 (BCC, Bi-Connected Components)
documentation_of: ./lowlink_bcc.hpp
---

## 概要
二重頂点連結成分分解を行うライブラリ。<br>
コンストラクタに無向グラフを渡すとlowlinkの収得, 関節点の列挙を行ってくれる。<br>
メンバ関数の`bcc()`を呼び出すと、二重頂点連結成分分解が開始される。<br>
<b>多重辺がある場合にも対応</b><br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`bcc_graph(std::vector<std::vector<int>>)`|宣言。 コンストラクタに無向グラフを渡す。 | $\text{O} (N+M)$ | 
|`std::vector<int> art_point`|メンバ変数。関節点が列挙される。順番は未定義| - | 
|`std::vector<std::vector<int>> bcc()`|二重頂点連結成分分解を行う。連結成分に属する頂点のリストのリストを返す。| $\text{O} (N+M)$ |
|`int [p]`|頂点 $p$ が属する連結成分の番号を返す。|$\text{O} (1)$|