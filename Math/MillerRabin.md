---
title: MillerRabin法
documentation_of: ./MillerRabin.hpp
---

## 概要

$N \leq 10^{18}$ などの制約下で素数判定を行えるアルゴリズム。<br>
計算量は乗算にかかる計算量を $\sigma$、試行回数を $k$ として $\text{O}(\sigma k \log N)$ となる。