#include "../header.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& a: A) {
            reverse(a.begin(), a.end());
            for (auto& x: a) {
                x = 1 - x;
            }
        }
        return A;
    }
};
