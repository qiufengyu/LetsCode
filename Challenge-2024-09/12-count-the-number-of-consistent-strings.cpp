#include "../header.h"

inline unsigned int getBit(string const& s) {
    unsigned b = 0;
    for (int i = 0; i < s.size(); i++) {
        int sft = s[i] - 'a';
        b |= (1 << sft);
    }
    return b;
}

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unsigned a = getBit(allowed);
        int res = 0;
        for (auto const& w: words) {
            unsigned b = getBit(w);
            if ((a | b) == a) {
                res++;
            }
        }
        return res;
    }
};