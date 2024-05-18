---
title: LiChaoTree (最小値取得)
documentation_of: ./LiChapTree_min.hpp
---

## 概要
LiChaoTree は $ax + b$ の直線または線分を使いし、決まった1点での最小値、最大値を取得できるデータ構造。

|関数名など|機能|計算量|
|---------|----|-----|
|`LiChaoTree(long long L, long long R)`| LiChaoTree の定義域を $[Lx, Rx)$ とする。| $\text{O}(1)$ |
|`void add_line(long long a, long long b)`| $ax + b$ の直線を追加する。| $\text{O}(\log N)$|
|`void add_segment_line(long long a, `<br>`long long b, long long l, long long r)`| $[Lx, Rx)$ の範囲に$ax + b$ の直線を追加する。 | $\text{O}(\log^{2} N)$ |
|`void get(x)`| $x$ での最小値を取得する。| $\text{O}(\log N)$|