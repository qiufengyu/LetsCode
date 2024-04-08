#include "../header.h"

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(), i = 0, res = 0, count = 0;
        while (i < n) {
            if (s[i] == '(') {
                count++;
                res = max(res, count);
            } else if (s[i] == ')') {
                count--;
            }
            i++;
        }
        return res;        
    }
};