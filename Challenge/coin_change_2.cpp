#include "header.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> res(amount + 1, vector<int>(coins.size() + 1, 0));
        sort(coins.begin(), coins.end());
        for (int j = 0; j < coins.size() + 1; j++) {
            res[0][j] = 1;
        }
        for (int i = 1; i < amount + 1; i++) {
            for(int j = 1; j < coins.size() + 1; j++) {
                res[i][j] = res[i][j-1];
                if (i - coins[j-1] >= 0) {
                    res[i][j] += res[i-coins[j-1]][j];
                }            
            }
        }
        print_vector(res);
        return res[amount][coins.size()];
    }
};


int main() {
    int amount = 20;
    vector<int> coins {1,2,3,4,5};
    cout << Solution().change(amount, coins) << endl;
    return 0;
}