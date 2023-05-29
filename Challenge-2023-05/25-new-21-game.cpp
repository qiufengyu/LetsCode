#include "../header.h"

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= (k + maxPts - 1)) {
            return 1.0;
        }
        vector<double> dp(n+1, 0.0);
        double res = 0.0;
        dp[0] = 1.0;
        double sum = 1.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = sum / (double)maxPts;
            if (i < k) {
                sum += dp[i];
            }
            if (i - maxPts >= 0 && i - maxPts < k) {
                sum -= dp[i - maxPts];
            }
        }
        for (int i = k; i <= n; ++i) {
            res += dp[i];
        }
        return res;
    }
};

int main() {
    cout << Solution().new21Game(12, 1, 10) << endl;
    return 0;
}