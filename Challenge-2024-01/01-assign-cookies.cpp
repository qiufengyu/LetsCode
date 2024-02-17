#include "../header.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIndex = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= g[gIndex]) {
                gIndex++;
                res++;
            }
            if (gIndex == g.size()) {
                break;
            }
        }
        return res;
    }
};