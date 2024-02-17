#include "../header.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        if (sz1 > sz2) {
            return false;
        }
        vector<int> v1(26, 0), v2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            v1[s1[i]-'a'] += 1;
            v2[s2[i]-'a'] += 1;
        }
        for (int i = sz1; i <= sz2; ++i) {
            if (v1[s2[i-sz1] - 'a'] > 0) {
                if (v1 == v2) {
                    return true;
                }
            }            
            if (i < sz2) {
                v2[s2[i-sz1] - 'a'] -= 1;
                v2[s2[i] - 'a'] += 1;
            }
        }
        return false;
    }
};