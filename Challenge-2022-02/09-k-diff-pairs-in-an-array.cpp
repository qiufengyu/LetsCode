#include "../header.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n: nums) {
            ++m[n];
        }
        int res = 0;
        if (k == 0) {
            for (pair<int, int> p: m) {
                if (p.second > 1) {
                    ++res;
                }
            }
            return res;
        }
        // k > 0
        for (pair<int, int> p: m) {
            if (m.count(p.first + k)) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().findPairs(nums, k) << endl;
    return 0;
}