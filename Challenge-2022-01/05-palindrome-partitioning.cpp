#include "../header.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        int index = 0;
        helper(s, res, current, index);
        return res;
    }

    bool isPalindrome(string const& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void helper(string const& s, vector<vector<string>>& res, vector<string>& current, int index) {
        if (index == s.size()) {
            res.push_back(current);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                current.push_back(s.substr(index, i - index + 1));
                helper(s, res, current, i + 1);
                current.pop_back();
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    vector<vector<string>> res = Solution().partition(s);
    print_vector<string>(res);
    return 0;
}