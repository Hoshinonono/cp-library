---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Polynomial/01_inv_of_fps.hpp
    title: "FPS\u306E\u9006\u5143"
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_csr.hpp
    title: atcoder/internal_csr.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"Test/Library Checker/Polynomial/inv_of_fps.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include <bits/stdc++.h>\n#include <atcoder/all>\n#line 1 \"Polynomial/01_inv_of_fps.hpp\"\
    \ntemplate <typename mint> std::vector<mint> inverse(std::vector<mint> &a){\n\
    \    const int n = a.size();\n    std::vector<mint> res;\n    res.reserve(a.size());\n\
    \    res.emplace_back(a[0].inv());\n    while(res.size() < a.size()){\n      \
    \  const int m = 2 * res.size();\n        std::vector<mint> buf(m), fres(m);\n\
    \        std::copy(a.begin(), a.begin() + std::min(m, n + 1), buf.begin());\n\
    \        std::copy(res.begin(), res.end(), fres.begin());\n        atcoder::internal::butterfly(buf);\n\
    \        atcoder::internal::butterfly(fres);\n        for (int i = 0; i < m; i++)\
    \ buf[i] *= fres[i];\n        atcoder::internal::butterfly_inv(buf);\n       \
    \ std::fill(buf.begin(), buf.begin() + res.size(), mint::raw(0));\n        atcoder::internal::butterfly(buf);\n\
    \        for (int i = 0; i < m; i++) buf[i] *= fres[i];\n        atcoder::internal::butterfly_inv(buf);\n\
    \        mint coef = -mint(mint::raw(m) * mint::raw(m)).inv();\n        for (int\
    \ i = res.size(); i < std::min(m, n + 1); i++) res.emplace_back(buf[i] * coef);\n\
    \    }\n    return res;\n}\n#line 6 \"Test/Library Checker/Polynomial/inv_of_fps.test.cpp\"\
    \nusing namespace std;\nusing mint = atcoder::modint998244353;\n\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int n, v;\n    cin >>\
    \ n;\n    vector<mint> a(n);\n    for(int i = 0; i < n; i++){\n        cin >>\
    \ v;\n        a[i] = mint::raw(v);\n    }\n    auto ans = inverse(a);\n    for(int\
    \ i = 0; i < n; i++) cout << ans[i].val() << (i + 1 == n ? '\\n' : ' ');\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include <bits/stdc++.h>\n#include <atcoder/all>\n#include \"Polynomial/01_inv_of_fps.hpp\"\
    \nusing namespace std;\nusing mint = atcoder::modint998244353;\n\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int n, v;\n    cin >>\
    \ n;\n    vector<mint> a(n);\n    for(int i = 0; i < n; i++){\n        cin >>\
    \ v;\n        a[i] = mint::raw(v);\n    }\n    auto ans = inverse(a);\n    for(int\
    \ i = 0; i < n; i++) cout << ans[i].val() << (i + 1 == n ? '\\n' : ' ');\n}\n\n"
  dependsOn:
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - atcoder/dsu.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/math.hpp
  - atcoder/maxflow.hpp
  - atcoder/internal_queue.hpp
  - atcoder/mincostflow.hpp
  - atcoder/internal_csr.hpp
  - atcoder/scc.hpp
  - atcoder/internal_scc.hpp
  - atcoder/segtree.hpp
  - atcoder/string.hpp
  - atcoder/twosat.hpp
  - Polynomial/01_inv_of_fps.hpp
  isVerificationFile: true
  path: Test/Library Checker/Polynomial/inv_of_fps.test.cpp
  requiredBy: []
  timestamp: '2025-11-08 19:35:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Polynomial/inv_of_fps.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Polynomial/inv_of_fps.test.cpp
- /verify/Test/Library Checker/Polynomial/inv_of_fps.test.cpp.html
title: Test/Library Checker/Polynomial/inv_of_fps.test.cpp
---
