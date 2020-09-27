#include "../header.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b;
        int countA = 0, countB = 0;
        for (auto n: nums) {
            if (n == a) countA++; 
            else if (n == b) countB++;
            else if (countA == 0) { countA++; a = n; }
            else if (countB == 0) { countB++; b = n; }
            else { countA--; countB--; }
        }
        vector<int> res;
        countA = 0;
        countB = 0;
        for (auto n: nums) {
            if (n == a) countA++;
            if (n == b) countB++;
        }
        if (countA > nums.size() / 3) {
            res.push_back(a);
        }
        if (countB > nums.size() / 3) {
            res.push_back(b);
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    auto res = Solution().majorityElement(nums);
    print_vector(res);
    return 0;
}