---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dsu_03_rollback.hpp
    title: "Rollback\u4ED8\u304DUnion Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\n\
    \r\n#include <bits/stdc++.h>\r\n#line 1 \"Graph/dsu_03_rollback.hpp\"\nstruct\
    \ rollback_dsu {\r\n    public:\r\n    rollback_dsu() : _n(0) {}\r\n    rollback_dsu(int\
    \ n) : _n(n), num_component(n), parent_or_size(n, -1) {}\r\n\r\n    int merge(int\
    \ a, int b) {\r\n        assert(0 <= a && a < _n);\r\n        assert(0 <= b &&\
    \ b < _n);\r\n        int x = leader(a), y = leader(b);\r\n        if (x == y)\
    \ {\r\n            history.emplace_back(-1, -1);\r\n            return x;\r\n\
    \        }\r\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\r\n        history.emplace_back(y, parent_or_size[y]);\r\n        parent_or_size[x]\
    \ += parent_or_size[y];\r\n        parent_or_size[y] = x;\r\n        num_component--;\r\
    \n        return x;\r\n    }\r\n\r\n    bool same(int a, int b) {\r\n        assert(0\
    \ <= a && a < _n);\r\n        assert(0 <= b && b < _n);\r\n        return leader(a)\
    \ == leader(b);\r\n    }\r\n\r\n    int leader(int a) {\r\n        assert(0 <=\
    \ a && a < _n);\r\n        while(parent_or_size[a] >= 0) a = parent_or_size[a];\r\
    \n        return a;\r\n    }\r\n\r\n    int size() { \r\n        return num_component;\r\
    \n    }\r\n\r\n    int size(int a) {\r\n        assert(0 <= a && a < _n);\r\n\
    \        return -parent_or_size[leader(a)];\r\n    }\r\n\r\n    void undo(){\r\
    \n        if(history.empty()) return;\r\n        int v, sz, par;\r\n        std::tie(v,\
    \ sz) = history.back();\r\n        history.pop_back();\r\n        if(v == -1)\
    \ return;\r\n        par = parent_or_size[v];\r\n        parent_or_size[v] = sz;\r\
    \n        parent_or_size[par] -= sz;\r\n        num_component++;\r\n    }\r\n\r\
    \n    void rollback(int cnt = -1){\r\n        if(cnt == -1) cnt = history.size();\r\
    \n        while(cnt--) undo();\r\n    }\r\n\r\n    std::vector<std::vector<int>>\
    \ groups() {\r\n        std::vector<int> leader_buf(_n), group_size(_n);\r\n \
    \       for (int i = 0; i < _n; i++) {\r\n            leader_buf[i] = leader(i);\r\
    \n            group_size[leader_buf[i]]++;\r\n        }\r\n        std::vector<std::vector<int>>\
    \ result(_n);\r\n        for (int i = 0; i < _n; i++) {\r\n            result[i].reserve(group_size[i]);\r\
    \n        }\r\n        for (int i = 0; i < _n; i++) {\r\n            result[leader_buf[i]].push_back(i);\r\
    \n        }\r\n        result.erase(\r\n            std::remove_if(result.begin(),\
    \ result.end(),\r\n                           [&](const std::vector<int>& v) {\
    \ return v.empty(); }),\r\n            result.end());\r\n        return result;\r\
    \n    }\r\n\r\n    private:\r\n    int _n, num_component;\r\n    // root node:\
    \ -1 * component size\r\n    // otherwise: parent\r\n    std::vector<int> parent_or_size;\r\
    \n    std::vector<std::pair<int,int>> history;\r\n};\n#line 5 \"Test/Library Checker/Data\
    \ Structure/persistent_unionfind_rollbackuf.test.cpp.cpp\"\nusing namespace std;\r\
    \n\r\n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\
    \n    int N, Q;\r\n    cin >> N >> Q;\r\n    vector<vector<int>> tree(Q + 1);\r\
    \n    vector<pair<int,int>> edge(Q + 1);\r\n    vector<int> ans(Q);\r\n    vector<vector<tuple<int,int,int>>>\
    \ query(Q + 1);\r\n    auto g = tree.begin() + 1;\r\n    auto e = edge.begin()\
    \ + 1;\r\n    auto q = query.begin() + 1;\r\n    for(int i = 0; i < Q; i++){\r\
    \n        int t, k, u, v;\r\n        cin >> t >> k >> u >> v;\r\n        if(t\
    \ == 0){\r\n            g[k].emplace_back(i);\r\n            e[i] = make_pair(u,\
    \ v);\r\n        }else{\r\n            ans[i] |= 2;\r\n            q[k].emplace_back(u,\
    \ v, i);\r\n        }\r\n    }\r\n    rollback_dsu uf(N);\r\n    \r\n    auto\
    \ dfs = [&](auto dfs, int v) -> void {\r\n        uf.merge(e[v].first, e[v].second);\r\
    \n        for(auto &&[x, y, id] : q[v]) ans[id] |= uf.same(x, y);\r\n        for(auto\
    \ &&u : g[v]) dfs(dfs, u);\r\n        uf.undo();\r\n    };\r\n\r\n    dfs(dfs,\
    \ -1);\r\n\r\n    for(auto &&v : ans){\r\n        if(~v & 2) continue;\r\n   \
    \     cout << (v & 1) << '\\n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n\r\n#include <bits/stdc++.h>\r\n#include \"Graph/dsu_03_rollback.hpp\"\r\nusing\
    \ namespace std;\r\n\r\n\r\nint main() {\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q;\r\n    cin >> N >> Q;\r\n    vector<vector<int>>\
    \ tree(Q + 1);\r\n    vector<pair<int,int>> edge(Q + 1);\r\n    vector<int> ans(Q);\r\
    \n    vector<vector<tuple<int,int,int>>> query(Q + 1);\r\n    auto g = tree.begin()\
    \ + 1;\r\n    auto e = edge.begin() + 1;\r\n    auto q = query.begin() + 1;\r\n\
    \    for(int i = 0; i < Q; i++){\r\n        int t, k, u, v;\r\n        cin >>\
    \ t >> k >> u >> v;\r\n        if(t == 0){\r\n            g[k].emplace_back(i);\r\
    \n            e[i] = make_pair(u, v);\r\n        }else{\r\n            ans[i]\
    \ |= 2;\r\n            q[k].emplace_back(u, v, i);\r\n        }\r\n    }\r\n \
    \   rollback_dsu uf(N);\r\n    \r\n    auto dfs = [&](auto dfs, int v) -> void\
    \ {\r\n        uf.merge(e[v].first, e[v].second);\r\n        for(auto &&[x, y,\
    \ id] : q[v]) ans[id] |= uf.same(x, y);\r\n        for(auto &&u : g[v]) dfs(dfs,\
    \ u);\r\n        uf.undo();\r\n    };\r\n\r\n    dfs(dfs, -1);\r\n\r\n    for(auto\
    \ &&v : ans){\r\n        if(~v & 2) continue;\r\n        cout << (v & 1) << '\\\
    n';\r\n    }\r\n}"
  dependsOn:
  - Graph/dsu_03_rollback.hpp
  isVerificationFile: true
  path: Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp
  requiredBy: []
  timestamp: '2024-01-06 20:28:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp
- /verify/Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp.html
title: Test/Library Checker/Data Structure/persistent_unionfind_rollbackuf.test.cpp.cpp
---
