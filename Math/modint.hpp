template<const unsigned int MOD> struct prime_modint {
    using mint = prime_modint;
    unsigned int v;
    prime_modint() : v(0) {}
    prime_modint(unsigned int a) { a %= MOD; v = a; }
    prime_modint(unsigned long long a) { a %= MOD; v = a; }
    prime_modint(int a) { a %= (int)(MOD); if(a < 0)a += MOD; v = a; }
    prime_modint(long long a) { a %= (int)(MOD); if(a < 0)a += MOD; v = a; }
    static constexpr int mod() { return MOD; }
    mint& operator++() {v++; if(v == MOD)v = 0; return *this;}
    mint& operator--() {if(v == 0)v = MOD; v--; return *this;}
    mint operator++(int) { mint result = *this; ++*this; return result; }
    mint operator--(int) { mint result = *this; --*this; return result; }
    mint& operator+=(const mint& rhs) { v += rhs.v; if(v >= MOD) v -= MOD; return *this; }
    mint& operator-=(const mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this; }
    mint& operator*=(const mint& rhs) {
        v = (unsigned int)((unsigned long long)(v) * rhs.v % MOD);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {
        assert(0 <= n);
        mint r = 1, x = *this;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const { assert(v); return pow(MOD - 2); }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }
    friend std::ostream& operator << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v; }
};
