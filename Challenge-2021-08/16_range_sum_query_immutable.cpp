#include "../header.h"

class NumArray {
    vector<int> _sum;
public:
    NumArray(vector<int>& nums) {
        _sum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            _sum[i+1] = _sum[i] + nums[i];
        }        
    }
    
    int sumRange(int left, int right) {
        return _sum[right+1] - _sum[left];
    }
};
