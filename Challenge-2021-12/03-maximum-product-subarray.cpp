#include "../header.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        vector<int> pos(sz, 0), neg(sz, 0);
        pos[0] = nums[0];
        neg[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int t = nums[i];
            if (t == 0) {
                pos[i] = 0;
                neg[i] = 0;
            } else if (t > 0) {
                pos[i] = max(t, pos[i-1] * t);
                neg[i] = neg[i-1] * t;
            } else {
                neg[i] = min(t, pos[i-1] * t);
                pos[i] = neg[i-1] * t;
            }
            res = max(res, pos[i]);
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().maxProduct(nums) << endl;
    return 0;
}