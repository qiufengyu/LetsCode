#include "../header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> lcs(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1; ++i) {
          for (int j = 1; j <= l2; ++j) {
            if (word1[i-1] == word2[j-1]) {
              lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else {
              lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
          }
        }
        return l1 + l2 - 2 * lcs[l1][l2];
    }
};

int main() {
  string w1, w2;
  cin >> w1 >> w2;
  cout << Solution().minDistance(w1, w2) << endl;
  return 0;
}