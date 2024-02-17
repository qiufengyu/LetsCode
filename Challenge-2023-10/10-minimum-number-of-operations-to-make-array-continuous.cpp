#include "../header.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int uniqueCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != nums[uniqueCount]) {
                uniqueCount++;
                nums[uniqueCount] = nums[i];
            }
        }
        uniqueCount += 1;
        int res = n;
        int j = 0;
        for (int i = 0; i < uniqueCount; i++) {
            while (j < uniqueCount && (nums[j] - nums[i]) < n) {
                j++;
            }
            res = min(res, n - (j - i));
        }
        return res;
    }
};

int main() {
    vector<int> nums {8,10,16,18,10,10,16,13,13,16};
    cout << Solution().minOperations(nums) << endl;
}