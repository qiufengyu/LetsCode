#include "../header.h"


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> r(i+1, 1);
            for (int j = 1; j < i; j++) {
                r[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(r);
        }
        return res;
    }
};

int main() {
    int numRows = 5;
    auto res = Solution().generate(numRows);
    print_vector<int>(res);
    return 0;
}