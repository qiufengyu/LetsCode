#include "../header.h"

class Solution {
public:
    double average(vector<int>& salary) {
        long long sum = 0L;
        int n = salary.size(), mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sum += salary[i];
            mn = min(mn, salary[i]);
            mx = max(mx, salary[i]);
        }
        long long r = sum - mn - mx;
        return ((double) r) / (n - 2);
    }
};