---
title: 2次元いもす法
documentation_of: ./CumulativeSum2D_imos.hpp
---

## 概要
平面加算・1点収得を行うための構造体。 
動作については <a href = "https://imoz.jp/algorithms/imos_method.html">いもす法 - いもす研</a> を参照。

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `imos2D<T>(int H, int W)`| `+` と `-` が定義されている構造体を載せることができる。<br> $H \times W$ の配列を初期値 $0$ で作成する。| $\text{O}(HW)$ |
|`void add(int ly, int lx, int ry, int rx, T v)`|・ $ly \leq y < ry$ <br>・ $lx \leq x < rx$ <br> を満たす領域に $\text{v}$ を加算する。| $\text{O}(1)$|
|`void build()`| 平面加算の結果を反映させ、1点収得ができるようにする。| $\text{O}(HW)$ |
|(1) `T a[y][x]` <br> (2) `std::vector<T> a[y]`|(1) `a[y][x]` へのアクセスを行う。 <br> (2) `a[y]` へのアクセスを行う。| $\text{O}(1)$ |
