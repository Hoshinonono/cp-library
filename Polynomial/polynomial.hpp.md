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
  bundledCode: "#line 1 \"Polynomial/polynomial.hpp\"\ntemplate <class mint> struct\
    \ Polynomial : std::vector<mint> {\n    using std::vector<mint>::vector;\n   \
    \ using poly = Polynomial;\n    poly& operator=(const std::vector<mint>& rhs)\
    \ {\n        this->assign(rhs.begin(), rhs.end());\n        return *this;\n  \
    \  }\n    poly& operator+=(const poly& rhs) {\n        int rn = rhs.size();\n\
    \        if(this->size() < rn) this->resize(rn);\n        for(int i = 0; i < rn;\
    \ i++) (*this)[i] += rhs[i];\n        return *this;\n    }\n    poly& operator-=(const\
    \ poly& rhs) {\n        int rn = rhs.size();\n        if(this->size() < rn) this->resize(rn);\n\
    \        for(int i = 0; i < rn; i++) (*this)[i] -= rhs[i];\n        return *this;\n\
    \    }\n    poly& operator*=(const poly& rhs) {\n        return *this = atcoder::convolution(*this,\
    \ rhs);\n    }\n    poly inv() const {\n        const int n = this->size();\n\
    \        poly res;\n        res.reserve(n);\n        res.emplace_back((*this)[0].inv());\n\
    \        while(res.size() < n){\n            const int m = 2 * res.size();\n \
    \           std::vector<mint> buf(m), fres(m);\n            std::copy(this->begin(),\
    \ this->begin() + std::min(m, n), buf.begin());\n            std::copy(res.begin(),\
    \ res.end(), fres.begin());\n            atcoder::internal::butterfly(buf);\n\
    \            atcoder::internal::butterfly(fres);\n            for (int i = 0;\
    \ i < m; i++) buf[i] *= fres[i];\n            atcoder::internal::butterfly_inv(buf);\n\
    \            std::fill(buf.begin(), buf.begin() + res.size(), mint::raw(0));\n\
    \            atcoder::internal::butterfly(buf);\n            for (int i = 0; i\
    \ < m; i++) buf[i] *= fres[i];\n            atcoder::internal::butterfly_inv(buf);\n\
    \            mint coef = -(mint::raw(m) * mint::raw(m)).inv();\n            for\
    \ (int i = res.size(); i < std::min(m, n); i++) res.emplace_back(buf[i] * coef);\n\
    \        }\n        return res;\n    }\n    poly operator+() const { return *this;\
    \ }\n    poly operator-() const { return poly() - *this; }\n    friend poly operator+(const\
    \ poly& lhs, const poly& rhs) {\n        return poly(lhs) += rhs;\n    }\n   \
    \ friend poly operator-(const poly& lhs, const poly& rhs) {\n        return poly(lhs)\
    \ -= rhs;\n    }\n    friend poly operator*(const poly& lhs, const poly& rhs)\
    \ {\n        return poly(lhs) *= rhs;\n    }\n    poly deriv() const {\n     \
    \   const int deg = this->size();\n        poly res(std::max(0, deg - 1));\n \
    \       mint coef = 1;\n        for(int i = 1; i < deg; i++) {\n            res[i\
    \ - 1] = (*this)[i] * coef;\n            coef++;\n        }\n        return res;\n\
    \    }\n    poly integ() const {\n        const int deg = this->size();\n    \
    \    poly res(deg + 1);\n        res[0] = 0;\n        if (deg > 0) res[1] = 1;\n\
    \        auto mod = mint::mod();\n        for (int i = 2; i <= deg; i++) res[i]\
    \ = (-res[mod % i]) * (mod / i);\n        for (int i = 0; i < deg; i++) res[i\
    \ + 1] *= (*this)[i];\n        return res;\n    }\n    poly log() const {\n  \
    \      return (this->deriv() * this->inv()).integ();\n    }\n    poly exp() const\
    \ {\n        const int deg = this->size();\n        \n        // 1/i\u306E\u30C6\
    \u30FC\u30D6\u30EB\u306E\u4F5C\u6210\n        int r = 2 << std::__lg(deg);\n \
    \       auto mod = mint::mod();\n        std::vector<mint> iv(r + 1);\n      \
    \  iv[1] = 1;\n        for (int i = 2; i <= r; i++) iv[i] = (-iv[mod % i]) * (mod\
    \ / i);\n\n        auto internal_butterfly_inv = [&](poly& f){\n            atcoder::internal::butterfly_inv(f);\n\
    \            mint iz = mint::raw(f.size()).inv();\n            for (auto &&v :\
    \ f) v *= iz;\n        };\n        \n        poly res = {1, this->size() >= 2\
    \ ? (*this)[1] : 0};\n        poly c{1}, z1, z2{1, 1};\n        for (int m = 2;\
    \ m < deg; m *= 2){\n            auto y = res;\n            y.resize(2 * m);\n\
    \            atcoder::internal::butterfly(y);\n            z1 = z2;\n        \
    \    poly z(m);\n            for (int i = 0; i < m; i++) z[i] = y[i] * z1[i];\n\
    \            internal_butterfly_inv(z);\n            std::fill(z.begin(), z.begin()\
    \ + (m / 2), mint::raw(0));\n            atcoder::internal::butterfly(z);\n  \
    \          for (int i = 0; i < m; ++i) z[i] *= -z1[i];\n            internal_butterfly_inv(z);\n\
    \            c.insert(c.end(), z.begin() + (m / 2), z.end());\n            z2\
    \ = c;\n            z2.resize(2 * m);\n            atcoder::internal::butterfly(z2);\n\
    \n            poly x(m);\n            std::copy(this->begin(), this->begin() +\
    \ std::min(m, deg), x.begin());\n            for(int i = 0; i + 1 < m; i++) x[i]\
    \ = x[i + 1] * mint::raw(i + 1);\n            x.back() = 0;\n            atcoder::internal::butterfly(x);\n\
    \            for (int i = 0; i < m; ++i) x[i] *= y[i];\n            internal_butterfly_inv(x);\n\
    \            x -= res.deriv();\n            x.resize(2 * m);\n            for\
    \ (int i = 0; i < m - 1; ++i) x[m + i] = x[i], x[i] = mint::raw(0);\n        \
    \    atcoder::internal::butterfly(x);\n            for (int i = 0; i < 2 * m;\
    \ ++i) x[i] *= z2[i];\n            internal_butterfly_inv(x);\n            for(int\
    \ i = x.size() - 1; i >= 1; i--) x[i] = iv[i] * x[i - 1];\n            x[0] =\
    \ 0;\n            for (int i = m; i < std::min(deg, 2 * m); ++i) x[i] += (*this)[i];\n\
    \            std::fill(x.begin(), x.begin() + m, mint::raw(0));\n            atcoder::internal::butterfly(x);\n\
    \            for (int i = 0; i < 2 * m; ++i) x[i] *= y[i];\n            internal_butterfly_inv(x);\n\
    \            res.insert(res.end(), x.begin() + m, x.end());\n        }\n     \
    \   return res;\n    }\n    friend std::ostream& operator << (std::ostream &os,\
    \ const poly vec) noexcept {\n        if (vec.empty()) return os;\n        os\
    \ << vec[0].val();\n        for (auto it = vec.begin(); ++it != vec.end(); ) os\
    \ << ' ' << it->val();\n        return os;\n    }\n};\n"
  code: "template <class mint> struct Polynomial : std::vector<mint> {\n    using\
    \ std::vector<mint>::vector;\n    using poly = Polynomial;\n    poly& operator=(const\
    \ std::vector<mint>& rhs) {\n        this->assign(rhs.begin(), rhs.end());\n \
    \       return *this;\n    }\n    poly& operator+=(const poly& rhs) {\n      \
    \  int rn = rhs.size();\n        if(this->size() < rn) this->resize(rn);\n   \
    \     for(int i = 0; i < rn; i++) (*this)[i] += rhs[i];\n        return *this;\n\
    \    }\n    poly& operator-=(const poly& rhs) {\n        int rn = rhs.size();\n\
    \        if(this->size() < rn) this->resize(rn);\n        for(int i = 0; i < rn;\
    \ i++) (*this)[i] -= rhs[i];\n        return *this;\n    }\n    poly& operator*=(const\
    \ poly& rhs) {\n        return *this = atcoder::convolution(*this, rhs);\n   \
    \ }\n    poly inv() const {\n        const int n = this->size();\n        poly\
    \ res;\n        res.reserve(n);\n        res.emplace_back((*this)[0].inv());\n\
    \        while(res.size() < n){\n            const int m = 2 * res.size();\n \
    \           std::vector<mint> buf(m), fres(m);\n            std::copy(this->begin(),\
    \ this->begin() + std::min(m, n), buf.begin());\n            std::copy(res.begin(),\
    \ res.end(), fres.begin());\n            atcoder::internal::butterfly(buf);\n\
    \            atcoder::internal::butterfly(fres);\n            for (int i = 0;\
    \ i < m; i++) buf[i] *= fres[i];\n            atcoder::internal::butterfly_inv(buf);\n\
    \            std::fill(buf.begin(), buf.begin() + res.size(), mint::raw(0));\n\
    \            atcoder::internal::butterfly(buf);\n            for (int i = 0; i\
    \ < m; i++) buf[i] *= fres[i];\n            atcoder::internal::butterfly_inv(buf);\n\
    \            mint coef = -(mint::raw(m) * mint::raw(m)).inv();\n            for\
    \ (int i = res.size(); i < std::min(m, n); i++) res.emplace_back(buf[i] * coef);\n\
    \        }\n        return res;\n    }\n    poly operator+() const { return *this;\
    \ }\n    poly operator-() const { return poly() - *this; }\n    friend poly operator+(const\
    \ poly& lhs, const poly& rhs) {\n        return poly(lhs) += rhs;\n    }\n   \
    \ friend poly operator-(const poly& lhs, const poly& rhs) {\n        return poly(lhs)\
    \ -= rhs;\n    }\n    friend poly operator*(const poly& lhs, const poly& rhs)\
    \ {\n        return poly(lhs) *= rhs;\n    }\n    poly deriv() const {\n     \
    \   const int deg = this->size();\n        poly res(std::max(0, deg - 1));\n \
    \       mint coef = 1;\n        for(int i = 1; i < deg; i++) {\n            res[i\
    \ - 1] = (*this)[i] * coef;\n            coef++;\n        }\n        return res;\n\
    \    }\n    poly integ() const {\n        const int deg = this->size();\n    \
    \    poly res(deg + 1);\n        res[0] = 0;\n        if (deg > 0) res[1] = 1;\n\
    \        auto mod = mint::mod();\n        for (int i = 2; i <= deg; i++) res[i]\
    \ = (-res[mod % i]) * (mod / i);\n        for (int i = 0; i < deg; i++) res[i\
    \ + 1] *= (*this)[i];\n        return res;\n    }\n    poly log() const {\n  \
    \      return (this->deriv() * this->inv()).integ();\n    }\n    poly exp() const\
    \ {\n        const int deg = this->size();\n        \n        // 1/i\u306E\u30C6\
    \u30FC\u30D6\u30EB\u306E\u4F5C\u6210\n        int r = 2 << std::__lg(deg);\n \
    \       auto mod = mint::mod();\n        std::vector<mint> iv(r + 1);\n      \
    \  iv[1] = 1;\n        for (int i = 2; i <= r; i++) iv[i] = (-iv[mod % i]) * (mod\
    \ / i);\n\n        auto internal_butterfly_inv = [&](poly& f){\n            atcoder::internal::butterfly_inv(f);\n\
    \            mint iz = mint::raw(f.size()).inv();\n            for (auto &&v :\
    \ f) v *= iz;\n        };\n        \n        poly res = {1, this->size() >= 2\
    \ ? (*this)[1] : 0};\n        poly c{1}, z1, z2{1, 1};\n        for (int m = 2;\
    \ m < deg; m *= 2){\n            auto y = res;\n            y.resize(2 * m);\n\
    \            atcoder::internal::butterfly(y);\n            z1 = z2;\n        \
    \    poly z(m);\n            for (int i = 0; i < m; i++) z[i] = y[i] * z1[i];\n\
    \            internal_butterfly_inv(z);\n            std::fill(z.begin(), z.begin()\
    \ + (m / 2), mint::raw(0));\n            atcoder::internal::butterfly(z);\n  \
    \          for (int i = 0; i < m; ++i) z[i] *= -z1[i];\n            internal_butterfly_inv(z);\n\
    \            c.insert(c.end(), z.begin() + (m / 2), z.end());\n            z2\
    \ = c;\n            z2.resize(2 * m);\n            atcoder::internal::butterfly(z2);\n\
    \n            poly x(m);\n            std::copy(this->begin(), this->begin() +\
    \ std::min(m, deg), x.begin());\n            for(int i = 0; i + 1 < m; i++) x[i]\
    \ = x[i + 1] * mint::raw(i + 1);\n            x.back() = 0;\n            atcoder::internal::butterfly(x);\n\
    \            for (int i = 0; i < m; ++i) x[i] *= y[i];\n            internal_butterfly_inv(x);\n\
    \            x -= res.deriv();\n            x.resize(2 * m);\n            for\
    \ (int i = 0; i < m - 1; ++i) x[m + i] = x[i], x[i] = mint::raw(0);\n        \
    \    atcoder::internal::butterfly(x);\n            for (int i = 0; i < 2 * m;\
    \ ++i) x[i] *= z2[i];\n            internal_butterfly_inv(x);\n            for(int\
    \ i = x.size() - 1; i >= 1; i--) x[i] = iv[i] * x[i - 1];\n            x[0] =\
    \ 0;\n            for (int i = m; i < std::min(deg, 2 * m); ++i) x[i] += (*this)[i];\n\
    \            std::fill(x.begin(), x.begin() + m, mint::raw(0));\n            atcoder::internal::butterfly(x);\n\
    \            for (int i = 0; i < 2 * m; ++i) x[i] *= y[i];\n            internal_butterfly_inv(x);\n\
    \            res.insert(res.end(), x.begin() + m, x.end());\n        }\n     \
    \   return res;\n    }\n    friend std::ostream& operator << (std::ostream &os,\
    \ const poly vec) noexcept {\n        if (vec.empty()) return os;\n        os\
    \ << vec[0].val();\n        for (auto it = vec.begin(); ++it != vec.end(); ) os\
    \ << ' ' << it->val();\n        return os;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Polynomial/polynomial.hpp
  requiredBy: []
  timestamp: '2026-09-23 01:15:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Polynomial/polynomial.hpp
layout: document
title: "\u591A\u9805\u5F0F"
---

## 概要

多項式ライブラリ。未整備