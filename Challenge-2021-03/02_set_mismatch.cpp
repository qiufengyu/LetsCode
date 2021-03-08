#include "../header.h"

class Solution {
public:
    // denote the duplicated number is a, and the missing number is b
    // (sum of 1 to n) -  (sum of num) = b - a = X
    // (sum of 1^2 to n^2) - (sum of num^2) = b^2 - a^2 = (b + a)*(b - a) = Y
    // then a = (Y / X - X) / 2, b = (Y / X + X) / 2
    vector<int> findErrorNums(vector<int>& nums) {
        size_t n = nums.size();
        long long sum = n * (n + 1) / 2;
        long long sum2 = (n * (n + 1) * (2 * n + 1)) / 6;
        for (auto& x: nums) {
            sum -= x;
            sum2 -= (x * x);
        }
        // X = sum, Y = sum2
        return vector<int> {int (sum2 / sum - sum) / 2, int (sum2 / sum + sum) / 2};
    }

    vector<int> findErrorNums1(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        unordered_set<int> s;
        int t = -1;
        for (auto& x: nums) {
            sum -= x;
            if (s.count(x)) {
                t = x;
            }
            s.insert(x);
        }
        return vector<int> {t, t + sum};
    }
};