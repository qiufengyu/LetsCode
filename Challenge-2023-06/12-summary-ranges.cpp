#include "../header.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) {
            return {};
        }
        if (nums.size() == 1) {
            return {to_string(nums[0])};
        }
        int start = nums[0], end = start;
        for (int i = 1; i < nums.size(); ++i) {
            // nums[i] - end may have overflow
            if (nums[i] == 1 + end) {
                end = nums[i];
            } else {
                if (end == start) {
                    res.push_back(to_string(start));
                } else {
                    string s = to_string(start) + "->" + to_string(end);
                    res.push_back(s);
                }                
                start = nums[i];
                end = start;                
            }
        }
        if (end == start) {
            res.push_back(to_string(start));
        } else {
            string s = to_string(start) + "->" + to_string(end);
            res.push_back(s);
        }  
        return res;        
    }
};

int main() {
    vector<int> nums {0,2,3,4,6,8,9};
    vector<string> res = Solution().summaryRanges(nums);
    print_vector<string>(res);
    return 0;
}