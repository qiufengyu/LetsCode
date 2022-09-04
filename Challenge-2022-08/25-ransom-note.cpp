#include "../header.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v1(26, 0), v2(26, 0);
        for (char c: ransomNote) {
            v1[c-'a'] += 1;
        }
        for (char c: magazine) {
            v2[c-'a'] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (v2[i] < v1[i]) {
                return false;
            }
        }
        return true;
    }
};