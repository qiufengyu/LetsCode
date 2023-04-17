#include "../header.h"

class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for (auto const c: s) {
            if (c == '*') {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
