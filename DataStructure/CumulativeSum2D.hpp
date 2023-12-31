template <class T> struct CumulativeSum2D{
    int h, w;
    std::vector<std::vector<T>> dat;
    CumulativeSum2D(int H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W + 1, 0)) {}
    CumulativeSum2D(std::vector<std::vector<T>> &A) 
        : h(A.size()), w(A[0].size()), dat(h + 1, std::vector<T>(w + 1, 0)) {
        for(int y = 1; y <= h; y++){
            for(int x = 1; x <= w; x++){
                dat[y][x] = A[y - 1][x - 1] + dat[y][x - 1] + dat[y - 1][x] - dat[y - 1][x - 1];
            }
        }
    }
    void add(int y, int x, T z){
        assert(0 <= y && y < h);
        assert(0 <= x && x < w);
        dat[y + 1][x + 1] += z;
    }
    void build(){
        for(int y = 1; y <= h; y++) {
            for(int x = 1; x <= w; x++) {
                dat[y][x] += dat[y][x - 1] + dat[y - 1][x] - dat[y - 1][x - 1];
            }
        }
    }
    T query(int ly, int lx, int ry, int rx){
        assert(0 <= ly && ly <= ry && ry <= h);
        assert(0 <= lx && lx <= rx && rx <= w);
        return dat[ry][rx] - dat[ly][rx] - dat[ry][lx] + dat[ly][lx];
    }
};
