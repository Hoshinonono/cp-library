---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Polynomial/inv_of_fps.test.cpp
    title: Test/Library Checker/Polynomial/inv_of_fps.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Polynomial/01_inv_of_fps.hpp\"\ntemplate <typename mint>\
    \ std::vector<mint> inverse(std::vector<mint> &a){\n    const int n = a.size();\n\
    \    std::vector<mint> res;\n    res.reserve(a.size());\n    res.emplace_back(a[0].inv());\n\
    \    while(res.size() < a.size()){\n        const int m = 2 * res.size();\n  \
    \      std::vector<mint> buf(m), fres(m);\n        std::copy(a.begin(), a.begin()\
    \ + std::min(m, n + 1), buf.begin());\n        std::copy(res.begin(), res.end(),\
    \ fres.begin());\n        atcoder::internal::butterfly(buf);\n        atcoder::internal::butterfly(fres);\n\
    \        for (int i = 0; i < m; i++) buf[i] *= fres[i];\n        atcoder::internal::butterfly_inv(buf);\n\
    \        std::fill(buf.begin(), buf.begin() + res.size(), mint::raw(0));\n   \
    \     atcoder::internal::butterfly(buf);\n        for (int i = 0; i < m; i++)\
    \ buf[i] *= fres[i];\n        atcoder::internal::butterfly_inv(buf);\n       \
    \ mint coef = -mint(mint(1 - mint::mod()) / buf.size()).pow(2);\n        for (int\
    \ i = res.size(); i < std::min(m, n + 1); i++) res.emplace_back(buf[i] * coef);\n\
    \    }\n    return res;\n}\n"
  code: "template <typename mint> std::vector<mint> inverse(std::vector<mint> &a){\n\
    \    const int n = a.size();\n    std::vector<mint> res;\n    res.reserve(a.size());\n\
    \    res.emplace_back(a[0].inv());\n    while(res.size() < a.size()){\n      \
    \  const int m = 2 * res.size();\n        std::vector<mint> buf(m), fres(m);\n\
    \        std::copy(a.begin(), a.begin() + std::min(m, n + 1), buf.begin());\n\
    \        std::copy(res.begin(), res.end(), fres.begin());\n        atcoder::internal::butterfly(buf);\n\
    \        atcoder::internal::butterfly(fres);\n        for (int i = 0; i < m; i++)\
    \ buf[i] *= fres[i];\n        atcoder::internal::butterfly_inv(buf);\n       \
    \ std::fill(buf.begin(), buf.begin() + res.size(), mint::raw(0));\n        atcoder::internal::butterfly(buf);\n\
    \        for (int i = 0; i < m; i++) buf[i] *= fres[i];\n        atcoder::internal::butterfly_inv(buf);\n\
    \        mint coef = -mint(mint(1 - mint::mod()) / buf.size()).pow(2);\n     \
    \   for (int i = res.size(); i < std::min(m, n + 1); i++) res.emplace_back(buf[i]\
    \ * coef);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Polynomial/01_inv_of_fps.hpp
  requiredBy: []
  timestamp: '2025-11-08 19:26:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Polynomial/inv_of_fps.test.cpp
documentation_of: Polynomial/01_inv_of_fps.hpp
layout: document
title: "FPS\u306E\u9006\u5143"
---

## 概要

[多項式/形式的冪級数ライブラリ Nyaan's Library](https://nyaannyaan.github.io/library/fps/formal-power-series.hpp.html) を参考。

$f(x)$ が与えられたときに

$$
f(x)g(x) = 1\,(\bmod x^{N})
$$

となる $ g(x) $ を $\text{O}(N \log N)$ で求める。