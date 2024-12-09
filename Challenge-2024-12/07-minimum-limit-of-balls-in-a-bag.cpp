#include "../header.h"

class Solution {
    bool check(vector<int>& nums, const int maxOperations, int size) {
        int op = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > size) {
                op += ((nums[i] - 1) / size);
                if (op > maxOperations) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 0, h = *max_element(nums.begin(), nums.end());
        int m = l + (h - l) / 2;
        while (l < h) {
            m = l + (h - l) / 2;
            if (check(nums, maxOperations, m)) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return h;
    }
};