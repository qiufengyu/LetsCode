#include "../header.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++m[tasks[i]];
        }
        for (auto const& p: m) {
            if (p.second == 1) {
                return -1;
            } else {
                res += ((p.second + 2) / 3);
            }
        }
        return res;
    }
};