template <class mint> struct StaticRangeLCM {
    int N, logN, mx;
    std::vector<int> start;
    std::vector<std::pair<int, mint>> dat;
    StaticRangeLCM(std::vector<int> &a) : mx(*std::max_element(a.begin(), a.end())) {
        logN = ceil_pow2(a.size());
        N = 1 << logN;
        start.resize(2 * N + 1);
        // 各数を割り切る最小の素数を代入
        // 逆数を代入
        std::vector<int> mn_pr(mx + 1);
        std::vector<mint> inv(mx + 1);
        for(int i = 2; i <= mx; i++){
            if(mn_pr[i] != 0) continue;
            inv[i] = mint(i).inv();
            for(int j = i; j <= mx; j += i){
                if(mn_pr[j] == 0) mn_pr[j] = i;
            }
        }
        std::vector<std::pair<int, std::pair<int,mint>>> point;
        std::vector<int> pos(mx + 1, -1);
        std::vector<std::pair<int, mint>> lst(2 * N, std::make_pair(-1, 0));
        for(int i = 0; i < (int)(a.size()); i++){
            if(a[i] == 1) continue;
            int v = a[i], prv = -1, tmp = 0;
            for(int j = 0; j <= logN; j++){
                int p = (i + N) >> j;
                if(lst[p].first != -1 && lst[p].first != i){
                    start[p + 1]++;
                    point.emplace_back(p, lst[p]);
                }
                lst[p] = std::make_pair(i, a[i]);
            }
            while(v != 1){
                if(mn_pr[v] == prv) tmp *= mn_pr[v];
                else tmp = mn_pr[v];
                if(pos[tmp] != -1){
                    int lv = pos[tmp] + N;
                    for(int j = 0; j <= logN; j++){
                        int p = lv >> j;
                        if(lst[p].first == i){
                            lst[p].second *= inv[mn_pr[tmp]];
                        }else{
                            start[p + 1]++;
                            point.emplace_back(p, lst[p]);
                            lst[p] = std::make_pair(i, inv[mn_pr[tmp]]);
                        }
                    }
                }
                pos[tmp] = i;
                prv = mn_pr[v];
                v /= mn_pr[v];
            }
        }
        for(int i = 1; i < 2 * N; i++){
            if(lst[i].first == -1) continue;
            start[i + 1]++;
            point.emplace_back(i, lst[i]);
        }
        dat.resize(point.size());
        for(int i = 0; i < 2 * N; i++) start[i + 1] += start[i];
        auto cnt = start;
        for(auto &&[u, v] : point) dat[cnt[u]++] = v;
        for(int i = 1; i < 2 * N; i++){
            int L = start[i], R = start[i + 1];
            for(int j = L; j + 1 < R; j++){
                dat[j + 1].second *= dat[j].second;
            }
        }
    }
    mint prod(int l, int r){
        mint mul = 1, div = 1;
        int L = l + N, R = r + N;
        while(L < R){
            if(L & 1){
                mul *= get(L, r);
                div *= get(L++, l);
            }
            if(R & 1){
                mul *= get(--R, r);
                div *= get(R, l);
            }
            L >>= 1, R >>= 1;
        }
        return mul / div;
    }
    private:
    mint get(int p, int r){
        int ng = start[p] - 1, ok = start[p + 1];
        while(ng + 1 < ok){
            int mid = (ok + ng) / 2;
            (dat[mid].first >= r ? ok : ng) = mid;
        }
        return ok > start[p] ? dat[ok - 1].second : 1;
    }
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
};