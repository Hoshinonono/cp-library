---
title: LowLink関連 (関節点, 橋)
documentation_of: ./lowlink.hpp
---

## 概要
lowlinkの収得を行うライブラリ。<br>
コンストラクタに無向グラフを渡すと関節点、橋の列挙を行ってくれる。<br>
計算量は、頂点数 $N$ 、辺数 $M$ として記述。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`lowlink_graph(std::vector<std::vector<int>>)`|宣言。 コンストラクタに無向グラフを渡す。 | $\text{O} (N+M)$ | 
|`std::vector<int> art_point`|メンバ変数。関節点が列挙される。<br>順番は未定義。 | - | 
|`std::vector<std::pair<int,int>> bridge`|メンバ変数。橋であるような辺を $u < v$ として、pair型で列挙される。<br>順番は未定義| - | 
