#include "../header.h"

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int c = 0, res = 0;
        for (int i = 0; i < costs.size(); ++i) {
            c += costs[i];
            if (c <= coins) {
                ++res;
            }
            else {
                break;
            }
        }
        return res;
    }
};