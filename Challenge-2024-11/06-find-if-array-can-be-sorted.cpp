#include "../header.h"
#include <bitset>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        int pMX = INT_MIN;
        int currentBits = __builtin_popcount(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int newBits = __builtin_popcount(nums[i]);
            if (newBits == currentBits) {
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            } else {
                currentBits = newBits;
                if (mn < pMX) {
                    return false;
                }
                pMX = mx;
                mn = nums[i];
                mx = nums[i];
            }
        }
        return mn > pMX;
    }
};