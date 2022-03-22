#include "../header.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current{};
        res.push_back(current);
        generate(nums, res, current, 0);
        return res;
    }

    void generate(vector<int>& nums, vector<vector<int>>& res, vector<int> current, int index) {
        if (index < nums.size()) {
            // without current index
            generate(nums, res, current, index + 1);
            // with current index
            current.push_back(nums[index]);
            res.push_back(current);
            generate(nums, res, current, index + 1);
        }    
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    vector<vector<int>> res = Solution().subsets(nums);
    print_vector<int>(res);
    return 0;
}