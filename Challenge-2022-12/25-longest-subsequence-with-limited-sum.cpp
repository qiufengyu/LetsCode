#include "../header.h"

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> v, res;
        int s = 0;
        sort(nums.begin(), nums.end());
        for (auto const num: nums) {
            s += num;
            v.push_back(s);
        }
        for (auto const q: queries) {
            auto i = upper_bound(v.begin(), v.end(), q);       
            res.push_back(i - v.begin());                      
        }
        return res;
    }
};
