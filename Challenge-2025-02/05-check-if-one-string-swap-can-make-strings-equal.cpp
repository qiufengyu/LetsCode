#include "../header.h"

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        size_t n = s1.size();
        int diffIndex = -1, count = 0;
        for (auto i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 2) {
                    return false;
                }
                if (diffIndex < 0) {
                    diffIndex = i;
                } else {
                    if (s1[diffIndex] != s2[i] || s2[diffIndex] != s1[i]) {
                        return false;
                    } else {
                        diffIndex = -1;
                    }
                }
                
            }
        }
        return diffIndex == -1;
    }
};