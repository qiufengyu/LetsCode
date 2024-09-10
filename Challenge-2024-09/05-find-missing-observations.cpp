#include "../header.h"

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int nr = rolls.size();
        int totalSum = (nr + n) * mean;
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int rest = totalSum - sum;
        if (rest < n || rest > 6 * n) {
            return {};
        }
        rest -= n;
        vector<int> res(n, 1);
        int i = 0;
        while (rest) {
            if (rest > 5) {
                res[i] = 6;
                rest -= 5;
            } else {
                res[i] = rest + 1;
                rest = 0;
            }
            i++;
        }
        return res;
    }
};