template <class T> struct imos2D{
    int h, w;
    std::vector<std::vector<T>> dat;
    imos2D(int H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W + 1, 0)) {}
    void add(int ly, int lx, int ry, int rx, T v){
        assert(0 <= ly && ly <= ry && ry <= h);
        assert(0 <= lx && lx <= rx && rx <= w);
        dat[ry][rx] += v;
        dat[ly][rx] -= v;
        dat[ry][lx] -= v;
        dat[ly][lx] += v;
    }
    void build(){
        for(int i = 0; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                dat[i][j] += dat[i][j - 1];
            }
        }
        for(int i = 0; i <= w; i++) {
            for(int j = 1; j <= h; j++) {
                dat[j][i] += dat[j - 1][i];
            }
        }
    }
    const std::vector<T>& operator[](int y) const {
        assert(0 <= y && y < h);
        return dat[y];
    }
    std::vector<T>& operator[](int y) { 
        assert(0 <= y && y < h);
        return dat[y];
    }
};
