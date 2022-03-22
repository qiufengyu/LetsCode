#include "../header.h"

class Solution {
public:
    bool count(const int k, const int m, const int n, const int mid) {
        int i = m, j = 1, num = 0;
        // sum # of values <= mid for each column 
        while (i > 0 && j <= n) {
            if (i * j <= mid) {
                num += i;
                ++j;
            } else {
                --i;
            }
        }
        return num >= k;
    }

    int findKthNumber(int m, int n, int k) {
        int left = 1, right =  m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (count(k, m, n, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};