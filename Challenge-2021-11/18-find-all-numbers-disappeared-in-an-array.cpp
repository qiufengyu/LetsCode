#include "../header.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != (i+1)) {
                if (nums[i] == nums[nums[i]-1]) {
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != (i+1)) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    auto res = Solution().findDisappearedNumbers(v);
    print_vector<int>(res);
    return 0;
}