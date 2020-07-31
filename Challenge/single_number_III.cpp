#include "../header.h"
#include <numeric>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        int v1 = 0, v2 = 0;
        for (auto x: nums) {
            if (x & diff) v1 ^= x;
            else v2 ^= x;
        }
        return vector<int> {v1, v2};
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    for(auto x: Solution().singleNumber(v)) {
        cout << x << endl;
    }
    return 0;
}