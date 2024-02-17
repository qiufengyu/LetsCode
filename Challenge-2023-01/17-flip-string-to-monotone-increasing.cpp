#include "../header.h"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1 = 0, countFlip = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                countFlip++;
                countFlip = min(countFlip, count1);
            } else {
                count1++;
            }
        }
        return countFlip;
    }
};