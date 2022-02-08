#include "../header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int start = 1, current = 1, l = nums.size();
        int prev = nums[0], prevCount = 1;
        while (current < l) {
            if (nums[current] == prev) {
                ++prevCount;
            } else {
                prevCount = 1;
                prev = nums[current];
            }
            if (prevCount <= 2) {
                nums[start] = nums[current];
                ++start;
            } else {
                ++res;
            }
            ++current;
        }
        // while (start < l) {
        //     nums[start++] = -1;
        // }
        return l - res;        
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().removeDuplicates(nums) << endl;
    print_vector<int>(nums);
    return 0;
}