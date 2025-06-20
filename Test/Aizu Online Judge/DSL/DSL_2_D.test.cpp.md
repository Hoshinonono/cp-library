---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/segtree_dual.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
  bundledCode: "#line 1 \"Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\r\n\r\n#include <bits/stdc++.h>\r\
    \n#line 1 \"DataStructure/segtree_dual.hpp\"\ntemplate <class S, S (*mapping)(S,\
    \ S), S (*id)()> struct dual_segtree {\r\n    public:\r\n    dual_segtree() :\
    \ dual_segtree(0) {}\r\n    dual_segtree(int n) : dual_segtree(std::vector<S>(n,\
    \ id())) {}\r\n    dual_segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\
    \n        log = ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2\
    \ * size, id());\r\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\r\
    \n    }\r\n    const S& operator[](int p) const {\r\n        assert(0 <= p &&\
    \ p < _n);\r\n        p += size;\r\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\r\n        return d[p];\r\n    }\r\n    S& operator[](int p) { \r\n \
    \       assert(0 <= p && p < _n);\r\n        p += size;\r\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\r\n        return d[p];\r\n    }\r\n    void\
    \ apply(int p, S f) {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\
    \n        for (int i = log; i >= 1; i--) push(p >> i);\r\n        d[p] = mapping(f,\
    \ d[p]);\r\n    }\r\n    void apply(int l, int r, S f) {\r\n        assert(0 <=\
    \ l && l <= r && r <= _n);\r\n        if (l == r) return;\r\n        l += size;\r\
    \n        r += size;\r\n        for (int i = log; i >= 1; i--) {\r\n         \
    \   if (((l >> i) << i) != l) push(l >> i);\r\n            if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\r\n        }\r\n        while (l < r) {\r\n      \
    \      if (l & 1) all_apply(l++, f);\r\n            if (r & 1) all_apply(--r,\
    \ f);\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n    }\r\n\
    \    private:\r\n    int _n, size, log;\r\n    std::vector<S> d;\r\n    void all_apply(int\
    \ k, S f) {\r\n        d[k] = mapping(f, d[k]);\r\n    }\r\n    void push(int\
    \ k) {\r\n        all_apply(2 * k, d[k]);\r\n        all_apply(2 * k + 1, d[k]);\r\
    \n        d[k] = id();\r\n    }\r\n    int ceil_pow2(int n) {\r\n        int x\
    \ = 0;\r\n        while ((1U << x) < (unsigned int)(n)) x++;\r\n        return\
    \ x;\r\n    }\r\n};\r\n#line 5 \"Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp\"\
    \n\r\nusing namespace std;\r\nint op(int af, int bf){ return af == -1 ? bf : af;\
    \ }\r\nint id(){ return -1; }\r\n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int n, q;\r\n    cin >> n >> q;\r\n    dual_segtree<int,\
    \ op, id> seg(vector<int>(n, numeric_limits<int>::max()));\r\n    while(q--){\r\
    \n        int cmd;\r\n        cin >> cmd;\r\n        if(cmd == 0){\r\n       \
    \     int l, r, x;\r\n            cin >> l >> r >> x;\r\n            seg.apply(l,\
    \ r + 1, x);\r\n        }else{\r\n            int p;\r\n            cin >> p;\r\
    \n            cout << seg[p] << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\r\n\
    \r\n#include <bits/stdc++.h>\r\n#include \"DataStructure/segtree_dual.hpp\"\r\n\
    \r\nusing namespace std;\r\nint op(int af, int bf){ return af == -1 ? bf : af;\
    \ }\r\nint id(){ return -1; }\r\n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int n, q;\r\n    cin >> n >> q;\r\n    dual_segtree<int,\
    \ op, id> seg(vector<int>(n, numeric_limits<int>::max()));\r\n    while(q--){\r\
    \n        int cmd;\r\n        cin >> cmd;\r\n        if(cmd == 0){\r\n       \
    \     int l, r, x;\r\n            cin >> l >> r >> x;\r\n            seg.apply(l,\
    \ r + 1, x);\r\n        }else{\r\n            int p;\r\n            cin >> p;\r\
    \n            cout << seg[p] << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - DataStructure/segtree_dual.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 11:08:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
- /verify/Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp.html
title: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
---
