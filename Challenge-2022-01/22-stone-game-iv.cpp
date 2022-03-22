#include "../header.h"

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, 0);
        return win(n, dp) > 0;
    }

    int win(int n, vector<int>& dp) {
        // Neither A or B reach        
        if (dp[n] == 0) {
            for (int i = sqrt(n); i >= 1; --i) {
                if (win(n - i * i, dp) < 0) {
                    dp[n] = 1;
                    return 1;
                }
            }
            // A cannot win
            dp[n] = -1;
            return -1;
        }
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().winnerSquareGame(n) << endl;
    return 0;
}