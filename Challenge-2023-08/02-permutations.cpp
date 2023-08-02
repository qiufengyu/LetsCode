#include "../header.h"

class Solution {
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& array, int length, int n) {
        if (length == n) {
            res.push_back(array);
            return;
        }
        for (int i = 0; i < n; i++) {
            // we know that -10 <= nums[i] <= 10
            if (nums[i] != 11) {
                int tmp = nums[i];
                nums[i] = 11;
                array.push_back(tmp);                
                helper(nums, res, array, length+1, n);
                nums[i] = tmp;
                array.pop_back();
            }            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> array;
        int n = nums.size();
        helper(nums, res, array, 0, n);
        return res;
    }
};

int main() {
    vector<int> nums{1,2,3};
    auto res = Solution().permute(nums);
    print_vector<int>(res);
    return 0;
}