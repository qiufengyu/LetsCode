#include "../header.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int i = 0, j = n - 1;
        n--;
        while (i <= j) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                res[n] = a;
                i++;
            } else {
                res[n] = b;
                j--;
            }
            n--;
        }
        return res;
    }
};