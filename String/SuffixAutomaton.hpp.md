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
  bundledCode: "#line 2 \"String/SuffixAutomaton.hpp\"\n#include <array>\n#include\
    \ <vector>\n\nstruct SuffixAutomaton {\n    struct Node {\n        int link, len;\n\
    \        std::array<int, 26> next;\n        Node() : link(-1), len(0) { next.fill(-1);\
    \ }\n        int& operator[](int p){ return next[p]; }\n    };\n\n    std::vector<Node>\
    \ nodes;\n    int last;\n\n    SuffixAutomaton() { nodes.emplace_back(Node());\
    \ last = 0; }\n    Node& operator[](int p){ return nodes[p]; }\n    int size(){\
    \ return nodes.size(); }\n    void extend(char c) {\n        int cv = c - 'a';\n\
    \        int cur = nodes.size();\n        nodes.emplace_back(Node());\n      \
    \  nodes[cur].len = nodes[last].len + 1;\n        int p = last;\n        while\
    \ (p != -1 && nodes[p][cv] == -1) {\n            nodes[p][cv] = cur;\n       \
    \     p = nodes[p].link;\n        }\n        if (p == -1) {\n            nodes[cur].link\
    \ = 0;\n        } else {\n            int q = nodes[p][cv];\n            if (nodes[p].len\
    \ + 1 == nodes[q].len) {\n                nodes[cur].link = q;\n            }\
    \ else {\n                int clone = nodes.size();\n                nodes.push_back(nodes[q]);\n\
    \                nodes[clone].len = nodes[p].len + 1;\n                while (p\
    \ != -1 && nodes[p][cv] == q) {\n                    nodes[p][cv] = clone;\n \
    \                   p = nodes[p].link;\n                }\n                nodes[q].link\
    \ = nodes[cur].link = clone;\n            }\n        }\n        last = cur;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n\nstruct SuffixAutomaton\
    \ {\n    struct Node {\n        int link, len;\n        std::array<int, 26> next;\n\
    \        Node() : link(-1), len(0) { next.fill(-1); }\n        int& operator[](int\
    \ p){ return next[p]; }\n    };\n\n    std::vector<Node> nodes;\n    int last;\n\
    \n    SuffixAutomaton() { nodes.emplace_back(Node()); last = 0; }\n    Node& operator[](int\
    \ p){ return nodes[p]; }\n    int size(){ return nodes.size(); }\n    void extend(char\
    \ c) {\n        int cv = c - 'a';\n        int cur = nodes.size();\n        nodes.emplace_back(Node());\n\
    \        nodes[cur].len = nodes[last].len + 1;\n        int p = last;\n      \
    \  while (p != -1 && nodes[p][cv] == -1) {\n            nodes[p][cv] = cur;\n\
    \            p = nodes[p].link;\n        }\n        if (p == -1) {\n         \
    \   nodes[cur].link = 0;\n        } else {\n            int q = nodes[p][cv];\n\
    \            if (nodes[p].len + 1 == nodes[q].len) {\n                nodes[cur].link\
    \ = q;\n            } else {\n                int clone = nodes.size();\n    \
    \            nodes.push_back(nodes[q]);\n                nodes[clone].len = nodes[p].len\
    \ + 1;\n                while (p != -1 && nodes[p][cv] == q) {\n             \
    \       nodes[p][cv] = clone;\n                    p = nodes[p].link;\n      \
    \          }\n                nodes[q].link = nodes[cur].link = clone;\n     \
    \       }\n        }\n        last = cur;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixAutomaton.hpp
  requiredBy: []
  timestamp: '2025-11-23 08:42:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/SuffixAutomaton.hpp
layout: document
title: SuffixAutomaton
---

## 概要

文字列 $s$ を与えた時に、 $s$ に含まれる部分文字列であるかを判定できる。<br>
[Suffix Automaton (よすぽの日記)](https://yosupo.hatenablog.com/entry/2021/01/31/160215)を参考。

出題例<br>
[AtCoder Beginner Contest 433 G - Substring Game](https://atcoder.jp/contests/abc433/tasks/abc433_g)
