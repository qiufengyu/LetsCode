#include "../header.h"

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(digits.begin(), digits.end());
        int ans = 0;
        int D = digits.size();
        string s = to_string(n);
        int len = s.size();
        for (int i = 1; i < len; i++) {
            ans += pow(D, i);
        }
        for (int i = 0; i < len; i++) {
            bool inDigits = false;
            for (const string& digit: digits) {
                if (digit[0] < s[i]) {
                    ans += pow(D, len - i - 1);
                } else if (digit[0] == s[i]) {
                    inDigits = true;
                    break;
                }
            }
            if (!inDigits) {
                return ans;
            }
        }
        return ans + 1;
    }
};