#include "../header.h"

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m;
        for (const auto& n: nums) {
          ++m[n];
        }
        int res = 0;
        for (const auto& e: m) {
          if (e.first < (k+1) / 2) {
            res += min(m[e.first], m[k - e.first]);
          }
        }
        if ((k & 1) == 0 && m[k / 2] > 0) {
          res += (m[k / 2] / 2);
        }
        return res;
    }
};

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  auto v = stringToIntegerVector(s);
  cout << Solution().maxOperations(v, k) << endl;
  return 0;
}