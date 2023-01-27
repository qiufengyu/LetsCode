#include "../header.h"

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size(), res = 0, current = 0;
        vector<pair<int, int>> gp;
        for (int i = 0; i < n; ++i) {
            gp.push_back({-growTime[i], plantTime[i]});
        }
        sort(gp.begin(), gp.end());
        for (int i = 0; i < n; ++i) {
            res = max(res, current + gp[i].second - gp[i].first);
            current += gp[i].second;
        }
        return res;
    }
};