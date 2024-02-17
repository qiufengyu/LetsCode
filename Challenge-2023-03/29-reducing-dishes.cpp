#include "../header.h"

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int sum = 0, res = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (sum + satisfaction[i] > 0) {
                res += (sum + satisfaction[i]);
                sum += satisfaction[i];
            }
        }
        return res;
    }
};