#include "../header.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0, evenCount = 0;
        for (int const& p: position) {
            if (p & 1) {
                oddCount++;
            } else {
                evenCount++;
            }
        }
        return min(oddCount, evenCount);
    }
};