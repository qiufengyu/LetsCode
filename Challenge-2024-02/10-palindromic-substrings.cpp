#include "../header.h"

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> palidrome(n, vector<bool>(n, false));
        int res = 0;
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                if (s[i] == s[i+l-1] && (l <= 2 || palidrome[i+1][i+l-2])) {
                    palidrome[i][i+l-1] = true;
                    res++;
                }
            }
        }
        return res;
    }
};