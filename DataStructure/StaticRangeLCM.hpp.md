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
  bundledCode: "#line 1 \"DataStructure/StaticRangeLCM.hpp\"\ntemplate <class mint>\
    \ struct StaticRangeLCM {\r\n    int N, logN, mx;\r\n    std::vector<int> start;\r\
    \n    std::vector<std::pair<int, mint>> dat;\r\n    StaticRangeLCM(std::vector<int>\
    \ &a) : mx(*std::max_element(a.begin(), a.end())) {\r\n        logN = ceil_pow2(a.size());\r\
    \n        N = 1 << logN;\r\n        start.resize(2 * N + 1);\r\n        // \u5404\
    \u6570\u3092\u5272\u308A\u5207\u308B\u6700\u5C0F\u306E\u7D20\u6570\u3092\u4EE3\
    \u5165\r\n        // \u9006\u6570\u3092\u4EE3\u5165\r\n        std::vector<int>\
    \ mn_pr(mx + 1);\r\n        std::vector<mint> inv(mx + 1);\r\n        for(int\
    \ i = 2; i <= mx; i++){\r\n            if(mn_pr[i] != 0) continue;\r\n       \
    \     inv[i] = mint(i).inv();\r\n            for(int j = i; j <= mx; j += i){\r\
    \n                if(mn_pr[j] == 0) mn_pr[j] = i;\r\n            }\r\n       \
    \ }\r\n        std::vector<std::pair<int, std::pair<int,mint>>> point;\r\n   \
    \     std::vector<int> pos(mx + 1, -1);\r\n        std::vector<std::pair<int,\
    \ mint>> lst(2 * N, std::make_pair(-1, 0));\r\n        for(int i = 0; i < (int)(a.size());\
    \ i++){\r\n            if(a[i] == 1) continue;\r\n            int v = a[i], prv\
    \ = -1, tmp = 0;\r\n            for(int j = 0; j <= logN; j++){\r\n          \
    \      int p = (i + N) >> j;\r\n                if(lst[p].first != -1 && lst[p].first\
    \ != i){\r\n                    start[p + 1]++;\r\n                    point.emplace_back(p,\
    \ lst[p]);\r\n                }\r\n                lst[p] = std::make_pair(i,\
    \ a[i]);\r\n            }\r\n            while(v != 1){\r\n                if(mn_pr[v]\
    \ == prv) tmp *= mn_pr[v];\r\n                else tmp = mn_pr[v];\r\n       \
    \         if(pos[tmp] != -1){\r\n                    int lv = pos[tmp] + N;\r\n\
    \                    for(int j = 0; j <= logN; j++){\r\n                     \
    \   int p = lv >> j;\r\n                        if(lst[p].first == i){\r\n   \
    \                         lst[p].second *= inv[mn_pr[tmp]];\r\n              \
    \          }else{\r\n                            start[p + 1]++;\r\n         \
    \                   point.emplace_back(p, lst[p]);\r\n                       \
    \     lst[p] = std::make_pair(i, inv[mn_pr[tmp]]);\r\n                       \
    \ }\r\n                    }\r\n                }\r\n                pos[tmp]\
    \ = i;\r\n                prv = mn_pr[v];\r\n                v /= mn_pr[v];\r\n\
    \            }\r\n        }\r\n        for(int i = 1; i < 2 * N; i++){\r\n   \
    \         if(lst[i].first == -1) continue;\r\n            start[i + 1]++;\r\n\
    \            point.emplace_back(i, lst[i]);\r\n        }\r\n        dat.resize(point.size());\r\
    \n        for(int i = 0; i < 2 * N; i++) start[i + 1] += start[i];\r\n       \
    \ auto cnt = start;\r\n        for(auto &&[u, v] : point) dat[cnt[u]++] = v;\r\
    \n        for(int i = 1; i < 2 * N; i++){\r\n            int L = start[i], R =\
    \ start[i + 1];\r\n            for(int j = L; j + 1 < R; j++){\r\n           \
    \     dat[j + 1].second *= dat[j].second;\r\n            }\r\n        }\r\n  \
    \  }\r\n    mint prod(int l, int r){\r\n        mint mul = 1, div = 1;\r\n   \
    \     int L = l + N, R = r + N;\r\n        while(L < R){\r\n            if(L &\
    \ 1){\r\n                mul *= get(L, r);\r\n                div *= get(L++,\
    \ l);\r\n            }\r\n            if(R & 1){\r\n                mul *= get(--R,\
    \ r);\r\n                div *= get(R, l);\r\n            }\r\n            L >>=\
    \ 1, R >>= 1;\r\n        }\r\n        return mul / div;\r\n    }\r\n    private:\r\
    \n    mint get(int p, int r){\r\n        int ng = start[p] - 1, ok = start[p +\
    \ 1];\r\n        while(ng + 1 < ok){\r\n            int mid = (ok + ng) / 2;\r\
    \n            (dat[mid].first >= r ? ok : ng) = mid;\r\n        }\r\n        return\
    \ ok > start[p] ? dat[ok - 1].second : 1;\r\n    }\r\n    int ceil_pow2(int n)\
    \ {\r\n        int x = 0;\r\n        while ((1U << x) < (unsigned int)(n)) x++;\r\
    \n        return x;\r\n    }\r\n};\r\n"
  code: "template <class mint> struct StaticRangeLCM {\r\n    int N, logN, mx;\r\n\
    \    std::vector<int> start;\r\n    std::vector<std::pair<int, mint>> dat;\r\n\
    \    StaticRangeLCM(std::vector<int> &a) : mx(*std::max_element(a.begin(), a.end()))\
    \ {\r\n        logN = ceil_pow2(a.size());\r\n        N = 1 << logN;\r\n     \
    \   start.resize(2 * N + 1);\r\n        // \u5404\u6570\u3092\u5272\u308A\u5207\
    \u308B\u6700\u5C0F\u306E\u7D20\u6570\u3092\u4EE3\u5165\r\n        // \u9006\u6570\
    \u3092\u4EE3\u5165\r\n        std::vector<int> mn_pr(mx + 1);\r\n        std::vector<mint>\
    \ inv(mx + 1);\r\n        for(int i = 2; i <= mx; i++){\r\n            if(mn_pr[i]\
    \ != 0) continue;\r\n            inv[i] = mint(i).inv();\r\n            for(int\
    \ j = i; j <= mx; j += i){\r\n                if(mn_pr[j] == 0) mn_pr[j] = i;\r\
    \n            }\r\n        }\r\n        std::vector<std::pair<int, std::pair<int,mint>>>\
    \ point;\r\n        std::vector<int> pos(mx + 1, -1);\r\n        std::vector<std::pair<int,\
    \ mint>> lst(2 * N, std::make_pair(-1, 0));\r\n        for(int i = 0; i < (int)(a.size());\
    \ i++){\r\n            if(a[i] == 1) continue;\r\n            int v = a[i], prv\
    \ = -1, tmp = 0;\r\n            for(int j = 0; j <= logN; j++){\r\n          \
    \      int p = (i + N) >> j;\r\n                if(lst[p].first != -1 && lst[p].first\
    \ != i){\r\n                    start[p + 1]++;\r\n                    point.emplace_back(p,\
    \ lst[p]);\r\n                }\r\n                lst[p] = std::make_pair(i,\
    \ a[i]);\r\n            }\r\n            while(v != 1){\r\n                if(mn_pr[v]\
    \ == prv) tmp *= mn_pr[v];\r\n                else tmp = mn_pr[v];\r\n       \
    \         if(pos[tmp] != -1){\r\n                    int lv = pos[tmp] + N;\r\n\
    \                    for(int j = 0; j <= logN; j++){\r\n                     \
    \   int p = lv >> j;\r\n                        if(lst[p].first == i){\r\n   \
    \                         lst[p].second *= inv[mn_pr[tmp]];\r\n              \
    \          }else{\r\n                            start[p + 1]++;\r\n         \
    \                   point.emplace_back(p, lst[p]);\r\n                       \
    \     lst[p] = std::make_pair(i, inv[mn_pr[tmp]]);\r\n                       \
    \ }\r\n                    }\r\n                }\r\n                pos[tmp]\
    \ = i;\r\n                prv = mn_pr[v];\r\n                v /= mn_pr[v];\r\n\
    \            }\r\n        }\r\n        for(int i = 1; i < 2 * N; i++){\r\n   \
    \         if(lst[i].first == -1) continue;\r\n            start[i + 1]++;\r\n\
    \            point.emplace_back(i, lst[i]);\r\n        }\r\n        dat.resize(point.size());\r\
    \n        for(int i = 0; i < 2 * N; i++) start[i + 1] += start[i];\r\n       \
    \ auto cnt = start;\r\n        for(auto &&[u, v] : point) dat[cnt[u]++] = v;\r\
    \n        for(int i = 1; i < 2 * N; i++){\r\n            int L = start[i], R =\
    \ start[i + 1];\r\n            for(int j = L; j + 1 < R; j++){\r\n           \
    \     dat[j + 1].second *= dat[j].second;\r\n            }\r\n        }\r\n  \
    \  }\r\n    mint prod(int l, int r){\r\n        mint mul = 1, div = 1;\r\n   \
    \     int L = l + N, R = r + N;\r\n        while(L < R){\r\n            if(L &\
    \ 1){\r\n                mul *= get(L, r);\r\n                div *= get(L++,\
    \ l);\r\n            }\r\n            if(R & 1){\r\n                mul *= get(--R,\
    \ r);\r\n                div *= get(R, l);\r\n            }\r\n            L >>=\
    \ 1, R >>= 1;\r\n        }\r\n        return mul / div;\r\n    }\r\n    private:\r\
    \n    mint get(int p, int r){\r\n        int ng = start[p] - 1, ok = start[p +\
    \ 1];\r\n        while(ng + 1 < ok){\r\n            int mid = (ok + ng) / 2;\r\
    \n            (dat[mid].first >= r ? ok : ng) = mid;\r\n        }\r\n        return\
    \ ok > start[p] ? dat[ok - 1].second : 1;\r\n    }\r\n    int ceil_pow2(int n)\
    \ {\r\n        int x = 0;\r\n        while ((1U << x) < (unsigned int)(n)) x++;\r\
    \n        return x;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/StaticRangeLCM.hpp
  requiredBy: []
  timestamp: '2025-09-14 18:09:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/StaticRangeLCM.hpp
layout: document
title: StaticRangeLCM
---

## 概要
数列から区間LCMを$\bmod\,p$で取得するデータ構造。<br>
以下の2つが制約となる。
- 更新がないこと
- 与える数列の上限を $M = \max A$ として $\Theta(M \log M)$ が間に合うこと

|関数名など|機能|計算量|
|---------|----|-----|
|`StaticRangeLCM<mint>(std::vector<int> a)`| 初期化。| $\text{O}(N \log N \log M)$ |
|`mint prod(int l, int r)`| $[l, r)$ についてのLCMを求める。| $\text{O}(\log^{2} N)$|