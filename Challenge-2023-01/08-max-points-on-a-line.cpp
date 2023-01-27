#include "../header.h"

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        for (int i = 0; i < n - 1; ++i) {
            unordered_map<double, int> m;
            int inf = 0;
            auto p1 = points[i];
            for (int j = i+ 1; j < n; ++j) {
                auto p2 = points[j];
                if (p1[0] == p2[0]) {
                    inf++;
                } else {
                    double k = (double)(p2[1] - p1[1]) / (p2[0] - p1[0]);
                    ++m[k];
                }
            }
            for (auto p: m) {
                inf = max(inf, p.second);
            }
            res = max(inf, res);
        }
        return res + 1;
    }
};

int main() {
    vector<vector<int>> points = {{0,0},{1,-1},{1,1}};
    cout << Solution().maxPoints(points) << endl;
    return 0;
}