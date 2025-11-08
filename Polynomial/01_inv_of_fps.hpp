template <typename mint> std::vector<mint> inverse(std::vector<mint> &a){
    const int n = a.size();
    std::vector<mint> res;
    res.reserve(a.size());
    res.emplace_back(a[0].inv());
    while(res.size() < a.size()){
        const int m = 2 * res.size();
        std::vector<mint> buf(m), fres(m);
        std::copy(a.begin(), a.begin() + std::min(m, n + 1), buf.begin());
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
        for (int i = res.size(); i < std::min(m, n + 1); i++) res.emplace_back(buf[i] * coef);
    }
    return res;
}
