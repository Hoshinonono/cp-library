---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Graph/dsu_weighted.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Graph/dsu_weighted.hpp\"\r\n\r\n\
    int main() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(false);\r\
    \n    int n, q;\r\n    std::cin >> n >> q;\r\n    Weighted_dsu uf(n);\r\n    while(q--){\r\
    \n        int cmd, u, v, d;\r\n        std::cin >> cmd >> u >> v;\r\n        if(cmd\
    \ == 0) {\r\n            std::cin >> d;\r\n            uf.merge(u, v, d);\r\n\
    \        } else {\r\n            if(!uf.same(u, v)){\r\n                std::cout\
    \ << '?' << '\\n';\r\n                continue;\r\n            }\r\n         \
    \   std::cout << uf.diff(u, v) << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
- /verify/Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp.html
title: Test/Aizu Online Judge/DSL/DSL_1_B.test.cpp
---
