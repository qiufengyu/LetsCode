#include "../header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int sz = intervals.size();
        int i = 0;
        while (i < sz && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }
        while (i < sz && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        res.push_back(newInterval);
        while (i < sz) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};

int main() {

}