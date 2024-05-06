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
  bundledCode: "#line 1 \"DataStructure/AdjacentDiffSet.hpp\"\nstruct Adjacent_Diff_Set\
    \ {\r\n    const long long inf = 1ll << 60;\r\n    std::multiset<long long> S,\
    \ D;\r\n    Adjacent_Diff_Set(){\r\n        S.insert(-inf);\r\n        S.insert(inf);\r\
    \n    }\r\n    void add(long long v){\r\n        auto ba_itr = S.lower_bound(v);\r\
    \n        auto fr_itr = std::prev(ba_itr);\r\n        if(*ba_itr != inf && *fr_itr\
    \ != -inf){\r\n            D.erase(D.find(*ba_itr - *fr_itr));\r\n        }\r\n\
    \        if(*ba_itr != inf) D.insert(*ba_itr - v);\r\n        if(*fr_itr != -inf)\
    \ D.insert(v - *fr_itr);\r\n        S.insert(v);\r\n    }\r\n    void del(long\
    \ long v){\r\n        auto it = S.lower_bound(v);\r\n        auto ba_itr = std::next(it);\r\
    \n        auto fr_itr = std::prev(it);\r\n        if(*ba_itr != inf) D.erase(D.find(*ba_itr\
    \ - v));\r\n        if(*fr_itr != -inf) D.erase(D.find(v - *fr_itr));\r\n    \
    \    if(*ba_itr != inf && *fr_itr != -inf){\r\n            D.insert(*ba_itr -\
    \ *fr_itr);\r\n        }\r\n        S.erase(it);\r\n    }\r\n    long long max(){\
    \ return *std::next(S.rbegin()); }\r\n    long long min(){ return *std::next(S.begin());\
    \ }\r\n    long long max_diff(){ return D.empty() ? 0 : *D.rbegin(); }\r\n   \
    \ long long min_diff(){ return D.empty() ? 0 : *D.begin(); }\r\n};\n"
  code: "struct Adjacent_Diff_Set {\r\n    const long long inf = 1ll << 60;\r\n  \
    \  std::multiset<long long> S, D;\r\n    Adjacent_Diff_Set(){\r\n        S.insert(-inf);\r\
    \n        S.insert(inf);\r\n    }\r\n    void add(long long v){\r\n        auto\
    \ ba_itr = S.lower_bound(v);\r\n        auto fr_itr = std::prev(ba_itr);\r\n \
    \       if(*ba_itr != inf && *fr_itr != -inf){\r\n            D.erase(D.find(*ba_itr\
    \ - *fr_itr));\r\n        }\r\n        if(*ba_itr != inf) D.insert(*ba_itr - v);\r\
    \n        if(*fr_itr != -inf) D.insert(v - *fr_itr);\r\n        S.insert(v);\r\
    \n    }\r\n    void del(long long v){\r\n        auto it = S.lower_bound(v);\r\
    \n        auto ba_itr = std::next(it);\r\n        auto fr_itr = std::prev(it);\r\
    \n        if(*ba_itr != inf) D.erase(D.find(*ba_itr - v));\r\n        if(*fr_itr\
    \ != -inf) D.erase(D.find(v - *fr_itr));\r\n        if(*ba_itr != inf && *fr_itr\
    \ != -inf){\r\n            D.insert(*ba_itr - *fr_itr);\r\n        }\r\n     \
    \   S.erase(it);\r\n    }\r\n    long long max(){ return *std::next(S.rbegin());\
    \ }\r\n    long long min(){ return *std::next(S.begin()); }\r\n    long long max_diff(){\
    \ return D.empty() ? 0 : *D.rbegin(); }\r\n    long long min_diff(){ return D.empty()\
    \ ? 0 : *D.begin(); }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/AdjacentDiffSet.hpp
  requiredBy: []
  timestamp: '2024-05-06 12:56:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/AdjacentDiffSet.hpp
layout: document
title: "\u96A3\u63A5\u5DEE\u96C6\u5408"
---

## 概要
追加した要素からなる集合をソートした際に隣接差の最大値、最小値を得るためのライブラリ。<br>
ここらへんの問題殴る用のライブラリ。
<ul>
    <li><a href="https://atcoder.jp/contests/abc308/tasks/abc308_g">
AtCoder Beginner Contest 308「G - Minimum Xor Pair Query」</a></li>
    <li><a href="https://codeforces.com/contest/1862/problem/G">
Codeforces Round 894 (Div. 3)「G. The Great Equalizer」</a></li>
</ul>

|関数名など|機能|計算量|
|---------|----|-----|
|`Adjacent_Diff_Set`| 空集合を作成。要素の集合には番兵が入れられる。| $\text{O}(1)$ |
|`void add(long long v)`| 要素 $v$ を追加する。| $\text{O}(\log N)$ |
|`void del(long long v)`| 要素 $v$ を削除する。| $\text{O}(\log N)$ |
|`long long max()`| 加えられた要素の最大値を取得。 | $\text{O}(\log N)$ |
|`long long min()`| 加えられた要素の最小値を取得。 | $\text{O}(\log N)$ |
|`long long max_diff()`| 加えられた要素をソートしたときの隣接差の最大値を取得。<br> 要素数が2未満の場合は `0` を返す。 | $\text{O}(\log N)$ |
|`long long min_diff()`| 加えられた要素をソートしたときの隣接差の最小値を取得。<br> 要素数が2未満の場合は `0` を返す。  | $\text{O}(\log N)$ |
