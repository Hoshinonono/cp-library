---
title: 最小シュタイナー木
documentation_of: ./steiner_tree.hpp
---

## 概要
グラフにおいて、いくつかの頂点集合からなる $\text{terminal}$ を連結にするのに必要な最小コストを求める。
<br>

頂点数 $N$, 辺数 $M$, $\text{terminal}$ の個数を $K$ として計算量 $\text{O} (3^{K}N + 2^{K}(N + M) \log M)$
