---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/CumulativeSum2D.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: Math/modint_61bit.hpp
    title: Math/modint_61bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
  bundledCode: "#line 1 \"Test/Aizu Online Judge/ALDS1_14_C.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\r\n\r\n#include <bits/stdc++.h>\r\
    \n#line 1 \"DataStructure/CumulativeSum2D.hpp\"\ntemplate <class T> struct CumulativeSum2D{\r\
    \n    int h, w;\r\n    std::vector<std::vector<T>> dat;\r\n    CumulativeSum2D(int\
    \ H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W + 1, 0)) {}\r\n    CumulativeSum2D(std::vector<std::vector<T>>\
    \ &A) \r\n        : h(A.size()), w(A[0].size()), dat(h + 1, std::vector<T>(w +\
    \ 1, 0)) {\r\n        for(int y = 1; y <= h; y++){\r\n            for(int x =\
    \ 1; x <= w; x++){\r\n                dat[y][x] = A[y - 1][x - 1] + dat[y][x -\
    \ 1] + dat[y - 1][x] - dat[y - 1][x - 1];\r\n            }\r\n        }\r\n  \
    \  }\r\n    void add(int y, int x, T z){\r\n        assert(0 <= y && y < h);\r\
    \n        assert(0 <= x && x < w);\r\n        dat[y + 1][x + 1] += z;\r\n    }\r\
    \n    void build(){\r\n        for(int y = 1; y <= h; y++) {\r\n            for(int\
    \ x = 1; x <= w; x++) {\r\n                dat[y][x] += dat[y][x - 1] + dat[y\
    \ - 1][x] - dat[y - 1][x - 1];\r\n            }\r\n        }\r\n    }\r\n    T\
    \ query(int ly, int lx, int ry, int rx){\r\n        assert(0 <= ly && ly <= ry\
    \ && ry <= h);\r\n        assert(0 <= lx && lx <= rx && rx <= w);\r\n        return\
    \ dat[ry][rx] - dat[ly][rx] - dat[ry][lx] + dat[ly][lx];\r\n    }\r\n};\r\n#line\
    \ 1 \"Math/modint_61bit.hpp\"\ntemplate<const long long MOD = 2305843009213693951,\
    \ \r\n        const long long MASK31 = (1ll << 31) - 1, const long long MASK30\
    \ = (1ll << 30) - 1>\r\nstruct modint61 {\r\n    using mint = modint61;\r\n  \
    \  long long v;\r\n    modint61() : v(0) {}\r\n    template<class T> modint61(T\
    \ x) { \r\n        while(x < 0) x += MOD;\r\n        while(x >= MOD) x -= MOD;\r\
    \n        v = x;\r\n    }\r\n    long long safe_mod(long long x){\r\n        x\
    \ = (x >> 61) + (x & MOD);\r\n        if (x >= MOD) x -= MOD;\r\n        return\
    \ x;\r\n    }\r\n    static constexpr long long mod() { return MOD; }\r\n    mint&\
    \ operator++() {v++; if(v == MOD)v = 0; return *this;}\r\n    mint& operator--()\
    \ {if(v == 0)v = MOD; v--; return *this;}\r\n    mint operator++(int) { mint result\
    \ = *this; ++*this; return result; }\r\n    mint operator--(int) { mint result\
    \ = *this; --*this; return result; }\r\n    mint& operator+=(const mint& rhs)\
    \ { v += rhs.v; if(v >= MOD) v -= MOD; return *this; }\r\n    mint& operator-=(const\
    \ mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this; }\r\n    mint&\
    \ operator*=(const mint& rhs) {\r\n        long long u = v >> 31, d = v & MASK31;\r\
    \n        long long ru = rhs.v >> 31, rd = rhs.v & MASK31;\r\n        long long\
    \ mid = d * ru + u * rd;\r\n        v = safe_mod(u * ru * 2 + (mid >> 30) + ((mid\
    \ & MASK30) << 31) + d * rd);\r\n        return *this;\r\n    }\r\n    mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\r\n    mint operator+() const\
    \ { return *this; }\r\n    mint operator-() const { return mint() - *this; }\r\
    \n    mint pow(long long n) const {\r\n        assert(0 <= n);\r\n        mint\
    \ r = 1, x = *this;\r\n        while (n) {\r\n            if (n & 1) r *= x;\r\
    \n            x *= x;\r\n            n >>= 1;\r\n        }\r\n        return r;\r\
    \n    }\r\n    mint inv() const { assert(v); return pow(MOD - 2); }\r\n    friend\
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
    \n#line 6 \"Test/Aizu Online Judge/ALDS1_14_C.test.cpp\"\nusing namespace std;\r\
    \n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\n\
    \    int h, w;\r\n    cin >> h >> w;\r\n    vector<mint61> Y(1001), X(1001);\r\
    \n    Y[0] = X[0] = 1;\r\n    for(int y = 0; y < 1000; y++){\r\n        Y[y +\
    \ 1] = Y[y] * 334;\r\n    }\r\n    for(int x = 0; x < 1000; x++){\r\n        X[x\
    \ + 1] = X[x] * 114514;\r\n    }\r\n    CumulativeSum2D<mint61> A(h, w);\r\n \
    \   for(int y = 0; y < h; y++){\r\n        string s;\r\n        cin >> s;\r\n\
    \        for(int x = 0; x < w; x++){\r\n            A.add(y, x, Y[y] * X[x] *\
    \ s[x]);\r\n        }\r\n    }\r\n    A.build();\r\n\r\n    int h2, w2;\r\n  \
    \  mint61 hash;\r\n    cin >> h2 >> w2;\r\n    for(int y = 0; y < h2; y++){\r\n\
    \        string s;\r\n        cin >> s;\r\n        for(int x = 0; x < w2; x++){\r\
    \n            hash += Y[y] * X[x] * s[x];\r\n        }\r\n    }\r\n\r\n    for(int\
    \ y = 0; y + h2 <= h; y++){\r\n        for(int x = 0; x + w2 <= w; x++){\r\n \
    \           if(hash * Y[y] * X[x] == A.query(y, x, y + h2, x + w2)){\r\n     \
    \           cout << y << ' ' << x << '\\n';\r\n            }\r\n        }\r\n\
    \    }\r\n}\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\r\
    \n\r\n#include <bits/stdc++.h>\r\n#include \"DataStructure/CumulativeSum2D.hpp\"\
    \r\n#include \"Math/modint_61bit.hpp\"\r\nusing namespace std;\r\n\r\nint main()\
    \ {\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\n    int h, w;\r\n\
    \    cin >> h >> w;\r\n    vector<mint61> Y(1001), X(1001);\r\n    Y[0] = X[0]\
    \ = 1;\r\n    for(int y = 0; y < 1000; y++){\r\n        Y[y + 1] = Y[y] * 334;\r\
    \n    }\r\n    for(int x = 0; x < 1000; x++){\r\n        X[x + 1] = X[x] * 114514;\r\
    \n    }\r\n    CumulativeSum2D<mint61> A(h, w);\r\n    for(int y = 0; y < h; y++){\r\
    \n        string s;\r\n        cin >> s;\r\n        for(int x = 0; x < w; x++){\r\
    \n            A.add(y, x, Y[y] * X[x] * s[x]);\r\n        }\r\n    }\r\n    A.build();\r\
    \n\r\n    int h2, w2;\r\n    mint61 hash;\r\n    cin >> h2 >> w2;\r\n    for(int\
    \ y = 0; y < h2; y++){\r\n        string s;\r\n        cin >> s;\r\n        for(int\
    \ x = 0; x < w2; x++){\r\n            hash += Y[y] * X[x] * s[x];\r\n        }\r\
    \n    }\r\n\r\n    for(int y = 0; y + h2 <= h; y++){\r\n        for(int x = 0;\
    \ x + w2 <= w; x++){\r\n            if(hash * Y[y] * X[x] == A.query(y, x, y +\
    \ h2, x + w2)){\r\n                cout << y << ' ' << x << '\\n';\r\n       \
    \     }\r\n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - DataStructure/CumulativeSum2D.hpp
  - Math/modint_61bit.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/ALDS1_14_C.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 11:04:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/ALDS1_14_C.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/ALDS1_14_C.test.cpp
- /verify/Test/Aizu Online Judge/ALDS1_14_C.test.cpp.html
title: Test/Aizu Online Judge/ALDS1_14_C.test.cpp
---
