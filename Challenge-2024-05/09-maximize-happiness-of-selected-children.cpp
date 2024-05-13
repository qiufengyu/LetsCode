#include "../header.h"

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0LL;
        sort(happiness.begin(), happiness.end());
        int n = happiness.size() - 1;
        for (int i = 0; i < k; i++) {
            res += max(happiness[n-i] - i, 0);
        }
        return res;
    }
};