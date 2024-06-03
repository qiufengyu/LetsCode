#include "../header.h"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(s[i] - t[i]);
        }
        int start = 0, current = 0, res = 0, cost = 0;
        while (current < n) {
            while (current < n && cost + diff[current] < maxCost) {
                cost += diff[current];
                current++;
            }
            res = max(res, current - start + 1);
            cost -= diff[start];
            start++;
        }
        return res;
    }
};