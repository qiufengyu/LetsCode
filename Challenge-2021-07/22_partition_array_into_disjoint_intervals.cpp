#include "../header.h"

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int mx = nums[0], current = nums[0];
        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < mx) {
                mx = current;
                len = i + 1;
            } else {
                current = max(current, nums[i]);
            }
        }
        return len;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().partitionDisjoint(v) << endl;
    return 0;
}