#include "../header.h"

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < candidates.size(); j++) {
                if ((candidates[j] & 1) != 0) {
                    count++;
                }
                candidates[j] = (candidates[j] >> 1);
            }
            res = max(res, count);
        }
        return res;
    }
};