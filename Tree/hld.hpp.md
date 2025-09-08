---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/vertex_add_path_sum01.test.cpp
    title: Test/Library Checker/Tree/vertex_add_path_sum01.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
    title: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
    title: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/hld.hpp\"\nstruct Heavy_Light_Decomposition{\n    int\
    \ N, tim = 0;\n    std::vector<int> sz, ent, leader, order, par;\n    std::vector<std::vector<int>>\
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
    \        }\n    }\n};\n"
  code: "struct Heavy_Light_Decomposition{\n    int N, tim = 0;\n    std::vector<int>\
    \ sz, ent, leader, order, par;\n    std::vector<std::vector<int>> &G;\n    Heavy_Light_Decomposition(std::vector<std::vector<int>>\
    \ &g) : \n            N(g.size()), G(g), sz(N), ent(N), leader(N), order(N), par(N)\
    \ {\n        dfs_size(0, -1);\n        dfs_hld(0);\n    }\n    const int operator[](int\
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
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Tree/hld.hpp
  requiredBy: []
  timestamp: '2023-12-31 10:45:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
  - Test/Library Checker/Tree/vertex_add_path_sum01.test.cpp
  - Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
documentation_of: Tree/hld.hpp
layout: document
title: "HL\u5206\u89E3 (HLD, Heavy-Light-Decomposition)"
---

## 概要
HL分解 (HLD, Heavy-Light-Decomposition) を行うためのライブラリ。<br>
それぞれの頂点に対して、 子の頂点のうち部分木の頂点数が最も大きい頂点を1つ選択して Heavy Edge で結ぶことで $\log N$ 個程度のパスに分解でき、パスの更新クエリに対して高速に処理できる。<br>
実装は <a href = "https://ei1333.github.io/luzhiled/snippets/tree/heavy-light-decomposition.html"> HL分解(Heavy-Light-Decomposition) | Luzhiled's memo </a> をかなり参考にした。<br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`Heavy_Light_Decomposition`<br>`(std::vector<std::vector<int>> g)`| コンストラクタに木を渡すと、HL分解される。| $\text{O} (N)$ | 
|(1) `int la(int v, int d)` <br>(2) `int la(int from, int to, int d)`|(1)頂点 $v$ から根に向かって距離 $d$ 進んだ頂点を返す。<br>(2)頂点 $\text{from}$ から頂点 $\text{to}$ に向かって距離 $d$ 進んだ頂点を返す。<br> 存在しない場合は `-1` を返す。| $\text{O}(\log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log N)$ |
|`int [v]`|頂点 $v$ が行きがけ順で何番目に訪問された頂点であるかを返す。配列などでここに対応する添え字の値を更新すると、頂点 $v$ に対する値を更新したことになる。|$\text{O}(1)$|
|`T query(int u, int v,`<br>`const T &identity,`<br>`const Q &qf, const F &f, bool edge = false)`| 頂点 $u$ - $v$ 間の頂点の値に対して演算を行う。第3引数以降は以下のようなものを渡す。<br>・ `T identity` ：演算に対応する単位元(ラムダ式ではないので注意)<br>・ `T qf(int l, int r)` ：列に対する区間収得クエリ。<br>・ `T f(T lhs, T rhs)` : 列と列の結合クエリ。<br>・ `edge` ：辺に対する演算であるか(省略可能)。省略した場合、頂点に対する演算であるとして計算する。| $O(\log N)$ |
|`T noncom_query(int u, int v,`<br>`const T &identity,`<br>`const Q1 &qf, const Q2 &rev_qf,`<br>`const F &f, bool edge)`|頂点 $u$ - $v$ 間の頂点の値に対して非可換な演算を行う。第3引数以降は以下のようなものを渡す。<br>・ `T identity` ：演算に対応する単位元(ラムダ式ではないので注意)<br>・ `T qf(int l, int r)` ：左辺が子、右辺が親とした区間収得クエリ。<br>・ `T rev_qf(int l, int r)` ：左辺が親、右辺が子とした区間収得クエリ。<br>・ `T f(T lhs, T rhs)` : 左辺が子、右辺が親としたときの列と列の結合クエリ。<br>・ `edge` ：辺に対する演算であるか(省略可能)。省略した場合、頂点に対する演算であるとして計算する。| $O(\log N)$ |
|`void update(int u, int v,`<br>`const Q &q, bool edge)`|頂点 $u$ - $v$ 間の頂点の値に対して更新演算を行う。第3引数以降は以下のようなものを渡す。<br>・ `Q q(int l, int r)` ：区間 $[l, r)$ に対する更新演算。遅延セグ木の seg.apply(l, r) などを入れることを想定。<br>・ `edge` ：辺に対する演算であるか(省略可能)。省略した場合、頂点に対する演算であるとして計算する。| $O(\log N)$ |
