---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree_dual.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Tree/hld.hpp
    title: "HL\u5206\u89E3 (HLD, Heavy-Light-Decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\r\
    \n\r\n#include <bits/stdc++.h>\r\n#line 1 \"Tree/hld.hpp\"\nstruct Heavy_Light_Decomposition{\n\
    \    int N, tim = 0;\n    std::vector<int> sz, ent, leader, order, par;\n    std::vector<std::vector<int>>\
    \ &G;\n    Heavy_Light_Decomposition(std::vector<std::vector<int>> &g) : \n  \
    \          N(g.size()), G(g), sz(N), ent(N), leader(N), order(N), par(N) {\n \
    \       dfs_size(0, -1);\n        dfs_hld(0);\n    }\n    const int operator[](int\
    \ v) const {\n        assert(0 <= v && v < N);\n        return ent[v];\n    }\n\
    \    int operator[](int v) { \n        assert(0 <= v && v < N);\n        return\
    \ ent[v];\n    }\n    int la(int v, int k) {\n        while(true) {\n        \
    \    int u = leader[v];\n            if(ent[v] - k >= ent[u]) return order[ent[v]\
    \ - k];\n            k -= ent[v] - ent[u] + 1;\n            v = par[u];\n    \
    \    }\n    }\n    int la(int from, int to, int d){\n        int d1 = 0, d2 =\
    \ 0;\n        int v = from, u = to;\n        do{\n            if(ent[u] < ent[v]){\n\
    \                if(leader[u] == leader[v]){\n                    d1 += ent[v]\
    \ - ent[u];\n                    break;\n                }\n                d1\
    \ += ent[v] - ent[leader[v]] + 1;\n                v = par[leader[v]];\n     \
    \       }else{\n                if(leader[u] == leader[v]){\n                \
    \    d2 += ent[u] - ent[v];\n                    break;\n                }\n \
    \               d2 += ent[u] - ent[leader[u]] + 1;\n                u = par[leader[u]];\n\
    \            }\n        }while(true);\n        if(d > d1 + d2) return -1;\n  \
    \      return d <= d1 ? la(from, d) : la(to, d1 + d2 - d);\n    }\n    int lca(int\
    \ u, int v) {\n        do{\n            if(ent[u] > ent[v]) std::swap(u, v);\n\
    \            if(leader[u] == leader[v]) return u;\n            v = par[leader[v]];\n\
    \        }while(true);\n    }\n    int dist(int u, int v){\n        int ans =\
    \ 0;\n        do{\n            if(ent[u] > ent[v]) std::swap(u, v);\n        \
    \    if(leader[u] == leader[v]) return ans + ent[v] - ent[u];\n            ans\
    \ += ent[v] - ent[leader[v]] + 1;\n            v = par[leader[v]];\n        }while(true);\n\
    \    }\n    template< typename T, typename Q, typename F >\n    T query(int u,\
    \ int v, const T &identity, const Q &qf, const F &f, bool edge = false) {\n  \
    \      T ans = identity;\n        do{\n            if(ent[u] > ent[v]) std::swap(u,\
    \ v);\n            if(leader[u] == leader[v]) break;\n            ans = f( qf(ent[leader[v]],\
    \ ent[v] + 1), ans);\n            v = par[leader[v]];\n        }while(true);\n\
    \        return f( qf(ent[u] + edge, ent[v] + 1), ans);\n    }\n    template<\
    \ typename T, typename Q1, typename Q2, typename F >\n    T noncom_query(int u,\
    \ int v, const T &identity, \n                   const Q1 &qf, const Q2 &rev_qf,\
    \ const F &f, bool edge = false) {\n        T sml = identity, smr = identity;\n\
    \        do{\n            if(leader[u] == leader[v]) break;\n            if(ent[u]\
    \ < ent[v]){\n                smr = f( qf(ent[leader[v]], ent[v] + 1), smr);\n\
    \                v = par[leader[v]];\n            }else{\n                sml\
    \ = f( sml, rev_qf(ent[leader[u]], ent[u] + 1));\n                u = par[leader[u]];\n\
    \            }\n        }while(true);\n        if(ent[u] < ent[v]){\n        \
    \    return f(sml,  f( qf(ent[u] + edge, ent[v] + 1), smr));\n        }else{\n\
    \            return f(f(sml, rev_qf(ent[v] + edge, ent[u] + 1)), smr);\n     \
    \   }\n    }\n    template< typename Q >\n    void update(int u, int v, const\
    \ Q &q, bool edge = false) {\n        do{\n            if(ent[u] > ent[v]) std::swap(u,\
    \ v);\n            if(leader[u] == leader[v]) break;\n            q(ent[leader[v]],\
    \ ent[v] + 1);\n            v = par[leader[v]];\n        }while(true);\n     \
    \   q(ent[u] + edge, ent[v] + 1);\n    }\n    private:\n    void dfs_size(int\
    \ v, int p){\n        par[v] = p;\n        sz[v] = 1;\n        if(!G[v].empty()\
    \ && G[v][0] == p) std::swap(G[v][0], G[v].back());\n        for(auto &u : G[v]){\n\
    \            if(u == p) continue;\n            dfs_size(u, v);\n            sz[v]\
    \ += sz[u];\n            if(sz[u] > sz[G[v][0]]) std::swap(G[v][0], u);\n    \
    \    }\n    }\n    void dfs_hld(int v){\n        ent[v] = tim++;\n        order[ent[v]]\
    \ = v;\n        for(auto &u : G[v]) {\n            if(u == par[v]) continue;\n\
    \            leader[u] = (G[v][0] == u ? leader[v] : u);\n            dfs_hld(u);\n\
    \        }\n    }\n};\n#line 1 \"DataStructure/segtree_dual.hpp\"\ntemplate <class\
    \ S, S (*mapping)(S, S), S (*id)()> struct dual_segtree {\r\n    public:\r\n \
    \   dual_segtree() : dual_segtree(0) {}\r\n    dual_segtree(int n) : dual_segtree(std::vector<S>(n,\
    \ id())) {}\r\n    dual_segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\
    \n        log = ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2\
    \ * size, id());\r\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\r\
    \n    }\r\n    const S& operator[](int p) const {\r\n        assert(0 <= p &&\
    \ p < _n);\r\n        p += size;\r\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\r\n        return d[p];\r\n    }\r\n    S& operator[](int p) { \r\n \
    \       assert(0 <= p && p < _n);\r\n        p += size;\r\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\r\n        return d[p];\r\n    }\r\n    void\
    \ apply(int p, S f) {\r\n        assert(0 <= p && p < _n);\r\n        p += size;\r\
    \n        for (int i = log; i >= 1; i--) push(p >> i);\r\n        d[p] = mapping(f,\
    \ d[p]);\r\n    }\r\n    void apply(int l, int r, S f) {\r\n        assert(0 <=\
    \ l && l <= r && r <= _n);\r\n        if (l == r) return;\r\n        l += size;\r\
    \n        r += size;\r\n        for (int i = log; i >= 1; i--) {\r\n         \
    \   if (((l >> i) << i) != l) push(l >> i);\r\n            if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\r\n        }\r\n        while (l < r) {\r\n      \
    \      if (l & 1) all_apply(l++, f);\r\n            if (r & 1) all_apply(--r,\
    \ f);\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n    }\r\n\
    \    private:\r\n    int _n, size, log;\r\n    std::vector<S> d;\r\n    void all_apply(int\
    \ k, S f) {\r\n        d[k] = mapping(f, d[k]);\r\n    }\r\n    void push(int\
    \ k) {\r\n        all_apply(2 * k, d[k]);\r\n        all_apply(2 * k + 1, d[k]);\r\
    \n        d[k] = id();\r\n    }\r\n    int ceil_pow2(int n) {\r\n        int x\
    \ = 0;\r\n        while ((1U << x) < (unsigned int)(n)) x++;\r\n        return\
    \ x;\r\n    }\r\n};\r\n#line 6 \"Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp\"\
    \n\r\nusing namespace std;\r\nusing ll = long long;\r\nll op(ll af, ll bf){ return\
    \ af + bf; }\r\nll e(){return 0;}\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q, cmd, u, v;\r\n    cin >> N >> Q;\r\n    vector<ll>\
    \ a(N), b(N);\r\n    vector<int> par(N);\r\n    vector<vector<int>> g(N);\r\n\
    \    for(auto &&v : a) cin >> v;\r\n    for(int i = 1; i < N; i++){\r\n      \
    \  cin >> par[i];\r\n        g[par[i]].emplace_back(i);\r\n    }\r\n    Heavy_Light_Decomposition\
    \ HLD(g);\r\n    for(int i = N - 1; i >= 1; i--){\r\n        a[par[i]] += a[i];\r\
    \n        b[HLD[i]] = a[i];\r\n    }\r\n    b[0] = a[0];\r\n    dual_segtree<ll,\
    \ op, e> seg(b);\r\n    auto update = [&](int l, int r){\r\n        seg.apply(l,\
    \ r, v);\r\n    };\r\n    while(Q--){\r\n        cin >> cmd >> u;\r\n        if(cmd\
    \ == 0){\r\n            cin >> v;\r\n            HLD.update(0, u, update);\r\n\
    \        }else{\r\n            cout << seg[HLD[u]] << '\\n';\r\n        }\r\n\
    \    }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Tree/hld.hpp\"\r\n#include \"DataStructure/segtree_dual.hpp\"\
    \r\n\r\nusing namespace std;\r\nusing ll = long long;\r\nll op(ll af, ll bf){\
    \ return af + bf; }\r\nll e(){return 0;}\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q, cmd, u, v;\r\n    cin >> N >> Q;\r\n    vector<ll>\
    \ a(N), b(N);\r\n    vector<int> par(N);\r\n    vector<vector<int>> g(N);\r\n\
    \    for(auto &&v : a) cin >> v;\r\n    for(int i = 1; i < N; i++){\r\n      \
    \  cin >> par[i];\r\n        g[par[i]].emplace_back(i);\r\n    }\r\n    Heavy_Light_Decomposition\
    \ HLD(g);\r\n    for(int i = N - 1; i >= 1; i--){\r\n        a[par[i]] += a[i];\r\
    \n        b[HLD[i]] = a[i];\r\n    }\r\n    b[0] = a[0];\r\n    dual_segtree<ll,\
    \ op, e> seg(b);\r\n    auto update = [&](int l, int r){\r\n        seg.apply(l,\
    \ r, v);\r\n    };\r\n    while(Q--){\r\n        cin >> cmd >> u;\r\n        if(cmd\
    \ == 0){\r\n            cin >> v;\r\n            HLD.update(0, u, update);\r\n\
    \        }else{\r\n            cout << seg[HLD[u]] << '\\n';\r\n        }\r\n\
    \    }\r\n}\r\n"
  dependsOn:
  - Tree/hld.hpp
  - DataStructure/segtree_dual.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 10:56:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
- /verify/Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp.html
title: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
---
