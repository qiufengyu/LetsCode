#include "../header.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] < b[0]) {
                return true;
            } else if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return false;
            }
        });
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(intervals[i][1], end);
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];              
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};