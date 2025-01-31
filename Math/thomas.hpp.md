---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/thomas.hpp\"\ntemplate<class T> vector<T> thomas(const\
    \ vector<T> &a, const vector<T> &b, \r\n                                   const\
    \ vector<T> &c, const vector<T> &d){\r\n    const int n = b.size();\r\n    vector<T>\
    \ scratch(n), x(n);\r\n    scratch[0] = c[0] / b[0];\r\n    x[0] = d[0] / b[0];\r\
    \n    for (int i = 1; i < n; i++) {\r\n        const T div = b[i] - a[i] * scratch[i\
    \ - 1];\r\n        if (i + 1 < n) scratch[i] = c[i] / div;\r\n        x[i] = (d[i]\
    \ - a[i] * x[i - 1]) / div;\r\n    }\r\n\r\n    for (int i = n - 2; i >= 0; i--)\r\
    \n        x[i] -= scratch[i] * x[i + 1];\r\n    \r\n    return x;\r\n}\n"
  code: "template<class T> vector<T> thomas(const vector<T> &a, const vector<T> &b,\
    \ \r\n                                   const vector<T> &c, const vector<T> &d){\r\
    \n    const int n = b.size();\r\n    vector<T> scratch(n), x(n);\r\n    scratch[0]\
    \ = c[0] / b[0];\r\n    x[0] = d[0] / b[0];\r\n    for (int i = 1; i < n; i++)\
    \ {\r\n        const T div = b[i] - a[i] * scratch[i - 1];\r\n        if (i +\
    \ 1 < n) scratch[i] = c[i] / div;\r\n        x[i] = (d[i] - a[i] * x[i - 1]) /\
    \ div;\r\n    }\r\n\r\n    for (int i = n - 2; i >= 0; i--)\r\n        x[i] -=\
    \ scratch[i] * x[i + 1];\r\n    \r\n    return x;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/thomas.hpp
  requiredBy: []
  timestamp: '2025-02-01 01:02:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/thomas.hpp
layout: document
title: Thomas algorithm
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