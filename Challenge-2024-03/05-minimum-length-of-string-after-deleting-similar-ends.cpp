#include "../header.h"

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && i < s.size() && j >= 0 && s[i] == s[j]) {
            int oi = i, oj = j;
            char x = s[i];
            while (i < s.size() && s[i] == x) {
                i++;
            }
            while (j >= 0 && s[j] == x) {
                j--;
            }
        }
        return j - i + 1 > 0 ? j - i + 1 : 0;
    }
};