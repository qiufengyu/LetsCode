#include "../header.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        if (num.size() <= k) {
            return "0";
        }
        for (int i = 0; i < num.size(); ++i) {
            while (res.size() > 0 && res.back() > num[i] && k > 0) {
                res.pop_back();
                --k;
            }
            if (res.size() > 0 || num[i] != '0') {
                res.push_back(num[i]);
            }
        }
        while (res.size() > 0 && k > 0) {
            res.pop_back();
            --k;
        }
        if (res.size() == 0) {
            return "0";
        }
        return res;
    }
};