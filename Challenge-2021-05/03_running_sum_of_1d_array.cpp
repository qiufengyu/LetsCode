#include "../header.h"

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int sum = 0;
        for (auto const& num: nums) {
            sum += num;
            res.push_back(sum);
        }
        return res;
    }
};
