#include "../header.h"

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int current = 0;
        helper(nums, current, 0, res);
        return res;
    }

    void helper(vector<int>& nums, int current, int index, int& res) {
        if (index < nums.size()) {            
            helper(nums, current, index + 1, res);            
            current = current ^ nums[index];   
            helper(nums, current, index + 1, res);
        } else if (index == nums.size()) {
            res += current;
        } 
    }
};

int main() {
    vector<int> nums {5, 1, 6};
    cout << Solution().subsetXORSum(nums) << endl;
    return 0;
}