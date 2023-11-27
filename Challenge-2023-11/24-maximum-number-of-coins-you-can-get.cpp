#include "../header.h"

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0, nnn = piles.size();
        for (int i = nnn - 2; i > nnn / 3 - 1; i -= 2) {
            res += piles[i];
        }
        return res;
    }
};