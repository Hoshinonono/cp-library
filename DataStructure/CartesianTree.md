---
title: CartesianTree
documentation_of: ./CartesianTree.hpp
---

## 概要
[https://en.wikipedia.org/wiki/Cartesian_tree](Wikipedia)<br>
根は数列全体の最小値または最大値に対応していて、そこから昇順または降順に二分木を構成したデータ構造。

|関数名など|機能|計算量|
|---------|----|-----|
|`CartesianTree(std::vector<int> a, bool max)`| CartesianTreeを構成。| $\text{O}(N)$ |
|`Node []`| 頂点を $v$ とする。<br>-`tree[v].l`:左の子の頂点番号<br>-`tree[v].r`:右の子の頂点番号<br>にアクセスできる。子がいない場合は`-1`が返る。| $\text{O}(1)$ |

