#include "../header.h"

class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ones = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        int res = 0, zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }
            res = max(res, zeros + ones);
        }
        return res;
    }
};