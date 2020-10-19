#include "../header.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return;
        }
        int kk = k % nums.size();
        reverse(nums.end() - kk, nums.end());
        reverse(nums.begin(), nums.end() - kk);
        reverse(nums.begin(), nums.end());
        return;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> v = stringToIntegerVector(s);
    Solution().rotate(v, k);
    print_vector<int>(v);
    return 0;
}