#include "../header.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
          return {};
        }
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> res;
        int d_index = 0;
        string current = "";
        helper(digits, m, res, current, d_index);
        return res;
    }

private:
    void helper(const string& digits, unordered_map<char, string>& m, vector<string>& res, string current, int d_index) {
      if (current.length() == digits.length()) {
        res.push_back(current);
        return;
      }
      string candidate = m[digits[d_index]];
      for (int i = 0; i < candidate.size(); ++i) {
        current.push_back(candidate[i]);
        helper(digits, m, res, current, d_index+1);
        current.pop_back();
      }
    }
};

int main() {
  string digits;
  cin >> digits;
  vector<string> res = Solution().letterCombinations(digits);
  for (auto r: res) {
    cout << r << endl;
  }
  return 0;
}