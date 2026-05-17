---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki8030.test.cpp
    title: Test/yukicoder/yuki8030.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/MillerRabin.hpp\"\n#include <utility>\n#include <vector>\n\
    \nstruct Miller_Rabin {\n    unsigned long long mul_mod(unsigned long long a,\
    \ unsigned long long b, unsigned long long m) {\n        unsigned long long ans\
    \ = 0;\n#ifndef __SIZEOF_INT128__\n            if(a < b) std::swap(a, b);\n  \
    \          while(b){\n                if(b & 1){\n                    ans += a;\n\
    \                    if(ans >= m) ans -= m;\n                }\n             \
    \   if((a <<= 1) >= m) a -= m;\n                b >>= 1;\n            }\n#else\n\
    \            ans = (unsigned long long)((__int128)(a) * (__int128)(b) % m); \n\
    #endif\n        return ans;\n    }\n    unsigned long long pow_mod(unsigned long\
    \ long x, unsigned long long n, unsigned long long m) {\n        if (m == 1) return\
    \ 0;\n        unsigned long long r = 1;\n        unsigned long long y = x % m;\n\
    \        while (n) {\n            if (n & 1) r = mul_mod(r, y, m);\n         \
    \   y = mul_mod(y, y, m);\n            n >>= 1;\n        }\n        return r;\n\
    \    }\n    bool is_prime(unsigned long long n) {\n        if (n <= 1) return\
    \ false;\n        if (n == 2) return true;\n        if (n % 2 == 0) return false;\n\
    \        unsigned long long d = n - 1;\n        while (d % 2 == 0) d /= 2;\n \
    \       static std::vector<std::vector<unsigned long long>> \n            bases\
    \ = {{2, 6, 61}, {2, 325, 9375, 28178, 450775, 9780504, 1795265022}};\n      \
    \  for (unsigned long long a : bases[d > 4759123141]) {\n            unsigned\
    \ long long t = d;\n            unsigned long long y = pow_mod(a, t, n);\n   \
    \         if(a % n){\n                while (t != n - 1 && y != 1 && y != n -\
    \ 1) {\n                    y = mul_mod(y, y, n);\n                    t <<= 1;\n\
    \                }\n            }\n            if (y != n - 1 && t % 2 == 0) return\
    \ false;\n        }\n        return true;\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\nstruct Miller_Rabin\
    \ {\n    unsigned long long mul_mod(unsigned long long a, unsigned long long b,\
    \ unsigned long long m) {\n        unsigned long long ans = 0;\n#ifndef __SIZEOF_INT128__\n\
    \            if(a < b) std::swap(a, b);\n            while(b){\n             \
    \   if(b & 1){\n                    ans += a;\n                    if(ans >= m)\
    \ ans -= m;\n                }\n                if((a <<= 1) >= m) a -= m;\n \
    \               b >>= 1;\n            }\n#else\n            ans = (unsigned long\
    \ long)((__int128)(a) * (__int128)(b) % m); \n#endif\n        return ans;\n  \
    \  }\n    unsigned long long pow_mod(unsigned long long x, unsigned long long\
    \ n, unsigned long long m) {\n        if (m == 1) return 0;\n        unsigned\
    \ long long r = 1;\n        unsigned long long y = x % m;\n        while (n) {\n\
    \            if (n & 1) r = mul_mod(r, y, m);\n            y = mul_mod(y, y, m);\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    bool is_prime(unsigned\
    \ long long n) {\n        if (n <= 1) return false;\n        if (n == 2) return\
    \ true;\n        if (n % 2 == 0) return false;\n        unsigned long long d =\
    \ n - 1;\n        while (d % 2 == 0) d /= 2;\n        static std::vector<std::vector<unsigned\
    \ long long>> \n            bases = {{2, 6, 61}, {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}};\n        for (unsigned long long a : bases[d > 4759123141])\
    \ {\n            unsigned long long t = d;\n            unsigned long long y =\
    \ pow_mod(a, t, n);\n            if(a % n){\n                while (t != n - 1\
    \ && y != 1 && y != n - 1) {\n                    y = mul_mod(y, y, n);\n    \
    \                t <<= 1;\n                }\n            }\n            if (y\
    \ != n - 1 && t % 2 == 0) return false;\n        }\n        return true;\n   \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/MillerRabin.hpp
  requiredBy: []
  timestamp: '2026-05-17 20:22:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/yuki8030.test.cpp
documentation_of: Math/MillerRabin.hpp
layout: document
title: "MillerRabin\u6CD5"
---

## 概要

$N \leq 10^{18}$ などの制約下で素数判定を行えるアルゴリズム。<br>
計算量は乗算にかかる計算量を $\sigma$、試行回数を $k$ として $\text{O}(\sigma k \log N)$ となる。