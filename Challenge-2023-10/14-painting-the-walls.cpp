#include "../header.h"

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // the order does not matter!
        int n = cost.size();
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            cout << i << endl;
            for (int j = n; j > 0; j--) {
                dp[j] = min(dp[j], cost[i] + dp[max(0, j - time[i] - 1)]);
            }
        }
        return dp[n];
    }
};

int main() {
    vector<int> cost {1,2,3,2}, time {1,5,3,2};
    cout << Solution().paintWalls(cost, time) << endl;
    return 0;
}