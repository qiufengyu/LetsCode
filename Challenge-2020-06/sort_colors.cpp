#include "header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        int p0 = 0, p1 = 0, p2 = sz - 1;
        while (p1 <= p2) {
            if (nums[p1] == 0) {
                nums[p1] = nums[p0];
                nums[p0] = 0;
                p0++;
                p1++;
            } else if (nums[p1] == 1) {
                p1++;
            } else {
                nums[p1] = nums[p2];
                nums[p2] = 2;
                p2--;
            }
        }
    }
};

int main() {
    vector<int> v {2,0,1};
    Solution().sortColors(v);
    for(auto &x: v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}