#include "../header.h"

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        while (l <= r) {
            int m = l + (r - l) / 2;
            // cout << l << " - " << m << " - " << r << endl;
            if (find(n, index, maxSum, m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l - 1;
    }

    bool find(int n, int index, int maxSum, int m) {
        long ls = 0, rs = 0;
        if (m > index) {
            ls += (long)(m + m - index) * (index + 1) / 2;
        } else {
            ls += (long)(1 + m) * m / 2 + (index - m + 1);
        }
        if (m < n - index) {
            rs += (long)(1 + m) * m / 2 + (n - index - m);
        } else {
            rs += (long)(m + m - (n - index) + 1) * (n - index) / 2;;
        }
        return ls + rs - m <= maxSum;
    }
};

int main() {
    int n = 4, index = 2, maxSum = 6;
    cout << Solution().maxValue(n, index, maxSum) << endl;
    return 0;
}