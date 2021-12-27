#include "../header.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> const& a, vector<int> const& b) -> bool {
                 return a[0] < b[0];
            }
        );
        vector<vector<int>> res;
        // 1 <= intervals.size() <= 10000 
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            int l = intervals[i][0], r = intervals[i][1];
            if (end < l) {
                res.push_back({start, end});
                start = l;
                end = r;
            } else {
                end = max(end, r);
            }
        }
        res.push_back({start, end});
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = Solution().merge(intervals);
    print_vector<int>(res);
    return 0;
}