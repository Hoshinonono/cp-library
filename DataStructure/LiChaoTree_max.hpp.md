---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/LiChaoTree_max.hpp\"\nclass LiChaoTree{\r\n\
    \    struct Line{\r\n        long long a, b;\r\n        long long get(long long\
    \ x){return a * x + b; }\r\n        Line(long long a, long long b) : a(a), b(b)\
    \ {}\r\n    };\r\n    struct Node {\r\n        Node *left, *right;\r\n       \
    \ Line line;\r\n        Node(Line line) : left(nullptr), right(nullptr), line(line)\
    \ {}\r\n    };\r\n    const long long inf = (1ll << 60);\r\n    const Line inf_line\
    \ = Line{0, -inf};\r\n\r\n    Node *root;\r\n    long long lx, rx;\r\n    Node*\
    \ _add_line(Node *nd, Line line, long long l, long long r){\r\n        if(l ==\
    \ r) return nullptr;\r\n        if(nd == nullptr) return new Node(line);\r\n \
    \       long long m = (l + r) >> 1;\r\n\r\n        bool left = (line.get(l) >=\
    \ nd->line.get(l));\r\n        bool mid = (line.get(m) >= nd->line.get(m));\r\n\
    \        bool right = (line.get(r) >= nd->line.get(r));\r\n        if(left &&\
    \ right)nd->line = line;\r\n        if(left == right)return nd;\r\n        if(mid)\
    \ std::swap(nd->line, line);\r\n        if(left != mid){\r\n            nd->left\
    \ = _add_line(nd->left, line, l, m);\r\n        }else{\r\n            nd->right\
    \ = _add_line(nd->right, line, m, r);\r\n        }\r\n        return nd;\r\n \
    \   }\r\n    Node* _add_segment_line(long long a, long long b, Node *nd, Line\
    \ line, long long l, long long r) {\r\n        if(r <= a || b <= l) return nd;\r\
    \n        if(a <= l && r <= b) return _add_line(nd, line, l, r);\r\n        if(nd\
    \ == nullptr) nd = new Node(inf_line);\r\n        long long m = (l + r) >> 1;\r\
    \n        nd->left = _add_segment_line(a, b, nd->left, line, l, m);\r\n      \
    \  nd->right = _add_segment_line(a, b, nd->right, line, m, r);\r\n        return\
    \ nd;\r\n    }\r\n    long long query(long long x, long long l, long long r){\r\
    \n        Node *nd = root;\r\n        long long res = -inf;\r\n        while(r\
    \ > l && nd != nullptr) {\r\n            long long m = (l + r) >> 1;\r\n     \
    \       res = std::max(res, nd->line.get(x));\r\n            if(x < m) {\r\n \
    \               r = m;\r\n                nd = nd->left;\r\n            } else\
    \ {\r\n                l = m;\r\n                nd = nd->right;\r\n         \
    \   }\r\n        }\r\n        return res;\r\n    }\r\n    public:\r\n    LiChaoTree(long\
    \ long lx, long long rx) : lx(lx), rx(rx), root(nullptr) {}\r\n    void add_line(long\
    \ long a, long long b) {\r\n        Line line(a, b);\r\n        root = _add_line(root,\
    \ line, lx, rx);\r\n    }\r\n    void add_segment_line(long long a, long long\
    \ b, long long l, long long r) {\r\n        Line line = Line{a, b};\r\n      \
    \  root = _add_segment_line(l, r, root, line, lx, rx);\r\n    }\r\n    long long\
    \ get(long long x) {\r\n        return query(x, lx, rx);\r\n    }\r\n};\n"
  code: "class LiChaoTree{\r\n    struct Line{\r\n        long long a, b;\r\n    \
    \    long long get(long long x){return a * x + b; }\r\n        Line(long long\
    \ a, long long b) : a(a), b(b) {}\r\n    };\r\n    struct Node {\r\n        Node\
    \ *left, *right;\r\n        Line line;\r\n        Node(Line line) : left(nullptr),\
    \ right(nullptr), line(line) {}\r\n    };\r\n    const long long inf = (1ll <<\
    \ 60);\r\n    const Line inf_line = Line{0, -inf};\r\n\r\n    Node *root;\r\n\
    \    long long lx, rx;\r\n    Node* _add_line(Node *nd, Line line, long long l,\
    \ long long r){\r\n        if(l == r) return nullptr;\r\n        if(nd == nullptr)\
    \ return new Node(line);\r\n        long long m = (l + r) >> 1;\r\n\r\n      \
    \  bool left = (line.get(l) >= nd->line.get(l));\r\n        bool mid = (line.get(m)\
    \ >= nd->line.get(m));\r\n        bool right = (line.get(r) >= nd->line.get(r));\r\
    \n        if(left && right)nd->line = line;\r\n        if(left == right)return\
    \ nd;\r\n        if(mid) std::swap(nd->line, line);\r\n        if(left != mid){\r\
    \n            nd->left = _add_line(nd->left, line, l, m);\r\n        }else{\r\n\
    \            nd->right = _add_line(nd->right, line, m, r);\r\n        }\r\n  \
    \      return nd;\r\n    }\r\n    Node* _add_segment_line(long long a, long long\
    \ b, Node *nd, Line line, long long l, long long r) {\r\n        if(r <= a ||\
    \ b <= l) return nd;\r\n        if(a <= l && r <= b) return _add_line(nd, line,\
    \ l, r);\r\n        if(nd == nullptr) nd = new Node(inf_line);\r\n        long\
    \ long m = (l + r) >> 1;\r\n        nd->left = _add_segment_line(a, b, nd->left,\
    \ line, l, m);\r\n        nd->right = _add_segment_line(a, b, nd->right, line,\
    \ m, r);\r\n        return nd;\r\n    }\r\n    long long query(long long x, long\
    \ long l, long long r){\r\n        Node *nd = root;\r\n        long long res =\
    \ -inf;\r\n        while(r > l && nd != nullptr) {\r\n            long long m\
    \ = (l + r) >> 1;\r\n            res = std::max(res, nd->line.get(x));\r\n   \
    \         if(x < m) {\r\n                r = m;\r\n                nd = nd->left;\r\
    \n            } else {\r\n                l = m;\r\n                nd = nd->right;\r\
    \n            }\r\n        }\r\n        return res;\r\n    }\r\n    public:\r\n\
    \    LiChaoTree(long long lx, long long rx) : lx(lx), rx(rx), root(nullptr) {}\r\
    \n    void add_line(long long a, long long b) {\r\n        Line line(a, b);\r\n\
    \        root = _add_line(root, line, lx, rx);\r\n    }\r\n    void add_segment_line(long\
    \ long a, long long b, long long l, long long r) {\r\n        Line line = Line{a,\
    \ b};\r\n        root = _add_segment_line(l, r, root, line, lx, rx);\r\n    }\r\
    \n    long long get(long long x) {\r\n        return query(x, lx, rx);\r\n   \
    \ }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LiChaoTree_max.hpp
  requiredBy: []
  timestamp: '2024-05-18 16:13:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/LiChaoTree_max.hpp
layout: document
title: "LiChaoTree (\u6700\u5927\u5024\u53D6\u5F97)"
---

## 概要
LiChaoTree は $ax + b$ の直線または線分を使いし、決まった1点での最小値、最大値を取得できるデータ構造。

|関数名など|機能|計算量|
|---------|----|-----|
|`LiChaoTree(long long L, long long R)`| LiChaoTree の定義域を $[Lx, Rx)$ とする。| $\text{O}(1)$ |
|`void add_line(long long a, long long b)`| $ax + b$ の直線を追加する。| $\text{O}(\log N)$|
|`void add_segment_line(long long a, `<br>`long long b, long long l, long long r)`| $[Lx, Rx)$ の範囲に$ax + b$ の直線を追加する。 | $\text{O}(\log^{2} N)$ |
|`void get(x)`| $x$ での最大値を取得する。| $\text{O}(\log N)$|