#include "../header.h"

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            set<int> candidate;
            for (auto x: nums) {
                candidate.insert(mask & x);
            }
            int t = res | (1 << i);
            for (auto x: candidate) {
                if (candidate.count(t ^ x)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().findMaximumXOR(nums) << endl;
    return 0;
}