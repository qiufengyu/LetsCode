#include "../header.h"

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for (auto const& word: words)  {
            for (int i = 1; i < word.size(); ++i) {
                st.erase(word.substr(i));
            }
        }
        int res = 0;
        for (auto const& word: st) {
            res += (1 + word.size());
        }
        return res;
    }
};