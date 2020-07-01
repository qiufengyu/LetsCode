#include "header.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, h = nums.size();
        int mid = l + (h - l) / 2;
        while (l < h) {
            int count = 0;
            mid = l + (h - l) / 2;
            for (auto &x: nums) {
                if (x <= mid) {
                    count++;
                }
            }
            if (count <= mid) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return h;
    }
};

int main() {
    vector<int> v {1,4,3,3,2};
    cout << Solution().findDuplicate(v) << endl;
    return 0;
}