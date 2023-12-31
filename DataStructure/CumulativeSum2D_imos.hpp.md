---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki0755.test.cpp
    title: Test/yukicoder/yuki0755.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/CumulativeSum2D_imos.hpp\"\ntemplate <class\
    \ T> struct imos2D{\n    int h, w;\n    std::vector<std::vector<T>> dat;\n   \
    \ imos2D(int H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W + 1, 0)) {}\n\
    \    void add(int ly, int lx, int ry, int rx, T v){\n        assert(0 <= ly &&\
    \ ly <= ry && ry <= h);\n        assert(0 <= lx && lx <= rx && rx <= w);\n   \
    \     dat[ry][rx] += v;\n        dat[ly][rx] -= v;\n        dat[ry][lx] -= v;\n\
    \        dat[ly][lx] += v;\n    }\n    void build(){\n        for(int i = 0; i\
    \ <= h; i++) {\n            for(int j = 1; j <= w; j++) {\n                dat[i][j]\
    \ += dat[i][j - 1];\n            }\n        }\n        for(int i = 0; i <= w;\
    \ i++) {\n            for(int j = 1; j <= h; j++) {\n                dat[j][i]\
    \ += dat[j - 1][i];\n            }\n        }\n    }\n    const std::vector<T>&\
    \ operator[](int y) const {\n        assert(0 <= y && y < h);\n        return\
    \ dat[y];\n    }\n    std::vector<T>& operator[](int y) { \n        assert(0 <=\
    \ y && y < h);\n        return dat[y];\n    }\n};\n"
  code: "template <class T> struct imos2D{\n    int h, w;\n    std::vector<std::vector<T>>\
    \ dat;\n    imos2D(int H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W + 1,\
    \ 0)) {}\n    void add(int ly, int lx, int ry, int rx, T v){\n        assert(0\
    \ <= ly && ly <= ry && ry <= h);\n        assert(0 <= lx && lx <= rx && rx <=\
    \ w);\n        dat[ry][rx] += v;\n        dat[ly][rx] -= v;\n        dat[ry][lx]\
    \ -= v;\n        dat[ly][lx] += v;\n    }\n    void build(){\n        for(int\
    \ i = 0; i <= h; i++) {\n            for(int j = 1; j <= w; j++) {\n         \
    \       dat[i][j] += dat[i][j - 1];\n            }\n        }\n        for(int\
    \ i = 0; i <= w; i++) {\n            for(int j = 1; j <= h; j++) {\n         \
    \       dat[j][i] += dat[j - 1][i];\n            }\n        }\n    }\n    const\
    \ std::vector<T>& operator[](int y) const {\n        assert(0 <= y && y < h);\n\
    \        return dat[y];\n    }\n    std::vector<T>& operator[](int y) { \n   \
    \     assert(0 <= y && y < h);\n        return dat[y];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CumulativeSum2D_imos.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:39:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/yuki0755.test.cpp
documentation_of: DataStructure/CumulativeSum2D_imos.hpp
layout: document
title: "2\u6B21\u5143\u3044\u3082\u3059\u6CD5"
---

## 概要
平面加算・1点収得を行うための構造体。 
動作については <a href = "https://imoz.jp/algorithms/imos_method.html">いもす法 - いもす研</a> を参照。

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `imos2D<T>(int H, int W)`| `+` と `-` が定義されている構造体を載せることができる。<br> $H \times W$ の配列を初期値 $0$ で作成する。| $\text{O}(HW)$ |
|`void add(int ly, int lx, int ry, int rx, T v)`|・ $ly \leq y < ry$ <br>・ $lx \leq x < rx$ <br> を満たす領域に $\text{v}$ を加算する。| $\text{O}(1)$|
|`void build()`| 平面加算の結果を反映させ、1点収得ができるようにする。| $\text{O}(HW)$ |
|(1) `T a[y][x]` <br> (2) `std::vector<T> a[y]`|(1) `a[y][x]` へのアクセスを行う。 <br> (2) `a[y]` へのアクセスを行う。| $\text{O}(1)$ |
