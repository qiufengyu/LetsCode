#include "../header.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        helper(s, res, current, 0);
        return res;
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

    void helper(const string& s, vector<vector<string>>& res, vector<string>& current, int index) {
        if (index == s.size()) {
            res.push_back(current);
        } else {
            for (int i = index; i < s.size(); ++i) {
                if (isPalindrome(s, index, i)) {
                    current.push_back(s.substr(index, i - index + 1));
                    helper(s, res, current, i + 1);
                    current.pop_back();
                }
            }
        }
    }
};