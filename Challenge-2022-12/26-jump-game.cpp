#include "../header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int t = q.front();
                q.pop();
                int s = nums[t];
                while (s > 0) {
                    if (t + s >= n - 1) {
                        return true;                        
                    }
                    if (t + s < n - 1 && dp[t + s] == 0) {
                        dp[t + s] = 1;
                        q.push(t + s);
                    }
                    --s;                    
                }
                --sz;
            }
        }
        return dp[n-1] == 1;
    }
};