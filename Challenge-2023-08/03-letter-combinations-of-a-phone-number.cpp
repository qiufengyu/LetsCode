#include "../header.h"

class Solution {
    unordered_map<char, string> mp {{'2', "abc"}, {'3', "def"},
                      {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                      {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    void helper(const string& digits, vector<string>& res, string& current, int index, const int n) {
        if (index == n) {
            res.push_back(current);
            return;
        }
        char d = digits[index];
        for (auto const& c: mp[d]) {
            current.push_back(c);
            helper(digits, res, current, index+1, n);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        if (n == 0) {
            return res;
        }
        string current;
        helper(digits, res, current, 0, n);
        return res;
    }
};