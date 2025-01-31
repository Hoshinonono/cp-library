---
title: Thomas algorithm
documentation_of: ./thomas.hpp
---

## 概要

[Tridiagonal_matrix_algorithm](https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm) を参考。<br>
三重対角行列についての解を $ \text{O}(N) $ で求める。

$ n $ 個の未知数を持つ三重対角方程式系は、次のように表すことができる。<br>

$$ a_{i}x_{i-1} + b_{i}x_{i} + c_{i}x_{i+1} = d_{i}, $$

$$
a_{1} = 0 \quad \text{and} \quad c_{n} = 0.
$$

として

$$
\begin{bmatrix}
b_1 & c_1 & 0 & & \\
a_2 & b_2 & c_2 & & \\
& a_3 & b_3 & \ddots & \\
& & \ddots & \ddots & c_{n-1} \\
0 & & & a_n & b_n
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2 \\
x_3 \\
\vdots \\
x_n
\end{bmatrix}
=
\begin{bmatrix}
d_1 \\
d_2 \\
d_3 \\
\vdots \\
d_n
\end{bmatrix}
$$

## 例題

[Codeforces Beta Round 24 D. Broken robot](https://codeforces.com/contest/24/problem/D)