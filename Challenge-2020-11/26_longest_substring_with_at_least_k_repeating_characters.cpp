#include "../header.h"

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int i = 0;
        while ( i + k <= s.size()) {
            int m[26] = {0};
            int mask = 0;
            int cur = i;
            for (int j = i; j < s.size(); j++) {
                int c = s[j] - 'a';
                ++m[c];
                if (m[c] < k) {
                    mask |= (1 << c);
                } else {
                    mask &= (~(1 << c));
                }
                if (mask == 0) {
                    res = max(res, j - i + 1);
                    cur = j;
                }
            }
            i = cur + 1;
        }
        return res;
    }
};