---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/Problems/problem3249.test.cpp
    title: Test/Aizu Online Judge/Problems/problem3249.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/RollingHash.hpp\"\nstruct RollingHash{\n    long\
    \ long BASE = 257, RMOD = (1ll << 61) - 1;\n    long long MASK31 = (1ll << 31)\
    \ - 1, MASK30 = (1ll << 30) - 1;\n    int n;\n    std::vector<long long> dat,\
    \ dat2, base_pow;\n    RollingHash()  {}\n    RollingHash(std::string &s) : n(s.size()),\
    \ dat(n+1), dat2(n+1), base_pow(n+1) {\n        base_pow[0] = 1;\n        for(int\
    \ i = 0; i < n; i++){\n            dat[i+1] = safe_mod(internal_mul(dat[i], BASE)\
    \ + s[i]);\n            dat2.rbegin()[i+1] = safe_mod(internal_mul(dat2.rbegin()[i],\
    \ BASE) + s.rbegin()[i]);\n            base_pow[i+1] = internal_mul(base_pow[i],\
    \ BASE);\n        }\n    }\n    long long internal_mul(long long a, long long\
    \ b){\n        long long au = a >> 31, ad = a & MASK31;\n        long long bu\
    \ = b >> 31, bd = b & MASK31;\n        long long mid = ad * bu + au * bd;\n  \
    \      long long midu = mid >> 30;\n        long long midd = mid & MASK30;\n \
    \       return safe_mod(au * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n\
    \    long long safe_mod(long long x){\n        long long xu = x >> 61, xd = x\
    \ & RMOD;\n        long long res = xu + xd;\n        if (res >= RMOD) res -= RMOD;\n\
    \        return res;\n    }\n    long long hash(int l, int r){\n        long long\
    \ res = dat[r] - internal_mul(dat[l], base_pow[r - l]);\n        if(res < 0)res\
    \ += RMOD;\n        return res;\n    }\n    long long revhash(int l, int r){\n\
    \        long long res = dat2[l] - internal_mul(dat2[r], base_pow[r - l]);\n \
    \       if(res < 0)res += RMOD;\n        return res;\n    }\n    long long joint(long\
    \ long lhs, long long rhs, long long rsize){\n        long long res = internal_mul(lhs,\
    \ base_pow[rsize]) + rhs;\n        if(res >= RMOD) res -= RMOD;\n        return\
    \ res;\n    }\n};\n"
  code: "struct RollingHash{\n    long long BASE = 257, RMOD = (1ll << 61) - 1;\n\
    \    long long MASK31 = (1ll << 31) - 1, MASK30 = (1ll << 30) - 1;\n    int n;\n\
    \    std::vector<long long> dat, dat2, base_pow;\n    RollingHash()  {}\n    RollingHash(std::string\
    \ &s) : n(s.size()), dat(n+1), dat2(n+1), base_pow(n+1) {\n        base_pow[0]\
    \ = 1;\n        for(int i = 0; i < n; i++){\n            dat[i+1] = safe_mod(internal_mul(dat[i],\
    \ BASE) + s[i]);\n            dat2.rbegin()[i+1] = safe_mod(internal_mul(dat2.rbegin()[i],\
    \ BASE) + s.rbegin()[i]);\n            base_pow[i+1] = internal_mul(base_pow[i],\
    \ BASE);\n        }\n    }\n    long long internal_mul(long long a, long long\
    \ b){\n        long long au = a >> 31, ad = a & MASK31;\n        long long bu\
    \ = b >> 31, bd = b & MASK31;\n        long long mid = ad * bu + au * bd;\n  \
    \      long long midu = mid >> 30;\n        long long midd = mid & MASK30;\n \
    \       return safe_mod(au * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n\
    \    long long safe_mod(long long x){\n        long long xu = x >> 61, xd = x\
    \ & RMOD;\n        long long res = xu + xd;\n        if (res >= RMOD) res -= RMOD;\n\
    \        return res;\n    }\n    long long hash(int l, int r){\n        long long\
    \ res = dat[r] - internal_mul(dat[l], base_pow[r - l]);\n        if(res < 0)res\
    \ += RMOD;\n        return res;\n    }\n    long long revhash(int l, int r){\n\
    \        long long res = dat2[l] - internal_mul(dat2[r], base_pow[r - l]);\n \
    \       if(res < 0)res += RMOD;\n        return res;\n    }\n    long long joint(long\
    \ long lhs, long long rhs, long long rsize){\n        long long res = internal_mul(lhs,\
    \ base_pow[rsize]) + rhs;\n        if(res >= RMOD) res -= RMOD;\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-05-25 08:55:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/Problems/problem3249.test.cpp
documentation_of: String/RollingHash.hpp
layout: document
redirect_from:
- /library/String/RollingHash.hpp
- /library/String/RollingHash.hpp.html
title: String/RollingHash.hpp
---
