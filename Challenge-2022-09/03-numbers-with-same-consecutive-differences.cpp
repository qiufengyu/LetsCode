#include "../header.h"

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> res {1,2,3,4,5,6,7,8,9};
        for (int i = 2; i <= n; ++i) {
            set<int> temp;
            for (int x: res) {
                int d = x % 10;
                if (d + k < 10) {
                    temp.insert(x * 10 + d + k);
                }
                if (d - k >= 0) {
                    temp.insert(x * 10 + d - k);
                }
            }
            res = temp;
        }
        return vector<int>(res.begin(), res.end());
    }
};