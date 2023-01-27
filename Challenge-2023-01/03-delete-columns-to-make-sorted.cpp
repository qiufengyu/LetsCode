#include "../header.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        int res = 0;
        char c1, c2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                c1 = strs[j][i];
                c2 = strs[j+1][i];
                if (c1 > c2) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};