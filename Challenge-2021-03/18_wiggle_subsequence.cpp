#include "../header.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        int *inc = new int[1000];        
        int *dec = new int[1000];
        memset(inc, 1, 1000);
        memset(dec, 1, 1000);
        for (int i = 1; i < sz; i++) {
            if (nums[i] > nums[i-1]) {
                inc[i] = dec[i-1]+ 1;
                dec[i] = dec[i-1];
            } else if (nums[i] < nums[i-1]) {
                inc[i] = inc[i-1];
                dec[i] = inc[i-1] + 1;
            } else {
                inc[i] = inc[i-1];
                dec[i] = dec[i-1];
            }
        }
        return max(inc[sz-1], dec[sz-1]);
    }
};