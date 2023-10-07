#include "../header.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // this solution will modify the array...
        // the correct solution would be two-pointer way :D
        for (int i = 0; i < (int)nums.size(); i++) {
            int v = nums[i];
            if (v != i + 1) {
                if (nums[v-1] == v) {
                    return v;
                }
                swap(nums[i], nums[v-1]);
                i--;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums {3,1,3,4,2};
    cout << Solution().findDuplicate(nums) << endl;
    return 0;
}