template<const long long MOD = 2305843009213693951, 
        const long long MASK31 = (1ll << 31) - 1, const long long MASK30 = (1ll << 30) - 1>
struct modint61 {
    using mint = modint61;
    long long v;
    modint61() : v(0) {}
    template<class T> modint61(T x) { 
        while(x < 0) x += MOD;
        while(x >= MOD) x -= MOD;
        v = x;
    }
    long long safe_mod(long long x){
        x = (x >> 61) + (x & MOD);
        if (x >= MOD) x -= MOD;
        return x;
    }
    static constexpr long long mod() { return MOD; }
    mint& operator++() {v++; if(v == MOD)v = 0; return *this;}
    mint& operator--() {if(v == 0)v = MOD; v--; return *this;}
    mint operator++(int) { mint result = *this; ++*this; return result; }
    mint operator--(int) { mint result = *this; --*this; return result; }
    mint& operator+=(const mint& rhs) { v += rhs.v; if(v >= MOD) v -= MOD; return *this; }
    mint& operator-=(const mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this; }
    mint& operator*=(const mint& rhs) {
        long long u = v >> 31, d = v & MASK31;
        long long ru = rhs.v >> 31, rd = rhs.v & MASK31;
        long long mid = d * ru + u * rd;
        v = safe_mod(u * ru * 2 + (mid >> 30) + ((mid & MASK30) << 31) + d * rd);
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
    friend bool operator<(const mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }
    friend std::istream& operator >> (std::istream& is, mint& rhs) noexcept {
        long long tmp;
        rhs = mint{(is >> tmp, tmp)};
        return is;
    }
    friend std::ostream& operator << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v; }
};
using mint61 = modint61<2305843009213693951>;
