#include "../header.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int sz = position.size();
        int odd = 0, even = 0;
        for (auto p: position) {
            if (p % 2 == 0) {
                even += 1;
            } else {
                odd += 1;
            }
        }
        return min(even, odd);
        
    }
};
