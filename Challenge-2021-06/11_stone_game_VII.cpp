#include "../header.h"

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
      int sz = stones.size();
      vector<vector<int>> dp(sz, vector<int>(sz, 0));
      vector<int> seqSum(sz + 1, 0);
      for (int i = 0; i < sz; ++i) {
        seqSum[i+1] = seqSum[i] + stones[i];
      }
      for (int i = sz - 2; i >= 0; --i) {
        for (int j = i + 1; j < sz; ++j) {
          dp[i][j] = max(seqSum[j+1] - seqSum[i+1] - dp[i+1][j], seqSum[j] - seqSum[i] - dp[i][j-1]);
        }
      }
      return dp[0][sz-1];        
    }
};