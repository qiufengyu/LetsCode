#include "../header.h"

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m;
        int res = 0;
        for (int num: nums) {
            ++m[num];
        }
        for (auto p: m) {
            if (p.first <= k / 2) {
                int temp =  min(p.second, m[k - p.first]);
                cout << "will add " << temp << " for " << p.first << " and " << k - p.first << endl;
                res += temp;
            }
        }
        if (k % 2 == 0) {
            res -= ((m[k / 2] + 1) / 2);
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    int k;
    cin >> k;
    cout << Solution().maxOperations(nums, k) << endl;
    return 0;
}