#include "../header.h"

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        int res = 0;
        int flip = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flip ^= dq.front();
                dq.pop_front();
            }
            if (flip == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                dq.push_back(1);
                flip ^= 1;
                res++;
            } else {
                dq.push_back(0);
            }
        }
        return res;
    }
};