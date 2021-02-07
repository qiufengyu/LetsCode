#include "../header.h"

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int sz = s.size();
        vector<int> res(sz, 0);
        vector<int> index;
        for (int i = 0; i < sz; i++) {
          if (s[i] == c) {
            index.push_back(i);
          }
        }
        int lastIndex = index.size();
        int nearest1 = -index[0];
        int nearest2 = index[0];
        int nearestIndex = 0;
        for (int i = 0; i < sz; i++) {
          if (i >= nearest1 && i <= nearest2) {
            res[i] = min(i-nearest1, nearest2 - i);
          } else {
            nearest1 = nearest2;
            if (nearestIndex < lastIndex - 1) {
              nearest2 = index[++nearestIndex];
            }
            res[i] = min(i - nearest1, abs(nearest2 - i));
          }
        }
        return res;
    }
};

int main() {
  string s;
  cin >> s;
  char c;
  cin >> c;
  auto res = Solution().shortestToChar(s, c);
  print_vector(res);
  return 0;
}