---
title: StaticRangeLCM
documentation_of: ./StaticRangeLCM.hpp
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