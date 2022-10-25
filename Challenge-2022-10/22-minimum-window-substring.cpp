#include "../header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (auto const& c: t) {
            ++m[c];
        }
        int left = 0, right = 0, count = t.size();
        int start = 0, length = INT_MAX;
        while (right < s.size()) {
            if (m[s[right]] > 0) {
                --count;
            }
            --m[s[right]];
            ++right;
            while (count == 0) {
                if (right - left < length) {
                    start = left;
                    length = right - left;
                }
                m[s[left]]++;
                if (m[s[left]] > 0) {
                    ++count;
                }
                ++left;
            }
        }
        if (length < INT_MAX) {
            return s.substr(start, length);
        }
        return "";
    }
};