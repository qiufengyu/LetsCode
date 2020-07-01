#include "header.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (auto &x: nums) {
            low = ~high & (low ^ x);
            high = ~low & (high ^ x);
        }
        return low;
    }
};

int main() {
    vector<int> v {0,1,0,1,0,1,99};
    cout << Solution().singleNumber(v) << endl;
    return 0;
}

