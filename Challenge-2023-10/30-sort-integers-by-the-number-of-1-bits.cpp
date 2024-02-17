#include "../header.h"

int bits(int const n) {

}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int const& lhs, int const& rhs) -> bool {
            int l = __popcount(lhs), r = __popcount(rhs);
            if (l == r) {
                return lhs < rhs;
            }
            return l < r;
        });
        return arr;
    }
};