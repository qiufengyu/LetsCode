#include "../header.h"

inline bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && !isVowel(s[i])) {
                ++i;
            }
            while (j >= 0 && !isVowel(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
            }
            ++i;
            --j;
        }
        return s;
    }
};