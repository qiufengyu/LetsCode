#include "../header.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string& a, const string& b) -> bool {
            if (a.size() == b.size()) {
                return a < b;
            } else {
                return a.size() > b.size();
            }
        });
        size_t sl = s.length();
        for (auto x: d) {
            size_t xl = x.length();
            if (xl > sl) {
                continue;
            }
            // if x is subsequence of s
            int si = 0;
            int xi = 0;
            while (si < sl) {
                if (x[xi] == s[si]) {
                    xi++;
                }
                if (xi == xl) {
                    return x;
                }
                si++;
            }
        }
        return "";
    }
};
