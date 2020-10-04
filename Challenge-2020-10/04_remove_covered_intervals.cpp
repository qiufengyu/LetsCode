#include "../header.h"

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        int right = -1;
        int cover = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] <= right) {
                cover++;
            } else {
                right = intervals[i][1];
            }
        }
        return intervals.size() - cover;
    }
};

