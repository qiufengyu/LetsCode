#include "../header.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        int prod = nums[0], pmax = nums[0], pmin = nums[0];
        for (int i = 1; i < sz; i++) {
            int tmax = pmax, tmin = pmin;
            pmax = max(nums[i], max(nums[i] * tmax, nums[i] * tmin));
            pmin = min(nums[i], min(nums[i] * tmin, nums[i] * tmax));
            prod = max(prod, pmax);
        }
        return prod;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().maxProduct(nums) << endl;
    return 0;

}