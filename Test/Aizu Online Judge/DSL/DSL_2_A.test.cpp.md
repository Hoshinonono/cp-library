---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A
  bundledCode: "#line 1 \"Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A\"\r\n\r\n\
    #include <bits/stdc++.h>\r\n#line 1 \"DataStructure/segtree.hpp\"\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\r\n    public:\r\n    segtree()\
    \ : segtree(0) {}\r\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\r\
    \n    segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\n        log =\
    \ ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2 *\
    \ size, e());\r\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\r\n\
    \        for (int i = size - 1; i >= 1; i--) {\r\n            update(i);\r\n \
    \       }\r\n    }\r\n\r\n    void set(int p, S x) {\r\n        assert(0 <= p\
    \ && p < _n);\r\n        p += size;\r\n        d[p] = x;\r\n        for (int i\
    \ = 1; i <= log; i++) update(p >> i);\r\n    }\r\n\r\n    S get(int p) {\r\n \
    \       assert(0 <= p && p < _n);\r\n        return d[p + size];\r\n    }\r\n\
    \    const S operator[](int p) const { return get(p); }\r\n    S operator[](int\
    \ p) { return get(p); }\r\n\r\n    S prod(int l, int r) {\r\n        assert(0\
    \ <= l && l <= r && r <= _n);\r\n        S sml = e(), smr = e();\r\n        l\
    \ += size;\r\n        r += size;\r\n\r\n        while (l < r) {\r\n          \
    \  if (l & 1) sml = op(sml, d[l++]);\r\n            if (r & 1) smr = op(d[--r],\
    \ smr);\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n     \
    \   return op(sml, smr);\r\n    }\r\n\r\n    S all_prod() { return d[1]; }\r\n\
    \r\n    template <bool (*f)(S)> int max_right(int l) {\r\n        return max_right(l,\
    \ [](S x) { return f(x); });\r\n    }\r\n    template <class F> int max_right(int\
    \ l, F f) {\r\n        assert(0 <= l && l <= _n);\r\n        assert(f(e()));\r\
    \n        if (l == _n) return _n;\r\n        l += size;\r\n        S sm = e();\r\
    \n        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm,\
    \ d[l]))) {\r\n                while (l < size) {\r\n                    l = (2\
    \ * l);\r\n                    if (f(op(sm, d[l]))) {\r\n                    \
    \    sm = op(sm, d[l]);\r\n                        l++;\r\n                  \
    \  }\r\n                }\r\n                return l - size;\r\n            }\r\
    \n            sm = op(sm, d[l]);\r\n            l++;\r\n        } while ((l &\
    \ -l) != l);\r\n        return _n;\r\n    }\r\n\r\n    template <bool (*f)(S)>\
    \ int min_left(int r) {\r\n        return min_left(r, [](S x) { return f(x); });\r\
    \n    }\r\n    template <class F> int min_left(int r, F f) {\r\n        assert(0\
    \ <= r && r <= _n);\r\n        assert(f(e()));\r\n        if (r == 0) return 0;\r\
    \n        r += size;\r\n        S sm = e();\r\n        do {\r\n            r--;\r\
    \n            while (r > 1 && (r % 2)) r >>= 1;\r\n            if (!f(op(d[r],\
    \ sm))) {\r\n                while (r < size) {\r\n                    r = (2\
    \ * r + 1);\r\n                    if (f(op(d[r], sm))) {\r\n                \
    \        sm = op(d[r], sm);\r\n                        r--;\r\n              \
    \      }\r\n                }\r\n                return r + 1 - size;\r\n    \
    \        }\r\n            sm = op(d[r], sm);\r\n        } while ((r & -r) != r);\r\
    \n        return 0;\r\n    }\r\n\r\n    private:\r\n    int _n, size, log;\r\n\
    \    std::vector<S> d;\r\n    int ceil_pow2(int n) {\r\n        int x = 0;\r\n\
    \        while ((1U << x) < (unsigned int)(n)) x++;\r\n        return x;\r\n \
    \   }\r\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n};\r\
    \n#line 5 \"Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp\"\n\r\nint op(int lhs,\
    \ int rhs) {\r\n    return std::min(lhs, rhs);\r\n}\r\n\r\nint e(){\r\n    return\
    \ std::numeric_limits<int>::max();\r\n}\r\n\r\nint main() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(false);\r\n    int n, q;\r\n    std::cin >> n\
    \ >> q;\r\n    segtree<int, op, e> seg(n);\r\n    while(q--){\r\n        int cmd,\
    \ x, y;\r\n        std::cin >> cmd >> x >> y;\r\n        if(cmd == 0) {\r\n  \
    \          seg.set(x, y);\r\n        } else {\r\n            std::cout << seg.prod(x,\
    \ ++y) << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"DataStructure/segtree.hpp\"\r\n\
    \r\nint op(int lhs, int rhs) {\r\n    return std::min(lhs, rhs);\r\n}\r\n\r\n\
    int e(){\r\n    return std::numeric_limits<int>::max();\r\n}\r\n\r\nint main()\
    \ {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(false);\r\n    int\
    \ n, q;\r\n    std::cin >> n >> q;\r\n    segtree<int, op, e> seg(n);\r\n    while(q--){\r\
    \n        int cmd, x, y;\r\n        std::cin >> cmd >> x >> y;\r\n        if(cmd\
    \ == 0) {\r\n            seg.set(x, y);\r\n        } else {\r\n            std::cout\
    \ << seg.prod(x, ++y) << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 11:08:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
- /verify/Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp.html
title: Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
---
