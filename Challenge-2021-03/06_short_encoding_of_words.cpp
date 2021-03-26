#include "../header.h"

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (auto& w: words) {
            for (int i = 1; i < w.size(); i++) {
                s.erase(w.substr(i));
            }
        }
        int res = 0;
        for (auto& w: s) {
            res += (1 + w.size());
        }
        return res;
    }
};
