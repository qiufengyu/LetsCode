#include "../header.h"

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int sz = tops.size();
        vector<int> tCount(7, 0), bCount(7, 0), same(7, 0);
        for (int i = 0; i < sz; ++i) {
            ++tCount[tops[i]];
            ++bCount[bottoms[i]];
            if (tops[i] == bottoms[i]) {
                ++same[tops[i]];
            }
        }
        for (int i = 1; i < 7; ++i) {
            if (tCount[i] + bCount[i] - same[i] == sz) {
                return sz - max(tCount[i], bCount[i]);
            }
        }
        return -1;
    }
};