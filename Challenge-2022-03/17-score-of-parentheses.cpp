#include "../header.h"

class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        int depth = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                depth++;
                if (s[i+1] == ')') {
                    res += 1 << depth;
                }
            } else {
                depth--;
            }
        }
        return res;
    }
};
