#include "../header.h"

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> mp;
        int mx = INT_MIN, mn = INT_MAX;
        for (auto const& i: nums) {
            mx = max(mx, i);
            mn = min(mn, i);
            ++mp[-i];
        }
        // we don't need to reduce the min number
        mp.erase(-mn);
        int res = 0, cnt = 0;
        for (auto const& p: mp) {
            cout << p.first << " -> " << p.second << endl;
            cnt += p.second;
            res += cnt;
        }
        return res;
    }
};

int main() {
    vector<int> nums {5,1,3};
    cout << Solution().reductionOperations(nums) << endl;
    return 0;
}