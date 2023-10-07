#include "../header.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thirdNumber = INT_MIN;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            int current = nums[i];
            if (current < thirdNumber) {
                return true;
            }
            while (!st.empty() && current > st.top()) {
                thirdNumber = st.top();
                st.pop();
            }
            st.push(current);
        }
        return false;
    }
};