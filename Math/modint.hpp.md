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
  bundledCode: "#line 1 \"Math/modint.hpp\"\ntemplate<const unsigned int MOD> struct\
    \ prime_modint {\n    using mint = prime_modint;\n    unsigned int v;\n    prime_modint()\
    \ : v(0) {}\n    prime_modint(unsigned int a) { a %= MOD; v = a; }\n    prime_modint(unsigned\
    \ long long a) { a %= MOD; v = a; }\n    prime_modint(int a) { a %= (int)(MOD);\
    \ if(a < 0)a += MOD; v = a; }\n    prime_modint(long long a) { a %= (int)(MOD);\
    \ if(a < 0)a += MOD; v = a; }\n    static constexpr int mod() { return MOD; }\n\
    \    mint& operator++() {v++; if(v == MOD)v = 0; return *this;}\n    mint& operator--()\
    \ {if(v == 0)v = MOD; v--; return *this;}\n    mint operator++(int) { mint result\
    \ = *this; ++*this; return result; }\n    mint operator--(int) { mint result =\
    \ *this; --*this; return result; }\n    mint& operator+=(const mint& rhs) { v\
    \ += rhs.v; if(v >= MOD) v -= MOD; return *this; }\n    mint& operator-=(const\
    \ mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this; }\n    mint&\
    \ operator*=(const mint& rhs) {\n        v = (unsigned int)((unsigned long long)(v)\
    \ * rhs.v % MOD);\n        return *this;\n    }\n    mint& operator/=(const mint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n    mint operator+() const { return\
    \ *this; }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint r = 1, x = *this;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ { assert(v); return pow(MOD - 2); }\n    friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::ostream&\
    \ operator << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v;\
    \ }\n};\n"
  code: "template<const unsigned int MOD> struct prime_modint {\n    using mint =\
    \ prime_modint;\n    unsigned int v;\n    prime_modint() : v(0) {}\n    prime_modint(unsigned\
    \ int a) { a %= MOD; v = a; }\n    prime_modint(unsigned long long a) { a %= MOD;\
    \ v = a; }\n    prime_modint(int a) { a %= (int)(MOD); if(a < 0)a += MOD; v =\
    \ a; }\n    prime_modint(long long a) { a %= (int)(MOD); if(a < 0)a += MOD; v\
    \ = a; }\n    static constexpr int mod() { return MOD; }\n    mint& operator++()\
    \ {v++; if(v == MOD)v = 0; return *this;}\n    mint& operator--() {if(v == 0)v\
    \ = MOD; v--; return *this;}\n    mint operator++(int) { mint result = *this;\
    \ ++*this; return result; }\n    mint operator--(int) { mint result = *this; --*this;\
    \ return result; }\n    mint& operator+=(const mint& rhs) { v += rhs.v; if(v >=\
    \ MOD) v -= MOD; return *this; }\n    mint& operator-=(const mint& rhs) { if(v\
    \ < rhs.v) v += MOD; v -= rhs.v; return *this; }\n    mint& operator*=(const mint&\
    \ rhs) {\n        v = (unsigned int)((unsigned long long)(v) * rhs.v % MOD);\n\
    \        return *this;\n    }\n    mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inv(); }\n    mint operator+() const { return *this; }\n\
    \    mint operator-() const { return mint() - *this; }\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint r = 1, x = *this;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const { assert(v);\
    \ return pow(MOD - 2); }\n    friend mint operator+(const mint& lhs, const mint&\
    \ rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::ostream&\
    \ operator << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:44:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/modint.hpp
layout: document
redirect_from:
- /library/Math/modint.hpp
- /library/Math/modint.hpp.html
title: Math/modint.hpp
---
