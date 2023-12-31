---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/fenwick_tree.hpp
    title: "\u30D5\u30A7\u30CB\u30C3\u30AF\u6728 (BIT, Binary Indexed Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
  bundledCode: "#line 1 \"Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include <bits/stdc++.h>\n#line 1 \"DataStructure/fenwick_tree.hpp\"\ntemplate\
    \ <class T> struct fenwick_tree {\r\n    using U = T;\r\n\r\n    public:\r\n \
    \   fenwick_tree() : _n(0) {}\r\n    fenwick_tree(int n) : _n(n), data(n) {}\r\
    \n\r\n    void add(int p, T x) {\r\n        assert(0 <= p && p < _n);\r\n    \
    \    p++;\r\n        while (p <= _n) {\r\n            data[p - 1] += U(x);\r\n\
    \            p += p & -p;\r\n        }\r\n    }\r\n\r\n    T sum(int l, int r)\
    \ {\r\n        assert(0 <= l && l <= r && r <= _n);\r\n        return sum(r) -\
    \ sum(l);\r\n    }\r\n\r\n    private:\r\n    int _n;\r\n    std::vector<U> data;\r\
    \n\r\n    U sum(int r) {\r\n        U s = 0;\r\n        while (r > 0) {\r\n  \
    \          s += data[r - 1];\r\n            r -= r & -r;\r\n        }\r\n    \
    \    return s;\r\n    }\r\n};\r\n#line 5 \"Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp\"\
    \n\n\nint main(){\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n),\
    \ ca;\n    for(auto &&v : a) std::cin >> v;\n    ca = a;\n    sort(ca.begin(),\
    \ ca.end());\n    ca.erase(std::unique(ca.begin(), ca.end()), ca.end());\n   \
    \ int m = ca.size();\n    fenwick_tree<int> fw(m);\n    long long ans = 0;\n \
    \   for(auto &&v : a){\n        v = std::distance(ca.begin(), std::lower_bound(ca.begin(),\
    \ ca.end(), v));\n        ans += fw.sum(v + 1, m);\n        fw.add(v, 1);\n  \
    \  }\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include <bits/stdc++.h>\n#include \"DataStructure/fenwick_tree.hpp\"\n\n\n\
    int main(){\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n), ca;\n\
    \    for(auto &&v : a) std::cin >> v;\n    ca = a;\n    sort(ca.begin(), ca.end());\n\
    \    ca.erase(std::unique(ca.begin(), ca.end()), ca.end());\n    int m = ca.size();\n\
    \    fenwick_tree<int> fw(m);\n    long long ans = 0;\n    for(auto &&v : a){\n\
    \        v = std::distance(ca.begin(), std::lower_bound(ca.begin(), ca.end(),\
    \ v));\n        ans += fw.sum(v + 1, m);\n        fw.add(v, 1);\n    }\n    std::cout\
    \ << ans << '\\n';\n}\n"
  dependsOn:
  - DataStructure/fenwick_tree.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 11:06:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
- /verify/Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp.html
title: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
---
