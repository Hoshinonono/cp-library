---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dsu_01_weighted.hpp
    title: "\u91CD\u307F\u4ED8\u304D Union Find (\u548C\u5DEE\u5206)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\r\n\r\n\
    #include <bits/stdc++.h>\r\n#line 1 \"Graph/dsu_01_weighted.hpp\"\nstruct Weighted_dsu\
    \ {\n    public:\n    Weighted_dsu() : _n(0) {}\n    Weighted_dsu(int n) : _n(n),\
    \ num_component(n), parent_or_size(n, -1), diff_weight(n) {}\n\n    bool merge(int\
    \ a, int b, long long w) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        w += diff_weight[a]\
    \ - diff_weight[b];\n        if(x == y) return w == 0;\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y), w *= -1;\n        parent_or_size[x] +=\
    \ parent_or_size[y];\n        parent_or_size[y] = x;\n        diff_weight[y] =\
    \ w;\n        num_component--;\n        return true;\n    }\n\n    long long diff(int\
    \ a, int b) {\n        assert(same(a, b));\n        return diff_weight[b] - diff_weight[a];\n\
    \    }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n \
    \       assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n  \
    \  }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        int r = leader(parent_or_size[a]);\n\
    \        diff_weight[a] += diff_weight[parent_or_size[a]];\n        return parent_or_size[a]\
    \ = r;\n    }\n\n    int size() { \n        return num_component;\n    }\n\n \
    \   int size(int a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \    private:\n        int _n, num_component;\n        std::vector<int> parent_or_size;\n\
    \        std::vector<long long> diff_weight;\n};\n#line 5 \"Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp\"\
    \n\r\nint main() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(false);\r\
    \n    int n, q;\r\n    std::cin >> n >> q;\r\n    Weighted_dsu uf(n);\r\n    while(q--){\r\
    \n        int cmd, u, v, d;\r\n        std::cin >> cmd >> u >> v;\r\n        if(cmd\
    \ == 0) {\r\n            std::cin >> d;\r\n            uf.merge(u, v, d);\r\n\
    \        } else {\r\n            if(!uf.same(u, v)){\r\n                std::cout\
    \ << '?' << '\\n';\r\n                continue;\r\n            }\r\n         \
    \   std::cout << uf.diff(u, v) << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Graph/dsu_01_weighted.hpp\"\r\n\
    \r\nint main() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(false);\r\
    \n    int n, q;\r\n    std::cin >> n >> q;\r\n    Weighted_dsu uf(n);\r\n    while(q--){\r\
    \n        int cmd, u, v, d;\r\n        std::cin >> cmd >> u >> v;\r\n        if(cmd\
    \ == 0) {\r\n            std::cin >> d;\r\n            uf.merge(u, v, d);\r\n\
    \        } else {\r\n            if(!uf.same(u, v)){\r\n                std::cout\
    \ << '?' << '\\n';\r\n                continue;\r\n            }\r\n         \
    \   std::cout << uf.diff(u, v) << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - Graph/dsu_01_weighted.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 19:43:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
- /verify/Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp.html
title: Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
---
