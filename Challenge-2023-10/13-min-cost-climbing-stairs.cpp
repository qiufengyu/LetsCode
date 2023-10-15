#include "../header.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c1 = 0, c2 = 0;
        cost.push_back(0);
        for (int i = 2; i < cost.size(); i++) {
            int tmp = c2;
            c2 = min(c1 + cost[i-2], c2 + cost[i-1]);
            c1 = tmp;
        }
        return c2;
    }
};

int main() {
    vector<int> cost {1,100,1,1,1,100,1,1,100,1};
    cout << Solution().minCostClimbingStairs(cost) << endl;
    return 0;
}