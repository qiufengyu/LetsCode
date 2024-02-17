#include "../header.h"

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int s1 = INT_MAX, s2 = INT_MAX;        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= s1) {                
                s2 = s1;
                s1 = prices[i];
            } else if (prices[i] < s2) {
                s2 = prices[i];
            }
        }
        int res = money - s1 - s2;
        if (res >= 0) {
            return res;
        }
        return money;
    }
};