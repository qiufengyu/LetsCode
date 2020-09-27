#include "../header.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dp (1001, 0);
        for (auto &t: trips) {
            dp[t[1]] += t[0];
            dp[t[2]] -= t[0];
        }
        for (int &c: dp) {
            capacity -= c;
            if (capacity < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> trips {{2,1,5},{3,5,7}};
    int capacity = 3;
    cout << Solution().carPooling(trips, capacity) << endl;
    return 0;
}