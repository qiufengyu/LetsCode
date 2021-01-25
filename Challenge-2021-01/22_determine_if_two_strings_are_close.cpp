#include "../header.h"

class Solution {
public:
    bool closeStrings(string word1, string word2) {
      int l1 = word1.length(), l2 = word2.length();
      if (l1 == l2) {
        vector<int> f1(26, 0), f2(26, 0);
        vector<int> c1(26, 0), c2(26, 0);
        // same charset, same pattern
        for (int i = 0; i < l1; i++) {
          ++f1[word1[i] - 'a'];
          c1[word1[i] - 'a'] = 1;
          ++f2[word2[i] - 'a'];
          c2[word2[i] - 'a'] = 1;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2 && c1 == c2;
      }
      return false;      
    }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << Solution().closeStrings(s1, s2) << endl;
  return 0;
}