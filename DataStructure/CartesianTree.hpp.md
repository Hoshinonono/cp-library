---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc407/submissions/66142040
  bundledCode: "#line 1 \"DataStructure/CartesianTree.hpp\"\n// https://atcoder.jp/contests/abc407/submissions/66142040\
    \ \u3092\u53C2\u8003\r\ntemplate <class T> struct CartesianTree {\r\n    struct\
    \ Node {\r\n        int l, r;\r\n        Node() : l(-1), r(-1) {}\r\n    };\r\n\
    \    int n, root;\r\n    std::vector<Node> tree;\r\n    const Node& operator[](int\
    \ idx) const { return tree[idx]; }\r\n    Node& operator[](int idx) { return tree[idx];\
    \ }\r\n    CartesianTree() {}\r\n    CartesianTree(const std::vector<T>& a, bool\
    \ _max = true) : n(a.size()), tree(n) {\r\n        std::vector<int> stk;\r\n \
    \       for (int i = 0, pos; i < n; i++) {\r\n            pos = -1;\r\n      \
    \      while (!stk.empty() && !((a[stk.back()] < a[i]) ^ _max)) {\r\n        \
    \        int j = stk.back();\r\n                stk.pop_back();\r\n          \
    \      tree[j].r = pos; \r\n                pos = j;\r\n            }\r\n    \
    \        tree[i].l = pos;\r\n            stk.emplace_back(i);\r\n        }\r\n\
    \        for (int i = 0; i + 1 < (int)stk.size(); i++) {\r\n            tree[stk[i]].r\
    \ = stk[i + 1];\r\n        }\r\n        root = stk[0];\r\n    }\r\n};\n"
  code: "// https://atcoder.jp/contests/abc407/submissions/66142040 \u3092\u53C2\u8003\
    \r\ntemplate <class T> struct CartesianTree {\r\n    struct Node {\r\n       \
    \ int l, r;\r\n        Node() : l(-1), r(-1) {}\r\n    };\r\n    int n, root;\r\
    \n    std::vector<Node> tree;\r\n    const Node& operator[](int idx) const { return\
    \ tree[idx]; }\r\n    Node& operator[](int idx) { return tree[idx]; }\r\n    CartesianTree()\
    \ {}\r\n    CartesianTree(const std::vector<T>& a, bool _max = true) : n(a.size()),\
    \ tree(n) {\r\n        std::vector<int> stk;\r\n        for (int i = 0, pos; i\
    \ < n; i++) {\r\n            pos = -1;\r\n            while (!stk.empty() && !((a[stk.back()]\
    \ < a[i]) ^ _max)) {\r\n                int j = stk.back();\r\n              \
    \  stk.pop_back();\r\n                tree[j].r = pos; \r\n                pos\
    \ = j;\r\n            }\r\n            tree[i].l = pos;\r\n            stk.emplace_back(i);\r\
    \n        }\r\n        for (int i = 0; i + 1 < (int)stk.size(); i++) {\r\n   \
    \         tree[stk[i]].r = stk[i + 1];\r\n        }\r\n        root = stk[0];\r\
    \n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CartesianTree.hpp
  requiredBy: []
  timestamp: '2025-09-09 01:53:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/CartesianTree.hpp
layout: document
title: CartesianTree
---

## 概要
[https://en.wikipedia.org/wiki/Cartesian_tree](Wikipedia)<br>
根は数列全体の最小値または最大値に対応していて、そこから昇順または降順に二分木を構成したデータ構造。

|関数名など|機能|計算量|
|---------|----|-----|
|`CartesianTree(std::vector<int> a, bool max)`| CartesianTreeを構成。| $\text{O}(N)$ |
|`Node []`| 頂点を $v$ とする。<br>-`tree[v].l`:左の子の頂点番号<br>-`tree[v].r`:右の子の頂点番号<br>にアクセスできる。子がいない場合は`-1`が返る。| $\text{O}(1)$ |

