---
title: 2次元累積和
documentation_of: ./CumulativeSum2D.hpp
---

## 概要
平面内にある値の総和を収得できるデータ構造。

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `CumulativeSum2D<T>(int H, int W)` <br> (2) `CumulativeSum2D(std::vector<std::vector<T>> A)`| `+` と `-` が定義されている構造体を載せることができる。<br> (1) $H \times W$ の配列を初期値 $0$ で作成する。 <br> (2) 2次元 vector に基づく値で 2次元累積和を構成する。| $\text{O}(HW)$ |
|`void add(int y, int x, T z)`| `a[y][x] += z` を行う.  $0 \leq y < H$, $0 \leq x < W$ | $\text{O}(1)$|
|`void build()`| 二次元累積和を構築する。コントラクタに2次元vectorを渡した場合は不要。| $\text{O}(HW)$ |
|`T query(int ly, int lx, int ry, int rx)`| ・ $ly \leq y < ry$ <br> ・ $lx \leq x < rx$ <br> を満たす `a[y][x]` の値の総和を収得する。| $\text{O}(1)$ |
