#include "../header.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n, 0);
        ps[0] = nums[0] % k;
        for (int i = 1; i < n; i++) {
            ps[i] = (ps[i-1] + nums[i]) % k;
        }
        print_vector<int>(ps);
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (mp.count(ps[i]) && i - mp[ps[i]] > 1) {
                return true;
            } else if (mp.count(ps[i]) == 0) {
                mp[ps[i]] = i;
            }
        }
        for (auto const& p: mp) {
            cout << p.first << ": " << p.second << endl;
        }
        return false;
    }
};

int main() {
    vector<int> nums{23,2,4,6,7};
    int k = 6;
    cout << Solution().checkSubarraySum(nums, k) << endl;
    return 0;
}