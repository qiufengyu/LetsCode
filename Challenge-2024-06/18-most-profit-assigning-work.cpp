#include "../header.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> mp;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            mp[difficulty[i]] = max(mp[difficulty[i]], profit[i]);
        }
        int maxP = 0;
        for (auto const& p: mp) {
            maxP = max(maxP, p.second);
            mp[p.first] = maxP;
        }
        int res = 0;
        for (int i = 0; i < worker.size(); i++) {
            int a = worker[i];
            auto ub = prev(mp.upper_bound(a));
            res += (*ub).second;
        }
        return res;
    }
};