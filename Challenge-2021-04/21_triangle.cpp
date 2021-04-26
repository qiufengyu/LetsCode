#include "../header.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> dp0(row, 0), dp1(row, 0);
        dp0[0] = triangle[0][0];
        int r = 1;
        while (r < row) {
            if (r % 2 == 1) {
                dp1[0] = dp0[0] + triangle[r][0];
                for (int i = 1; i < r; ++i) {
                    dp1[i] = min(dp0[i], dp0[i-1]) + triangle[r][i];
                }
                dp1[r] = dp0[r-1] + triangle[r][r];
            } else {
                dp0[0] = dp1[0] + triangle[r][0];
                for (int i = 1; i < r; ++i) {
                    dp0[i] = min(dp1[i], dp1[i-1]) + triangle[r][i];
                }
                dp0[r] = dp1[r-1] + triangle[r][r];
            }
            r++;
        }
        if (r % 2) {
            return *min_element(dp0.begin(), dp0.end());
        }
        else {
            return *min_element(dp1.begin(), dp1.end());
        }
    }
};