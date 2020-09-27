#include "../header.h"

struct {
    bool operator()(int a, int b) const {   
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }   
} cmp;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().largestNumber(v) << endl;
    return 0;
}