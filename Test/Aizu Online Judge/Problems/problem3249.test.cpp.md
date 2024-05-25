---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/RollingHash.hpp
    title: String/RollingHash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3249
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3249
  bundledCode: "#line 1 \"Test/Aizu Online Judge/Problems/problem3249.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3249\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#line 1 \"String/RollingHash.hpp\"\nstruct\
    \ RollingHash{\n    long long BASE = 257, RMOD = (1ll << 61) - 1;\n    long long\
    \ MASK31 = (1ll << 31) - 1, MASK30 = (1ll << 30) - 1;\n    int n;\n    std::vector<long\
    \ long> dat, dat2, base_pow;\n    RollingHash()  {}\n    RollingHash(std::string\
    \ &s) : n(s.size()), dat(n+1), dat2(n+1), base_pow(n+1) {\n        base_pow[0]\
    \ = 1;\n        for(int i = 0; i < n; i++){\n            dat[i+1] = safe_mod(internal_mul(dat[i],\
    \ BASE) + s[i]);\n            dat2.rbegin()[i+1] = safe_mod(internal_mul(dat2.rbegin()[i],\
    \ BASE) + s.rbegin()[i]);\n            base_pow[i+1] = internal_mul(base_pow[i],\
    \ BASE);\n        }\n    }\n    long long internal_mul(long long a, long long\
    \ b){\n        long long au = a >> 31, ad = a & MASK31;\n        long long bu\
    \ = b >> 31, bd = b & MASK31;\n        long long mid = ad * bu + au * bd;\n  \
    \      long long midu = mid >> 30;\n        long long midd = mid & MASK30;\n \
    \       return safe_mod(au * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n\
    \    long long safe_mod(long long x){\n        long long xu = x >> 61, xd = x\
    \ & RMOD;\n        long long res = xu + xd;\n        if (res >= RMOD) res -= RMOD;\n\
    \        return res;\n    }\n    long long hash(int l, int r){\n        long long\
    \ res = dat[r] - internal_mul(dat[l], base_pow[r - l]);\n        if(res < 0)res\
    \ += RMOD;\n        return res;\n    }\n    long long revhash(int l, int r){\n\
    \        long long res = dat2[l] - internal_mul(dat2[r], base_pow[r - l]);\n \
    \       if(res < 0)res += RMOD;\n        return res;\n    }\n    long long joint(long\
    \ long lhs, long long rhs, long long rsize){\n        long long res = internal_mul(lhs,\
    \ base_pow[rsize]) + rhs;\n        if(res >= RMOD) res -= RMOD;\n        return\
    \ res;\n    }\n};\n#line 5 \"Test/Aizu Online Judge/Problems/problem3249.test.cpp\"\
    \nusing namespace std;\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\
    \n    cin.tie(0);\r\n    string s;\r\n    while(cin >> s){\r\n        if(s ==\
    \ \"#\") break;\r\n        int n = s.size() / 2;\r\n        string fr = s.substr(0,\
    \ n), ba = s.substr(s.size() - n, n);\r\n        reverse(ba.begin(), ba.end());\r\
    \n        RollingHash RH1(fr), RH2(ba);\r\n        vector<int> dp(n + 1, 1 <<\
    \ 30);\r\n        dp[0] = 0;\r\n        for(int l = 0; l < n; l++){\r\n      \
    \      for(int r = l + 1; r <= n; r++){\r\n                if(RH1.hash(l, r) ==\
    \ RH2.hash(l, r)) dp[r] = min(dp[r], dp[l]);\r\n                if(RH1.hash(l,\
    \ r) == RH2.revhash(l, r)) dp[r] = min(dp[r], dp[l] + (r - l) * (r - l));\r\n\
    \            }\r\n        }\r\n        if(dp[n] >> 30 & 1) dp[n] = -1;\r\n   \
    \     cout << dp[n] << '\\n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3249\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include \"String/RollingHash.hpp\"\r\nusing\
    \ namespace std;\r\n\r\nint main(){\r\n    ios::sync_with_stdio(false);\r\n  \
    \  cin.tie(0);\r\n    string s;\r\n    while(cin >> s){\r\n        if(s == \"\
    #\") break;\r\n        int n = s.size() / 2;\r\n        string fr = s.substr(0,\
    \ n), ba = s.substr(s.size() - n, n);\r\n        reverse(ba.begin(), ba.end());\r\
    \n        RollingHash RH1(fr), RH2(ba);\r\n        vector<int> dp(n + 1, 1 <<\
    \ 30);\r\n        dp[0] = 0;\r\n        for(int l = 0; l < n; l++){\r\n      \
    \      for(int r = l + 1; r <= n; r++){\r\n                if(RH1.hash(l, r) ==\
    \ RH2.hash(l, r)) dp[r] = min(dp[r], dp[l]);\r\n                if(RH1.hash(l,\
    \ r) == RH2.revhash(l, r)) dp[r] = min(dp[r], dp[l] + (r - l) * (r - l));\r\n\
    \            }\r\n        }\r\n        if(dp[n] >> 30 & 1) dp[n] = -1;\r\n   \
    \     cout << dp[n] << '\\n';\r\n    }\r\n}"
  dependsOn:
  - String/RollingHash.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/Problems/problem3249.test.cpp
  requiredBy: []
  timestamp: '2024-05-25 09:00:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/Problems/problem3249.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/Problems/problem3249.test.cpp
- /verify/Test/Aizu Online Judge/Problems/problem3249.test.cpp.html
title: Test/Aizu Online Judge/Problems/problem3249.test.cpp
---
