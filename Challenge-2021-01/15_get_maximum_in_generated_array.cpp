#include "../header.h"

class Solution {
public:
    int getMaximumGenerated(int n) {
        int a[101];
        memset(a, 0, 101);
        a[1] = 1;
        if (n <= 1) {
          return n;
        }
        int ans = INT_MIN;
        for (int i = 2; i <= n; i++) {
          if (i & 1) {
            a[i] = a[i/2] + a[i/2+1];
          } else {
            a[i] = a[i/2];
          }
          ans = max(ans, a[i]);
        }
        return ans;
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().getMaximumGenerated(n) << endl;
  return 0;
}