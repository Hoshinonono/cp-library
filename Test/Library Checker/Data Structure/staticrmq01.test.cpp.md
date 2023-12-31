---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.hpp
    title: DataStructure/SparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/Library Checker/Data Structure/staticrmq01.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ <bits/stdc++.h>\r\n#line 1 \"DataStructure/SparseTable.hpp\"\ntemplate <class\
    \ T, T (*op)(T, T), T (*e)()> struct SparseTable {\r\n    const int n, LOGV;\r\
    \n    std::vector<std::vector<T>> table;\r\n    std::vector<int> log_table;\r\n\
    \    SparseTable(const std::vector<T> &v) : n(v.size()), LOGV(std::__lg(std::max(n,\
    \ 1)) + 1), \r\n                                           log_table(n + 1), table(LOGV,\
    \ std::vector<T>(n)) {\r\n        std::copy(v.begin(), v.end(), table[0].begin());\r\
    \n        for(int i = 1; i < LOGV; i++) {\r\n            for(int j = 0; j + (1\
    \ << i) <= n; j++) {\r\n                table[i][j] = op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\r\n            }\r\n        }\r\n        for(int\
    \ i = 2; i <= n; i++) {\r\n            log_table[i] = log_table[i >> 1] + 1;\r\
    \n        }\r\n    }\r\n    T prod(int l, int r){\r\n        assert(0 <= l &&\
    \ l <= r && r <= n);\r\n        if(l == r) return e();\r\n        int b = log_table[r\
    \ - l];\r\n        return op(table[b][l], table[b][r - (1 << b)]);\r\n    }\r\n\
    };\r\n#line 5 \"Test/Library Checker/Data Structure/staticrmq01.test.cpp\"\n\r\
    \nusing namespace std;\r\n\r\nint op(int a, int b){ return min(a, b); }\r\nint\
    \ e(){ return 1 << 30; }\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q, l, r;\r\n    cin >> N >> Q;\r\n    vector<int>\
    \ a(N);\r\n    for(auto &&v : a) cin >> v;\r\n    SparseTable<int, op, e> st(a);\r\
    \n    \r\n    while(Q--){\r\n        cin >> l >> r;\r\n        cout << st.prod(l,\
    \ r) << '\\n';\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ <bits/stdc++.h>\r\n#include \"DataStructure/SparseTable.hpp\"\r\n\r\nusing namespace\
    \ std;\r\n\r\nint op(int a, int b){ return min(a, b); }\r\nint e(){ return 1 <<\
    \ 30; }\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\
    \n    int N, Q, l, r;\r\n    cin >> N >> Q;\r\n    vector<int> a(N);\r\n    for(auto\
    \ &&v : a) cin >> v;\r\n    SparseTable<int, op, e> st(a);\r\n    \r\n    while(Q--){\r\
    \n        cin >> l >> r;\r\n        cout << st.prod(l, r) << '\\n';\r\n    }\r\
    \n}\r\n"
  dependsOn:
  - DataStructure/SparseTable.hpp
  isVerificationFile: true
  path: Test/Library Checker/Data Structure/staticrmq01.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 10:48:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Data Structure/staticrmq01.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Data Structure/staticrmq01.test.cpp
- /verify/Test/Library Checker/Data Structure/staticrmq01.test.cpp.html
title: Test/Library Checker/Data Structure/staticrmq01.test.cpp
---
