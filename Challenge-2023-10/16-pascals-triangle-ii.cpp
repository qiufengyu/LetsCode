#include "../header.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp1(rowIndex+1, 0), dp2(rowIndex+1, 0);
        for (int i = 0; i <= rowIndex; i++) {
            dp2[0] = 1;
            dp2[i] = 1;
            for (int j = 1; j < i; j++) {
                dp2[j] = dp1[j-1] + dp1[j];
            }
            swap(dp1, dp2);
        }
        return dp1;
    }
};