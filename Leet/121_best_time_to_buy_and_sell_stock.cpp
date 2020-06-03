//
// Created by Fengyu Qiu on 2018/7/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0) {
            return 0;
        }
        int profit = 0;
        int cMin = prices[0];
        for(int i = 1; i<sz; ++i) {
            cMin = min(cMin, prices[i]);
            profit = max(profit, prices[i] - cMin);
        }
        return profit;
    }
};
int main() {
    vector<int> v = {4,2,1,5};
    auto res = Solution().maxProfit(v);
    cout<<res<<endl;
    return 0;
}
