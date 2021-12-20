#include "../header.h"

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int res = 0;
        int l = digits.size();
        string s = to_string(n);
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            res += pow(l, i);
        }
        // generating number with len size
        for (int i = 0; i < len; ++i) {
            bool in = false;
            for (const string& digit: digits) {
                if (digit[0] < s[i]) {
                    res += pow(l, len - i - 1);
                } else if (digit[0] == s[i]) {
                    in = true;
                    break;
                }
            }
            if (!in) {
                return res;
            }
        }
        return res + 1;
    }
};