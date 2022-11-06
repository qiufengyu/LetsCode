#include "../header.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        int sum = 0;
        unordered_map<int, int> m;
        m.emplace(0, -1);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sum = sum % k;
            if (m.count(sum) && i - m[sum] >= 2) {
                return true;
            }
            m.emplace(sum, i);
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().checkSubarraySum(nums, k) << endl;
    return 0;
}