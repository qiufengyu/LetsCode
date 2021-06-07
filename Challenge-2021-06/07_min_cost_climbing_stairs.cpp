#include "../header.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f[1001];
        int sz = cost.size();
        for (int i = 0; i <= sz; ++i) {
          f[i] = INT_MAX;
        }
        f[sz] = cost[sz-1];
        f[sz - 1] = cost[sz-2];
        for (int i = sz - 2; i > 0; --i) {
          f[i] = cost[i-1] + min(f[i+1], f[i+2]);
        }
        // f[0] = min(f[1], f[2]);
        return min(f[2], f[1]);
    }
};

int main() {
  vector<int> cost {1,100,1,1,1,100,1,1,100,1};
  cout << Solution().minCostClimbingStairs(cost) << endl;
  return 0;
}