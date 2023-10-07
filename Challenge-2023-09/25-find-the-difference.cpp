#include "../header.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vs(26, 0), vt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            vs[s[i]-'a']++;
            vt[t[i]-'a']++;
        }
        vt[t.back()-'a']++;
        for (int i = 0; i < 26; i++) {
            if (vs[i] != vt[i]) {
                return (i + 'a');
            }
        }
        return 0;
    }
};