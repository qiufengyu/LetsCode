#include "../header.h"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int left = values[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            int right = values[i] - i;
            res = max(res, left + right);
            left = max(left, values[i] + i);
        }
        return res;
    }
};