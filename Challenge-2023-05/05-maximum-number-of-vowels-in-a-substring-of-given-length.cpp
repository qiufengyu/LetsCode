#include "../header.h"

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, v = 0;
        for (int i = 0; i < k && i < s.size(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') {
                v++;
            }
        }
        res = v;
        for (int i = k; i < s.size(); ++i) {
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                --v;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') {
                ++v;
            }
            res = max(res, v);
        }
        return res;
    }
};