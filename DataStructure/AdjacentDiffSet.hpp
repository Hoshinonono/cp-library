struct Adjacent_Diff_Set {
    const long long inf = 1ll << 60;
    std::multiset<long long> S, D;
    Adjacent_Diff_Set(){
        S.insert(-inf);
        S.insert(inf);
    }
    void add(long long v){
        auto ba_itr = S.lower_bound(v);
        auto fr_itr = std::prev(ba_itr);
        if(*ba_itr != inf && *fr_itr != -inf){
            D.erase(D.find(*ba_itr - *fr_itr));
        }
        if(*ba_itr != inf) D.insert(*ba_itr - v);
        if(*fr_itr != -inf) D.insert(v - *fr_itr);
        S.insert(v);
    }
    void del(long long v){
        auto it = S.lower_bound(v);
        auto ba_itr = std::next(it);
        auto fr_itr = std::prev(it);
        if(*ba_itr != inf) D.erase(D.find(*ba_itr - v));
        if(*fr_itr != -inf) D.erase(D.find(v - *fr_itr));
        if(*ba_itr != inf && *fr_itr != -inf){
            D.insert(*ba_itr - *fr_itr);
        }
        S.erase(it);
    }
    long long max(){ return *std::next(S.rbegin()); }
    long long min(){ return *std::next(S.begin()); }
    long long max_diff(){ return D.empty() ? 0 : *D.rbegin(); }
    long long min_diff(){ return D.empty() ? 0 : *D.begin(); }
};