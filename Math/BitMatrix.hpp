#pragma once
#include <utility>
#include <vector>
#include <bitset>
#include <cassert>

template <size_t MAX_COL> struct BitMatrix{
    int H, W;
    std::vector<std::bitset<MAX_COL + 1>> A;
    BitMatrix(int n) : H(n), W(MAX_COL), A(n) {}
    const std::bitset<MAX_COL + 1>& operator[](int k) const { return A[k]; }
    std::bitset<MAX_COL + 1>& operator[](int k) { return A[k]; }
    int gauss_jordan() {
        int rank = 0;
        for(int j = 0; j < W && rank < H; j++) {
            int pivot = -1;
            for(int i = rank; i < H; i++) {
                if(A[i][j]){
                    pivot = i;
                    break;
                }
            }
            if (pivot == -1) continue;
            std::swap(A[pivot], A[rank]);
            for (int i = 0 ; i < H ; i++) {
                if (i != rank && A[i][j]) A[i] ^= A[rank];
            }
            rank++;
        }
        return rank;
    }
    std::pair<int, std::vector<int>> linear_equation(const std::vector<int>& b) {
        assert(H == (int)b.size());
        for (int i = 0; i < H; i++) A[i][W] = b[i] & 1;
        int rank = gauss_jordan();
        for (int i = rank; i < H; i++) {
            if (A[i][W]) return {-1, std::vector<int>{}};
        }
        std::vector<int> res(W, 0);
        for (int i = 0, j = 0; i < rank; i++) {
            while (!A[i][j]) j++;
            res[j] = A[i][W];
        }
        return {rank, res};
    }
};
