#include "../header.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        int i = 1;
        while (i < numRows) {
            ++i;
            vector<int> t(i, 1);
            for (int j = 1; j < i - 1; ++j) {
                t[j] = res[i-2][j] + res[i-2][j-1];
            }
            res.push_back(t);
        }
        return res;
    }
};