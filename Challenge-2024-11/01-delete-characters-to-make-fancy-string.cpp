#include "../header.h"

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int count = 1;
        res.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == res.back()) {
                count++;
            } else {
                count = 1;
            }
            if (count <= 2) {
                res.push_back(s[i]);
            }
        }    
        return res;  
    }
};