#include "../header.h"

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& v1, const vector<int>& v2) -> bool {
            return v1[0] < v2[0];
        });
        print_vector<int>(points);
        int res = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            res = max(points[i+1][0] - points[i][0], res);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> p{{8,7},{9,9},{7,4},{9,7}};
    cout << Solution().maxWidthOfVerticalArea(p) << endl;
    return 0;
}