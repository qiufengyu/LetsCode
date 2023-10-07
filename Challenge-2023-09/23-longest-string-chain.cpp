#include "../header.h"

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n <= 1) {
            return n;
        }
        sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool { return a.length() < b.length();});
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            string a = words[i];
            for (int j = 0; j < i; j++) {
                if (predecessor(a, words[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    bool predecessor(const string& a, const string& b) {
        if (a.size() == (b.size() + 1)) {
            for (int i = 0; i < a.size(); i++) {
                string ac = a.substr(0, i) + a.substr(i + 1, a.size() - i - 1);
                if (ac == b) {
                    return true;
                }
            }
        }
        return false;
    }
};