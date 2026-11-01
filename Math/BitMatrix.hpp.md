---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki0074.test.cpp
    title: Test/yukicoder/yuki0074.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/BitMatrix.hpp\"\n#include <utility>\n#include <vector>\n\
    #include <bitset>\n#include <cassert>\n\ntemplate <size_t MAX_COL> struct BitMatrix{\n\
    \    int H, W;\n    std::vector<std::bitset<MAX_COL + 1>> A;\n    BitMatrix(int\
    \ n) : H(n), W(MAX_COL), A(n) {}\n    const std::bitset<MAX_COL + 1>& operator[](int\
    \ k) const { return A[k]; }\n    std::bitset<MAX_COL + 1>& operator[](int k) {\
    \ return A[k]; }\n    int gauss_jordan() {\n        int rank = 0;\n        for(int\
    \ j = 0; j < W && rank < H; j++) {\n            int pivot = -1;\n            for(int\
    \ i = rank; i < H; i++) {\n                if(A[i][j]){\n                    pivot\
    \ = i;\n                    break;\n                }\n            }\n       \
    \     if (pivot == -1) continue;\n            std::swap(A[pivot], A[rank]);\n\
    \            for (int i = 0 ; i < H ; i++) {\n                if (i != rank &&\
    \ A[i][j]) A[i] ^= A[rank];\n            }\n            rank++;\n        }\n \
    \       return rank;\n    }\n    std::pair<int, std::vector<int>> linear_equation(const\
    \ std::vector<int>& b) {\n        assert(H == (int)b.size());\n        for (int\
    \ i = 0; i < H; i++) A[i][W] = b[i] & 1;\n        int rank = gauss_jordan();\n\
    \        for (int i = rank; i < H; i++) {\n            if (A[i][W]) return {-1,\
    \ std::vector<int>{}};\n        }\n        std::vector<int> res(W, 0);\n     \
    \   for (int i = 0, j = 0; i < rank; i++) {\n            while (!A[i][j]) j++;\n\
    \            res[j] = A[i][W];\n        }\n        return {rank, res};\n    }\n\
    };\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n#include <bitset>\n\
    #include <cassert>\n\ntemplate <size_t MAX_COL> struct BitMatrix{\n    int H,\
    \ W;\n    std::vector<std::bitset<MAX_COL + 1>> A;\n    BitMatrix(int n) : H(n),\
    \ W(MAX_COL), A(n) {}\n    const std::bitset<MAX_COL + 1>& operator[](int k) const\
    \ { return A[k]; }\n    std::bitset<MAX_COL + 1>& operator[](int k) { return A[k];\
    \ }\n    int gauss_jordan() {\n        int rank = 0;\n        for(int j = 0; j\
    \ < W && rank < H; j++) {\n            int pivot = -1;\n            for(int i\
    \ = rank; i < H; i++) {\n                if(A[i][j]){\n                    pivot\
    \ = i;\n                    break;\n                }\n            }\n       \
    \     if (pivot == -1) continue;\n            std::swap(A[pivot], A[rank]);\n\
    \            for (int i = 0 ; i < H ; i++) {\n                if (i != rank &&\
    \ A[i][j]) A[i] ^= A[rank];\n            }\n            rank++;\n        }\n \
    \       return rank;\n    }\n    std::pair<int, std::vector<int>> linear_equation(const\
    \ std::vector<int>& b) {\n        assert(H == (int)b.size());\n        for (int\
    \ i = 0; i < H; i++) A[i][W] = b[i] & 1;\n        int rank = gauss_jordan();\n\
    \        for (int i = rank; i < H; i++) {\n            if (A[i][W]) return {-1,\
    \ std::vector<int>{}};\n        }\n        std::vector<int> res(W, 0);\n     \
    \   for (int i = 0, j = 0; i < rank; i++) {\n            while (!A[i][j]) j++;\n\
    \            res[j] = A[i][W];\n        }\n        return {rank, res};\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/BitMatrix.hpp
  requiredBy: []
  timestamp: '2026-11-01 11:03:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/yuki0074.test.cpp
documentation_of: Math/BitMatrix.hpp
layout: document
title: "F2 \u4E0A\u306E\u884C\u5217 (BitMatrix)"
---

## 概要
$\mathbb{F}_2$ 上の $H \times W$ 行列を `std::bitset` で管理する構造体である．<br>
各行を `std::bitset` で持つため，行どうしの加算 (XOR) が $\text{O}(W / w)$ で行える ( $w$ はワードサイズで $64$ )．<br>
これを用いて，掃き出し法による階数の計算や連立一次方程式 $Ax = b$ の求解を高速に行う．<br>
列数 $W$ は常に `MAX_COL` となる．内部では右辺 $b$ 用に 1 列余分に持っている．

|関数名など|機能|計算量|
|---------|----|-----|
|`BitMatrix<MAX_COL>(int N)`| 宣言. $N$ 行 `MAX_COL` 列の行列を作る．初期値はすべて $0$ ．<br> `MAX_COL` はコンパイル時定数である必要がある．| $\text{O}(N \cdot W / w)$ |
|`A[i]`| $i$ 行目の `std::bitset` を返す．`A[i][j]` で $(i, j)$ 成分の参照・代入ができる． $0 \leq i < H$ , $0 \leq j < W$ | $\text{O}(1)$ |
|`int gauss_jordan()`| 行列を掃き出し法で簡約化し，階数 (rank) を返す．行列は破壊的に変更される．| $\text{O}(H W \min(H, W) / w)$ |
|`std::pair<int, std::vector<int>> linear_equation(std::vector<int> b)`| 連立一次方程式 $Ax = b$ を $\mathbb{F}_2$ 上で解く．行列は破壊的に変更される．<br> 解が存在するとき，`{rank, x}` を返す．`x` は長さ $W$ の解の一つで，自由変数はすべて $0$ としたものである．<br> 解が存在しないとき，`{-1, {}}` を返す．<br> 解の個数は $2^{W - \text{rank}}$ 個となる．<br> `b[i]` は $\bmod 2$ で扱われる．<br> 制約 <br>・ `b.size()` $= H$ | $\text{O}(H W \min(H, W) / w)$ |
