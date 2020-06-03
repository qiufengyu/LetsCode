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
        int res = 0;
        for(int i = 0; i<sz-1; ++i) {
            res += max(prices[i+1]-prices[i], 0);
        }
        return res;
    }
};
int main() {
    vector<int> v = {4,2,1,5};
    auto res = Solution().maxProfit(v);
    cout<<res<<endl;
    return 0;
}
