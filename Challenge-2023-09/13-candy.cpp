#include "../header.h"


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), r = 0;
        if (n == 1) {
            return 1;
        }
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                res[i] = res[i-1] + 1;
            }
        }
        for (int j = n - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j+1]) {
                res[j] = max(res[j], res[j+1] + 1);
            }
            r += res[j];
        }
        return r + res[n-1];
    }
};