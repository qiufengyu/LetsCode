#include "../header.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> v1, const vector<int> v2) -> bool { return v1[1] < v2[1]; });
        int noneOverlap = 0;
        if (intervals.size () < 1) {
            return 0;
        }
        int end = intervals[0][0] - 1;
        for (auto i: intervals) {
            if (i[0] >= end) {
                noneOverlap++;
                end = i[1];
            }
        }
        return intervals.size() - noneOverlap;
    }
};