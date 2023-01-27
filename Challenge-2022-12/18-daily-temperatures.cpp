#include "../header.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), nxt = 0;
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            int ti = temperatures[i], tn = temperatures[i+1], in = i + 1;
            while (tn <= ti && in <= n && res[in] > 0) {
                in += res[in];
                tn = temperatures[in];
            }
            if (in < n && temperatures[in] > ti) {
                res[i] = in - i;
            }
        }
        return res;
    }
};