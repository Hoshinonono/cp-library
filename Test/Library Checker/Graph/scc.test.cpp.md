---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC, Strongly Connected Component)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Test/Library Checker/Graph/scc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n#line 1\
    \ \"Graph/scc.hpp\"\nstruct SCC {\r\n    int n, group_num;\r\n    std::vector<std::vector<int>>\
    \ &g;\r\n    std::vector<int> ids;\r\n    SCC(std::vector<std::vector<int>> &_g)\
    \ : n(_g.size()), g(_g), ids(n), group_num(0) {\r\n        int now_ord = 0;\r\n\
    \        std::vector<int> visited, low(n), ord(n, -1);\r\n        visited.reserve(n);\r\
    \n        auto dfs = [&](auto self, int v) -> void {\r\n            low[v] = ord[v]\
    \ = now_ord++;\r\n            visited.emplace_back(v);\r\n            for(auto\
    \ to : g[v]) {\r\n                if (ord[to] == -1) {\r\n                   \
    \ self(self, to);\r\n                    low[v] = std::min(low[v], low[to]);\r\
    \n                } else {\r\n                    low[v] = std::min(low[v], ord[to]);\r\
    \n                }\r\n            }\r\n            if (low[v] == ord[v]) {\r\n\
    \                while (true) {\r\n                    int u = visited.back();\r\
    \n                    visited.pop_back();\r\n                    ord[u] = n;\r\
    \n                    ids[u] = group_num;\r\n                    if (u == v) break;\r\
    \n                }\r\n                group_num++;\r\n            }\r\n     \
    \   };\r\n        for (int i = 0; i < n; i++) {\r\n            if (ord[i] == -1)\
    \ dfs(dfs, i);\r\n        }\r\n        for (auto& x : ids) {\r\n            x\
    \ = group_num - 1 - x;\r\n        }\r\n    }\r\n    const int operator[](int p)\
    \ const {\r\n        assert(0 <= p && p < n);\r\n        return ids[p];\r\n  \
    \  }\r\n    int operator[](int p) { \r\n        assert(0 <= p && p < n);\r\n \
    \       return ids[p];\r\n    }\r\n    std::vector<std::vector<int>> groups(){\r\
    \n        std::vector<int> counts(group_num);\r\n        for (auto x : ids) counts[x]++;\r\
    \n        std::vector<std::vector<int>> groups(group_num);\r\n        for (int\
    \ i = 0; i < group_num; i++) {\r\n            groups[i].reserve(counts[i]);\r\n\
    \        }\r\n        for (int i = 0; i < n; i++) {\r\n            groups[ids[i]].emplace_back(i);\r\
    \n        }\r\n        return groups;\r\n    }\r\n};\r\n#line 5 \"Test/Library\
    \ Checker/Graph/scc.test.cpp\"\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, m, u, v;\n    std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for(int i = 0; i < m; i++){\n        std::cin >> u >> v;\n      \
    \  g[u].emplace_back(v);\n    }\n    SCC scc(g);\n    auto G = scc.groups();\n\
    \    std::cout << G.size() << '\\n';\n    for(auto &&vec : scc.groups()){\n  \
    \      std::cout << vec.size();\n        for(auto &&v : vec) std::cout << ' '\
    \ << v;\n        std::cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    #include \"Graph/scc.hpp\"\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, m, u, v;\n    std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for(int i = 0; i < m; i++){\n        std::cin >> u >> v;\n      \
    \  g[u].emplace_back(v);\n    }\n    SCC scc(g);\n    auto G = scc.groups();\n\
    \    std::cout << G.size() << '\\n';\n    for(auto &&vec : scc.groups()){\n  \
    \      std::cout << vec.size();\n        for(auto &&v : vec) std::cout << ' '\
    \ << v;\n        std::cout << '\\n';\n    }\n}\n"
  dependsOn:
  - Graph/scc.hpp
  isVerificationFile: true
  path: Test/Library Checker/Graph/scc.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 10:55:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Graph/scc.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Graph/scc.test.cpp
- /verify/Test/Library Checker/Graph/scc.test.cpp.html
title: Test/Library Checker/Graph/scc.test.cpp
---
