#include "../header.h"

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        for (vector<int>& r: wall) {
          int sum = 0, rz = r.size();
          for (int i = 0; i < rz - 1; ++i) {
            sum += r[i];
            ++m[sum];
          }
        }
        int mx = 0;
        for (auto& p: m) {
          mx = max(mx, p.second);
        }
        return wall.size() - mx;
    }
};
