#include "../header.h"

class Solution {
    int m(vector<int>& mapping, int const n) const {
        int ma = 0, aa = n, factor = 1;
        while (aa > 0) {
            ma += (mapping[aa % 10] * factor);
            factor *= 10; 
            aa /= 10;
        }
        return ma; 
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mn, ni;
        for (int i = 0; i < nums.size(); i++) {
            ni[nums[i]] = i;
            mn[nums[i]] = m(mapping, nums[i]);
        }
        sort(nums.begin(), nums.end(), [&mn, &ni](const int a, const int b) -> bool {
            if (mn[a] == mn[b]) {
                return ni[a] < ni[b];
            }
            return mn[a] < mn[b];
            
        });
        return nums;
    }
};

int main() {
    vector<int> mapping{8,9,4,0,2,1,3,5,7,6}, nums{991,338,38};
    auto res = Solution().sortJumbled(mapping, nums);
    print_vector<int>(res);
    return 0;
}