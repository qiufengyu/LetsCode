#include "../header.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> m1, m2;
        int l = pattern.size();
        vector<string> res;
        bool flag = true;
        for (string const word: words) {
            m1.clear();
            m2.clear();
            flag = true;
            for (int i = 0; i < l; ++i) {
                char c1 = word[i], c2 = pattern[i];
                if (m1.count(c1) == 0) {
                    m1[c1] = c2;
                }
                if (m2.count(c2) == 0) {
                    m2[c2] = c1;
                }
                if (m1[c1] != c2 || m2[c2] != c1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }
};