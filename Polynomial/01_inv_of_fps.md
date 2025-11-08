---
title: FPSの逆元
documentation_of: ./01_inv_of_fps.hpp
---

## 概要

[多項式/形式的冪級数ライブラリ Nyaan's Library](https://nyaannyaan.github.io/library/fps/formal-power-series.hpp.html) を参考。

$f(x)$ が与えられたときに

$$
f(x)g(x) = 1\,(\bmod x^{N})
$$

となる $ g(x) $ を $\text{O}(N \log N)$ で求める。