#include "../header.h"

class Solution {
public:
    int takeCharacters(string s, int k) {        
        if (k == 0) {
            return 0;
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
            return -1;
        }
        unordered_map<char, int> mp1, mp2;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            mp1[s[i]]++;
            if (mp1['a'] >= k && mp1['b'] >= k && mp1['c'] >= k) {
                left = i;
                break;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            mp2[s[i]]++;
            if (mp2['a'] >= k && mp2['b'] >= k && mp2['c'] >= k) {
                right = i;
                break;
            }
        }
        int res = min(left + 1, (int)s.size() - right);
        for (int i = 0; i <= left; i++) {
            mp2[s[i]]++;
            if (s[i] == s[right]) {
                while (mp2['a'] >= k && mp2['b'] >= k && mp2['c'] >= k && right < s.size()) {
                    mp2[s[right]]--;
                    right++;
                }
                right--;
                mp2[s[right]]++;
                res = min(res, i + 1 + (int)s.size() - right);
            }
        }
        return res;
    }
};