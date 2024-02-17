#include "../header.h"

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int n = arr.size();
        int mx = arr[0], mn = arr[0];
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] >= mx) {
                mx = arr[i];
            }
            if (arr[i] <= mn) {
                mn = arr[i];
            }
        }
        if (mn == mx) {
            return true;
        }
        if ((mx - mn) % (n - 1) != 0) {
            return false;
        }
        int d = (mx - mn) / (n - 1);
        for (int i = mn; i <= mx; i += d) {
            if (st.count(i) == 0) {
                return false;
            }
        }
        return true;
    }
};