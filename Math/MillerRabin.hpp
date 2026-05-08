#pragma once
#include <utility>
#include <vector>

struct Miller_Rabin {
    unsigned long long mul_mod(unsigned long long a, unsigned long long b, unsigned long long m) {
        unsigned long long ans = 0;
#ifndef __SIZEOF_INT128__
            if(a > b) std::swap(a, b);
            while(b){
                if(b & 1){
                    ans += a;
                    if(ans >= m) ans -= m;
                }
                if((a <<= 1) >= m) a -= m;
                b >>= 1;
            }
#else
            ans = (unsigned long long)((__int128)(a) * (__int128)(b) % m); 
#endif
        return ans;
    }
    unsigned long long pow_mod(unsigned long long x, unsigned long long n, unsigned long long m) {
        if (m == 1) return 0;
        unsigned long long r = 1;
        unsigned long long y = x % m;
        while (n) {
            if (n & 1) r = mul_mod(r, y, m);
            y = mul_mod(y, y, m);
            n >>= 1;
        }
        return r;
    }
    bool is_prime(unsigned long long n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        unsigned long long d = n - 1;
        while (d % 2 == 0) d /= 2;
        static std::vector<std::vector<long long>> 
            bases = {{2, 6, 61}, {2, 325, 9375, 28178, 450775, 9780504, 1795265022}};
        for (long long a : bases[d > 4759123141]) {
            unsigned long long t = d;
            unsigned long long y = pow_mod(a, t, n);
            if(a % n){
                while (t != n - 1 && y != 1 && y != n - 1) {
                    y = mul_mod(y, y, n);
                    t <<= 1;
                }
            }
            if (y != n - 1 && t % 2 == 0) return false;
        }
        return true;
    }
};
