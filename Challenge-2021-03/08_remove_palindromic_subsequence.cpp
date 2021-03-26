#include "../header.h"

class Solution {
public:
    int removePalindromeSub(string s) {
        size_t sz = s.size();
        if (sz == 0) {
            return 0;
        }
        bool isPalindrome = true;
        for (int i = 0; i < sz /2; i++) {
            if (s[i] != s[sz-1-i]) {
                isPalindrome = false;
            }
        }
        return isPalindrome ? 1 : 2;
    }
};
