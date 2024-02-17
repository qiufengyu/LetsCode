#include "../header.h"

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = endTime[i];
            jobs[i][1] = startTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> m{{0, 0}};
        for (auto const& j: jobs) {
            auto p = prev(m.upper_bound(j[1]));
            int x = p->second + j[2];
            if (x > rbegin(m)->second) {
                m[j[0]] = x;
            }
        }
        return rbegin(m)->second;
    }
};