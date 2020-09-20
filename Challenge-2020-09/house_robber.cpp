#include "../header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        } else if (sz == 1) {
            return nums[0];
        } else {
            vector<int> r(sz, 0);
            vector<int> nr(sz, 0);
            r[0] = nums[0];
            nr[0] = 0;
            for (int i = 1; i < sz; i++) {
                r[i] = max(nr[i-1] + nums[i], r[i-1]);
                nr[i] = max(nr[i-1], r[i-1]);
            }
            return max(r[sz-1], nr[sz-1]);
        }
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().rob(v) << endl;
    return 0;
}