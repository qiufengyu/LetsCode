#include "../header.h"

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        int maxPotion = *(potions.end() - 1);
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            long long p = ceil((1.0 * success) / spells[i]);
            auto li = lower_bound(potions.begin(), potions.end(), p) - potions.begin();
            res.push_back(m - li);
        }
        return res;
    }
};