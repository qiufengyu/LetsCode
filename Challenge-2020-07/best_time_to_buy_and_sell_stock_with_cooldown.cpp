#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if (days == 0) {
            return 0;
        }
        vector<int> buy(days + 1, 0); // with stock
        vector<int> sell(days + 1, 0); // without stock
        buy[0] = -prices[0];
        for (int i = 0; i < days; i++) {
            int price = prices[i];
            buy[i + 1] = max(buy[i], - price + (i == 0 ? 0 : sell[i-1]));
            sell[i + 1] = max(sell[i], buy[i] + price);
        }
        return sell[days];        
    }
};

int main() {
    vector<int> prices {1,2,3,0,2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}