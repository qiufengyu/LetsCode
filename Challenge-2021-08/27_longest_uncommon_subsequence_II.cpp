#include "../header.h"

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        for (int i = 0; i < strs.size(); ++i) {
            int j = 0;
            for (j = 0; j < strs.size(); ++j) {
                if (j == i) {
                    continue;
                }
                if (isSubsequence(strs[i], strs[j])) {
                    break;
                }
            }
            if (j == strs.size()) {
                res = max(res, (int)strs[i].size());
            }
        }
        return res;
    }

    bool isSubsequence(string const& a, string const& b) {
        int al = 0;
        for (int i = 0; i < b.length() && al < a.length(); ++i) {
            if (a[al] == b[i]) {
                al++;
            }
        }
        return al == a.length();
    }
};