#include "../header.h"

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> ws;
        for (auto const& word: words) {
            ws.insert(word);
        }
        vector<string> res;
        for (auto const& word: words) {
            int l = word.length();
            vector<int> dp(l+1, 0);
            dp[0] = 1;
            for (int i = 0; i < l; ++i) {
                if (dp[i] == 0) {
                    continue;
                }
                for (int j = i + 1; j <= l; ++j) {
                    if (j - i < l && ws.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[l] == 1) {
                    res.push_back(word);
                    break; // can exit first
                }
            }
        }
        return res;
    }
};
