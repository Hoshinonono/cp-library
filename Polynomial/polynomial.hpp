template <class mint> struct Polynomial : std::vector<mint> {
    using std::vector<mint>::vector;
    using poly = Polynomial;
    poly& operator=(const std::vector<mint>& rhs) {
        this->assign(rhs.begin(), rhs.end());
        return *this;
    }
    poly& operator+=(const poly& rhs) {
        int rn = rhs.size();
        if(this->size() < rn) this->resize(rn);
        for(int i = 0; i < rn; i++) (*this)[i] += rhs[i];
        return *this;
    }
    poly& operator-=(const poly& rhs) {
        int rn = rhs.size();
        if(this->size() < rn) this->resize(rn);
        for(int i = 0; i < rn; i++) (*this)[i] -= rhs[i];
        return *this;
    }
    poly& operator*=(const poly& rhs) {
        return *this = atcoder::convolution(*this, rhs);
    }
    poly inv() const {
        const int n = this->size();
        poly res;
        res.reserve(n);
        res.emplace_back((*this)[0].inv());
        while(res.size() < n){
            const int m = 2 * res.size();
            std::vector<mint> buf(m), fres(m);
            std::copy(this->begin(), this->begin() + std::min(m, n), buf.begin());
            std::copy(res.begin(), res.end(), fres.begin());
            atcoder::internal::butterfly(buf);
            atcoder::internal::butterfly(fres);
            for (int i = 0; i < m; i++) buf[i] *= fres[i];
            atcoder::internal::butterfly_inv(buf);
            std::fill(buf.begin(), buf.begin() + res.size(), mint::raw(0));
            atcoder::internal::butterfly(buf);
            for (int i = 0; i < m; i++) buf[i] *= fres[i];
            atcoder::internal::butterfly_inv(buf);
            mint coef = -(mint::raw(m) * mint::raw(m)).inv();
            for (int i = res.size(); i < std::min(m, n); i++) res.emplace_back(buf[i] * coef);
        }
        return res;
    }
    poly operator+() const { return *this; }
    poly operator-() const { return poly() - *this; }
    friend poly operator+(const poly& lhs, const poly& rhs) {
        return poly(lhs) += rhs;
    }
    friend poly operator-(const poly& lhs, const poly& rhs) {
        return poly(lhs) -= rhs;
    }
    friend poly operator*(const poly& lhs, const poly& rhs) {
        return poly(lhs) *= rhs;
    }
    poly deriv() const {
        const int deg = this->size();
        poly res(std::max(0, deg - 1));
        mint coef = 1;
        for(int i = 1; i < deg; i++) {
            res[i - 1] = (*this)[i] * coef;
            coef++;
        }
        return res;
    }
    poly integ() const {
        const int deg = this->size();
        poly res(deg + 1);
        res[0] = 0;
        if (deg > 0) res[1] = 1;
        auto mod = mint::mod();
        for (int i = 2; i <= deg; i++) res[i] = (-res[mod % i]) * (mod / i);
        for (int i = 0; i < deg; i++) res[i + 1] *= (*this)[i];
        return res;
    }
    poly log() const {
        return (this->deriv() * this->inv()).integ();
    }
    poly exp() const {
        const int deg = this->size();
        
        // 1/iのテーブルの作成
        int r = 2 << std::__lg(deg);
        auto mod = mint::mod();
        vector<mint> iv(r + 1);
        iv[1] = 1;
        for (int i = 2; i <= r; i++) iv[i] = (-iv[mod % i]) * (mod / i);

        auto internal_butterfly_inv = [&](poly& f){
            atcoder::internal::butterfly_inv(f);
            mint iz = mint::raw(f.size()).inv();
            for (auto &&v : f) v *= iz;
        };
        
        poly res = {1, this->size() >= 2 ? (*this)[1] : 0};
        poly c{1}, z1, z2{1, 1};
        for (int m = 2; m < deg; m *= 2){
            auto y = res;
            y.resize(2 * m);
            atcoder::internal::butterfly(y);
            z1 = z2;
            poly z(m);
            for (int i = 0; i < m; i++) z[i] = y[i] * z1[i];
            internal_butterfly_inv(z);
            std::fill(z.begin(), z.begin() + (m / 2), mint::raw(0));
            atcoder::internal::butterfly(z);
            for (int i = 0; i < m; ++i) z[i] *= -z1[i];
            internal_butterfly_inv(z);
            c.insert(c.end(), z.begin() + (m / 2), z.end());
            z2 = c;
            z2.resize(2 * m);
            atcoder::internal::butterfly(z2);

            poly x(m);
            std::copy(this->begin(), this->begin() + std::min(m, deg), x.begin());
            for(int i = 0; i < m; i++) x[i] = x[i + 1] * mint::raw(i + 1);
            x.back() = 0;
            atcoder::internal::butterfly(x);
            for (int i = 0; i < m; ++i) x[i] *= y[i];
            internal_butterfly_inv(x);
            x -= res.deriv();
            x.resize(2 * m);
            for (int i = 0; i < m - 1; ++i) x[m + i] = x[i], x[i] = mint::raw(0);
            atcoder::internal::butterfly(x);
            for (int i = 0; i < 2 * m; ++i) x[i] *= z2[i];
            internal_butterfly_inv(x);
            for(int i = x.size() - 1; i >= 1; i--) x[i] = iv[i] * x[i - 1];
            x[0] = 0;
            for (int i = m; i < min(deg, 2 * m); ++i) x[i] += (*this)[i];
            std::fill(x.begin(), x.begin() + m, mint::raw(0));
            atcoder::internal::butterfly(x);
            for (int i = 0; i < 2 * m; ++i) x[i] *= y[i];
            internal_butterfly_inv(x);
            res.insert(res.end(), x.begin() + m, x.end());
        }
        return res;
    }
    friend std::ostream& operator << (std::ostream &os, const poly vec) noexcept {
        if (vec.empty()) return os;
        os << vec[0].val();
        for (auto it = vec.begin(); ++it != vec.end(); ) os << ' ' << it->val();
        return os;
    }
};
