#include "../header.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for (auto const& num: nums) {
            if (!st.count(num-1)) {
                int current = num;
                int currentLength = 1;
                while (st.count(current+1)) {
                    ++current;
                    ++currentLength;
                }
                res = max(res, currentLength);
            }            
        }
        return res;
    }
};