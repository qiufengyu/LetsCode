#include "../header.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        long right = 0;
        for (int num: nums) {
            left = max(left, num);
            right += num;
        }
        while (left <= right) {
            long mid = (left + right) / 2;
            if (valid(nums, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;        
    }
    
    bool valid(const vector<int>& nums, int m, int mx) {
        int count = 1;
        long sum = 0;
        for (int num: nums) {
            sum += num;
            if (sum > mx) {
                sum = num;
                count++;
                if (count > m) {
                    return false;
                }
            }
        }
        return true;
    }
};