#include "../header.h"

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n, false);
        int mx = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < n; ++i) {
            res[i] = ((extraCandies + candies[i]) >= mx);
        }
        return res;
    }
};