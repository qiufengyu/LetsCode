#include "../header.h"

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        long c[101] = {0};
        for (int i = 0; i < 101; i++) {
            c[i] = 0;
        }
        for (int a: arr) {
            ++c[a];
        }
        long ans = 0;
        for (int i = 0; i <= target; ++i) {
            for (int j = i; j <= target; ++j) {
                const int k = target - i - j;
                if (k < 0 || k < j || k >= 101) {
                    continue;
                }
                if (!c[i] || !c[j] || !c[k]) {
                    continue;
                }
                if (i == j && j == k) {
                    ans += (c[i] - 2) * (c[i] - 1) * c[i] / 6;
                }
                else if (i != j && j == k) {
                    ans += c[i] * c[j] * (c[j] - 1) / 2;
                }
                else if (i == j && j != k) {
                    ans += c[k] * c[j] * (c[j] - 1) / 2;
                } else {
                    ans += c[i] * c[j] * c[k];
                }
            }
        }
        return ans % mod;
    }
};