struct RollingHash{
    long long BASE = 257, RMOD = (1ll << 61) - 1;
    long long MASK31 = (1ll << 31) - 1, MASK30 = (1ll << 30) - 1;
    int n;
    std::vector<long long> dat, dat2, base_pow;
    RollingHash()  {}
    RollingHash(std::string &s) : n(s.size()), dat(n+1), dat2(n+1), base_pow(n+1) {
        base_pow[0] = 1;
        for(int i = 0; i < n; i++){
            dat[i+1] = safe_mod(internal_mul(dat[i], BASE) + s[i]);
            dat2.rbegin()[i+1] = safe_mod(internal_mul(dat2.rbegin()[i], BASE) + s.rbegin()[i]);
            base_pow[i+1] = internal_mul(base_pow[i], BASE);
        }
    }
    long long internal_mul(long long a, long long b){
        long long au = a >> 31, ad = a & MASK31;
        long long bu = b >> 31, bd = b & MASK31;
        long long mid = ad * bu + au * bd;
        long long midu = mid >> 30;
        long long midd = mid & MASK30;
        return safe_mod(au * bu * 2 + midu + (midd << 31) + ad * bd);
    }
    long long safe_mod(long long x){
        long long xu = x >> 61, xd = x & RMOD;
        long long res = xu + xd;
        if (res >= RMOD) res -= RMOD;
        return res;
    }
    long long hash(int l, int r){
        long long res = dat[r] - internal_mul(dat[l], base_pow[r - l]);
        if(res < 0)res += RMOD;
        return res;
    }
    long long revhash(int l, int r){
        long long res = dat2[l] - internal_mul(dat2[r], base_pow[r - l]);
        if(res < 0)res += RMOD;
        return res;
    }
    long long joint(long long lhs, long long rhs, long long rsize){
        long long res = internal_mul(lhs, base_pow[rsize]) + rhs;
        if(res >= RMOD) res -= RMOD;
        return res;
    }
};
