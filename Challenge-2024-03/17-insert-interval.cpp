#include "../header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) {
            return {newInterval};
        }
        int start = newInterval[0], end = newInterval[1];
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        auto endsLB = lower_bound(ends.begin(), ends.end(), start);
        auto startsUB = upper_bound(starts.begin(), starts.end(), end);
        if (endsLB == ends.end()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (startsUB == starts.begin()) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int startIndex = endsLB - ends.begin();
        if (*endsLB == start) {
            startIndex--;
        }
        int endIndex = startsUB - starts.begin();
        int index = 0;
        vector<vector<int>> res;
        for (index = 0; index < startIndex && index < n; index++) {
            res.push_back(intervals[index]);
        }
        int a = min(start, startIndex >= 0 ? intervals[startIndex][0] : start);
        int b = max(end, endIndex < n ? intervals[endIndex][1] : end);
        res.push_back({a, b});
        while (endIndex < n) {
            res.push_back(intervals[endIndex]);
            endIndex++;
        }
        return res;
    }
};