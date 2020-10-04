#include "../header.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> mem(s.size(), -1);
        return helper(wordSet, s, 0, mem);
    }

    bool helper(set<string>& wordSet, string s, int start, vector<int> &mem) {
        if (start >= s.size()) {
            return true;
        }
        if (mem[start] != -1) {
            return mem[start];
        }
        for (int i = start + 1; i <= s.size(); i++) {
            if (wordSet.count(s.substr(start, i - start)) && helper(wordSet, s, i, mem)) {
                return mem[start] = 1;
            }
        }
        return mem[start] = 0;
    }
};