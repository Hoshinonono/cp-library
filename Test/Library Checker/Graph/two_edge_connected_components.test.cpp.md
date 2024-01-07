---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/lowlink_tecc.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (TECC, Two-Edge-Connected\
      \ Components)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"Test/Library Checker/Graph/two_edge_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#line 1 \"Graph/lowlink_tecc.hpp\"\nstruct\
    \ tecc_graph{\r\n    int N;\r\n    bool TECC_flag = false;\r\n    std::vector<std::vector<int>>\
    \ &g;\r\n    std::vector<bool> used;\r\n    std::vector<int> order, low, comp;\r\
    \n    std::vector<std::pair<int,int>> bridge;\r\n    tecc_graph(std::vector<std::vector<int>>\
    \ &G) \r\n            : N(G.size()), g(G), used(N), order(N), low(N), comp(N,\
    \ -1) {\r\n        int timer = 0;\r\n        for(int v = 0; v < N; v++){\r\n \
    \           if(!used[v]) dfs_lowlink(v, -1, timer);\r\n        }\r\n    }\r\n\
    \    int operator[](int p) { \r\n        assert(TECC_flag && 0 <= p && p < N);\r\
    \n        return comp[p]; \r\n    }\r\n    void dfs_lowlink(int v, int par, int\
    \ &timer){\r\n        used[v] = true;\r\n        low[v] = order[v] = timer++;\r\
    \n        bool par_flg = false;\r\n        for(auto &u : g[v]){\r\n          \
    \  if(!used[u]){\r\n                dfs_lowlink(u, v, timer);\r\n            \
    \    low[v] = std::min(low[v], low[u]);\r\n                if(order[v] < low[u])\
    \ bridge.emplace_back(std::minmax(v, u));\r\n                else merge(u, v);\r\
    \n            }else if(u != par || par_flg){\r\n                low[v] = std::min(low[v],\
    \ order[u]);\r\n            }\r\n            if(u == par) par_flg = true;\r\n\
    \        }\r\n    }\r\n    std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>\
    \ tecc(){\r\n        TECC_flag = true;\r\n        std::vector<std::vector<int>>\
    \ Group(N);\r\n        for(int i = 0; i < N; i++){\r\n            if(comp[i] <\
    \ 0) Group[i].reserve(-comp[i]);\r\n        }\r\n        for(int i = 0; i < N;\
    \ i++) Group[leader(i)].push_back(i);\r\n        Group.erase(\r\n            std::remove_if(Group.begin(),\
    \ Group.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            Group.end());\r\n        for(int id = 0;\
    \ id < Group.size(); id++){\r\n            for(auto &&v : Group[id]) comp[v] =\
    \ id;\r\n        }\r\n        std::vector<std::vector<int>> result(Group.size());\r\
    \n        for(auto &&e : bridge){\r\n            int u = comp[e.first], v = comp[e.second];\r\
    \n            result[u].push_back(v);\r\n            result[v].push_back(u);\r\
    \n        }\r\n        return std::make_pair(result, Group);\r\n    }\r\n    private:\r\
    \n    int leader(int v){\r\n        if(comp[v] < 0)return v;\r\n        return\
    \ comp[v] = leader(comp[v]);\r\n    }\r\n    void merge(int u, int v){\r\n   \
    \     int x = leader(u), y = leader(v);\r\n        if(x == y) return;\r\n    \
    \    if (-comp[x] < -comp[y]) std::swap(x, y);\r\n        comp[x] += comp[y];\r\
    \n        comp[y] = x;\r\n    }\r\n};\n#line 5 \"Test/Library Checker/Graph/two_edge_connected_components.test.cpp\"\
    \nusing namespace std;\r\n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int n, m, u, v;\r\n    cin >> n >> m;\r\n    vector<vector<int>>\
    \ g(n);\r\n    while(m--){\r\n        cin >> u >> v;\r\n        g[u].emplace_back(v);\r\
    \n        g[v].emplace_back(u);\r\n    }\r\n    auto ans = tecc_graph(g).tecc().second;\r\
    \n    cout << ans.size() << '\\n';\r\n    for(auto &&G : ans){\r\n        cout\
    \ << G.size();\r\n        for(auto &&v : G) cout << ' ' << v;\r\n        cout\
    \ << '\\n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Graph/lowlink_tecc.hpp\"\r\nusing\
    \ namespace std;\r\n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\n \
    \   cin.tie(0);\r\n    int n, m, u, v;\r\n    cin >> n >> m;\r\n    vector<vector<int>>\
    \ g(n);\r\n    while(m--){\r\n        cin >> u >> v;\r\n        g[u].emplace_back(v);\r\
    \n        g[v].emplace_back(u);\r\n    }\r\n    auto ans = tecc_graph(g).tecc().second;\r\
    \n    cout << ans.size() << '\\n';\r\n    for(auto &&G : ans){\r\n        cout\
    \ << G.size();\r\n        for(auto &&v : G) cout << ' ' << v;\r\n        cout\
    \ << '\\n';\r\n    }\r\n}"
  dependsOn:
  - Graph/lowlink_tecc.hpp
  isVerificationFile: true
  path: Test/Library Checker/Graph/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 02:01:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Graph/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Graph/two_edge_connected_components.test.cpp
- /verify/Test/Library Checker/Graph/two_edge_connected_components.test.cpp.html
title: Test/Library Checker/Graph/two_edge_connected_components.test.cpp
---
