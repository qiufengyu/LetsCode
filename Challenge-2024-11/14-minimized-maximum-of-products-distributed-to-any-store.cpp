#include "../header.h"

class Solution {
    bool check(vector<int>& q, int n, int x) {
        int nn = 0;
        for (int i = 0; i < q.size(); i++) {
            nn += (q[i] / x);
            if ((q[i] % x) > 0) {
                nn++;
            }
        }
        return nn <= n;
    } 
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long sum = accumulate(quantities.begin(), quantities.end(), 0LL);
        int start = sum / n, end = *max_element(quantities.begin(), quantities.end());
        start = max(start, 1);
        int m = start + (end - start) / 2;
        while (start < end) {
            m = start + (end - start) / 2;
            if (check(quantities, n, m)) {
                end = m;
            } else {
                start = m + 1;
            }
        }
        return end;
    }
};