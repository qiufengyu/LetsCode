#include "../header.h"

// mathematical way:
// size_t n = nums.size();
// long long sum = n * (n + 1) / 2;
// long long sum2 = (n * (n + 1) * (2 * n + 1)) / 6;
// for (auto& x: nums) {
//     sum -= x;
//     sum2 -= (x * x);
// }
// sum = missed - duplicate
// sum2 = missed^2 - duplicated^2

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0, n = nums.size(), gs = n * (n + 1) / 2;
        int duplicated = -1;
        bool dup = false;
        unordered_set<int> us;
        for (auto const i: nums) {
            sum += i;
            if (!dup) {
                if (us.count(i)) {
                    duplicated = i;
                    dup = true;
                }
                us.insert(i);
            }
        }
        return {duplicated, gs + duplicated - sum};
    }
};