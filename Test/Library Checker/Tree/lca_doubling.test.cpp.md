---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Tree/lca_doubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30BF\
      \u30D6\u30EA\u30F3\u30B0)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Test/Library Checker/Tree/lca_doubling.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include <bits/stdc++.h>\r\
    \n#line 1 \"Tree/lca_doubling.hpp\"\nstruct LCA_tree {\r\n    int n, LOGV, root;\r\
    \n    std::vector<std::vector<int>> &g, parent;\r\n    std::vector<int> depth,\
    \ id;\r\n    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}\r\
    \n    LCA_tree(std::vector<std::vector<int>> &_g, int r) : n(_g.size()), g(_g),\
    \ root(r), depth(n), id(n, -1) {\r\n        LOGV = std::__lg(std::max(1, n - 1));\r\
    \n        parent.resize(LOGV + 1, std::vector<int>(n, -1));\r\n        std::vector<int>\
    \ stk;\r\n        stk.reserve(n);\r\n        stk.emplace_back(root);\r\n     \
    \   depth[root] = 0;\r\n        int cnt = 0;\r\n        while(!stk.empty()){\r\
    \n            int v = stk.back();\r\n            stk.pop_back();\r\n         \
    \   id[v] = cnt++;\r\n            for(int i = 1; (1 << i) <= depth[v]; i++){\r\
    \n                parent[i][v] = parent[i - 1][parent[i - 1][v]];\r\n        \
    \    }\r\n            for(auto &&u : g[v]){\r\n                if(id[u] != -1)\
    \ continue;\r\n                parent[0][u] = v;\r\n                depth[u] =\
    \ depth[v] + 1;\r\n                stk.emplace_back(u);\r\n            }\r\n \
    \       }\r\n    }\r\n    int lca(int u, int v){\r\n        assert(0 <= u && u\
    \ < n);\r\n        assert(0 <= v && v < n);\r\n        if(depth[u] > depth[v])\
    \ std::swap(u, v);\r\n        int d = depth[v] - depth[u];\r\n        while(d){\r\
    \n            v = parent[std::__lg(d & -d)][v];\r\n            d -= d & -d;\r\n\
    \        }\r\n        if(u == v) return u;\r\n        for(int i = std::__lg(depth[v]);\
    \ i >= 0; i--){\r\n            if(parent[i][u] != parent[i][v]){\r\n         \
    \       u = parent[i][u];\r\n                v = parent[i][v];\r\n           \
    \ }\r\n        }\r\n        return parent[0][u];\r\n    }\r\n    int la(int v,\
    \ int d){\r\n        if(d > depth[v]) return -1;\r\n        while(d){\r\n    \
    \        v = parent[std::__lg(d & -d)][v];\r\n            d -= d & -d;\r\n   \
    \     }\r\n        return v;\r\n    }\r\n    int la(int from, int to, int d){\r\
    \n        int lcav = lca(from, to);\r\n        int len = depth[from] + depth[to]\
    \ - 2 * depth[lcav];\r\n        if(d > len) return -1;\r\n        return (d <=\
    \ depth[from] - depth[lcav] ? la(from, d) : la(to, len - d));\r\n    }\r\n   \
    \ int dist(int u, int v){\r\n        int lcav = lca(u, v);\r\n        return depth[u]\
    \ + depth[v] - 2 * depth[lcav];\r\n    }\r\n    bool on_path(int from, int to,\
    \ int mid){\r\n        return dist(from, mid) + dist(mid, to) == dist(from, to);\r\
    \n    }\r\n    int Auxiliary_Tree(std::vector<int> &ver){\r\n        int ret =\
    \ 0, m = ver.size();\r\n        std::sort(ver.begin(), ver.end(), [&](int va,\
    \ int vb) {return id[va] < id[vb];});\r\n        for(int i = 0; i < m; i++){\r\
    \n            ret += depth[ver[i]];\r\n            ret -= depth[lca(ver[i], ver[i\
    \ + 1 == m ? 0 : i + 1])];\r\n        }\r\n        return ret;\r\n    }\r\n};\r\
    \n#line 5 \"Test/Library Checker/Tree/lca_doubling.test.cpp\"\n\r\nusing namespace\
    \ std;\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\
    \n    int N, Q, v, u;\r\n    cin >> N >> Q;\r\n    vector<vector<int>> G(N);\r\
    \n    for(int i = 1; i < N; i++){\r\n        cin >> v;\r\n        G[v].emplace_back(i);\r\
    \n        G[i].emplace_back(v);\r\n    }\r\n    LCA_tree g(G);\r\n    while(Q--){\r\
    \n        cin >> u >> v;\r\n        cout << g.lca(u, v) << '\\n';\r\n    }\r\n\
    }\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include <bits/stdc++.h>\r\
    \n#include \"Tree/lca_doubling.hpp\"\r\n\r\nusing namespace std;\r\n\r\nint main(){\r\
    \n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\n    int N, Q, v, u;\r\
    \n    cin >> N >> Q;\r\n    vector<vector<int>> G(N);\r\n    for(int i = 1; i\
    \ < N; i++){\r\n        cin >> v;\r\n        G[v].emplace_back(i);\r\n       \
    \ G[i].emplace_back(v);\r\n    }\r\n    LCA_tree g(G);\r\n    while(Q--){\r\n\
    \        cin >> u >> v;\r\n        cout << g.lca(u, v) << '\\n';\r\n    }\r\n\
    }\r\n"
  dependsOn:
  - Tree/lca_doubling.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/lca_doubling.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 10:56:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/lca_doubling.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/lca_doubling.test.cpp
- /verify/Test/Library Checker/Tree/lca_doubling.test.cpp.html
title: Test/Library Checker/Tree/lca_doubling.test.cpp
---
