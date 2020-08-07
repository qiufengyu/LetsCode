#include "../header.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[nums[i] - 1]) {
                int temp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[temp - 1] = temp;
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    for (auto x: Solution().findDuplicates(nums)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}