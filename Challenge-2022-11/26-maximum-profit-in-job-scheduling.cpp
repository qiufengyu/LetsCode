#include "../header.h"

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> m{{0, 0}};
        for (auto const& j: jobs) {
            int p = prev(m.upper_bound(j[1]))->second + j[2];
            if (p > rbegin(m)->second) {
                m[j[0]] = p;
            }
        }
        return rbegin(m)->second;
    }
};