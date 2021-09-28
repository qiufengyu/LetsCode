#include "../header.h"

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> intArr;
        for (auto const& a: arr) {
            int mask = 0;
            for (char c: a) {
                mask |= (1 << (c - 'a'));
            }
            if (__builtin_popcount(mask) != a.length()) {
                // if the string contains duplicated char, should not be considered
                continue;
            }
            intArr.push_back(mask);
        }
        int res = 0;
        dfs(0, 0, res, intArr);
        return res;        
    }

    void dfs(int s, int mask, int& res, vector<int>& intArr) {
        res = max(res, __builtin_popcount(mask));
        for (int i = s; i < intArr.size(); ++i) {
            if ((mask & intArr[i]) == 0) {
                dfs(i + 1, mask | intArr[i], res, intArr);
            }
        }
    }
};