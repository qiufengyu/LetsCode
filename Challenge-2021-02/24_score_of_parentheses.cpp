#include "../header.h"

class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        int depth = -1;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                ++depth;
                if (S[i+1] == ')') {
                    res += 1 << depth;
                } 
            } else {
                --depth;
            }
        }
        return res;
    }
};
