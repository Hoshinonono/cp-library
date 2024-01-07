---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/lowlink.hpp
    title: "LowLink\u95A2\u9023 (\u95A2\u7BC0\u70B9, \u6A4B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
  bundledCode: "#line 1 \"Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\r\n\r\n\
    #include <bits/stdc++.h>\r\n#line 1 \"Graph/lowlink.hpp\"\nstruct lowlink_graph{\r\
    \n    int N;\r\n    std::vector<std::vector<int>>& g;\r\n    std::vector<bool>\
    \ used;\r\n    std::vector<int> order, low, art_point;\r\n    std::vector<std::pair<int,int>>\
    \ bridge;\r\n    lowlink_graph(std::vector<std::vector<int>> &G) \r\n        \
    \    : N(G.size()), g(G), used(N), order(N), low(N) {\r\n        int timer = 0;\r\
    \n        for(int v = 0; v < N; v++){\r\n            if(!used[v]) dfs_lowlink(v,\
    \ -1, timer);\r\n        }\r\n    }\r\n    void dfs_lowlink(int v, int par, int\
    \ &timer){\r\n        used[v] = true;\r\n        low[v] = order[v] = timer++;\r\
    \n        bool is_art_point = false;\r\n        int cnt = 0;\r\n        for(auto\
    \ &u : g[v]){\r\n            if(!used[u]){\r\n                cnt++;\r\n     \
    \           dfs_lowlink(u, v, timer);\r\n                low[v] = std::min(low[v],\
    \ low[u]);\r\n                is_art_point |= ~par && low[u] >= order[v];\r\n\
    \                if(order[v] < low[u]) bridge.emplace_back(std::minmax(v, u));\r\
    \n            }else if(u != par){\r\n                low[v] = std::min(low[v],\
    \ order[u]);\r\n            }\r\n        }\r\n        is_art_point |= par == -1\
    \ && cnt > 1;\r\n        if(is_art_point) art_point.push_back(v);\r\n    }\r\n\
    };\n#line 5 \"Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp\"\nusing namespace std;\r\
    \n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\n\
    \    int n, m, u, v;\r\n    cin >> n >> m;\r\n    vector<vector<int>> g(n);\r\n\
    \    while(m--){\r\n        cin >> u >> v;\r\n        g[u].emplace_back(v);\r\n\
    \        g[v].emplace_back(u);\r\n    }\r\n    auto ans = lowlink_graph(g).bridge;\r\
    \n    sort(ans.begin(), ans.end());\r\n    for(auto &&[u, v] : ans) cout << u\
    \ << ' ' << v << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Graph/lowlink.hpp\"\r\nusing namespace\
    \ std;\r\n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\
    \n    int n, m, u, v;\r\n    cin >> n >> m;\r\n    vector<vector<int>> g(n);\r\
    \n    while(m--){\r\n        cin >> u >> v;\r\n        g[u].emplace_back(v);\r\
    \n        g[v].emplace_back(u);\r\n    }\r\n    auto ans = lowlink_graph(g).bridge;\r\
    \n    sort(ans.begin(), ans.end());\r\n    for(auto &&[u, v] : ans) cout << u\
    \ << ' ' << v << '\\n';\r\n}"
  dependsOn:
  - Graph/lowlink.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 01:03:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp
- /verify/Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp.html
title: Test/Aizu Online Judge/GRL/GRL_3_B.test.cpp
---
