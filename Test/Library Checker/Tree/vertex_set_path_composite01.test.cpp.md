---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Math/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#line 1 \"Tree/hld.hpp\"\nstruct Heavy_Light_Decomposition{\n\
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
    \        }\n    }\n};\n#line 1 \"DataStructure/segtree.hpp\"\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\r\n    public:\r\n    segtree()\
    \ : segtree(0) {}\r\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\r\
    \n    segtree(const std::vector<S>& v) : _n(int(v.size())) {\r\n        log =\
    \ ceil_pow2(_n);\r\n        size = 1 << log;\r\n        d = std::vector<S>(2 *\
    \ size, e());\r\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\r\n\
    \        for (int i = size - 1; i >= 1; i--) {\r\n            update(i);\r\n \
    \       }\r\n    }\r\n\r\n    void set(int p, S x) {\r\n        assert(0 <= p\
    \ && p < _n);\r\n        p += size;\r\n        d[p] = x;\r\n        for (int i\
    \ = 1; i <= log; i++) update(p >> i);\r\n    }\r\n\r\n    S get(int p) {\r\n \
    \       assert(0 <= p && p < _n);\r\n        return d[p + size];\r\n    }\r\n\
    \    const S operator[](int p) const { return get(p); }\r\n    S operator[](int\
    \ p) { return get(p); }\r\n\r\n    S prod(int l, int r) {\r\n        assert(0\
    \ <= l && l <= r && r <= _n);\r\n        S sml = e(), smr = e();\r\n        l\
    \ += size;\r\n        r += size;\r\n\r\n        while (l < r) {\r\n          \
    \  if (l & 1) sml = op(sml, d[l++]);\r\n            if (r & 1) smr = op(d[--r],\
    \ smr);\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n     \
    \   return op(sml, smr);\r\n    }\r\n\r\n    S all_prod() { return d[1]; }\r\n\
    \r\n    template <bool (*f)(S)> int max_right(int l) {\r\n        return max_right(l,\
    \ [](S x) { return f(x); });\r\n    }\r\n    template <class F> int max_right(int\
    \ l, F f) {\r\n        assert(0 <= l && l <= _n);\r\n        assert(f(e()));\r\
    \n        if (l == _n) return _n;\r\n        l += size;\r\n        S sm = e();\r\
    \n        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm,\
    \ d[l]))) {\r\n                while (l < size) {\r\n                    l = (2\
    \ * l);\r\n                    if (f(op(sm, d[l]))) {\r\n                    \
    \    sm = op(sm, d[l]);\r\n                        l++;\r\n                  \
    \  }\r\n                }\r\n                return l - size;\r\n            }\r\
    \n            sm = op(sm, d[l]);\r\n            l++;\r\n        } while ((l &\
    \ -l) != l);\r\n        return _n;\r\n    }\r\n\r\n    template <bool (*f)(S)>\
    \ int min_left(int r) {\r\n        return min_left(r, [](S x) { return f(x); });\r\
    \n    }\r\n    template <class F> int min_left(int r, F f) {\r\n        assert(0\
    \ <= r && r <= _n);\r\n        assert(f(e()));\r\n        if (r == 0) return 0;\r\
    \n        r += size;\r\n        S sm = e();\r\n        do {\r\n            r--;\r\
    \n            while (r > 1 && (r % 2)) r >>= 1;\r\n            if (!f(op(d[r],\
    \ sm))) {\r\n                while (r < size) {\r\n                    r = (2\
    \ * r + 1);\r\n                    if (f(op(d[r], sm))) {\r\n                \
    \        sm = op(d[r], sm);\r\n                        r--;\r\n              \
    \      }\r\n                }\r\n                return r + 1 - size;\r\n    \
    \        }\r\n            sm = op(d[r], sm);\r\n        } while ((r & -r) != r);\r\
    \n        return 0;\r\n    }\r\n\r\n    private:\r\n    int _n, size, log;\r\n\
    \    std::vector<S> d;\r\n    int ceil_pow2(int n) {\r\n        int x = 0;\r\n\
    \        while ((1U << x) < (unsigned int)(n)) x++;\r\n        return x;\r\n \
    \   }\r\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n};\r\
    \n#line 1 \"Math/modint.hpp\"\ntemplate<const unsigned int MOD> struct prime_modint\
    \ {\n    using mint = prime_modint;\n    unsigned int v;\n    prime_modint() :\
    \ v(0) {}\n    prime_modint(unsigned int a) { a %= MOD; v = a; }\n    prime_modint(unsigned\
    \ long long a) { a %= MOD; v = a; }\n    prime_modint(int a) { a %= (int)(MOD);\
    \ if(a < 0)a += MOD; v = a; }\n    prime_modint(long long a) { a %= (int)(MOD);\
    \ if(a < 0)a += MOD; v = a; }\n    static constexpr int mod() { return MOD; }\n\
    \    mint& operator++() {v++; if(v == MOD)v = 0; return *this;}\n    mint& operator--()\
    \ {if(v == 0)v = MOD; v--; return *this;}\n    mint operator++(int) { mint result\
    \ = *this; ++*this; return result; }\n    mint operator--(int) { mint result =\
    \ *this; --*this; return result; }\n    mint& operator+=(const mint& rhs) { v\
    \ += rhs.v; if(v >= MOD) v -= MOD; return *this; }\n    mint& operator-=(const\
    \ mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this; }\n    mint&\
    \ operator*=(const mint& rhs) {\n        v = (unsigned int)((unsigned long long)(v)\
    \ * rhs.v % MOD);\n        return *this;\n    }\n    mint& operator/=(const mint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n    mint operator+() const { return\
    \ *this; }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint r = 1, x = *this;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ { assert(v); return pow(MOD - 2); }\n    friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::ostream&\
    \ operator << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v;\
    \ }\n};\n#line 7 \"Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp\"\
    \n\r\n//using mint = prime_modint<1000000007>;\r\nusing mint = prime_modint<998244353>;\r\
    \n\r\nusing namespace std;\r\n\r\nusing S = pair<mint, mint>;\r\nS op1(S lhs,\
    \ S rhs){\r\n    return {rhs.first * lhs.first, rhs.first * lhs.second + rhs.second};\r\
    \n}\r\nS op2(S lhs, S rhs){\r\n    return {lhs.first * rhs.first, lhs.first *\
    \ rhs.second + lhs.second};\r\n}\r\nS e(){\r\n    return make_pair(1, 0);\r\n\
    }\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\n    cin.tie(0);\r\n\
    \    int N, Q, cmd, u, v, x;\r\n    cin >> N >> Q;\r\n    vector<pair<mint,mint>>\
    \ a(N), b(N);\r\n    vector<vector<int>> g(N);\r\n    for(int i = 0; i < N; i++){\r\
    \n        cin >> a[i].first.v >> a[i].second.v;\r\n    }\r\n    for(int i = 1;\
    \ i < N; i++){\r\n        cin >> u >> v;\r\n        g[u].emplace_back(v);\r\n\
    \        g[v].emplace_back(u);\r\n    }\r\n\r\n    Heavy_Light_Decomposition HLD(g);\r\
    \n\r\n    for(int i = 0; i < N; i++){\r\n        b[HLD[i]] = a[i];\r\n    }\r\n\
    \    segtree<S, op1, e> seg1(b);\r\n    segtree<S, op2, e> seg2(b);\r\n\r\n  \
    \  auto qf = [&](int l, int r){\r\n        return seg1.prod(l, r);\r\n    };\r\
    \n    auto rev_qf = [&](int l, int r){\r\n        return seg2.prod(l, r);\r\n\
    \    };\r\n    auto f = [&](S lhs, S rhs){\r\n        return make_pair(rhs.first\
    \ * lhs.first, rhs.first * lhs.second + rhs.second);\r\n    };\r\n\r\n    while(Q--){\r\
    \n        cin >> cmd >> u >> v >> x;\r\n        if(cmd == 0){\r\n            seg1.set(HLD[u],\
    \ make_pair(v, x));\r\n            seg2.set(HLD[u], make_pair(v, x));\r\n    \
    \    }else{\r\n            auto pa = HLD.noncom_query(u, v, e(), qf, rev_qf, f);\r\
    \n            cout << pa.first * x + pa.second << '\\n';\r\n        }\r\n    }\r\
    \n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"Tree/hld.hpp\"\r\n#include \"DataStructure/segtree.hpp\"\
    \r\n#include \"Math/modint.hpp\"\r\n\r\n//using mint = prime_modint<1000000007>;\r\
    \nusing mint = prime_modint<998244353>;\r\n\r\nusing namespace std;\r\n\r\nusing\
    \ S = pair<mint, mint>;\r\nS op1(S lhs, S rhs){\r\n    return {rhs.first * lhs.first,\
    \ rhs.first * lhs.second + rhs.second};\r\n}\r\nS op2(S lhs, S rhs){\r\n    return\
    \ {lhs.first * rhs.first, lhs.first * rhs.second + lhs.second};\r\n}\r\nS e(){\r\
    \n    return make_pair(1, 0);\r\n}\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    int N, Q, cmd, u, v, x;\r\n    cin >> N >> Q;\r\n   \
    \ vector<pair<mint,mint>> a(N), b(N);\r\n    vector<vector<int>> g(N);\r\n   \
    \ for(int i = 0; i < N; i++){\r\n        cin >> a[i].first.v >> a[i].second.v;\r\
    \n    }\r\n    for(int i = 1; i < N; i++){\r\n        cin >> u >> v;\r\n     \
    \   g[u].emplace_back(v);\r\n        g[v].emplace_back(u);\r\n    }\r\n\r\n  \
    \  Heavy_Light_Decomposition HLD(g);\r\n\r\n    for(int i = 0; i < N; i++){\r\n\
    \        b[HLD[i]] = a[i];\r\n    }\r\n    segtree<S, op1, e> seg1(b);\r\n   \
    \ segtree<S, op2, e> seg2(b);\r\n\r\n    auto qf = [&](int l, int r){\r\n    \
    \    return seg1.prod(l, r);\r\n    };\r\n    auto rev_qf = [&](int l, int r){\r\
    \n        return seg2.prod(l, r);\r\n    };\r\n    auto f = [&](S lhs, S rhs){\r\
    \n        return make_pair(rhs.first * lhs.first, rhs.first * lhs.second + rhs.second);\r\
    \n    };\r\n\r\n    while(Q--){\r\n        cin >> cmd >> u >> v >> x;\r\n    \
    \    if(cmd == 0){\r\n            seg1.set(HLD[u], make_pair(v, x));\r\n     \
    \       seg2.set(HLD[u], make_pair(v, x));\r\n        }else{\r\n            auto\
    \ pa = HLD.noncom_query(u, v, e(), qf, rev_qf, f);\r\n            cout << pa.first\
    \ * x + pa.second << '\\n';\r\n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - Tree/hld.hpp
  - DataStructure/segtree.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 10:56:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
- /verify/Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp.html
title: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
---
