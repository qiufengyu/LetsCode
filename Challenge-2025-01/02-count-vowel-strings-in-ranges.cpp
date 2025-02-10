#include "../header.h"

inline bool vowel(string const& s) {
    if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u')) {
        return true;
    }
    return false;
}

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> counts(words.size() + 1, 0);
        for (int i = 1; i <= words.size(); i++) {
            if (vowel(words[i-1])) {
                counts[i] = counts[i-1] + 1;
            } else {
                counts[i] = counts[i-1];
            }
        }
        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int q1 = queries[i][0], q2 = queries[i][1];
            res[i] = counts[q2 + 1] - counts[q1];
        }
        return res;
    }
};