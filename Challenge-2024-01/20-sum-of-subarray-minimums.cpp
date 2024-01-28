#include "../header.h"

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int const M = 1000000007;
        long res = 0L;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i <= arr.size(); ++i) {
            int current = i < arr.size() ? arr[i] : 0;
            while (st.top() != -1 && current < arr[st.top()]) {
                int idx = st.top();
                st.pop();
                int j = st.top();
                int left = idx - j, right = i - idx;
                long s = (left * right * (long)arr[idx]) % M;
                res += s;
                res %= M;
            }
            st.push(i);
        }
        return res;
    }
};