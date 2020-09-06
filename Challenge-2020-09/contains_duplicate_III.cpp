// Please see java solution, lower/upper bound is not very clear

#include "../header.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0) return false;
        multiset<int> mset;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];                     
            if (!mset.empty()) {
                auto lower = mset.lower_bound(x);
                int a = *(lower); // first value >= x
                if ((lower != mset.end() || lower == mset.begin()) && a <= t + x)
                    return true;
                if (lower != mset.begin() && x <= t + *(--lower)) {
                    return true;
                }
            }
            mset.insert(x);
            if (i >= k) {
                mset.erase(nums[i-k]);
            }
        }
        return false;
    }
};

int main() {
    string s;
    int k, t;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cin >> k >> t;
    cout << Solution().containsNearbyAlmostDuplicate(nums, k, t) << endl;
    return 0;
}