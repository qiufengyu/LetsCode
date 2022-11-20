#include "../header.h"

inline int cross(const vector<int>& O, const vector<int>& A, const vector<int>& B) {
    return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
}

class Solution {    
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size(), k = 0;
        if (n <= 3) {
            return trees;
        }
        vector<vector<int>> H(2*n);
        // sort
        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });
        // lower
        for (int i = 0; i < n; ++i) {
            while (k >= 2 && cross(H[k-2], H[k-1], trees[i]) < 0) { // trees in the same line should also be included
                k--;
            }
            H[k++] = trees[i];
        }
        if (k >= n) {
            return trees;
        }
        // upper
        for (int i = n - 1, t = k + 1; i > 0 ; --i) {
            while (k >= t && cross(H[k-2], H[k-1], trees[i-1]) < 0) {
                k--;
            }
            H[k++] = trees[i-1];
        }
        H.resize(k-1);
        return H;
    }
};