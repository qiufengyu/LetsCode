#include "../header.h"

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            int x = nums[queries[i][1]];
            int y = x + queries[i][0];
            nums[queries[i][1]] = y;
            if (x % 2 == 0) {
                sum -= x;
            }
            if (y % 2 == 0) {
                sum += y;
            }
            res.push_back(sum);
        }
        return res;
    }
};