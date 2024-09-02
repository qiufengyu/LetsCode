#include "../header.h"

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = accumulate(chalk.begin(), chalk.end(), 0);
        k %= sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k - chalk[i] < 0) {
                return i;
            }
            k -= chalk[i];
        }
        return chalk.size() - 1;
    }
};