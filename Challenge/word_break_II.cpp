#include "../header.h"

class Solution {
    unordered_map<string, vector<string>> mem;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        return helper(wordSet, s);
    }

    vector<string> helper(set<string>& wordSet, string s) {
        if (mem.count(s)) return mem[s];
        if (s.length() == 0) return {""};
        vector<string> res;
        for (string w: wordSet) {
            if (s.substr(0, w.size()).compare(w) == 0) {
                vector<string> right = helper(wordSet, s.substr(w.size()));
                for (string r: right) {
                    res.push_back(w + (r.size() == 0 ? "" : " ") + r);
                }
            }
        }
        return mem[s] = res;
    }    
};

int main() {
    vector<string> dict {"cat", "cats", "and", "sand", "dog"};
    string s {"catsanddog"};
    for(auto r: Solution().wordBreak(s, dict)) {
        cout << r << endl;
    }
}