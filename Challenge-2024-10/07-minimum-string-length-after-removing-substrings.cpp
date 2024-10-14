#include "../header.h"

class Solution {
public:
    int minLength(string s) {
        string res{""};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D' && res.size() > 0 && *prev(res.end()) == 'C') {
                res.pop_back();
            } else if (s[i] == 'B' && res.size() > 0 && *prev(res.end()) == 'A') {
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        return (int)res.size();
    }
};