#include "../header.h"

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        vector<int> start(26, INT_MAX), end(26, INT_MIN);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            start[idx] = min(start[idx], i);
            end[idx] = max(end[idx], i); 
        }
        for (int i = 0; i < 26; i++) {
            if (start[i] != INT_MAX && end[i] != INT_MIN) {
                res = max(res, end[i] - start[i] - 1);
            }
        }
        return res;
    }
};