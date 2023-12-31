---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Tree/lca_ufdoubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30C0\
      \u30D6\u30EA\u30F3\u30B0+UF)"
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
  bundledCode: "#line 1 \"Test/Library Checker/Tree/lca_ufdoubling.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include <bits/stdc++.h>\r\
    \n#line 1 \"Tree/lca_ufdoubling.hpp\"\nstruct LCA_tree {\r\n    int n, root;\r\
    \n    std::array<int, 32> log_table{};\r\n    std::vector<std::vector<int>> &g,\
    \ parent;\r\n    std::vector<int> depth, id;\r\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g) : LCA_tree(_g, 0){}\r\n    LCA_tree(std::vector<std::vector<int>> &_g,\
    \ int r)\r\n         : n(_g.size()), g(_g), root(r), depth(n), depth2(n), id(n,\
    \ -1), edge(n),\r\n           parent_or_size(n, -1), parent(5, std::vector<int>(n))\
    \ {\r\n        for(int i = 2; i < 32; i++) log_table[i] = log_table[i >> 1] +\
    \ 1;\r\n        std::vector<int> stk, par(n, -1);\r\n        stk.reserve(n);\r\
    \n        stk.emplace_back(root);\r\n        int cnt = 0, timer = 0;\r\n     \
    \   while(!stk.empty()){\r\n            int v = stk.back();\r\n            if(id[v]\
    \ == -1){\r\n                id[v] = cnt++;\r\n                for(auto &&u :\
    \ g[v]){\r\n                    if(id[u] != -1) continue;\r\n                \
    \    par[u] = v;\r\n                    depth[u] = depth[v] + 1;\r\n         \
    \           stk.emplace_back(u);\r\n                }\r\n            }else{\r\n\
    \                stk.pop_back();\r\n                if(par[v] == -1) break;\r\n\
    \                int x = leader(v), y = leader(par[v]);\r\n                if(-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\r\n                parent_or_size[x]\
    \ += parent_or_size[y];\r\n                parent_or_size[y] = x;\r\n        \
    \        parent[0][y] = x;\r\n                depth2[y] = 1;\r\n             \
    \   edge[y] = std::make_pair(timer++, par[v]);\r\n            }\r\n        }\r\
    \n        for(int i = 1; i < n; i++) leader(i);\r\n        parent[0][leader(0)]\
    \ = -1;\r\n        for(int i = 1; i < 5; i++){\r\n            for(int j = 0; j\
    \ < n; j++){\r\n                parent[i][j] = parent[i - 1][j] == -1 ? -1 : parent[i\
    \ - 1][parent[i - 1][j]];\r\n            }\r\n        }\r\n    }\r\n    int lca(int\
    \ u, int v){\r\n        assert(0 <= u && u < n);\r\n        assert(0 <= v && v\
    \ < n);\r\n        if(u == v) return v;\r\n        if(depth2[u] > depth2[v]) std::swap(u,\
    \ v);\r\n        int d = std::max(0, depth2[v] - depth2[u] - 1);\r\n        while(d){\r\
    \n            v = parent[log_table[d & -d]][v];\r\n            d -= d & -d;\r\n\
    \        }\r\n        if(u == parent[0][v]) return edge[v].second;\r\n       \
    \ if(depth2[u] != depth2[v]) v = parent[0][v];\r\n        for(int i = log_table[depth2[v]];\
    \ i >= 0; i--){\r\n            if(parent[i][u] != parent[i][v]){\r\n         \
    \       u = parent[i][u];\r\n                v = parent[i][v];\r\n           \
    \ }\r\n        }\r\n        if(edge[v].first > edge[u].first) return edge[v].second;\r\
    \n        return edge[u].second;\r\n    }\r\n    int dist(int u, int v){\r\n \
    \       int lcav = lca(u, v);\r\n        return depth[u] + depth[v] - 2 * depth[lcav];\r\
    \n    }\r\n    bool on_path(int from, int to, int mid){\r\n        return dist(from,\
    \ mid) + dist(mid, to) == dist(from, to);\r\n    }\r\n    int Auxiliary_Tree(std::vector<int>\
    \ &ver){\r\n        int ret = 0, m = ver.size();\r\n        std::sort(ver.begin(),\
    \ ver.end(), [&](int va, int vb) {return id[va] < id[vb];});\r\n        for(int\
    \ i = 0; i < m; i++){\r\n            ret += depth[ver[i]];\r\n            ret\
    \ -= depth[lca(ver[i], ver[i + 1 == m ? 0 : i + 1])];\r\n        }\r\n       \
    \ return ret;\r\n    }\r\n    private:\r\n    std::vector<int> parent_or_size,\
    \ depth2;\r\n    std::vector<std::pair<int,int>> edge;\r\n    int leader(int v){\r\
    \n        if(parent_or_size[v] < 0) return v;\r\n        int root = leader(parent_or_size[v]);\r\
    \n        depth2[v] += depth2[parent_or_size[v]];\r\n        return parent_or_size[v]\
    \ = root;\r\n    }\r\n};\r\n#line 5 \"Test/Library Checker/Tree/lca_ufdoubling.test.cpp\"\
    \n\r\nusing namespace std;\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q, v, u;\r\n    cin >> N >> Q;\r\n    vector<vector<int>>\
    \ G(N);\r\n    for(int i = 1; i < N; i++){\r\n        cin >> v;\r\n        G[v].emplace_back(i);\r\
    \n        G[i].emplace_back(v);\r\n    }\r\n    LCA_tree g(G);\r\n    while(Q--){\r\
    \n        cin >> u >> v;\r\n        cout << g.lca(u, v) << '\\n';\r\n    }\r\n\
    }\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include <bits/stdc++.h>\r\
    \n#include \"Tree/lca_ufdoubling.hpp\"\r\n\r\nusing namespace std;\r\n\r\nint\
    \ main(){\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\n    int N,\
    \ Q, v, u;\r\n    cin >> N >> Q;\r\n    vector<vector<int>> G(N);\r\n    for(int\
    \ i = 1; i < N; i++){\r\n        cin >> v;\r\n        G[v].emplace_back(i);\r\n\
    \        G[i].emplace_back(v);\r\n    }\r\n    LCA_tree g(G);\r\n    while(Q--){\r\
    \n        cin >> u >> v;\r\n        cout << g.lca(u, v) << '\\n';\r\n    }\r\n\
    }\r\n"
  dependsOn:
  - Tree/lca_ufdoubling.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/lca_ufdoubling.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 10:56:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/lca_ufdoubling.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/lca_ufdoubling.test.cpp
- /verify/Test/Library Checker/Tree/lca_ufdoubling.test.cpp.html
title: Test/Library Checker/Tree/lca_ufdoubling.test.cpp
---
