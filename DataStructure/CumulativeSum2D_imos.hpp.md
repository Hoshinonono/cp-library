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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/CumulativeSum2D_imos.hpp
layout: document
redirect_from:
- /library/DataStructure/CumulativeSum2D_imos.hpp
- /library/DataStructure/CumulativeSum2D_imos.hpp.html
title: DataStructure/CumulativeSum2D_imos.hpp
---
