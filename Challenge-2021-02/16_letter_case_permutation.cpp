#include "../header.h"

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string s = "";
        helper(S, s, res, S.size(), 0);
        return res;
    }

    void helper(const string S, string current, vector<string>& res, int length, int index) {
      if (index >= length) {
        res.push_back(current);
        return;
      }
      if (isdigit(S[index])) {
        string temp = current + S[index];
        helper(S, temp, res, length, index+1);
      } else {
        string temp1 = current + S[index];
        helper(S, temp1, res, length, index+1);
        if (S[index] >= 'a' && S[index] <= 'z') {
          string temp2 = current + ((char)(S[index] - 'a' + 'A'));
          helper(S, temp2, res, length, index+1);
        } else {
          string temp2 = current + ((char)(S[index] - 'A' + 'a'));
          helper(S, temp2, res, length, index+1);
        }
      }
    }
};

int main() {
  string s;
  cin >> s;
  vector<string> res = Solution().letterCasePermutation(s);
  print_vector(res);
  return 0;
}