#include "../header.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        vector<string> res;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - 1 != end) {
                if (start == end) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
            }
            end = nums[i];
        }
        if (start == end) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(end));
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    vector<string> res = Solution().summaryRanges(nums);
    print_vector<string>(res);
    return 0;
}