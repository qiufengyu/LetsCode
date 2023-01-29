#include "../header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            return {newInterval};
        }
        int i = 0;
        for (i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] >= newInterval[0]) {
                break;
            } else {
                res.push_back(intervals[i]);
            }
        }
        int mn = newInterval[0], mx = newInterval[1];
        while (i < intervals.size()) {            
            if (intervals[i][0] > mx) {
                break;
            }
            mn = min(mn, intervals[i][0]);
            mx = max(mx, intervals[i][1]);
            ++i;
        }
        res.push_back({mn, mx});
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};