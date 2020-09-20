#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        } else {
            int ans = 0, minPrice = prices[0];
            for (auto x: prices) {
                if (x < minPrice) {
                    minPrice = x;
                }
                int temp = x - minPrice;
                if (temp > ans) {
                    ans = temp;
                }
            }
            return ans;
        }
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().maxProfit(v) << endl;
    return 0;
}