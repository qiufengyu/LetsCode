#include "../header.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProduct(n + 1, 1), sufProduct(n + 1, 1);
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            preProduct[i+1] = preProduct[i] * nums[i];
            sufProduct[n-i-1] = sufProduct[n-i] * nums[n-i-1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = preProduct[i] * sufProduct[i+1];
        }
        return res;
    }
};