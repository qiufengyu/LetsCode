#include "../header.h"

using std::get;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<tuple<int, bool, int>> time(2 * n);
        for (int i = 0; i < n; i++) {
            int s = events[i][0], e = events[i][1], v = events[i][2];
            time[2 * i] = {s, false, v};
            time[2 * i + 1] = {e, true, v};
        }
        sort(time.begin(), time.end());
        int res = 0, maxV = 0;
        for (auto const& t: time) {
            if (get<1>(t)) {
                maxV = max(maxV, get<2>(t));
            } else {
                res = max(res, maxV + get<2>(t));
            }
        }
        return res;
    }
};