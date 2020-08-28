#include "../header.h"

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        unordered_map<int, int> m;
        vector<int> start;
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
            start.push_back(intervals[i][0]);
        }
        sort(start.begin(), start.end());
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            int j;
            for (j = start.size() - 1; j >= 0; j--) {
                if (start[j] < interval[1]) break; // j+1 is the right interval start index
            }
            res.push_back(j == start.size() - 1 ? -1 : m[start[j+1]]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals {{1,4}, {2,3}, {3,4}};
    for (auto r: Solution().findRightInterval(intervals)) {
        cout << r << endl;
    }
    return 0;
}

