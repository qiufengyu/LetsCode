#include "../header.h"

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int i = 2;
        int r = -1;
        while (i < n) {
            char c1 = num[i-2], c2 = num[i-1], c3 = num[i];
            if (c1 == c2) {
                if (c2 == c3) {
                    r = max(r, c1 - '0');
                    i += 3;
                } else {
                    i += 2;
                }                
            } else {
                i++;
            }
        }
        string res;
        if (r >= 0) {
            char x = r + '0';            
            res.push_back(x);
            res.push_back(x);
            res.push_back(x);
        }
        return res;
    }
};