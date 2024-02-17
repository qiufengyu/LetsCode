#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[zero] += 1;
        dp[one] += 1;
        for (int i = 1; i <= high; ++i) {
            dp[i] = (dp[i] + dp[max(0, i - zero)]) % M;
            dp[i] = (dp[i] + dp[max(0, i - one)]) % M;
        }
        print_vector<int>(dp);
        int res = 0;
        for (int i = low; i <= high; ++i) {
            res = (res + dp[i]) % M;
        }
        return res;
    }
};

int main() {
    int l = 3, h = 3, o = 1, z = 1;
    cout << Solution().countGoodStrings(l, h, z, o) << endl;
    return 0;
}