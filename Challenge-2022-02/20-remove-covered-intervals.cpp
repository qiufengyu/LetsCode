#include "../header.h"

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        int res = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            auto interval = intervals[i];
            if (interval[1] > r) {
                if (interval[0] > l) { // if same, then the previous is covered.
                    ++res;
                }
                l = interval[0];
                r = interval[1];
            }
        }
        return res;
    }
};