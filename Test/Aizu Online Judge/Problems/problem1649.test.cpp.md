---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dsu.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1649
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1649
  bundledCode: "#line 1 \"Test/Aizu Online Judge/Problems/problem1649.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1649\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#line 1 \"Graph/dsu.hpp\"\nstruct dsu {\n\
    \    public:\n    dsu() : _n(0) {}\n    dsu(int n) : _n(n), num_component(n),\
    \ parent_or_size(n, -1) {}\n\n    int merge(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return x;\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        num_component--;\n        return x;\n\
    \    }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n \
    \       assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n  \
    \  }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n\
    \    }\n\n    int size() { \n        return num_component;\n    }\n\n    int size(int\
    \ a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \    private:\n    int _n, num_component;\n    // root node: -1 * component size\n\
    \    // otherwise: parent\n    std::vector<int> parent_or_size;\n};\n#line 5 \"\
    Test/Aizu Online Judge/Problems/problem1649.test.cpp\"\nusing namespace std;\r\
    \n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\n \
    \   while(true){\r\n        int w, h;\r\n        cin >> w >> h;\r\n        if(w\
    \ == 0) break;\r\n        dsu uf(w + h);\r\n        for(int i = 0; i < w + h -\
    \ 1; i++){\r\n            int x, y, v;\r\n            cin >> x >> y >> v;\r\n\
    \            uf.merge(--x, --y + w);\r\n        }\r\n        cout << (uf.size()\
    \ == 1 ? \"YES\" : \"NO\") << '\\n';\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1649\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Graph/dsu.hpp\"\r\nusing namespace\
    \ std;\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\
    \n    while(true){\r\n        int w, h;\r\n        cin >> w >> h;\r\n        if(w\
    \ == 0) break;\r\n        dsu uf(w + h);\r\n        for(int i = 0; i < w + h -\
    \ 1; i++){\r\n            int x, y, v;\r\n            cin >> x >> y >> v;\r\n\
    \            uf.merge(--x, --y + w);\r\n        }\r\n        cout << (uf.size()\
    \ == 1 ? \"YES\" : \"NO\") << '\\n';\r\n    }\r\n}\r\n"
  dependsOn:
  - Graph/dsu.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/Problems/problem1649.test.cpp
  requiredBy: []
  timestamp: '2024-05-06 18:57:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/Problems/problem1649.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/Problems/problem1649.test.cpp
- /verify/Test/Aizu Online Judge/Problems/problem1649.test.cpp.html
title: Test/Aizu Online Judge/Problems/problem1649.test.cpp
---
