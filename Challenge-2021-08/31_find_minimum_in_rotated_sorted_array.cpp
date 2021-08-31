#include "../header.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int m = s + (e - s) / 2;
        if (nums[0] <= nums[e]) {
            return nums[0];
        }
        while (s < e) {
            m = s + (e - s) / 2;
            if (nums[s] > nums[e]) {
                if (nums[m] >= nums[s]) { // m and s points to same element => e - s = 1
                    s = m + 1;
                } else {
                    e = m;
                }
            } else {
                break;
            }
        }
        return nums[s];        
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().findMin(v) << endl;
    return 0;
}