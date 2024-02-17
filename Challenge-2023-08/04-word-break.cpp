#include "../header.h"

class Solution {
    bool helper(vector<int>& dp, unordered_set<string>& dict, int n, int index, string const& s) {
        if (index >= n) {
            return true;
        }
        if (dp[index] == 1) {
            return true;
        } else if (dp[index] == 0) {
            return false;
        }
        for (int i = index; i < n; i++) {
            string ss = s.substr(index, i - index + 1);
            if (dict.count(ss)) {
                if (i + 1 < n) {
                    if (dp[i+1] == 1)  {
                        dp[index] = 1;
                        return true;
                    } else if (dp[i+1] == 0) {
                        dp[index] = 0;
                    }
                }                    
                if (helper(dp, dict, n, i+1, s)) {
                    dp[index] = 1;
                    return true;
                }
            }
        }
        dp[index] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);
        return helper(dp, dict, n, 0, s);
    }
};

int main() {
    string s = "catsandog";
    vector<string> wordDict{"cats","dog","sand","and","cat"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}