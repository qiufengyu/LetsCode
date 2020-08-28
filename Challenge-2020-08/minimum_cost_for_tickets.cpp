#include "../header.h"

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        for (auto d: days) {
            dp[d] = 0;
        }
        dp[0] = 0;
        for (int i = 1; i < 366; i++) {
            if (dp[i] == -1) {
                dp[i] = dp[i-1];
            } else {
                int temp = dp[i-1] + costs[0];
                temp = min(temp, dp[max(i-7, 0)] + costs[1]);
                temp = min(temp, dp[max(i-30, 0)] + costs[2]);
                dp[i] = temp;
            }
        }
        return dp[365];
    }
};

int main() {
    string d {"[1,2,3,4,6,7,9,10]"}, c{"[3,5,15]"};
    // cin >> d >> c;
    vector<int> days = stringToIntegerVector(d);
    vector<int> costs = stringToIntegerVector(c);
    cout << Solution().mincostTickets(days, costs) << endl;
    return 0;
}