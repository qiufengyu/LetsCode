#include "../header.h"

class Solution {
public:
    int kthFactor(int n, int k) {
      vector<int> rest{n};
      int count = 1;
      if (k == 1) {
        return 1;
      }
      for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
          count++;
          rest.push_back(n / i);
        }
        if (count == k) {
          return i;
        }
      }
      int s = (int)sqrt(n);
      int r = count + rest.size() - k;
      if (s * s == n) {
        r--;
      }        
      // in the rest part or exceed
      if (r >= rest.size()) {
        return -1;
      }
      return rest[r];
    }
};

int main() {
  int n, k;
  cin >> n >> k;
  cout << Solution().kthFactor(n, k) << endl;
  return 0;
}