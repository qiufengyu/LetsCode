#include "../header.h"

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word[0] >= 'A' && word[0] <= 'Z') {
            bool allL = true, allU = true;
            for (int i = 1; i < word.size(); ++i) {
                allL = allL && (word[i] >= 'a' && word[i] <= 'z');
                allU = allU && (word[i] >= 'A' && word[i] <= 'Z');
            }
            return (allL || allU);
        }
        bool allLowercase = true;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] < 'a' || word[i] > 'z') {
                return false;
            }
        }
        return true;
        
    }
};
