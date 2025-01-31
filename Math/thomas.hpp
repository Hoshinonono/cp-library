template<class T> vector<T> thomas(const vector<T> &a, const vector<T> &b, 
                                   const vector<T> &c, const vector<T> &d){
    const int n = b.size();
    vector<T> scratch(n), x(n);
    scratch[0] = c[0] / b[0];
    x[0] = d[0] / b[0];
    for (int i = 1; i < n; i++) {
        const T div = b[i] - a[i] * scratch[i - 1];
        if (i + 1 < n) scratch[i] = c[i] / div;
        x[i] = (d[i] - a[i] * x[i - 1]) / div;
    }

    for (int i = n - 2; i >= 0; i--)
        x[i] -= scratch[i] * x[i + 1];
    
    return x;
}