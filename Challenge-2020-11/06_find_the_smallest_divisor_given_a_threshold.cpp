#include "../header.h"

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1000000;
        int res = 1000000;
        while (l <= r) {
            int m = l + (r - l) / 2;
            cout << l << ", " << m << ", " << r << endl;
            int sum = 0;
            for (auto x: nums) {
                if (x % m == 0) {
                    sum += x / m;
                } else {
                    sum += (x / m + 1);
                }
            }
            if (sum <= threshold) {
                r = m - 1;
                res = min(res, m);
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    int threshold;
    cin >> threshold;
    cout << Solution().smallestDivisor(nums, threshold) << endl;
    return 0;
}