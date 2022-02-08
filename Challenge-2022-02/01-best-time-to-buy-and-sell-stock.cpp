#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, mn = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] <= mn) {
                mn = prices[i];
            }
            res = max(res, prices[i] - mn);
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> prices = stringToIntegerVector(s);
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}