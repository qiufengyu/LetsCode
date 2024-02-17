#include "../header.h"

class Solution {
public:
    int partitionString(string s) {
        bool counter[26];
        memset(counter, 0, sizeof(counter));
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (!counter[idx]) {
                counter[idx] = true;
            } else {
                memset(counter, 0, sizeof(counter));
                counter[idx] = true;
                ++res;
            }
        }
        return res + 1;
    }
};