#include "../header.h"

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size(), false);
        for (int i = 0; i < l.size(); i++) {
            // vector<int> t(nums.begin() + l[i], nums.begin() + r[i] + 1);
            res[i] = check(nums, l[i], r[i]);
        }
        return res;
    }

    bool check(vector<int>& arr, int l, int r) {
        unordered_set<int> st;
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = l; i <= r; i++) {
            st.insert(arr[i]);
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
        int diff = (mx - mn) / (r - l);
        if (diff * (r - l) != (mx - mn)) {
            return false;
        }
        int start = mn + diff;
        while (start < mx) {
            if (st.find(start) == st.end()) {
                return false;
            }
            start += diff;
        }
        return true;
    }
};