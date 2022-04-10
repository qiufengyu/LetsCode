#include "../header.h"

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> m;
        for (int num: arr) {
            ++m[num];
        }
        long res = 0;
        for (int i = 0; i <= target; ++i) {
            for (int j = i; j <= target; ++j) {
                int k = target - i - j;
                if (k < j || k > 100) {
                    continue;
                }
                if (m.count(i) > 0 && m.count(j) > 0 && m.count(k) > 0) {
                    if (i == j && j == k) {
                        res += (m[i] - 2) * (m[i] - 1) * m[i] / 6;
                    } else if (i != j && j == k) {
                        res += m[j] * (m[j] - 1) * m[i] / 2;
                    } else if (i == j && j != k) {
                        res += m[k] * m[j] * (m[j] - 1) / 2;
                    } else {
                        res +=  m[k] * m[j] * m[i];
                    }
                }
            }
        }
        return res % (1e9 + 7);
    }
};