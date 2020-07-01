#include "header.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <= e) { // must include equal           
            cout << mid << ": " << nums[mid] << endl;
            if (nums[mid] < target) {
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                return mid;
            }
            mid = s + (e - s) / 2;
            cout << s << ", " << mid << ", " << e << endl;
        }
        return mid;
    }
};

int main() {
    vector<int> v {1,3,5,6};
    cout << Solution().searchInsert(v, 7) << endl;
    return 0;
}