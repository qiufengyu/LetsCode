#include "../header.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < s3) {
                return true;
            }
            while (!st.empty() && st.top() < nums[i]) {
                s3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};