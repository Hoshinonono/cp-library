---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/ALDS1_14_C.test.cpp
    title: Test/Aizu Online Judge/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/modint_61bit.hpp\"\ntemplate<const long long MOD =\
    \ 2305843009213693951, \r\n        const long long MASK31 = (1ll << 31) - 1, const\
    \ long long MASK30 = (1ll << 30) - 1>\r\nstruct modint61 {\r\n    using mint =\
    \ modint61;\r\n    long long v;\r\n    modint61() : v(0) {}\r\n    template<class\
    \ T> modint61(T x) { \r\n        while(x < 0) x += MOD;\r\n        while(x >=\
    \ MOD) x -= MOD;\r\n        v = x;\r\n    }\r\n    long long safe_mod(long long\
    \ x){\r\n        x = (x >> 61) + (x & MOD);\r\n        if (x >= MOD) x -= MOD;\r\
    \n        return x;\r\n    }\r\n    static constexpr long long mod() { return\
    \ MOD; }\r\n    mint& operator++() {v++; if(v == MOD)v = 0; return *this;}\r\n\
    \    mint& operator--() {if(v == 0)v = MOD; v--; return *this;}\r\n    mint operator++(int)\
    \ { mint result = *this; ++*this; return result; }\r\n    mint operator--(int)\
    \ { mint result = *this; --*this; return result; }\r\n    mint& operator+=(const\
    \ mint& rhs) { v += rhs.v; if(v >= MOD) v -= MOD; return *this; }\r\n    mint&\
    \ operator-=(const mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this;\
    \ }\r\n    mint& operator*=(const mint& rhs) {\r\n        long long u = v >> 31,\
    \ d = v & MASK31;\r\n        long long ru = rhs.v >> 31, rd = rhs.v & MASK31;\r\
    \n        long long mid = d * ru + u * rd;\r\n        v = safe_mod(u * ru * 2\
    \ + (mid >> 30) + ((mid & MASK30) << 31) + d * rd);\r\n        return *this;\r\
    \n    }\r\n    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv();\
    \ }\r\n    mint operator+() const { return *this; }\r\n    mint operator-() const\
    \ { return mint() - *this; }\r\n    mint pow(long long n) const {\r\n        assert(0\
    \ <= n);\r\n        mint r = 1, x = *this;\r\n        while (n) {\r\n        \
    \    if (n & 1) r *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n   \
    \     }\r\n        return r;\r\n    }\r\n    mint inv() const { assert(v); return\
    \ pow(MOD - 2); }\r\n    friend mint operator+(const mint& lhs, const mint& rhs)\
    \ { return mint(lhs) += rhs; }\r\n    friend mint operator-(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) -= rhs; }\r\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) *= rhs; }\r\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\r\n    friend bool\
    \ operator<(const mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }\r\n  \
    \  friend bool operator==(const mint& lhs, const mint& rhs) { return (lhs.v ==\
    \ rhs.v); }\r\n    friend bool operator!=(const mint& lhs, const mint& rhs) {\
    \ return (lhs.v != rhs.v); }\r\n    friend std::istream& operator >> (std::istream&\
    \ is, mint& rhs) noexcept {\r\n        long long tmp;\r\n        rhs = mint{(is\
    \ >> tmp, tmp)};\r\n        return is;\r\n    }\r\n    friend std::ostream& operator\
    \ << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v; }\r\n\
    };\r\nusing mint61 = modint61<2305843009213693951>;\r\n"
  code: "template<const long long MOD = 2305843009213693951, \r\n        const long\
    \ long MASK31 = (1ll << 31) - 1, const long long MASK30 = (1ll << 30) - 1>\r\n\
    struct modint61 {\r\n    using mint = modint61;\r\n    long long v;\r\n    modint61()\
    \ : v(0) {}\r\n    template<class T> modint61(T x) { \r\n        while(x < 0)\
    \ x += MOD;\r\n        while(x >= MOD) x -= MOD;\r\n        v = x;\r\n    }\r\n\
    \    long long safe_mod(long long x){\r\n        x = (x >> 61) + (x & MOD);\r\n\
    \        if (x >= MOD) x -= MOD;\r\n        return x;\r\n    }\r\n    static constexpr\
    \ long long mod() { return MOD; }\r\n    mint& operator++() {v++; if(v == MOD)v\
    \ = 0; return *this;}\r\n    mint& operator--() {if(v == 0)v = MOD; v--; return\
    \ *this;}\r\n    mint operator++(int) { mint result = *this; ++*this; return result;\
    \ }\r\n    mint operator--(int) { mint result = *this; --*this; return result;\
    \ }\r\n    mint& operator+=(const mint& rhs) { v += rhs.v; if(v >= MOD) v -= MOD;\
    \ return *this; }\r\n    mint& operator-=(const mint& rhs) { if(v < rhs.v) v +=\
    \ MOD; v -= rhs.v; return *this; }\r\n    mint& operator*=(const mint& rhs) {\r\
    \n        long long u = v >> 31, d = v & MASK31;\r\n        long long ru = rhs.v\
    \ >> 31, rd = rhs.v & MASK31;\r\n        long long mid = d * ru + u * rd;\r\n\
    \        v = safe_mod(u * ru * 2 + (mid >> 30) + ((mid & MASK30) << 31) + d *\
    \ rd);\r\n        return *this;\r\n    }\r\n    mint& operator/=(const mint& rhs)\
    \ { return *this = *this * rhs.inv(); }\r\n    mint operator+() const { return\
    \ *this; }\r\n    mint operator-() const { return mint() - *this; }\r\n    mint\
    \ pow(long long n) const {\r\n        assert(0 <= n);\r\n        mint r = 1, x\
    \ = *this;\r\n        while (n) {\r\n            if (n & 1) r *= x;\r\n      \
    \      x *= x;\r\n            n >>= 1;\r\n        }\r\n        return r;\r\n \
    \   }\r\n    mint inv() const { assert(v); return pow(MOD - 2); }\r\n    friend\
    \ mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs;\
    \ }\r\n    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs)\
    \ -= rhs; }\r\n    friend mint operator*(const mint& lhs, const mint& rhs) { return\
    \ mint(lhs) *= rhs; }\r\n    friend mint operator/(const mint& lhs, const mint&\
    \ rhs) { return mint(lhs) /= rhs; }\r\n    friend bool operator<(const mint& lhs,\
    \ const mint& rhs) { return lhs.v < rhs.v; }\r\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\r\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\r\n\
    \    friend std::istream& operator >> (std::istream& is, mint& rhs) noexcept {\r\
    \n        long long tmp;\r\n        rhs = mint{(is >> tmp, tmp)};\r\n        return\
    \ is;\r\n    }\r\n    friend std::ostream& operator << (std::ostream &os, const\
    \ mint& rhs) noexcept { return os << rhs.v; }\r\n};\r\nusing mint61 = modint61<2305843009213693951>;\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint_61bit.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:44:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/ALDS1_14_C.test.cpp
documentation_of: Math/modint_61bit.hpp
layout: document
redirect_from:
- /library/Math/modint_61bit.hpp
- /library/Math/modint_61bit.hpp.html
title: Math/modint_61bit.hpp
---
