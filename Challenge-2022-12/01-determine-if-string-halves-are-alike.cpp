#include "../header.h"

bool isVowel(char v) {
    return (0x208222>>(v&0x1f))&1;
}

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            if (isVowel(s[i])) {
                c1++;
            }
            if (isVowel(s[i/2])) {
                c2++;
            }
            
        }
        return c1 == c2;
    }
};